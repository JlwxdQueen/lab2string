cmake_minimum_required(VERSION 3.30)
project(Lab1string)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1string stringwork/main.cpp
        stringwork/char_array.h
        stringwork/c_string.h
        stringwork/file_string.h
)

