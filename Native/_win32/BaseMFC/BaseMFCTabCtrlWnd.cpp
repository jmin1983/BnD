//
// BaseMFCTabCtrlWnd.cpp
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "BaseMFCTabCtrlWnd.h"
#include "BaseMFCMainTabCtrlPageStartStop.h"

#include <TabCtrlPage.h>

using namespace BnD;

BaseMFCTabCtrlWnd::BaseMFCTabCtrlWnd()
    : TabCtrlWnd()
{
}

std::list<std::pair <B1String, std::shared_ptr<TabCtrlPage> > > BaseMFCTabCtrlWnd::createPages()
{
    std::list<std::pair <B1String, std::shared_ptr<TabCtrlPage> > > pages;
    pages.push_back(std::make_pair("Start/Stop", createStartStopPage()));
    return pages;
}

void BaseMFCTabCtrlWnd::addPage(std::shared_ptr<TabCtrlPage> page, const B1String& string)
{
    if (page->create(this) != true) {
        assert(false);
    }
    TabCtrlWnd::addPage(page, string, true);
    GetDynamicLayout()->AddItem(page->m_hWnd, CMFCDynamicLayout::MoveNone(), CMFCDynamicLayout::SizeHorizontal(100));
}

void BaseMFCTabCtrlWnd::onCreated()
{
    EnableDynamicLayout();
    GetDynamicLayout()->Create(this);
    auto pages = createPages();
    if (pages.empty()) {
        auto startStopPage = createStartStopPage();
        if (startStopPage != NULL) {
            pages.push_back(std::make_pair("Start/Stop", startStopPage));
        }
    }
    for (const auto& pagePair : pages) {
        addPage(pagePair.second, pagePair.first);
    }
    enablePages(false);
    showDefaultPage();
}
