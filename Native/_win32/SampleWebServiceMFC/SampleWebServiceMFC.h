//
// SampleWebServiceMFC.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <SampleWebService.h>

namespace BnD {
    class SampleWebServiceMFC : public SampleWebService {
    protected:
        BaseSampleWebService* createMainService(D1ProductIdentifier::SITE site, D1ProductIdentifier::TYPE type) final;
    public:
        D1RedisClientInterface* redisClientInterface();
    };
}   //  !BnD
