cmake_minimum_required(VERSION 3.14)
project(MatrixPybind LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)


set(MATRIX_SOURCE Matrix.cpp Matrix.h)


pybind11_add_module(MatrixBind MatrixPybind.cpp ${MATRIX_SOURCE})
