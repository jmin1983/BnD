//
// StandardSWSRepository.h
//
// Library: SWSStandard
// Package: SWSStandard
// Module:  SWSStandard
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSSTANDARD_STANDARD_SWS_REPOSITORY_H
#define _SWSSTANDARD_STANDARD_SWS_REPOSITORY_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Base/B1Singleton.h>

namespace BnD {
    class StandardSWSRepository : public B1Singleton<StandardSWSRepository> {
    public:
        StandardSWSRepository();
        virtual ~StandardSWSRepository();
    public:
        bool initialize();
        void finalize();
    };
}   //  !BnD

#endif  // !_SWSSTANDARD_STANDARD_SWS_REPOSITORY_H
