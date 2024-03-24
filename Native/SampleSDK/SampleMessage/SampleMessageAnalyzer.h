//
// SampleMessageAnalyzer.h
//
// Library: SampleMessage
// Package: SampleMessage
// Module:  SampleMessage
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_MESSAGE_ANALYZER_H
#define _SAMPLE_SDK_MESSAGE_ANALYZER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <D1Message/D1MessageAnalyzer.h>

namespace BnD {
    class SampleMessageAnalyzer : public D1MessageAnalyzer {
    public:
        SampleMessageAnalyzer();
        virtual ~SampleMessageAnalyzer();
    protected:
        //  When adding a new message, need to work on SampleMessageAnalyzerListener::new_function(), enum MSG, initializeTable(), implAnalyzeMessage(). (any better method?)
#define MAKE_DIAACA_MSG_ENUM(c) DIAACA_MSG_##c
        enum DIAACA_MSG {
            DIAACA_MSG_BEGIN = MSG_COUNTS + 1000,

            MAKE_DIAACA_MSG_ENUM(SampleMsgInitializeReq),

            DIAACA_MSG_COUNTS,

            //  When adding a new message, check the comment at the top of enum MSG.
        };
    protected:
        bool implInitialize() final;
        MESSAGE_RESULT implAnalyzeMessage(D1MessageAnalyzerListener* listener, int32 message, const D1BaseMessage& baseMessage, const B1Archive& archive, int32 from) const final;
    };
}   //  !BnD

#endif  // !_SAMPLE_SDK_MESSAGE_ANALYZER_H
