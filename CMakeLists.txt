cmake_minimum_required(VERSION 3.23)
project(stack C)

set(CMAKE_C_STANDARD 17)

include_directories(include/)

add_library(stack src/stack.c)
