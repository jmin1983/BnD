//
// TabCtrlPage.cpp
//
// Library: GeneralUI
// Package: GeneralUI
// Module:  GeneralUI
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "TabCtrlPage.h"

using namespace BnD;

TabCtrlPage::TabCtrlPage(int32 idd, CWnd* owner)
    : CDialog()
    , _owner(owner)
    , _idd(idd)
{
}

bool TabCtrlPage::create(CWnd* parent)
{
    return Create(_idd, parent) ? true : false;
}

bool TabCtrlPage::reload()
{
    if (isAvailablePage()) {
        return implReloadPage();
    }
    else {
        return true;
    }
}

void TabCtrlPage::unload()
{
    if (isAvailablePage()) {
        implUnloadPage();
    }
}
