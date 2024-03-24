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

#include <D1Base/D1MainServiceWrapper.h>
#include <D1Base/D1ProductIdentifier.h>

#include <BaseSampleWebService.h>

namespace BnD {
    class SampleWebService : public D1MainServiceWrapper<BaseSampleWebService, SampleWebService> {
    protected:
        virtual BaseSampleWebService* createMainService(D1ProductIdentifier::SITE site, D1ProductIdentifier::TYPE type) override;
    };
}   //  !BnD

#endif  // !_SWSINTEGRATED_SAMPLE_WEB_SERVICE_H
