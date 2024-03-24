//
// PopupInputDlg.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

namespace BnD {
    class PopupInputDlg : public CDialog {
    public:
        PopupInputDlg(CWnd* owner, B1String&& initialText = "", bool readOnly = false);
    protected:
        const B1String _initialText;
        const bool _readOnly;
        B1String _inputText;
    protected:
        BOOL OnInitDialog() final;
        void OnOK() final;
    public:
        const B1String& inputText() const { return _inputText; }
    };
}
