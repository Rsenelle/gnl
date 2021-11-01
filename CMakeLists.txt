cmake_minimum_required(VERSION 3.20)
project(gnl C)

set(CMAKE_C_STANDARD 99)

add_executable(gnl main.c get_next_line.c get_next_line.h get_next_line_utils.c)
