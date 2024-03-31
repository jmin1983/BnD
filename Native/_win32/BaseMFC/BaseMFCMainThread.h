//
// BaseMFCMainThread.h
//
// Library: BaseMFC
// Package: BaseMFC
// Module:  BaseMFC
//
// Written by jmin1983@gmail.com
// Feel free to use, for any purpose.
//

#pragma once

#include <B1Base/B1Thread.h>
#include <B1Base/B1Singleton.h>

#include <D1Data/D1ConfFileReader.h>

#include <BaseMFCTabCtrlWnd.h>

namespace BnD {
    class TabCtrlPage;
    class BaseMFCMainThreadListener {
    public:
        virtual void onMFCServiceStarted() {}
        virtual void onMFCServiceStopped() {}
    };

    class BaseMFCMainThread : protected B1Thread {
    protected:
        BaseMFCMainThread(const BaseMFCTabCtrlWnd* mainTab);
        virtual ~BaseMFCMainThread();
    private:
        const BaseMFCTabCtrlWnd* _mainTab;
    protected:
        BaseMFCMainThreadListener* _listener;
    protected:
        virtual void implInitPage(const TabCtrlPage& page) {}
    protected:
        virtual void implThreadBegin() override;
        virtual void implThreadEnd() override;
    public:
        bool start(BaseMFCMainThreadListener* listener);
        void checkStopped();
    };

    template <typename T, typename U>
    class BaseMFCMainThreadWrapper : public BaseMFCMainThread
                                   , public B1Singleton<U> {
    public:
        BaseMFCMainThreadWrapper(const BaseMFCTabCtrlWnd* mainTab) : BaseMFCMainThread(mainTab) {}
    protected:
        std::shared_ptr<T> _mfcService;
    protected:
        virtual std::shared_ptr<D1ConfFileReader> implInit() = 0;
        virtual void implDeinit() {}
    protected:
        void implThreadBegin() final
        {
            if (_mfcService != NULL) {
                assert(false);
                return;
            }
            auto config = implInit();
            if (config == NULL) {
                TRACE("no valid config file found");
                assert(false);
                return;
            }
            _mfcService = std::make_shared<T>();
            if (_mfcService->start(config->redisAddress(), config->redisPort(), config->redisDB(),
                                   config->logPath("sws_mfc"), config->logCounts()) != true) {
                return;
            }
            BaseMFCMainThread::implThreadBegin();
            if (_listener) {
                _listener->onMFCServiceStarted();
            }
        }
        void implThreadFunc() final { if (_mfcService) _mfcService->wait(); }
        void implThreadEnd() final
        {
            if (_listener) {
                _listener->onMFCServiceStopped();
            }
            implDeinit();
            if (_mfcService) {
                _mfcService.reset();
            }
            BaseMFCMainThread::implThreadEnd();
        }
    public:
        void requestStop() { if (_mfcService) _mfcService->stop(); }
        void stopNow() { if (_mfcService) _mfcService->stop(); join(); }
    public:
        T* mainService() { return _mfcService.get(); }
    };
}   //  !BnD
