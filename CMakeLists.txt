cmake_minimum_required(VERSION 3.20)
project(Crystallized)

set(CMAKE_CXX_STANDARD 14)
set(INCDIR include/cryst/)

include_directories(include)


add_library(Crystallized ${INCDIR}Crystallized.h)
add_subdirectory(test)
