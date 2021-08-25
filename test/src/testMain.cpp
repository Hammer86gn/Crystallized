//======== testMain.cpp ========
//Purpose: The main class for testing Crystallized
//=============================

#include <iostream>
#include <cryst/application/Application.h>
#include <cryst/EntryPoint.h>
#include <cryst/logging/EngineLogger.h>


class Test : public cryst::Application {
public:
    Test()  {
        std::cout << "Instantiating the application\n";
    }

    ~Test() override {
        std::cout << "Deleting the application\n";
    }

    void onRun() override {
        long long time = 100;

        auto logger = new EngineLogger();

        while (time > 0) {
           logger->info("Hello, World!");
           time--;
        }
    }
};

cryst::Application *cryst::instantiateApplication(int argc, char **argv) {
    return new Test();
}
