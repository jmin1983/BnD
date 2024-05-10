//
// SampleWebService.cpp
//
// Library: SWSIntegrated
// Package: SWSIntegrated
// Module:  SWSIntegrated
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SWSIntegrated.h"
#include "SampleWebService.h"

#include <StandardSampleWebService.h>

#include <SampleBase/ProductIdentifier.h>

using namespace BnD;

auto SampleWebService::createMainService(int32 site, int32 type) -> BaseSampleWebService*
{
    switch (type) {
        case ProductIdentifier::SAMPLE_TYPE_STANDARD_SERVICE:
            return new StandardSampleWebService();
        default:
            break;
    }
    return NULL;
}

auto SampleWebService::createProductIdentifier() -> D1ProductIdentifier*
{
    return new ProductIdentifier();
}
