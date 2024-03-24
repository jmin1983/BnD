//
// BaseMFCDlg.cpp
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "BaseMFCDlg.h"
#include "BaseMFCTabCtrlWnd.h"

#include <boost/scoped_ptr.hpp>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace BnD;

BaseMFCDlg::BaseMFCDlg(UINT idTemplate, HICON icon, CWnd* parent)
    : CDialogEx(idTemplate, parent)
{
    _hIcon = icon;
}

BOOL BaseMFCDlg::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN) {
        BOOL bControlKey = (0x8000 == (0x8000 & GetKeyState(VK_LCONTROL)));
        if (pMsg->wParam == 'C') {
            if (GetFocus()->GetDlgCtrlID() == mainLogCtrlID()) {
                if (bControlKey) {
                    copyToClipBoard();
                }
            }
        }
        else if (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN) {
            return TRUE;
        }
    }
    return CDialogEx::PreTranslateMessage(pMsg);
}

void BaseMFCDlg::DoDataExchange(CDataExchange* pDX)
{
    DDX_Control(pDX, mainLogCtrlID(), _logList);
    CDialogEx::DoDataExchange(pDX);
}

BOOL BaseMFCDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    SetIcon(_hIcon, TRUE);  // set big icon.
    SetIcon(_hIcon, FALSE); // set small icon.

    {
        CRect rect;
        GetDlgItem(mainDlgClientRectCtrlID())->GetWindowRect(rect);
        ScreenToClient(rect);
        _mainTab.reset(createMainTabCtrlWnd());
        _mainTab->create(CONSTS_MAIN_TAB_ID, rect, this, this);
        _mainTab->EnableDynamicLayout();
        auto manager = this->GetDynamicLayout();
        auto moveSetting = CMFCDynamicLayout::MoveNone();
        auto sizeSetting = CMFCDynamicLayout::SizeHorizontal(100);
        manager->AddItem(_mainTab->m_hWnd, moveSetting, sizeSetting);
    }
    setLoggerCallback(writeLogCallback, this);
    return TRUE;    //  return TRUE if do not focus to control.
}

void BaseMFCDlg::OnCancel()
{
    SetWindowTextA("EXITING PROGRAM...");
    _mainTab->unloadPages();
    PostMessage(WM_QUIT);
}

BEGIN_MESSAGE_MAP(BaseMFCDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_MESSAGE(USER_MESSAGE_LOG_CALLBACK, onLogMessage)
    ON_MESSAGE(USER_MESSAGE_RELOAD_PAGES, onReloadPages)
    ON_MESSAGE(USER_MESSAGE_DISABLE_PAGES, onDisablePages)
END_MESSAGE_MAP()

void BaseMFCDlg::OnPaint()
{
    if (IsIconic()) {
        CPaintDC dc(this);

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, _hIcon);
    }
    else {
        CDialogEx::OnPaint();
    }
}

HCURSOR BaseMFCDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(_hIcon);
}

LRESULT BaseMFCDlg::onLogMessage(WPARAM wParam, LPARAM lPraram)
{
    boost::scoped_ptr<CString> message((CString*)lPraram);
    int lineCount = _logList.GetCount();
    if (lineCount > 500) {
        _logList.DeleteString(0);
    }
    _logList.AddString(message->GetString());
    _logList.SetTopIndex(lineCount - 1);
    return 0;
}

LRESULT BaseMFCDlg::onReloadPages(WPARAM wParam, LPARAM lPraram)
{
    _mainTab->reloadPages();
    _mainTab->enablePages(true);
    return TRUE;
}

LRESULT BaseMFCDlg::onDisablePages(WPARAM wParam, LPARAM lPraram)
{
    _mainTab->enablePages(false);
    return TRUE;
}

void BaseMFCDlg::copyToClipBoard()
{
    int selected = _logList.GetSelCount();
    CArray<int, int> items;
    items.SetSize(selected);
    _logList.GetSelItems(selected, items.GetData());
    CString tempString;
    CString fullString;
    CString linefeed = "\n";
    for (int row = 0; row < selected; row++) {
        int sel = items[row];
        _logList.GetText(sel, tempString);
        fullString.Append(tempString);
    }

    int32 strLength = static_cast<int32>((_tcslen(fullString) + 1) * sizeof(TCHAR));
    if (strLength > 0) {
        HGLOBAL hGlobal = GlobalAlloc(GHND | GMEM_SHARE, strLength);
        TCHAR* pGlobal = (TCHAR*)GlobalLock(_Post_ _Notnull_ hGlobal);
        _tcscpy(_Post_ _Notnull_ pGlobal, fullString);
        GlobalUnlock(hGlobal);
        OpenClipboard();
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hGlobal);
        CloseClipboard();
    }
}

bool BaseMFCDlg::writeLogCallback(const char* log, void* param)
{
    ((BaseMFCDlg*)param)->PostMessage(USER_MESSAGE_LOG_CALLBACK, 0, (LPARAM)new CString(log));
    return true;
}
