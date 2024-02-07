cmake_minimum_required(VERSION 3.26)
project(Machine_Learning_Tests C)

set(CMAKE_C_STANDARD 23)

add_executable(Machine_Learning_Tests main.c
        "Testing Randomness with Seed.c"
        "Linear Regression Model.c")
