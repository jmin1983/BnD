//
// SWSMainTabCtrlPageStartStop.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <BaseMFCMainTabCtrlPageStartStop.h>

#include <D1Data/D1ConfFileReader.h>

namespace BnD {
    class SWSMainTabCtrlPageStartStop : public BaseMFCMainTabCtrlPageStartStop {
    public:
        SWSMainTabCtrlPageStartStop(CWnd* owner);
    protected:
        enum CONSTS {
            IDD = IDD_MAIN_TAB_PAGE_START_STOP,
        };
    protected:
        D1ConfFileReader _config;
    protected:
        virtual BOOL OnInitDialog();
    protected:
        DECLARE_MESSAGE_MAP()
        afx_msg void onBnClickedBtnStart();
        afx_msg void onBnClickedBtnStop();
        afx_msg void onBnClickedBtnSaveConfig();
        afx_msg void onBnClickedBtnLoadConfig();
    protected:
        bool implReloadPage() final;
        void implUnloadPage() final;
        void implOnUIMFCServiceStopped() final;
        int32 resourceIDStartButton() final { return IDC_BTN_START; }
        int32 resourceIDStopButton() final { return IDC_BTN_STOP; }
    protected:
        bool saveConfig(const B1String& path);
        bool loadConfig(const B1String& path);
    };
}
