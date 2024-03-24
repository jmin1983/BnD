//
// SWSMFCDlg.cpp
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "SWSMFCDlg.h"
#include "SWSMainTabCtrlWnd.h"
#include "SWSMainThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace BnD;

SWSMFCDlg::SWSMFCDlg(CWnd* parent)
    : BaseMFCDlg(IDD_MFC_DIALOG, AfxGetApp()->LoadIcon(IDR_MAINFRAME), parent)
    , _wasMainThread()
{
}

BaseMFCTabCtrlWnd* SWSMFCDlg::createMainTabCtrlWnd()
{
    auto mainTab = new SWSMainTabCtrlWnd();
    _wasMainThread.reset(new SWSMainThread(mainTab));
    return mainTab;
}
