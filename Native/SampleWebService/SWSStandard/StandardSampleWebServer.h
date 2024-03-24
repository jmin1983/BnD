//
// StandardSampleWebServer.h
//
// Library: SWSStandard
// Package: SWSStandard
// Module:  SWSStandard
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVER_H
#define _SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <SampleWebServer.h>

namespace BnD {
    class StandardSampleWebServer : public SampleWebServer {
    public:
        StandardSampleWebServer();
    protected:
        B1WebSocketServerSession* createWebSocketServerSession(B1ServerSocket* serverSocket) final;
    };
}   //  !BnD

#endif  // !_SWSSTANDARD_STANDARD_SAMPLE_WEB_SERVER_H
