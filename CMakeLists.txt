cmake_minimum_required(VERSION 3.15)
project(M2OEP)

set(CMAKE_CXX_STANDARD 17)

add_executable(M2OEP main.cpp
        Person.h
        Person.cpp
        Teacher.h
        Teacher.cpp
        Student.h
        Student.cpp
        Class.h
        Class.cpp)