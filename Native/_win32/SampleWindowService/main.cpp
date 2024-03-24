//
// DiaAcaWindowsService_main.cpp
//
// Library: SampleWindowService
// Package: SampleWindowService
// Module:  SampleWindowService
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleWindowService.h"

#if defined(_WIN32) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#endif

using namespace BnD;

int32 main(int32 argc, char* argv[])
{
#if defined(_WIN32) && defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(140339);
#endif

    SampleWindowService service;
    if (argc > 1) {
        auto string = B1String(argv[1]);
        if (string == "install") {
            if (service.installService(service.toString()) != true) {
                printf("install service failed\n");
            }
        }
        else if (string == "uninstall") {
            if (service.uninstallService() != true) {
                printf("uninstall service failed\n");
            }
        }
        else if (string == "start") {
            if (service.startService() != true) {
                printf("start service failed\n");
            }
        }
        else if (string == "stop") {
            if (service.stopService() != true) {
                printf("stop service failed\n");
            }
        }
        else {
            printf("unknown command\n");
        }
        return 0;
    }
    if (service.startService() != true) {
        printf("start failed %s\n", service.serviceName().cString());
        return 1;
    }
    return 0;
}
