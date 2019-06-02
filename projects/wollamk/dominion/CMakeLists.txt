cmake_minimum_required(VERSION 3.13)
project(dominion C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(dominion
        cardtest4.c
        dominion.c
        dominion.h
        dominion_helpers.h
        interface.c
        interface.h
        rngs.c
        rngs.h
)
