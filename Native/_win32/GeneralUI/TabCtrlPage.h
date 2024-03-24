//
// TabCtrlPage.h
//
// Library: GeneralUI
// Package: GeneralUI
// Module:  GeneralUI
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <ControlOwner.h>

namespace BnD {
    class TabCtrlPage : public CDialog
                      , public ControlOwner {
    public:
        TabCtrlPage(int32 idd, CWnd* owner);
    protected:
        CWnd* _owner;
        int32 _idd;
    protected:
        virtual bool implReloadPage() { return true; }
        virtual void implUnloadPage() {}
    public:
        bool create(CWnd* parent);
        bool reload();
        void unload();
    };
}
