cmake_minimum_required(VERSION 3.15)
project(tp3)

set(CMAKE_CXX_STANDARD 14)

# Algunos flags para pasar al compilador (gnu++14 en vez de c++14 para que sea cross-plat)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++14 -ggdb3 -g -Werror")

# Google Test
add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

# Leemos todos los archivos fuente en ./src
file(GLOB SOURCE_FILES src/*.cpp src/*.h src/*.hpp)

# Leemos todos los archivos de test en ./tests
file(GLOB TEST_SOURCES tests/*.cpp)

#add_executable(main ${SOURCE_FILES})
add_executable(run_tests ${SOURCE_FILES} ${TEST_SOURCES})

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(run_tests gtest gtest_main)

## Test suites a ejecutar
#add_test(run_tests tests)