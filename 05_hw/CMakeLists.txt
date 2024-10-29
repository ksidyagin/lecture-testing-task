cmake_minimum_required(VERSION 3.20)
project(Main)
find_package(GTest REQUIRED)

add_library(stack stack.cpp)

add_executable(main main.cpp)
target_link_libraries(main stack)

add_executable(gtest_stack gtest_stack.cpp)
target_link_libraries(gtest_stack stack GTest::GTest)