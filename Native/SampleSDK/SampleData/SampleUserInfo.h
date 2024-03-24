//
// SampleUserInfo.h
//
// Library: SampleData
// Package: SampleData
// Module:  SampleData
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_DATA_SAMPLE_USER_INFO_H
#define _SAMPLE_SDK_DATA_SAMPLE_USER_INFO_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <B1Base/B1Object.h>

namespace BnD {
    class SampleUserInfo : public B1Object {
    public:
        SampleUserInfo();
        virtual ~SampleUserInfo();
    protected:
        DataInt32 _number;
        DataString _userID;
        DataString _name;
    protected:
        void archiveTo(B1Archive* archive) const final;
        void unarchiveFrom(const B1Archive& archive) final;
    public:
        int32 number() const { return _number.second; }
        const B1String& userID() const { return _userID.second; }
        const B1String& name() const { return _name.second; }

        void setNumber(int32 number) { _number.second = number; }
        void setUserID(B1String&& userID) { _userID.second = std::move(userID); }
        void setName(B1String&& name) { _name.second = std::move(name); }

        B1String toString() const;
    };
}   //  !BnD

#endif  // !_SAMPLE_SDK_DATA_SAMPLE_USER_INFO_H
