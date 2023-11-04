cmake_minimum_required(VERSION 3.10)
project(l2)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "tests/*.cpp")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_l2 ${TESTS} ${SOURCES})
target_link_libraries(
  test_l2
  GTest::gtest_main
)

include(GoogleTest)
add_test(NAME BASIC COMMAND tests)