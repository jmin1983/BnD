//
// StandardSampleWebService.cpp
//
// Library: SWSStandard
// Package: SWSStandard
// Module:  SWSStandard
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SWSStandard.h"
#include "StandardSampleWebService.h"
#include "StandardSampleWebServer.h"
#include "StandardSWSRepository.h"

#include <SampleBase/BuildInfo.h>

using namespace BnD;

StandardSampleWebService::StandardSampleWebService()
    : BaseSampleWebService(VERSION_SWS_LATEST, g_buildDate.copy(), "SampleWebService_Standard")
{
}

bool StandardSampleWebService::implInitRepositories()
{
    _repository.reset(new StandardSWSRepository());
    if (_repository->initialize() != true) {
        _repository->finalize();
        _repository.reset();
        return false;
    }
    return true;
}

auto StandardSampleWebService::createAcadiaServer() -> SampleWebServer*
{
    return new StandardSampleWebServer();
}

void StandardSampleWebService::implMainProcess()
{
}

void StandardSampleWebService::implFinalizeRepositories()
{
    if (_repository) {
        _repository->finalize();
        _repository.reset();
    }
}
