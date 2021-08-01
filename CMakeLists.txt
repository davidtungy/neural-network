cmake_minimum_required(VERSION 3.14)
project(neural-network)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(CTest)
enable_testing()

include(GoogleTest)

# Include Google Testing framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

include_directories(include)
add_library(nn_lib src/neuron.cc src/layer.cc src/neural_network.cc)

add_executable(main src/main.cc)
target_link_libraries(main nn_lib)

add_executable(neuron_test tests/neuron_test.cc)
target_link_libraries(neuron_test nn_lib gtest_main gmock_main)

gtest_discover_tests(neuron_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)