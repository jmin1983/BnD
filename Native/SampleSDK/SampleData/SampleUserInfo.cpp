//
// SampleUserInfo.cpp
//
// Library: SampleData
// Package: SampleData
// Module:  SampleData
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleData.h"
#include "SampleUserInfo.h"

using namespace BnD;

SampleUserInfo::SampleUserInfo()
    : B1Object()
    , _number("Number", -1)
    , _userID("UserID", "")
    , _name("Name", "")
{
}

SampleUserInfo::~SampleUserInfo()
{
}

void SampleUserInfo::archiveTo(B1Archive* archive) const
{
    writeDataToArchive(_number, archive);
    writeDataToArchive(_userID, archive);
    writeDataToArchive(_name, archive);
}

void SampleUserInfo::unarchiveFrom(const B1Archive& archive)
{
    readDataFromArchive(archive, &_number);
    readDataFromArchive(archive, &_userID);
    readDataFromArchive(archive, &_name);
}

B1String SampleUserInfo::toString() const
{
    B1String str;
    str.appendf(", number[%d]", number());
    str.appendf(", userID[%s]", userID().cString());
    str.appendf(", name[%s]", name().cString());
    return str;
}
