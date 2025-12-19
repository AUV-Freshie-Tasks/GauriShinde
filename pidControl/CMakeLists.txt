cmake_minimum_required(VERSION 3.14)
project(pidBind LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

#set(pid_source derivativeController.cpp derivativeController.h integralController.cpp integralController.h proportionalController.cpp proportionalController.h pidController.cpp pidController.h)

set(pid_source pidController.h pidController.cpp integralController.cpp proportionalController.cpp derivativeController.cpp)
pybind11_add_module(pidBind pidBind ${pid_source})