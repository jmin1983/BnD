//
// SampleWebServer.cpp
//
// Library: SWSBase
// Package: SWSBase
// Module:  SWSBase
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SWSBase.h"
#include "SampleWebServer.h"
#include "SampleWebServerSession.h"

using namespace BnD;

SampleWebServer::SampleWebServer()
    : B1HttpServer("")
{
}

SampleWebServer::~SampleWebServer()
{
}

auto SampleWebServer::createWebSocketServerSession(B1ServerSocket* serverSocket) -> B1WebSocketServerSession*
{
    return new SampleWebServerSession(serverSocket, this);
}