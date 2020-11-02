cmake_minimum_required(VERSION 2.6)

project(SZE-MOSZE-2020-POTTYOK)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

get_filename_component(PARENT_DIR ../ ABSOLUTE)
include_directories(${PARENT_DIR})

add_executable( runJsonTests JsonTests.cpp )
target_link_libraries(runJsonTests gtest gtest_main pthread)
target_compile_features(runJsonTests PRIVATE cxx_std_17)

add_executable( runEntityTests EntityTests.cpp ${PARENT_DIR}/Monster.cpp ${PARENT_DIR}/JSON.cpp ${PARENT_DIR}/Hero.cpp )
target_link_libraries(runEntityTests gtest gtest_main pthread)
target_compile_features(runEntityTests PRIVATE cxx_std_17)


