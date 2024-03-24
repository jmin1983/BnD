//
// MainTabCtrlPageDev.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <TabCtrlPage.h>

namespace BnD {
    class MainTabCtrlPageDev : public TabCtrlPage {
    public:
        MainTabCtrlPageDev(CWnd* owner);
    protected:
        DECLARE_MESSAGE_MAP()
        afx_msg void onBnClickedBtnShowSha256Text();
    protected:
        bool implReloadPage() final;
        void implEnableControls(bool enable) final;
    };
}
