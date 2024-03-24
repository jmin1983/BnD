//
// StandardSampleWebServer.cpp
//
// Library: SWSStandard
// Package: SWSStandard
// Module:  SWSStandard
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SWSStandard.h"
#include "StandardSampleWebServer.h"
#include "StandardSampleWebServerSession.h"

using namespace BnD;

StandardSampleWebServer::StandardSampleWebServer()
    : SampleWebServer()
{
}

auto StandardSampleWebServer::createWebSocketServerSession(B1ServerSocket* serverSocket) -> B1WebSocketServerSession*
{
    return new StandardSampleWebServerSession(serverSocket, this);
}
