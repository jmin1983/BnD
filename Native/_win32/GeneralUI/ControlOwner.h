//
// ControlOwner.h
//
// Library: GeneralUI
// Package: GeneralUI
// Module:  GeneralUI
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

namespace BnD {
    class ControlOwner {
    protected:
        virtual bool isAvailablePage() const { return true; }
        virtual void implEnableControls(bool enable) {}
    public:
        void enableControls(bool enable);
    };
}
