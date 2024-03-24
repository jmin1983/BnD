//
// TabCtrlWnd.cpp
//
// Library: GeneralUI
// Package: GeneralUI
// Module:  GeneralUI
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "TabCtrlWnd.h"
#include "TabCtrlPage.h"
#include "WindowsHelper.h"

#include <algorithm>

using namespace BnD;

TabCtrlWnd::TabCtrlWnd()
    : CWnd()
    , _owner(NULL)
    , _tab()
    , _tabRect()
    , _pages()
{
}

BEGIN_MESSAGE_MAP(TabCtrlWnd, CWnd)
    ON_WM_CREATE()
    ON_WM_CTLCOLOR()
    ON_WM_ERASEBKGND()
    ON_WM_SIZE()
    ON_NOTIFY(TCN_SELCHANGE, CONSTS_TAB_ID, onTabSelectChange)
END_MESSAGE_MAP()

int TabCtrlWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    int32 result = CWnd::OnCreate(lpCreateStruct);
    if (result != 0) {
        return result;
    }

    _tabRect = onCreateTab();

    if (_tab.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | TCS_HOTTRACK | TCS_FOCUSNEVER, _tabRect, this, CONSTS_TAB_ID)) {
        if (WindowsHelper::isValid(_owner)) {
            _tab.SetFont(_owner->GetFont());
        }
        _tab.SetItemSize(CSize(10, _tabRect.Height()));
    }
    else {
        assert(!"failed to create property tab");
        return -1;
    }
    onCreated();
    return 0;
}

HBRUSH TabCtrlWnd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);

    //if (pWnd->GetDlgCtrlID() == CONSTS_TAB_ID) {
    //    hbr = (HBRUSH)_backBrush.GetSafeHandle();
    //}

    return hbr;
}

BOOL TabCtrlWnd::OnEraseBkgnd(CDC* pDC)
{
    return CWnd::OnEraseBkgnd(pDC);

    //CRect rect;
    //GetClientRect(rect);
    //pDC->FillSolidRect(rect, _backColor);
    //return TRUE;
}

void TabCtrlWnd::onTabSelectChange(NMHDR* pNMHDR, LRESULT* pResult)
{
    showPage(_tab.GetCurSel());
    *pResult = 0;
}

void TabCtrlWnd::OnSize(UINT nType, int cx, int cy)
{
    CRect rect = onAddPage();
    CRect tabRect;
    this->GetWindowRect(tabRect);
    _tab.MoveWindow(0, 0, tabRect.Width(), tabRect.Height());
    std::for_each(_pages.begin(), _pages.end(), [this, rect, &tabRect](std::pair<int32, std::shared_ptr<TabCtrlPage> > page) {
        tabRect.MoveToXY(rect.left, rect.top);
        page.second->MoveWindow(tabRect);
    });
}

CRect TabCtrlWnd::onCreateTab()
{
    CRect rect;
    GetClientRect(rect);
    rect.bottom = CONSTS_TAB_ITEM_SIZE;
    return rect;
}

CRect TabCtrlWnd::onAddPage()
{
    CRect rect;
    GetClientRect(rect);
    return CRect(_tabRect.left, _tabRect.bottom, _tabRect.right, rect.Height());
}

void TabCtrlWnd::showPage(int32 index)
{
    for (const auto& pagePair : _pages) {
        if (WindowsHelper::isValid(pagePair.second.get())) {
            pagePair.second->ShowWindow(pagePair.first == index ? SW_SHOW : SW_HIDE);
            CRect rect; 
        }
    }
}

bool TabCtrlWnd::create(uint32 id, const CRect& rect, CWnd* parent, CWnd* owner)
{
    assert(owner != NULL);
    _owner = owner;
    bool created = WindowsHelper::makeChildWindow("_tab_ctrl_wnd_class", "", this, parent,
        WS_VISIBLE | WS_BORDER | /*WS_HSCROLL | WS_VSCROLL |*/ WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, rect, id, true);
    if (created != true) {
        assert(!"failed to create property_tab_ctrl window");
    }
    return created;
}

void TabCtrlWnd::addPage(std::shared_ptr<TabCtrlPage> page, const B1String& string, bool fitToParent, bool show)
{
    if (WindowsHelper::isValid(*page) != true) {
        assert(false);
        return;
    }
    int32 index = static_cast<int32>(_pages.size());
    _pages[index] = page;
    CString nstring;
    nstring.Format(_T("  %s  "), string.cString());
    _tab.InsertItem(index, nstring);
    CRect rect = onAddPage();
    if (fitToParent) {
        page->MoveWindow(rect);
    }
    else {
        CRect pageRect;
        page->GetWindowRect(pageRect);
        ScreenToClient(pageRect);
        pageRect.MoveToXY(rect.left, rect.top);
        page->MoveWindow(pageRect);
    }
    page->ShowWindow(show ? SW_SHOW : SW_HIDE);
}

TabCtrlPage* TabCtrlWnd::getCurrentPage() const
{
    int32 index = _tab.GetCurSel();
    auto itr = _pages.find(index);
    return itr != _pages.end() ? itr->second.get() : NULL;
}

bool TabCtrlWnd::setCurrentPage(TabCtrlPage* page)
{
    for (const auto& pagePair : _pages) {
        if (pagePair.second.get() == page) {
            _tab.SetCurSel(pagePair.first);
            showPage(pagePair.first);
            return true;
        }
    }
    return false;
}

void TabCtrlWnd::reloadPages()
{
    for (const auto& pagePair : _pages) {
        if (pagePair.second->reload() != true) {
            AfxMessageBox("reload page failed");
        }
    }
}

void TabCtrlWnd::unloadPages()
{
    for (const auto& pagePair : _pages) {
        pagePair.second->unload();
    }
}

void TabCtrlWnd::enablePages(bool enable)
{
    for (const auto& pagePair : _pages) {
        pagePair.second->enableControls(enable);
    }
}

void TabCtrlWnd::showDefaultPage()
{
    for (auto itr = _pages.cbegin(); itr != _pages.cend(); ++itr) {
        itr->second->ShowWindow(itr == _pages.begin() ? SW_SHOW : SW_HIDE);
    }
}
