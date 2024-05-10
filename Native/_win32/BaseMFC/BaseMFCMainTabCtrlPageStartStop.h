//
// BaseMFCMainTabCtrlPageStartStop.h
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <BaseMFCMainThread.h>
#include <TabCtrlPage.h>

namespace BnD {
    class D1ProductIdentifier;
};

namespace BnD {
    class BaseMFCMainTabCtrlPageStartStop : public TabCtrlPage
                                          , protected BaseMFCMainThreadListener {
    public:
        BaseMFCMainTabCtrlPageStartStop(int32 idd, CWnd* owner);
    protected:
        enum USER_MESSAGES {
            USER_MESSAGES_ON_BASE_MFC_STOPPED = WM_USER + 1005,
        };
    protected:
        CString _captionSrc;
    protected:
        virtual void implOnUIMFCServiceStopped() {}
        virtual int32 resourceIDStartButton() { return -1; }
        virtual int32 resourceIDStopButton() { return -1; }
    protected:
        virtual BOOL OnInitDialog();
    protected:
        DECLARE_MESSAGE_MAP()
        afx_msg LRESULT onMFCServiceStopped(WPARAM wParam, LPARAM lPraram);
    protected:
        void onMFCServiceStarted() final;
        void onMFCServiceStopped() final;
    protected:
        void setProgramRunning(int32 idAddress, int32 idPort, int32 idDb, int32 idController = -1);
        void setProgramStopped();
        void setCaptionTypeAndSite(const D1ProductIdentifier& productIdentifier);
    };
}
