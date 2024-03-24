//
// WindowsHelper.h
//
// Library: GeneralUI
// Package: GeneralUI
// Module:  GeneralUI
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <B1Base/B1String.h>

#include <Windows.h>

namespace BnD {
    namespace WindowsHelper {
        inline void registerWnd(const B1String& className, uint32 style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW, HINSTANCE instance = NULL)
        {
            assert(className.isEmpty() != true);
            if (instance == NULL) {
#ifdef _AFX
                instance = ::AfxGetInstanceHandle();
#else
                instance = ::GetModuleHandle(NULL);
#endif
            }
            {
                WNDCLASSA temp;
                if (::GetClassInfoA(instance, className.cString(), &temp))
                    return;
            }
            WNDCLASSA wndClass;
            ::ZeroMemory(&wndClass, sizeof(wndClass));
            wndClass.style = style;
            wndClass.lpfnWndProc = ::DefWindowProc;
            wndClass.cbClsExtra = 0;
            wndClass.cbWndExtra = sizeof(LONG_PTR);
            wndClass.hInstance = instance;
            wndClass.hIcon = NULL;
            wndClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
            wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            wndClass.lpszMenuName = NULL;
            wndClass.lpszClassName = className.cString();
            ATOM result = ::RegisterClassA(&wndClass);
            if (0 == result) {
                assert(!"failed to register class for window");
            }
        }
        inline bool isValid(HWND handle)
        {
            return (handle != NULL && ::IsWindow(handle));
        }
        inline bool isValid(HMENU handle)
        {
            return (handle != NULL && ::IsMenu(handle));
        }
#ifdef _AFX
        inline bool isValid(const CWnd* object)
        {
            return (object != NULL && isValid(object->GetSafeHwnd()));
        }
        inline bool isValid(const CMenu* object)
        {
            return (object != NULL && isValid(object->GetSafeHmenu()));
        }
        inline bool makeChildWindow(const B1String& className, const B1String& caption,
                                    CWnd* mine, CWnd* parent, uint32 style = 0, uint32 styleEx = 0,
                                    const CRect& rect = CRect(), uint32 id = 0, bool clipChild = false)
        {
            if (NULL == mine) {
                assert(false);
                return false;
            }
            if (isValid(parent) != true) {
                assert(false);
                return false;
            }
#ifdef _DEBUG
            if (id != 0 &&
                parent->GetDlgItem(id) != NULL) {
                assert(!"invalid control id");
            }
#endif
            registerWnd(className);
            style |= WS_CHILD;
            if (clipChild)
                style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
            if (isValid(mine)) {
                mine->DestroyWindow();
            }
            return (mine->CreateEx(styleEx, CString(className.cString()), CString(caption.cString()), style, rect, parent, id) == TRUE);
        }
#endif
    };
}
