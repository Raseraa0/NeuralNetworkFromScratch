cmake_minimum_required(VERSION 3.22)

project(NeuralNetworkFromScratch)

file(
  GLOB
  SOURCES
  "src/*.cpp"
  "src/Manipulator/*.cpp"
  "src/DataStructure/*.cpp"
)

file(
  GLOB
  HEADERS
  "include/*.h"
  "include/Manipulator/*.h"
  "include/DataStructure/*.h"
)

set(SOURCES_MAIN ${SOURCES})
list(FILTER SOURCES_MAIN EXCLUDE REGEX "src/test\\.cpp")

set(SOURCES_TEST ${SOURCES})
list(FILTER SOURCES_TEST EXCLUDE REGEX "src/main\\.cpp")

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

add_compile_options(-O3)
add_compile_options(-flto)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Wpedantic)
add_compile_options(-Werror)
# add_compile_options(-Wconversion)
# add_compile_options(-Wsign-conversion)
add_compile_options(-Wshadow)
add_compile_options(-Wnon-virtual-dtor)
add_compile_options(-Wreorder)
add_compile_options(-Wmaybe-uninitialized)
add_compile_options(-Wunused-variable)

add_executable(
  neuralNetwork
  ${SOURCES_MAIN}
  ${HEADERS}
)

target_include_directories(neuralNetwork PRIVATE include)

add_executable(
  test
  ${SOURCES_TEST}
  ${HEADERS}
)

target_include_directories(test PRIVATE include)
