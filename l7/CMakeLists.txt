cmake_minimum_required(VERSION 3.10)
project(l7)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
file(GLOB LIB "lib/*.cpp")

add_library(lib_l7 ${LIB})

add_executable(main_l7 ${SOURCES})

target_link_libraries(
  main_l7
  lib_l7
)