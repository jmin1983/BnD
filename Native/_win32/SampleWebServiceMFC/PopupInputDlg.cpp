//
// PopupInputDlg.cpp
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "PopupInputDlg.h"

using namespace BnD;

PopupInputDlg::PopupInputDlg(CWnd* owner, B1String&& initialText, bool readOnly)
    : CDialog(IDD_POPUP_INPUT, owner)
    , _initialText(initialText)
    , _readOnly(readOnly)
{
}

BOOL PopupInputDlg::OnInitDialog()
{
    auto result = CDialog::OnInitDialog();
    if (_initialText.isEmpty() != true) {
        SetDlgItemText(IDC_EDT_INPUT_TEXT, _initialText.cString());
    }
    if (_readOnly) {
        ((CEdit*)GetDlgItem(IDC_EDT_INPUT_TEXT))->SetReadOnly(TRUE);
    }
    return result;
}

void PopupInputDlg::OnOK()
{
    CString temp;
    GetDlgItemText(IDC_EDT_INPUT_TEXT, temp);
    _inputText.from(temp.GetString());
    CDialog::OnOK();
}
