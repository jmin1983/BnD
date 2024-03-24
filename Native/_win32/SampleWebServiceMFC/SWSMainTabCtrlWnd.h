//
// SWSMainTabCtrlWnd.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <BaseMFCTabCtrlWnd.h>

namespace BnD {
    class SWSMainTabCtrlWnd : public BaseMFCTabCtrlWnd {
    protected:
        std::shared_ptr<BaseMFCMainTabCtrlPageStartStop> createStartStopPage() final;
        std::list<std::pair <B1String, std::shared_ptr<TabCtrlPage> > > createPages() final;
    };
}
