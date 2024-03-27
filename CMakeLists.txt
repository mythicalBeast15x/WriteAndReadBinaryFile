cmake_minimum_required(VERSION 3.27)
project(WriteBinaryFile C)

set(CMAKE_C_STANDARD 11)

add_executable(WriteBinaryFile main.c
        binaryFile.h)
