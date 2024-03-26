//
// SWSMainThread.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <BaseMFCMainThread.h>

#include "SampleWebServiceMFC.h"

namespace BnD {
    class BaseMFCTabCtrlWnd;
    class SWSMainThread : public BaseMFCMainThreadWrapper<SampleWebServiceMFC, SWSMainThread> {
    public:
        SWSMainThread(const BaseMFCTabCtrlWnd* mainTab);
    protected:
        std::shared_ptr<D1ConfFileReader> implInit() final;
    };
}   //  !BnD
