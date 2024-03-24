//
// SWSMainTabCtrlWnd.cpp
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "SWSMainTabCtrlWnd.h"
#include "MainTabCtrlPageDev.h"
#include "SWSMainTabCtrlPageStartStop.h"

using namespace BnD;

std::shared_ptr<BaseMFCMainTabCtrlPageStartStop> SWSMainTabCtrlWnd::createStartStopPage()
{
    return std::make_shared<SWSMainTabCtrlPageStartStop>(_owner);
}

std::list<std::pair <B1String, std::shared_ptr<TabCtrlPage> > > SWSMainTabCtrlWnd::createPages()
{
    auto pages = BaseMFCTabCtrlWnd::createPages();
    pages.push_back(std::make_pair("Dev", std::make_shared<MainTabCtrlPageDev>(_owner)));
    return pages;
}
