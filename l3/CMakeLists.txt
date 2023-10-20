cmake_minimum_required(VERSION 3.10)
project(l3)

include_directories("include")

file(GLOB SOURCES "src/*.cpp")

add_executable(l3_main ${SOURCES})