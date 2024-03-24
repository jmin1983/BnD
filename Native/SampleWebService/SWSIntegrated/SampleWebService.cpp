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

using namespace BnD;

BaseSampleWebService* SampleWebService::createMainService(D1ProductIdentifier::SITE site, D1ProductIdentifier::TYPE type)
{
    switch (type) {
        case D1ProductIdentifier::TYPE_STANDARD_SERVICE:
            return new StandardSampleWebService();
        default:
            break;
    }
    return NULL;
}
