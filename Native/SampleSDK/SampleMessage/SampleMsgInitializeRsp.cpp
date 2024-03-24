//
// SampleMsgInitializeRsp.cpp
//
// Library: SampleMessage
// Package: Sample
// Module:  SampleMessage
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleMessage.h"
#include "SampleMsgInitializeRsp.h"

using namespace BnD;

SampleMsgInitializeRsp::SampleMsgInitializeRsp()
    : D1BaseMessage()
    , _result("Result", -1)
    , _sessionUsage("SessionUsage", 0)
    , _sessionID("SessionID", -1)
    , _sessionKey("SessionKey", "")
{
    _messageID.second = messageString().copy();
}

SampleMsgInitializeRsp::SampleMsgInitializeRsp(D1BaseMessage&& baseMessage)
    : D1BaseMessage(std::move(baseMessage))
    , _result("Result", -1)
    , _sessionUsage("SessionUsage", 0)
    , _sessionID("SessionID", -1)
    , _sessionKey("SessionKey", "")
{
}

SampleMsgInitializeRsp::~SampleMsgInitializeRsp()
{
}

void SampleMsgInitializeRsp::archiveMessage(B1Archive* archive) const
{
    writeDataToArchive(_result, archive);
    writeDataToArchive(_sessionUsage, archive);
    writeDataToArchive(_sessionID, archive);
    writeDataToArchive(_sessionKey, archive);
}

void SampleMsgInitializeRsp::unarchiveMessage(const B1Archive& archive)
{
    readDataFromArchive(archive, &_result);
    readDataFromArchive(archive, &_sessionUsage);
    readDataFromArchive(archive, &_sessionID);
    readDataFromArchive(archive, &_sessionKey);
}

B1String SampleMsgInitializeRsp::toString() const
{
    B1String str = D1BaseMessage::toString();
    str.appendf(", result[%d]", result());
    str.appendf(", sessionUsage[%d]", sessionUsage());
    str.appendf(", sessionID[%d]", sessionID());
    str.appendf(", sessionKey[%s]", sessionKey().cString());
    return str;
}
