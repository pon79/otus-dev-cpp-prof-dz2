cmake_minimum_required(VERSION 3.20)

project(ip-filter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ip-filter main.cpp iphelper.h)
