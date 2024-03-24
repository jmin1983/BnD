//
// SampleMariaDBResult.h
//
// Library: SampleDBClient
// Package: SampleDBClient
// Module:  SampleDBClient
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_DBCLIENT_SAMPLE_MARIA_DB_RESULT_H
#define _SAMPLE_SDK_DBCLIENT_SAMPLE_MARIA_DB_RESULT_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif
 
#include <D1DBClient/D1MariaDBResult.h>

#include <map>
#include <vector>

namespace BnD {
    class SampleUserInfo;
    class SampleMariaDBResult : public MariaDBDataTypeResult<SampleUserInfo> {
    public:
        SampleMariaDBResult(const B1String& userID, SampleUserInfo* data);
    protected:
        bool implReadDBResult(const boost::mysql::rows_view& rows, SampleUserInfo* data) final;
    };
}   //  !BnD

#endif  // !_SAMPLE_SDK_DBCLIENT_SAMPLE_MARIA_DB_RESULT_H
