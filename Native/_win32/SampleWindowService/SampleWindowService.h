//
// SampleWindowService.h
//
// Library: SampleWindowService
// Package: SampleWindowService
// Module:  SampleWindowService
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_WINDOW_SERVICE_H
#define _SAMPLE_WINDOW_SERVICE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Base/B1MainServiceInterface.h>
#include <B1Util/B1WindowService.h>

namespace BnD {
    class SampleWebService;
    class SampleWindowService : public B1MainServiceInterface
                              , public B1WindowService {
    public:
        SampleWindowService();
    protected:
        std::shared_ptr<SampleWebService> _service;
    protected:
        bool start() final;
        void wait() final;
        void stop() final;
        bool isStopped() const final;
    public:
        bool startService();
        B1String toString() const;
    };
}   //  !BnD

#endif  // !_SAMPLE_WINDOW_SERVICE_H
