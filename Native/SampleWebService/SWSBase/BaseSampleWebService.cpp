//
// BaseSampleWebService.cpp
//
// Library: SWSBase
// Package: SWSBase
// Module:  SWSBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SWSBase.h"
#include "BaseSampleWebService.h"
#include "SampleWebServer.h"

#include <B1Base/B1TickUtil.h>
#include <B1Redic/B1RedisDirectClient.h>

#include <D1Base/D1RedisClientInterface.h>
#include <D1Data/D1ConfFileReader.h>

#include <SampleMessage/SampleMessageAnalyzer.h>

using namespace BnD;

BaseSampleWebService::BaseSampleWebService(int32 version, B1String&& buildDate, B1String&& name)
    : B1MainService(version, std::move(buildDate), std::move(name))
{
}

auto BaseSampleWebService::createAcadiaServer() -> SampleWebServer*
{
    return new SampleWebServer();
}

bool BaseSampleWebService::implStart()
{
    uint64 loadPerfCheckTickBegin = B1TickUtil::currentTick();

    D1ConfFileReader confReader;
    if (confReader.loadDefault() != true) {
        B1LOG("no configuration file found -> load default value");
    }
    B1LOG("Connecting [%s:%d(%d)]", confReader.adminAddress().cString(), confReader.adminPort(), confReader.adminDB());
    if (initRedis(confReader.adminAddress(), confReader.adminPort(), confReader.adminDB()) != true) {
        return false;
    }
    if (implInitRepositories() != true) {
        return false;
    }
    if (initMessageAnalyzer() != true) {
        return false;
    }
    _acadiaServer.reset(createAcadiaServer());
    if (_acadiaServer == NULL) {
        return false;
    }
    if (initAcadiaServer() != true) {
        return false;
    }
    if (implInitManagers() != true) {
        return false;
    }
    implInitActions();
    redisClientInterface()->hmset("SWSInfo:Version", makeVersionInfoMap(), true);

    B1LOG("initializing performance check: tick[%llu]", B1TickUtil::diffTick(loadPerfCheckTickBegin, B1TickUtil::currentTick()));
    return true;
}

bool BaseSampleWebService::implWorking()
{
    implMainProcess();
    return true;
}

void BaseSampleWebService::implStop()
{
    implFinalizeManagers();
    if (_acadiaServer) {
        _acadiaServer->finalize();
        _acadiaServer.reset();
    }
    if (_messageAnalyzer) {
        _messageAnalyzer->finalize();
        _messageAnalyzer.reset();
    }
    implFinalizeRepositories();
    _redisClientInterface.reset();
    if (_redisDirectClient) {
        _redisDirectClient->finalize();
        _redisDirectClient.reset();
    }
}

bool BaseSampleWebService::initRedis(const B1String& address, int32 port, int32 db)
{
    _redisDirectClient.reset(new B1RedisDirectClient(NULL));
    if (_redisDirectClient->initialize(address, port, db, false) != true) {
        return false;
    }
    _redisClientInterface.reset(new D1RedisClientInterface(_redisDirectClient.get()));
    return true;
}

bool BaseSampleWebService::initMessageAnalyzer()
{
    _messageAnalyzer.reset(new SampleMessageAnalyzer());
    if (_messageAnalyzer->initialize(NULL) != true) {
        return false;
    }
    return true;
}

bool BaseSampleWebService::initAcadiaServer()
{
    const auto portString = redisClientInterface()->hmget("System:Configuration:SWS", "ServerPort");
    int32 port = SampleWebServer::CONSTS_DEFAULT_PORT;
    try {
        port = portString.toInt32();
    }
    catch (...) {}
    if (_acadiaServer->initialize(port) != true) {
        return false;
    }
    return true;
}
