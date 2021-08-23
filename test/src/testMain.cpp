//======== testMain.cpp ========
//Purpose: The main class for testing Crystallized
//=============================

#include <iostream>
#include <cryst/application/Application.h>
#include <cryst/EntryPoint.h>


class Test : public cryst::Application {
public:
    Test()  {
        std::cout << "Instantiating the application\n";
    }

    ~Test() override {
        std::cout << "Deleting the application\n";
    }

    void onRun() override {
        long long time = 1;

        while (time > 0) {
           std::cout << "Hello, World!" << "\n";
           time--;
        }
    }
};

cryst::Application *cryst::instantiateApplication(int argc, char **argv) {
    return new Test();
}
