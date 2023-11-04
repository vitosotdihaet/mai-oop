cmake_minimum_required(VERSION 3.10)
project(l4)

include_directories("include")

file(GLOB SOURCES "src/*.cpp")

add_executable(main_l4 ${SOURCES})