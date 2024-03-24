//
// BaseSampleWebService.h
//
// Library: SWSBase
// Package: SWSBase
// Module:  SWSBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSBASE_BASE_SAMPLE_WEB_SERVICE_H
#define _SWSBASE_BASE_SAMPLE_WEB_SERVICE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Base/B1MainService.h>
#include <B1Base/B1Singleton.h>

namespace BnD {
    class SampleWebServer;
    class SampleMessageAnalyzer;
    class D1RedisClientInterface;
    class B1RedisDirectClient;
    class BaseSampleWebService : public B1MainService
                            , public B1Singleton<BaseSampleWebService> {
    public:
        BaseSampleWebService(int32 version, B1String&& buildDate, B1String&& name);
        virtual ~BaseSampleWebService() {}
    protected:
        std::shared_ptr<SampleWebServer> _acadiaServer;
        std::shared_ptr<SampleMessageAnalyzer> _messageAnalyzer;
        std::shared_ptr<D1RedisClientInterface> _redisClientInterface;
        std::shared_ptr<B1RedisDirectClient> _redisDirectClient;
    protected:
        virtual bool implInitRepositories() { return true; }
        virtual SampleWebServer* createAcadiaServer();
        virtual bool implInitManagers() { return true; }
        virtual void implInitActions() {}
        virtual void implMainProcess() = 0;
        virtual void implFinalizeManagers() {}
        virtual void implFinalizeRepositories() {}
    protected:  //  B1MainService
        bool implStart() final;
        bool implWorking() final;
        void implStop() final;
    protected:
        bool initRedis(const B1String& address, int32 port, int32 db);
        bool initMessageAnalyzer();
        bool initAcadiaServer();
    public:
        D1RedisClientInterface* redisClientInterface() { return _redisClientInterface.get(); }
        SampleMessageAnalyzer* messageAnalyzer() { return _messageAnalyzer.get(); }
    };
}   //  !BnD

#endif  // !_SWSBASE_BASE_SAMPLE_WEB_SERVICE_H
