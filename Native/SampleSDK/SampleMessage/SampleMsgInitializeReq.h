//
// SampleMsgInitializeReq.h
//
// Library: SampleMessage
// Package: Sample
// Module:  SampleMessage
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_MESSAGE_SAMPLE_MSG_INITIALIZE_REQ_H
#define _SAMPLE_SDK_MESSAGE_SAMPLE_MSG_INITIALIZE_REQ_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <D1Message/D1BaseMessage.h>

namespace BnD {
    class SampleMsgInitializeReq : public D1BaseMessage {
    public:
        SampleMsgInitializeReq();
        SampleMsgInitializeReq(D1BaseMessage&& baseMessage);
        virtual ~SampleMsgInitializeReq();
    protected:
        DataInt32 _clientType;
    protected:
        void archiveMessage(B1Archive* archive) const final;
        void unarchiveMessage(const B1Archive& archive) final;
    public:
        B1String toString() const final;
    public:
        int32 clientType() const { return _clientType.second; }

        void setClientType(int32 type) { _clientType.second = type; }
    public:
        static const B1String& messageString()
        {
            static B1String s_messageString("SampleMsgInitializeReq");
            return s_messageString;
        }
    };
}   //  !BnD

#endif // _SAMPLE_SDK_MESSAGE_SAMPLE_MSG_INITIALIZE_REQ_H
