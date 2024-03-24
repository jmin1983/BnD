//
// StandardSampleWebServerSession.h
//
// Library: SWSStandard
// Package: SWSStandard
// Module:  SWSStandard
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVER_SESSION_H
#define _SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVER_SESSION_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <SampleWebServerSession.h>

namespace BnD {
    class StandardSampleWebServerSession : public SampleWebServerSession {
    public:
        StandardSampleWebServerSession(B1ServerSocket* serverSocket, B1BaseServerSessionListener* listener);
    };
}   //  !BnD

#endif  // !_SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVER_SESSION_H
