//
// SampleMessageAnalyzer.cpp
//
// Library: SampleMessage
// Package: SampleMessage
// Module:  SampleMessage
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleMessage.h"
#include "SampleMessageAnalyzer.h"
#include "SampleMessageAnalyzerListener.h"

#include "SampleMsgInitializeReq.h"

using namespace BnD;

#undef MAKE_MSG_ENUM

SampleMessageAnalyzer::SampleMessageAnalyzer()
    : D1MessageAnalyzer()
{
}

SampleMessageAnalyzer::~SampleMessageAnalyzer()
{
}

bool SampleMessageAnalyzer::implInitialize()
{
    if (_listener && dynamic_cast<SampleMessageAnalyzerListener*>(_listener) == NULL) {
        assert(false);
        return false;
    }
    if (D1MessageAnalyzer::implInitialize() != true) {
        return false;
    }
#define INSERT_TABLE_VALUE(c) table->insert(std::make_pair(c::messageString().copy(), MAKE_DIAACA_MSG_ENUM(c)));
    std::map<B1String, int32>* table = &_messageTable;
    INSERT_TABLE_VALUE(SampleMsgInitializeReq);

    if (_messageTable.size() != MSG_COUNTS + DIAACA_MSG_COUNTS - DIAACA_MSG_BEGIN - 1) {
        assert(false);
        return false;
    }
    return true;
}

auto SampleMessageAnalyzer::implAnalyzeMessage(D1MessageAnalyzerListener* listener, int32 message, const D1BaseMessage& baseMessage, const B1Archive& archive, int32 from) const -> MESSAGE_RESULT
{
    const auto result = D1MessageAnalyzer::implAnalyzeMessage(listener, message, baseMessage, archive, from);
    if (MESSAGE_IGNORED != result) {
        return result;
    }

    SampleMessageAnalyzerListener* ohtListener =
#if defined(_DEBUG)
        dynamic_cast<SampleMessageAnalyzerListener*>(listener);
    if (NULL == ohtListener) {
        assert(false);
        return result;
    }
#else
        static_cast<SampleMessageAnalyzerListener*>(listener);
#endif
#define NOTIFY_LISTENER(c)\
    case MAKE_DIAACA_MSG_ENUM(c): {\
        c m(std::move(const_cast<D1BaseMessage&>(baseMessage)));\
        archive.toObject(&m);\
        return ohtListener->onMessage##c(m, from) ? MESSAGE_COMPLETE : MESSAGE_INCOMPLETE;\
    }

    switch (message) {
        NOTIFY_LISTENER(SampleMsgInitializeReq);
        default:
            break;
    }
    assert(false);
    return MESSAGE_IGNORED;
}
