//
// SampleWebService_main.cpp
//
// Library: SampleWebService
// Package: SampleWebService
// Module:  SampleWebService
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include <SWSIntegrated.h>
#include <SampleWebService.h>

#include <D1Data/D1ConfFileReader.h>

#include <signal.h>
#include <stdio.h>

#if defined(_WIN32) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#endif

using namespace BnD;

void signalHandler(int signo)
{
    printf("signal detected[%d]\n", signo);
    SampleWebService::get()->stop();
}

int32 main(int32 argc, char* argv[])
{
#if defined(_WIN32) && defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(140339);
#endif

    signal(SIGINT, signalHandler);

    D1ConfFileReader config;
    config.loadDefault();
    SampleWebService sws;
    const B1String name = "sws";
    if (sws.start(config.adminAddress(), config.adminPort(), config.adminDB(), config.logPath(name), name, config.logCounts()) != true) {
        return -1;
    }
    sws.wait();
    return 0;
}
