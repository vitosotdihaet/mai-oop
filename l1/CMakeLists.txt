cmake_minimum_required(VERSION 3.10)
project(l1)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(l1 main.cpp)

# find_package(GTest REQUIRED)
# add_executable(gtests tests.cpp)

# target_link_libraries(gtests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
# enable_testing()
# add_test(gtests gtests)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tests
  tests.cpp
)
target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
add_test(NAME BASIC COMMAND tests)