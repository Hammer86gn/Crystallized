//======== OpenGL.h ========
//Purpose: For OpenGL utilities
//=============================

#pragma once

#include <GLFW/glfw3.h>

#include <cryst/logging/EngineLogger.h>

class OpenGL {
public:
    void initOpenGL() {
        this->renderLogger = new EngineLogger("RENDER");

        if (!glfwInit())
            std::cout << "Wow it doesn't work\n";
            return;
    }

//    static void reloadWindow(GLFWwindow* window) {
//
//    }


    EngineLogger* getRenderLogger() {
        return renderLogger;
    }
private:
    EngineLogger* renderLogger;
};