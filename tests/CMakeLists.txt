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

add_executable( runGameTests GameTests.cpp ${PARENT_DIR}/Game.cpp ${PARENT_DIR}/Map.cpp ${PARENT_DIR}/Monster.cpp ${PARENT_DIR}/Hero.cpp ${PARENT_DIR}/JSON.cpp )
target_link_libraries(runGameTests gtest gtest_main pthread)
target_compile_features(runGameTests PRIVATE cxx_std_17)

add_executable( runDamageTests DamageTests.cpp )
target_link_libraries(runDamageTests gtest gtest_main pthread)
target_compile_features(runDamageTests PRIVATE cxx_std_17)

add_executable( runRendererTests RendererTests.cpp ${PARENT_DIR}/Game.cpp ${PARENT_DIR}/MarkedMap.cpp ${PARENT_DIR}/ObserverTextRenderer.cpp ${PARENT_DIR}/HeroTextRenderer.cpp ${PARENT_DIR}/Monster.cpp ${PARENT_DIR}/Hero.cpp ${PARENT_DIR}/Map.cpp ${PARENT_DIR}/JSON.cpp )
target_link_libraries(runRendererTests gtest gtest_main pthread)
target_compile_features(runRendererTests PRIVATE cxx_std_17)

add_executable( runMapTests MapTests.cpp ${PARENT_DIR}/Map.cpp )
target_link_libraries(runMapTests gtest gtest_main pthread)
target_compile_features(runMapTests PRIVATE cxx_std_17)

add_executable( runMarkedMapTests MarkedMapTests.cpp ${PARENT_DIR}/MarkedMap.cpp ${PARENT_DIR}/Monster.cpp ${PARENT_DIR}/Hero.cpp ${PARENT_DIR}/Map.cpp ${PARENT_DIR}/JSON.cpp )
target_link_libraries(runMarkedMapTests gtest gtest_main pthread)
target_compile_features(runMarkedMapTests PRIVATE cxx_std_17)

add_executable( runMapEntityTests MapEntityTests.cpp ${PARENT_DIR}/Game.cpp ${PARENT_DIR}/Map.cpp ${PARENT_DIR}/Monster.cpp ${PARENT_DIR}/Hero.cpp ${PARENT_DIR}/JSON.cpp )
target_link_libraries(runMapEntityTests gtest gtest_main pthread)
target_compile_features(runMapEntityTests PRIVATE cxx_std_17)
