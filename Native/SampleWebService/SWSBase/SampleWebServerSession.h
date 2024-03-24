//
// SampleWebServerSession.h
//
// Library: SWSBase
// Package: SWSBase
// Module:  SWSBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SWSBASE_SAMPLE_WEB_SERVER_SESSION_H
#define _SWSBASE_SAMPLE_WEB_SERVER_SESSION_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Http/B1WebSocketServerSession.h>

#include <SampleMessage/SampleMessageAnalyzerListener.h>

namespace BnD {
    class SampleWebServerSession : protected SampleMessageAnalyzerListener
                              , public B1WebSocketServerSession {
    public:
        SampleWebServerSession(B1ServerSocket* serverSocket, B1BaseServerSessionListener* listener);
        virtual ~SampleWebServerSession();
    protected:  //  SampleMessageAnalyzerListener
        bool onMessageSampleMsgInitializeReq(const SampleMsgInitializeReq& data, int32 from) final;
    protected:  // B1WebSocketServerSession
        void onWebSocketAccepted() final;
        bool onWebSocketReadComplete(const B1String& text) final;           //  return false if there are no more data to read.
        //bool onWebSocketReadComplete(const std::vector<uint8>& data) final; //  return false if there are no more data to read.
    public:
        bool writeMessage(const class D1BaseMessage& message) const;
    };
}   //  !BnD

#endif  // !_SWSBASE_SAMPLE_WEB_SERVER_SESSION_H
