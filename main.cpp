#include <iostream>
#include <icamerasystem.h>
#include <icamerasystemsubscriber.h>

int main() {
    icon::openLogFile("icon.log");

    auto camSystem = icon::createCameraSystem(icon::ICameraSystem::ETHERNET_CAMERA, "Ruler E1200");

    delete camSystem;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
