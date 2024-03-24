//
// SampleMariaDBClient.h
//
// Library: SampleDBClient
// Package: SampleDBClient
// Module:  SampleDBClient
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_DBCLIENT_SAMPLE_MARIA_DB_CLIENT_H
#define _SAMPLE_SDK_DBCLIENT_SAMPLE_MARIA_DB_CLIENT_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <D1DBClient/D1MariaDBClient.h>

namespace BnD {
    class SampleMariaDBClient : public D1MariaDBClient {
    public:
        SampleMariaDBClient();
    public:
        bool getUserInfo(const B1String& userID, class SampleUserInfo* userInfo) const;

        bool addUser(const B1String& userID, const B1String& userName, const B1String& groupID);
    };
}   //  !BnD

#endif  // !_SAMPLE_SDK_DBCLIENT_SAMPLE_MARIA_DB_CLIENT_H
