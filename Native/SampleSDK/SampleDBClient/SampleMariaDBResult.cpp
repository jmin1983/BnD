//
// SampleMariaDBResult.cpp
//
// Library: SampleDBClient
// Package: SampleDBClient
// Module:  SampleDBClient
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleDBClient.h"
#include "SampleMariaDBResult.h"

#include <SampleData/SampleUserInfo.h>

using namespace BnD;

SampleMariaDBResult::SampleMariaDBResult(const B1String& userID, SampleUserInfo* data)
    : MariaDBDataTypeResult(data, B1String::formatAs("SELECT `Number`, `UserID`, `Name` FROM tb_user_info where `UserID` = %s", userID.cString()))
{
}

bool SampleMariaDBResult::implReadDBResult(const boost::mysql::rows_view& rows, SampleUserInfo* data)
{
    std::vector<B1String> items;
    if (getSingleRowResult(rows, &items, 3) != true) {
        return false;
    }
    int32 number = -1;
    try {
        number = items[0].toInt32();
    }
    catch (...) {
    }
    data->setNumber(number);
    data->setUserID(std::move(items[1]));
    data->setName(std::move(items[2]));
    return true;
}
