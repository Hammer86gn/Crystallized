//======== Application.cpp ========
//Purpose:
//=============================

#include <cryst/application/Application.h>

#include <string>
#include <cstring>
#include <iostream>
#include <thread>

#include <GLFW/glfw3.h>

cryst::Application::Application(std::string name) {
    this->m_name = name;

   this->m_window = glfwCreateWindow(720,720,name.c_str(),NULL,NULL);

   if (m_window == NULL) {
       std::cout << "Window failed to initialize\n";

       glfwTerminate();
   }

    glfwMakeContextCurrent(m_window);

   if (!gladLoaderLoadGL()) {
       std::cout << "GLAD failed to initialize\n";
   }

   while (!glfwWindowShouldClose(m_window)) {
       glClear(GL_COLOR_BUFFER_BIT);

       glfwSwapBuffers(m_window);

       glfwPollEvents();
   }
}

cryst::Application::~Application() {

}

void cryst::Application::onRun() {

}
