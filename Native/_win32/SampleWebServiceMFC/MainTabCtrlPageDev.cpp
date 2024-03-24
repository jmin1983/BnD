//
// MainTabCtrlPageDev.cpp
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "MainTabCtrlPageDev.h"
#include "PopupInputDlg.h"

#include <B1Base/B1StringUtil.h>
#include <B1Base/B1SystemUtil.h>
#include <B1Crypto/B1Encryptor.h>

using namespace BnD;

MainTabCtrlPageDev::MainTabCtrlPageDev(CWnd* owner)
    : TabCtrlPage(IDD_MAIN_TAB_PAGE_DEV, owner)
{
}

BEGIN_MESSAGE_MAP(MainTabCtrlPageDev, TabCtrlPage)
    ON_BN_CLICKED(IDC_BTN_SHA256_TEXT, onBnClickedBtnShowSha256Text)
END_MESSAGE_MAP()

void MainTabCtrlPageDev::onBnClickedBtnShowSha256Text()
{
    CString text;
    GetDlgItemText(IDC_EDIT_SHA256_TEXT, text);
    B1String result;
    if (B1Encryptor::encryptSha256(text.GetString(), &result) != true) {
        AfxMessageBox("encrypt failed!");
        return;
    }
    PopupInputDlg dlg(this, std::move(result), true);
    dlg.DoModal();
}

bool MainTabCtrlPageDev::implReloadPage()
{
    return true;
}

void MainTabCtrlPageDev::implEnableControls(bool enable)
{
}
