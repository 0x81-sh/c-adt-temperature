cmake_minimum_required(VERSION 3.17)
project(temperature C)

set(CMAKE_C_STANDARD 11)

add_executable(temperature main.c temperature.h temperature.c)