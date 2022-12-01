cmake_minimum_required(VERSION 3.13)
project(utf8-cpp CXX)

add_library(utf8-cpp INTERFACE ../../../../../src/frog.cxx ../../../../../src/frog.hxx ../../../../../src/car.cxx ../../../../../src/car.hxx)

target_include_directories(utf8-cpp SYSTEM INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

export(TARGETS utf8-cpp FILE Utf8CppConfig.cmake)
