//
// SampleMariaDBClient.cpp
//
// Library: SampleDBClient
// Package: SampleDBClient
// Module:  SampleDBClient
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleDBClient.h"
#include "SampleMariaDBClient.h"
#include "SampleMariaDBResult.h"

using namespace BnD;

SampleMariaDBClient::SampleMariaDBClient()
{
}

bool SampleMariaDBClient::getUserInfo(const B1String& userID, class SampleUserInfo* userInfo) const
{
    SampleMariaDBResult result(userID, userInfo);
    return execute(result.sql(), &result);
}

bool SampleMariaDBClient::addUser(const B1String& userID, const B1String& userName, const B1String& groupID)
{
    return false;
}
