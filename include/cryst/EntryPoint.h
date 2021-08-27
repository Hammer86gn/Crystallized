//======== EntryPoint.h ========
//Purpose: A header that acts as the entry point for the Crystallized Application
//=============================

#pragma once

#include <cryst/application/Application.h>
#include <cryst/graphics/opengl/OpenGL.h>

extern cryst::Application* cryst::instantiateApplication(int argc, char** argv);

int main(int argc, char** argv) {

    //TODO Initialize openGL here

    auto idk = new OpenGL();

    idk->initOpenGL();

    auto* a = cryst::instantiateApplication(argc,argv);
    a->onRun();
    delete a;
}