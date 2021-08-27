cmake_minimum_required(VERSION 3.20)
project(Crystallized)

set(CMAKE_CXX_STANDARD 17)

set(INCDIR include/cryst/)
set(SRCDIR src/cryst/)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)

include_directories(libs/glfw/include)
include_directories(libs/glad/include)

include_directories(include)

add_library(Crystallized ${INCDIR}Crystallized.h ${INCDIR}application/Application.h ${INCDIR}EntryPoint.h
        ${SRCDIR}application/Application.cpp ${INCDIR}logging/EngineLogger.h ${SRCDIR}logging/EngineLogger.cpp ${INCDIR}graphics/opengl/OpenGL.h)

target_link_libraries(Crystallized glfw)
target_link_libraries(Crystallized glad)

add_subdirectory(test)
