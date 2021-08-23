cmake_minimum_required(VERSION 3.20)
project(Crystallized)

set(CMAKE_CXX_STANDARD 14)

set(INCDIR include/cryst/)
set(SRCDIR src/cryst/)

include_directories(include)

add_library(Crystallized ${INCDIR}Crystallized.h ${INCDIR}application/Application.h ${INCDIR}EntryPoint.h ${SRCDIR}application/Application.cpp)
add_subdirectory(test)
