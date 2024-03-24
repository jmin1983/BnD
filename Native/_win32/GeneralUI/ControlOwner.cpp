//
// ControlOwner.cpp
//
// Library: GeneralUI
// Package: GeneralUI
// Module:  GeneralUI
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "pch.h"
#include "ControlOwner.h"

using namespace BnD;

void ControlOwner::enableControls(bool enable)
{
    if (enable) {
        enable = isAvailablePage();
    }
    implEnableControls(enable);
}
