//
// BaseMFCTabCtrlWnd.h
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <TabCtrlWnd.h>

#include <list>

namespace BnD {
    class BaseMFCMainTabCtrlPageStartStop;
    class BaseMFCTabCtrlWnd : public TabCtrlWnd {
    public:
        BaseMFCTabCtrlWnd();
    protected:
        virtual std::shared_ptr<BaseMFCMainTabCtrlPageStartStop> createStartStopPage() = 0;
        virtual std::list<std::pair <B1String, std::shared_ptr<TabCtrlPage> > > createPages();
    protected:
        void addPage(std::shared_ptr<TabCtrlPage> page, const B1String& string);
    protected:
        void onCreated() final;
    };
}
