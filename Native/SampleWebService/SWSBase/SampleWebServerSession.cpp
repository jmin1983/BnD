//
// SampleWebServerSession.cpp
//
// Library: SWSBase
// Package: SWSBase
// Module:  SWSBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SWSBase.h"
#include "SampleWebServerSession.h"
#include "BaseSampleWebService.h"

#include <B1Base/B1Time.h>

#include <SampleMessage/SampleMessageAnalyzer.h>
#include <SampleMessage/SampleMsgInitializeReq.h>
#include <SampleMessage/SampleMsgInitializeRsp.h>

#include <iterator>

using namespace BnD;

SampleWebServerSession::SampleWebServerSession(B1ServerSocket* serverSocket, B1BaseServerSessionListener* listener)
    : B1WebSocketServerSession(serverSocket, listener)
{
}

SampleWebServerSession::~SampleWebServerSession()
{
}

bool SampleWebServerSession::onMessageSampleMsgInitializeReq(const SampleMsgInitializeReq& data, int32 from)
{
    SampleMsgInitializeRsp rsp;
    rsp.setSessionID(111);
    rsp.setSessionKey("abcde");
    writeMessage(rsp);
    return true;
}

void SampleWebServerSession::onWebSocketAccepted()
{
    B1LOG("web socket accepted: peerAddress[%s], localPort[%d]", peerAddress().cString(), localPort());
}

bool SampleWebServerSession::onWebSocketReadComplete(B1String&& text)
{
    BaseSampleWebService::get()->messageAnalyzer()->analyzeMessage(this, text, 0);
    return true;
}

bool SampleWebServerSession::writeMessage(const D1BaseMessage& message) const
{
    B1String json;
    if (message.composeToJson(&json) != true) {
        return false;
    }
    writeText(std::move(json));
    return true;
}
