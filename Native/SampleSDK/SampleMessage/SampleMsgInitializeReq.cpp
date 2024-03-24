//
// SampleMsgInitializeReq.cpp
//
// Library: SampleMessage
// Package: Sample
// Module:  SampleMessage
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleMessage.h"
#include "SampleMsgInitializeReq.h"

using namespace BnD;

SampleMsgInitializeReq::SampleMsgInitializeReq()
    : D1BaseMessage()
    , _clientType("ClientType", 0)
{
    _messageID.second = messageString().copy();
}

SampleMsgInitializeReq::SampleMsgInitializeReq(D1BaseMessage&& baseMessage)
    : D1BaseMessage(std::move(baseMessage))
    , _clientType("ClientType", 0)
{
}

SampleMsgInitializeReq::~SampleMsgInitializeReq()
{
}

void SampleMsgInitializeReq::archiveMessage(B1Archive* archive) const
{
    writeDataToArchive(_clientType, archive);
}

void SampleMsgInitializeReq::unarchiveMessage(const B1Archive& archive)
{
    readDataFromArchive(archive, &_clientType);
}

B1String SampleMsgInitializeReq::toString() const
{
    B1String str = D1BaseMessage::toString();
    str.appendf(", clientType[%d]", clientType());
    return str;
}
