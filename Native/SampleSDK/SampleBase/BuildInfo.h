//
// BuildInfo.h
//
// Library: SampleBase
// Package: SampleBase
// Module:  SampleBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_BASE_BUILD_INFO_H
#define _SAMPLE_SDK_BASE_BUILD_INFO_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Base/B1String.h>

namespace BnD {
    const static B1String g_buildDate("20240228");
    enum VERSION_SWS {
        VERSION_SWS_1_0_0_0 = 1000,

        VERSION_SWS_LATEST = VERSION_SWS_1_0_0_0,
    };
}   //  !BnD

#endif  // !_SAMPLE_SDK_BASE_BUILD_INFO_H
