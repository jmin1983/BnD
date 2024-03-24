//
// BaseMFCMainTabCtrlPageStartStop.cpp
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "BaseMFCMainTabCtrlPageStartStop.h"
#include "BaseMFCDlg.h"

#include <D1Base/D1ProductIdentifier.h>

using namespace BnD;

BaseMFCMainTabCtrlPageStartStop::BaseMFCMainTabCtrlPageStartStop(int32 idd, CWnd* owner)
    : TabCtrlPage(idd, owner)
    , _captionSrc()
{
}

BOOL BaseMFCMainTabCtrlPageStartStop::OnInitDialog()
{
    auto result = TabCtrlPage::OnInitDialog();
    EnableDynamicLayout();
    _owner->GetWindowTextA(_captionSrc);
    _owner->SetWindowTextA(_captionSrc + "(NOT RUNNING)");
    return result;
}

BEGIN_MESSAGE_MAP(BaseMFCMainTabCtrlPageStartStop, TabCtrlPage)
    ON_MESSAGE(USER_MESSAGES_ON_BASE_MFC_STOPPED, onMFCServiceStopped)
END_MESSAGE_MAP()

LRESULT BaseMFCMainTabCtrlPageStartStop::onMFCServiceStopped(WPARAM wParam, LPARAM lPraram)
{
    setProgramStopped();
    implOnUIMFCServiceStopped();
    return TRUE;
}

void BaseMFCMainTabCtrlPageStartStop::onMFCServiceStarted()
{
    _owner->PostMessage(BaseMFCDlg::USER_MESSAGE_RELOAD_PAGES);
}

void BaseMFCMainTabCtrlPageStartStop::onMFCServiceStopped()
{
    PostMessage(USER_MESSAGES_ON_BASE_MFC_STOPPED);
}

void BaseMFCMainTabCtrlPageStartStop::setProgramRunning(int32 idAddress, int32 idPort, int32 idDb, int32 idController)
{
    {
        auto idStart = resourceIDStartButton();
        auto idStop = resourceIDStopButton();
        if (idStart > 0 && idStop > 0) {
            GetDlgItem(idStart)->EnableWindow(FALSE);
            GetDlgItem(idStop)->EnableWindow(TRUE);
        }
    }
    CString caption(_captionSrc);
    {
        CString redisAddress;
        GetDlgItemText(idAddress, redisAddress);
        int32 redisPort = GetDlgItemInt(idPort);
        int32 redisDB = GetDlgItemInt(idDb);
        if (idController > 0) {
            CString dcsID;
            GetDlgItemText(idController, dcsID);
            caption.AppendFormat("(%s:%d(%d)_%s)", redisAddress.GetString(), redisPort, redisDB, dcsID.GetString());
        }
        else {
            caption.AppendFormat("(%s:%d(%d))", redisAddress.GetString(), redisPort, redisDB);
        }
    }
    _owner->SetWindowText(caption);
}

void BaseMFCMainTabCtrlPageStartStop::setProgramStopped()
{
    _owner->SetWindowTextA(_captionSrc + "(NOT RUNNING)");
    auto idStart = resourceIDStartButton();
    auto idStop = resourceIDStopButton();
    if (idStart > 0 && idStop > 0) {
        GetDlgItem(idStart)->EnableWindow(TRUE);
        GetDlgItem(idStop)->EnableWindow(FALSE);
    }
}

void BaseMFCMainTabCtrlPageStartStop::setCaptionTypeAndSite(D1RedisClientInterface* redisReader)
{
    auto site = D1ProductIdentifier::getProductSite(redisReader);
    auto eqType = D1ProductIdentifier::getProductType(redisReader);
    CString caption;
    _owner->GetWindowTextA(caption);
    _owner->SetWindowTextA(caption + " (type:" + D1ProductIdentifier::toProductTypeString(eqType).cString() +
                                     ", site:" + D1ProductIdentifier::toProductSiteString(site).cString() + ")");
}
