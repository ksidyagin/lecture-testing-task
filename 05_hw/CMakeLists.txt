cmake_minimum_required(VERSION 3.20)
project(Main)
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

add_library(stack stack.cpp)

add_executable(main main.cpp)
target_link_libraries(main stack)

add_executable(gtest_stack gtest_stack.cpp)
target_link_libraries(gtest_stack stack GTest::GTest)

add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark stack benchmark::benchmark)