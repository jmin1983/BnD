//
// SWSIntegrated.h
//
// Library: SWSIntegrated
// Package: SWSIntegrated
// Module:  SWSIntegrated
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSINTEGRATED_H
#define _SWSINTEGRATED_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Base/B1Base.h>  //  include first
#include <B1Base/B1String.h>
#include <B1Base/B1Logger.h>

#if defined(_WIN32)
#if defined(_DLL)
#if defined(_DEBUG)
#pragma comment(lib, "libcryptoMDd.lib")
#pragma comment(lib, "libsslMDd.lib")
#else
#pragma comment(lib, "libcryptoMD.lib")
#pragma comment(lib, "libsslMD.lib")
#endif
#else
#pragma comment(lib, "libcryptoMT.lib")
#pragma comment(lib, "libsslMT.lib")
#pragma comment(lib, "crypt32.lib")
#endif
#endif

#endif  // !_SWSINTEGRATED_H
