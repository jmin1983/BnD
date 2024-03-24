//
// SWSMFCDlg.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <BaseMFCDlg.h>

namespace BnD {
    class SWSMainThread;
    class SWSMFCDlg : public BaseMFCDlg {
    public:
        SWSMFCDlg(CWnd* pParent = nullptr);
#ifdef AFX_DESIGN_TIME
        enum { IDD = IDD_DCS_MFC_DIALOG };
#endif
    protected:
        std::shared_ptr<SWSMainThread> _wasMainThread;
    protected:
        int32 mainLogCtrlID() final { return IDC_LIST_LOG; }
        int32 mainDlgClientRectCtrlID() final { return IDC_MFC_DIALOG_CLIENT_RECT; }
        BaseMFCTabCtrlWnd* createMainTabCtrlWnd() final;
    };
}
