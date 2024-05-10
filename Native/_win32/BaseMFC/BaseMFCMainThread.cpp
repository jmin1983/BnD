//
// BaseMFCMainThread.cpp
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "BaseMFCMainThread.h"

using namespace BnD;

BaseMFCMainThread::BaseMFCMainThread(const BaseMFCTabCtrlWnd* mainTab)
    : _mainTab(mainTab)
    , _listener(NULL)
{
}

BaseMFCMainThread::~BaseMFCMainThread()
{
}

void BaseMFCMainThread::implThreadBegin()
{
    for (const auto& pagePair : _mainTab->pages()) {
        implInitPage(*pagePair.second.get());
    }
}

void BaseMFCMainThread::implThreadEnd()
{
    _listener = NULL;
}

bool BaseMFCMainThread::start(B1String&& name, BaseMFCMainThreadListener* listener)
{
    if (isAlive()) {
        return false;
    }
    _name = std::move(name);
    _listener = listener;
    return run();
}

void BaseMFCMainThread::checkStopped()
{
    join();
}
