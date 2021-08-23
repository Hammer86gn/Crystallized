//======== Application.h ========
//Purpose: A class used to manage a Crystallized Application
//=============================

#pragma once

namespace cryst {

    class Application {
    public:
        Application();

        virtual ~Application();

        //NOTE: This is what runs the application you can think of this as the new int main();
        virtual void onRun();
    };

    //NOTE: must be implemented in order for the game to run
    cryst::Application* instantiateApplication(int argc, char** argv);

}


