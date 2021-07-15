cmake_minimum_required(VERSION 3.13)
project(neural-network)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(CTest)
enable_testing()

include_directories(include)
add_library(nn_lib src/neural_network.cc)

add_executable(main src/main.cc)
target_link_libraries(main nn_lib)