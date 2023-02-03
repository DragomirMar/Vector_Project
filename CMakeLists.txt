cmake_minimum_required(VERSION 3.21)
project(vi)

set(CMAKE_CXX_STANDARD 17)

add_executable(vi main.cpp doctest.h utest.cpp vector.h)
