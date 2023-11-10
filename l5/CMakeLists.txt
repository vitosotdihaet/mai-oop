cmake_minimum_required(VERSION 3.10)
project(l5)

include_directories("include")

file(GLOB SOURCES "src/*.cpp")

add_executable(main_l5 ${SOURCES})