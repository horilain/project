cmake_minimum_required(VERSION 3.22)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp graham/graham.cpp graham/graham.h utils.h utils.cpp menu/menu.cpp menu/menu.h jarvis/jarvis.cpp jarvis/jarvis.h)
