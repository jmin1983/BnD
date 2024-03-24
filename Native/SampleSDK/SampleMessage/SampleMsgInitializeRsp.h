//
// SampleMsgInitializeRsp.h
//
// Library: SampleMessage
// Package: Sample
// Module:  SampleMessage
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_MESSAGE_SAMPLE_MSG_INITIALIZE_RSP_H
#define _SAMPLE_SDK_MESSAGE_SAMPLE_MSG_INITIALIZE_RSP_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <D1Message/D1BaseMessage.h>

namespace BnD {
    class SampleMsgInitializeRsp : public D1BaseMessage {
    public:
        SampleMsgInitializeRsp();
        SampleMsgInitializeRsp(D1BaseMessage&& baseMessage);
        virtual ~SampleMsgInitializeRsp();
    protected:
        DataInt32 _result;
        DataInt32 _sessionUsage;
        DataInt32 _sessionID;
        DataString _sessionKey;
    protected:
        void archiveMessage(B1Archive* archive) const final;
        void unarchiveMessage(const B1Archive& archive) final;
    public:
        B1String toString() const final;
    public:
        int32 result() const { return _result.second; }
        int32 sessionUsage() const { return _sessionUsage.second; }
        int32 sessionID() const { return _sessionID.second; }
        const B1String& sessionKey() const { return _sessionKey.second; }

        void setResult(int32 result) { _result.second = result; }
        void setSessionUsage(int32 usage) { _sessionUsage.second = usage; }
        void setSessionID(int32 id) { _sessionID.second = id; }
        void setSessionKey(B1String&& key) { _sessionKey.second = std::move(key); }
    public:
        static const B1String& messageString()
        {
            static B1String s_messageString("SampleMsgInitializeRsp");
            return s_messageString;
        }
    };
}   //  !BnD

#endif // _SAMPLE_SDK_MESSAGE_SAMPLE_MSG_INITIALIZE_RSP_H
