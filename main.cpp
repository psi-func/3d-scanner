#include <iostream>
#include <vector>
#include <memory>

#include <icamerasystem.h>
#include <icamerasystemsubscriber.h>
#include "ThreadSafePrint.h"

namespace we {
    class ErrorHandler : public icon::ErrorHandler {
        void onError(const icon::IError& error) override {
            safeCerr(error.getMessage().c_str());

            if (error.getCode() == icon::E_COMMUNICATION) {
                safeCerr("\nCheck that the camera is properly connected and powered.");
                safeCerr( "Check that the IP-address defined in the code corresponds to your cameras IP-address.\n");
            }
        }
    };
}


int main() {
    try {
        icon::openLogFile("icon.log");
        we::ErrorHandler errorHandler;
        auto camSystem = icon::createCameraSystem(icon::ICameraSystem::ETHERNET_CAMERA, "Ruler E1200");
        camSystem->loadConfiguration("ruler e1200.icx");

        delete camSystem;
    }
    catch (std::exception& e) {
        we::safeCerr(e.what());
    }
    return 0;
}
