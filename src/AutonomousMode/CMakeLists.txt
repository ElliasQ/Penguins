cmake_minimum_required(VERSION 3.21)
project(AutonomousMode C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AutonomousMode
        cmd_arguments_handler.c
        cmd_arguments_handler.h
        main.c
        reading_data.c
        reading_data.h errors_handler.c errors_handler.h)
