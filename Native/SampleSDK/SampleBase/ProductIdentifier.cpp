//
// ProductIdentifier.cpp
//
// Library: SampleBase
// Package: SampleBase
// Module:  SampleBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleBase.h"
#include "ProductIdentifier.h"

using namespace BnD;

bool ProductIdentifier::implGetProductType(const B1String& typeString)
{
    if (D1ProductIdentifier::implGetProductType(typeString) != true) {
        int32 type = TYPE_UNKNOWN;
        try {
            type = typeString.toInt32();
        }
        catch (...) {}
        if (type < SAMPLE_TYPE_STANDARD_SERVICE || type >= SAMPLE_TYPE_END) {
            assert(false);
            return false;
        }
        _type = type;
    }
    return true;
}

bool ProductIdentifier::implToProductTypeString(B1String* result) const
{
    if (D1ProductIdentifier::implToProductTypeString(result) != true) {
        switch (_type) {
            case SAMPLE_TYPE_STANDARD_SERVICE:
                *result = "Standard Service";
                return true;
            default:
                break;
        }
    }
    return false;
}
