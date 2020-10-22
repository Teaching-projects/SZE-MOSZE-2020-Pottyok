cmake_minimum_required(VERSION 2.6)

project(SZE-MOSZE-2020-POTTYOK)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable( runTests JsonTests.cpp )
target_link_libraries(runTests gtest gtest_main pthread)
target_compile_features(runTests PRIVATE cxx_std_17)
