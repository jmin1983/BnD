//
// TabCtrlWnd.h
//
// Library: GeneralUI
// Package: GeneralUI
// Module:  GeneralUI
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <map>

namespace BnD {
    class TabCtrlPage;
    class TabCtrlWnd : public CWnd {
    public:
        TabCtrlWnd();
    protected:
        enum CONSTS {
            CONSTS_TAB_ID = 1000,
            CONSTS_TAB_ITEM_SIZE = 24,
        };
    protected:
        CWnd* _owner;
        CTabCtrl _tab;
        CRect _tabRect;
        std::map<int32, std::shared_ptr<TabCtrlPage> > _pages;  //  map<index, page>
    protected:
        DECLARE_MESSAGE_MAP()
        afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
        afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
        afx_msg BOOL OnEraseBkgnd(CDC* pDC);
        afx_msg void onTabSelectChange(NMHDR* pNMHDR, LRESULT* pResult);
        afx_msg void OnSize(UINT nType, int cx, int cy);
    protected:
        virtual CRect onCreateTab();    //  return tab_rect.
        virtual CRect onAddPage();      //  return tab_page_rect
        virtual void onCreated() {}
    protected:
        void showPage(int32 index);
    public:
        bool create(uint32 id, const CRect& rect, CWnd* parent, CWnd* owner);
        void addPage(std::shared_ptr<TabCtrlPage> page, const B1String& string, bool fitToParent = false, bool show = false);
        TabCtrlPage* getCurrentPage() const;
        bool setCurrentPage(TabCtrlPage* page);
        void reloadPages();
        void unloadPages();
        void enablePages(bool enable);
        void showDefaultPage();
        const std::map<int32, std::shared_ptr<TabCtrlPage> >& pages() const { return _pages; }
    };
}
