//
// StandardSampleWebServerSession.cpp
//
// Library: SWSStandard
// Package: SWSStandard
// Module:  SWSStandard
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SWSStandard.h"
#include "StandardSampleWebServerSession.h"

using namespace BnD;

StandardSampleWebServerSession::StandardSampleWebServerSession(B1ServerSocket* serverSocket, B1BaseServerSessionListener* listener)
    : SampleWebServerSession(serverSocket, listener)
{
}
