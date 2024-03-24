//
// SampleWindowService.cpp
//
// Library: SampleWindowService
// Package: SampleWindowService
// Module:  SampleWindowService
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#include "SampleWindowService.h"

#include <D1Data/D1ConfFileReader.h>

#include <SampleWebService.h>

using namespace BnD;

SampleWindowService::SampleWindowService()
    : B1WindowService("SampleWindowService")
    , _service(new SampleWebService())
{
}

bool SampleWindowService::start()
{
    D1ConfFileReader config;
    config.load();
    if (_service->start(config.redisAddress(), config.redisPort(), config.redisDB(),
        config.logPath(_service->serviceName()), config.logCounts()) != true) {
        return false;
    }
    return true;
}

void SampleWindowService::wait()
{
    _service->wait();
}

void SampleWindowService::stop()
{
    _service->stop();
}

bool SampleWindowService::isStopped() const
{
    return _service->isStopped();
}

bool SampleWindowService::startService()
{
    return startServiceDispatch(this);
}

B1String SampleWindowService::toString() const
{
    return _service->serviceName();
}
