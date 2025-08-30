cmake_minimum_required(VERSION 4.0)
project(Doma_)

set(CMAKE_CXX_STANDARD 20)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

add_subdirectory(src/third_party)

include_directories(src/
        src/third_party/vma/
        src/third_party/fmt/include/fmt/
        src/third_party/glm/glm/
        src/third_party/SDL/include/

)

add_executable(Doma_
        src/main.cpp
        src/vk_engine.h
        src/vk_engine.cpp
        src/vk_types.h
        src/vk_initializers.h
        src/vk_initializers.cpp
       )


