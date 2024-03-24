//
// SampleWebServer.h
//
// Library: SWSBase
// Package: SWSBase
// Module:  SWSBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSBASE_SAMPLE_WEB_SERVER_H
#define _SWSBASE_SAMPLE_WEB_SERVER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Http/B1HttpServer.h>

namespace BnD {
    class SampleWebServer : public B1HttpServer {
    public:
        SampleWebServer();
        virtual ~SampleWebServer();
    public:
        enum CONSTS {
            CONSTS_DEFAULT_PORT = 22001,
        };
    protected:
        virtual B1WebSocketServerSession* createWebSocketServerSession(B1ServerSocket* serverSocket) override;
    };
}   //  !BnD

#endif  // !_SWSBASE_SAMPLE_WEB_SERVER_H
