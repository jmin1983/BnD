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

using namespace BnD;

BaseSampleWebService* SampleWebServiceMFC::createMainService(D1ProductIdentifier::SITE site, D1ProductIdentifier::TYPE type)
{
    switch (type) {
        case D1ProductIdentifier::TYPE_STANDARD_SERVICE:
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
