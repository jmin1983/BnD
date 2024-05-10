//
// SWSMainTabCtrlPageStartStop.cpp
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "SWSMainTabCtrlPageStartStop.h"
#include "SWSMainThread.h"
#include "SWSMFCDlg.h"

#include <SampleBase/ProductIdentifier.h>

using namespace BnD;

SWSMainTabCtrlPageStartStop::SWSMainTabCtrlPageStartStop(CWnd* owner)
    : BaseMFCMainTabCtrlPageStartStop(IDD, owner)
    , _config()
{
}

BOOL SWSMainTabCtrlPageStartStop::OnInitDialog()
{
    auto result = BaseMFCMainTabCtrlPageStartStop::OnInitDialog();

    loadConfig(_config.configFilePath());
    GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);
    return result;
}

BEGIN_MESSAGE_MAP(SWSMainTabCtrlPageStartStop, BaseMFCMainTabCtrlPageStartStop)
    ON_MESSAGE(USER_MESSAGES_ON_BASE_MFC_STOPPED, onMFCServiceStopped)
    ON_BN_CLICKED(IDC_BTN_START, onBnClickedBtnStart)
    ON_BN_CLICKED(IDC_BTN_STOP, onBnClickedBtnStop)
    ON_BN_CLICKED(IDC_BTN_SAVE_CONFIG, onBnClickedBtnSaveConfig)
    ON_BN_CLICKED(IDC_BTN_LOAD_CONFIG, onBnClickedBtnLoadConfig)
END_MESSAGE_MAP()

void SWSMainTabCtrlPageStartStop::onBnClickedBtnStart()
{
    if (saveConfig(_config.configFilePath()) != true) {
        return;
    }
    setProgramRunning(IDC_EDIT_ADMIN_ADDRESS, IDC_EDIT_ADMIN_PORT, IDC_EDIT_ADMIN_DB);
    if (SWSMainThread::get()->start("sws", this) != true) {
        setProgramStopped();
        AfxMessageBox("Unable to start WebAssistantService");
        return;
    }
}

void SWSMainTabCtrlPageStartStop::onBnClickedBtnStop()
{
    GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);
    _owner->SetWindowText(_captionSrc + "(STOPPING)");
    _owner->PostMessage(SWSMFCDlg::USER_MESSAGE_DISABLE_PAGES);
    SWSMainThread::get()->requestStop();
}

void SWSMainTabCtrlPageStartStop::onBnClickedBtnSaveConfig()
{
    char fileter[] = "Config File(*.json)|*.json|";
    CFileDialog dlg(FALSE, ".json", "", OFN_HIDEREADONLY, fileter);
    dlg.m_ofn.lpstrInitialDir = _config.configFilePath().cString();
    if (IDOK == dlg.DoModal() ) {
        saveConfig(B1String::formatAs("%s\\%s", dlg.GetFolderPath(), dlg.GetFileName()));
    }
}

void SWSMainTabCtrlPageStartStop::onBnClickedBtnLoadConfig()
{
    char fileter[] = "Config File(*.json)|*.json|";
    CFileDialog dlg(TRUE, ".json", "", OFN_HIDEREADONLY, fileter);
    dlg.m_ofn.lpstrInitialDir = _config.configFilePath().cString();
    if (IDOK == dlg.DoModal()) {
        loadConfig(B1String::formatAs("%s\\%s", dlg.GetFolderPath(), dlg.GetFileName()));
    }
}

bool SWSMainTabCtrlPageStartStop::implReloadPage()
{
    ProductIdentifier productIdentifier;
    productIdentifier.getProductInfo(SWSMainThread::get()->mainService()->redisClientInterface());
    setCaptionTypeAndSite(productIdentifier);
    return true;
}

void SWSMainTabCtrlPageStartStop::implUnloadPage()
{
    SWSMainThread::get()->stopNow();
}

void SWSMainTabCtrlPageStartStop::implOnUIMFCServiceStopped()
{
    SWSMainThread::get()->checkStopped();
}

bool SWSMainTabCtrlPageStartStop::saveConfig(const B1String& path)
{
    CString adminAddress;
    GetDlgItemText(IDC_EDIT_ADMIN_ADDRESS, adminAddress);
    int32 adminPort = GetDlgItemInt(IDC_EDIT_ADMIN_PORT);
    int32 adminDB = GetDlgItemInt(IDC_EDIT_ADMIN_DB);

    if (adminAddress.IsEmpty()) {
        MessageBox("ADMIN address is empty", "ERROR", MB_ICONERROR);
        return false;
    }

    if (adminPort < 1 || adminPort > 65535) {
        MessageBox("ADMIN Port is invalid", "ERROR", MB_ICONERROR);
        return false;
    }
    if (adminDB < 0 || adminDB > 15) {
        MessageBox("ADMIN DB is invalid", "ERROR", MB_ICONERROR);
        return false;
    }

    _config.setAdminAddress(adminAddress.GetString());
    _config.setAdminPort(adminPort);
    _config.setAdminDB(adminDB);
    if (_config.save(path) != true) {
        MessageBox("ERROR", "Save config file failed", MB_ICONERROR);
        return false;
    }
    return true;
}

bool SWSMainTabCtrlPageStartStop::loadConfig(const B1String& path)
{
    // load config.
    if (_config.load(path) != true) {
        B1LOG("no config file found");
    }
    SetDlgItemText(IDC_EDIT_ADMIN_ADDRESS, _config.adminAddress().cString());
    SetDlgItemInt(IDC_EDIT_ADMIN_PORT, _config.adminPort());
    SetDlgItemInt(IDC_EDIT_ADMIN_DB, _config.adminDB());
    return true;
}
