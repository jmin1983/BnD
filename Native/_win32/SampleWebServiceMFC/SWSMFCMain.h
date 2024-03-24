//
// SWSMFCMain.h
//
// Library: SWSMFC
// Package: SWSMFC
// Module:  SWSMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include pch first"
#endif

class was_mfc_main : public CWinApp
{
public:
	was_mfc_main();

public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern was_mfc_main theApp;
