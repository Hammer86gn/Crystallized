//======== Application.h ========
//Purpose: A class used to manage a Crystallized Application
//=============================

#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>

namespace cryst {

    class Application {
    public:
         Application(std::string name);

        virtual ~Application();

        //NOTE: This is what runs the application you can think of this as the new int main();
        virtual void onRun();

    private:
        std::string m_name;

    protected:
        GLFWwindow* m_window;
    };

    //NOTE: must be implemented in order for the game to run
    cryst::Application* instantiateApplication(int argc, char** argv);

}


