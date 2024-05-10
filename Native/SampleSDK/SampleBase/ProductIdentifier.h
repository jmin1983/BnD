//
// ProductIdentifier.h
//
// Library: SampleBase
// Package: SampleBase
// Module:  SampleBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#ifndef _SAMPLE_SDK_BASE_PRODUCT_IDENTIFIER_H
#define _SAMPLE_SDK_BASE_PRODUCT_IDENTIFIER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <D1Base/D1ProductIdentifier.h>

namespace BnD {
    class ProductIdentifier : public D1ProductIdentifier {
    public:
        enum SAMPLE_TYPE {
            SAMPLE_TYPE_STANDARD_SERVICE = TYPE_RESERVED_BEGIN,

            SAMPLE_TYPE_END,

            SAMPLE_TYPE_COUNTS = SAMPLE_TYPE_END - TYPE_RESERVED_BEGIN,
        };
    protected:
        bool implGetProductType(const B1String& typeString) final;
        bool implToProductTypeString(B1String* result) const final;
    };
}

#endif  // !_SAMPLE_SDK_BASE_PRODUCT_IDENTIFIER_H
