//
// SampleWebService.h
//
// Library: SWSIntegrated
// Package: SWSIntegrated
// Module:  SWSIntegrated
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSINTEGRATED_SAMPLE_WEB_SERVICE_H
#define _SWSINTEGRATED_SAMPLE_WEB_SERVICE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <D1Base/D1BaseServiceWrapper.h>
#include <D1Base/D1ProductIdentifier.h>

#include <BaseSampleWebService.h>

namespace BnD {
    class SampleWebService : public D1BaseServiceWrapper<BaseSampleWebService, SampleWebService> {
    protected:
        virtual BaseSampleWebService* createMainService(std::shared_ptr<D1ProductIdentifier> productIdentifier) override;
        int32 getServiceID(D1RedisClientInterface* redisReader) final { return 0; }
        D1ProductIdentifier* createProductIdentifier(int32 serviceID) final;
    };
}   //  !BnD

#endif  // !_SWSINTEGRATED_SAMPLE_WEB_SERVICE_H
