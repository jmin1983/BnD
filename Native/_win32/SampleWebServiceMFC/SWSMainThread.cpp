//
// SWSMainThread.cpp
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "SWSMainThread.h"

#include <D1Data/D1ConfFileReader.h>

using namespace BnD;

SWSMainThread::SWSMainThread(const BaseMFCTabCtrlWnd* mainTab)
    : BaseMFCMainThreadWrapper(mainTab)
{
}

std::shared_ptr<D1ConfFileReader> SWSMainThread::implInit()
{
    auto config = std::make_shared<D1ConfFileReader>();
    config->loadDefault();
    return config;
}
