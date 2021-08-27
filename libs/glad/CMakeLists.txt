cmake_minimum_required(VERSION 3.20)
project(glad)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(glad include/glad/gl.h src/gl.c include/KHR/khrplatform.h)
