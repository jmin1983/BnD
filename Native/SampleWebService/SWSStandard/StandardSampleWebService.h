//
// StandardSampleWebService.h
//
// Library: SWSStandard
// Package: SWSStandard
// Module:  SWSStandard
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVICE_H
#define _SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVICE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <BaseSampleWebService.h>

namespace BnD {
    class StandardSampleWebService : public BaseSampleWebService {
    public:
        StandardSampleWebService();
    protected:
        std::shared_ptr<class StandardSWSRepository> _repository;
    protected:
        bool implInitRepositories() final;
        SampleWebServer* createAcadiaServer() final;
        void implMainProcess() final;
        void implFinalizeRepositories() final;
    };
}   //  !BnD

#endif  // !_SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVICE_H
