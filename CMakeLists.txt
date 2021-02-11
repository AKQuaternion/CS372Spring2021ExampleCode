cmake_minimum_required(VERSION 3.17)
project(CS372Spring2021ExampleCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS372Spring2021ExampleCode main.cpp catch.hpp modernCPPexamples.cpp)
add_executable(tests catch.hpp catchMain.cpp tests.cpp)