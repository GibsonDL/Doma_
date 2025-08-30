cmake_minimum_required(VERSION 4.0)
project(Doma_)

set(CMAKE_CXX_STANDARD 20)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")




add_executable(Doma_ main.cpp
        vk_engine.h vk_engine.cpp vk_types.h
       )

