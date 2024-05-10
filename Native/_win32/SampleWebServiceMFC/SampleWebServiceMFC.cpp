//
// SampleWebServiceMFC.cpp
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "SampleWebServiceMFC.h"
#include "StandardSampleWebServicePublic.h"

#include <SampleBase/ProductIdentifier.h>

using namespace BnD;

auto SampleWebServiceMFC::createMainService(int32 site, int32 type) -> BaseSampleWebService*
{
    switch (type) {
        case ProductIdentifier::SAMPLE_TYPE_STANDARD_SERVICE:
            return new StandardSampleWebServicePublic();
        default:
            break;
    }
    return NULL;
}

D1RedisClientInterface* SampleWebServiceMFC::redisClientInterface()
{
    return _service->redisClientInterface();
}
