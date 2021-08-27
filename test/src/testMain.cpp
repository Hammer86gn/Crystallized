//======== testMain.cpp ========
//Purpose: The main class for testing Crystallized
//=============================

#include <iostream>
#include <cryst/application/Application.h>
#include <cryst/EntryPoint.h>
#include <cryst/logging/EngineLogger.h>
#include <glad/gl.h>


class Test : public cryst::Application {
    friend class cryst::Application;
public:
    //NOTE: Called on program startup
    Test(std::string name) : Application(name) {
        this->m_name = name;

        std::cout << "Instantiating the application\n";
    }

    //NOTE: Called on program deletion
    ~Test() override {
        std::cout << "Deleting the application\n";
    }

    //NOTE: Called every frame
    void onRun() override {

        auto logger = new EngineLogger("TEST");

        logger->log(LogLevel::CONFIG, this->m_name);

        logger->log(LogLevel::INFO, "This should run");

    }

private:
    std::string m_name;
};

cryst::Application *cryst::instantiateApplication(int argc, char **argv) {
    return new Test("Test");
}
