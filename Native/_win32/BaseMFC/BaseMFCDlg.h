//
// BaseMFCDlg.h
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

namespace BnD {
    class BaseMFCTabCtrlWnd;
    class BaseMFCDlg : public CDialogEx {
    public:
        BaseMFCDlg(UINT idTemplate, HICON icon, CWnd* parent = nullptr);
    protected:
        enum CONSTS {
            CONSTS_MAIN_TAB_ID = 10001,
        };
    public:
        enum USER_MESSAGE {
            USER_MESSAGE_LOG_CALLBACK = WM_USER + 5,
            USER_MESSAGE_RELOAD_PAGES,
            USER_MESSAGE_DISABLE_PAGES,
        };
    protected:
        HICON _hIcon;
        CListBox _logList;
        std::shared_ptr<BaseMFCTabCtrlWnd> _mainTab;
    protected:
        virtual int32 mainLogCtrlID() = 0;
        virtual int32 mainDlgClientRectCtrlID() = 0;
        virtual BaseMFCTabCtrlWnd* createMainTabCtrlWnd() = 0;
    protected:
        virtual BOOL PreTranslateMessage(MSG* pMsg);
        virtual void DoDataExchange(CDataExchange* pDX);
        virtual BOOL OnInitDialog();
        virtual void OnCancel();
    protected:
        DECLARE_MESSAGE_MAP()
        afx_msg void OnPaint();
        afx_msg HCURSOR OnQueryDragIcon();
        afx_msg LRESULT onLogMessage(WPARAM wParam, LPARAM lPraram);
        afx_msg LRESULT onReloadPages(WPARAM wParam, LPARAM lPraram);
        afx_msg LRESULT onDisablePages(WPARAM wParam, LPARAM lPraram);
    protected:
        void copyToClipBoard();
    protected:
        static bool writeLogCallback(const char* log, void* param);
    };

}
