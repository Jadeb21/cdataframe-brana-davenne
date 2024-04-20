cmake_minimum_required(VERSION 3.27)
project(projet C)

set(CMAKE_C_STANDARD 11)

add_executable(projet main.c
        CDataframe.c
        CDataframe.h
        colomn.c
        colomn.h)
