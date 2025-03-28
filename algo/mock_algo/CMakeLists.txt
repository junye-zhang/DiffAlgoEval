cmake_minimum_required(VERSION 3.14)

project(MockAlgo LANGUAGES CXX)

add_library(mock_algo STATIC
    mock_algo.cpp
    mock_algo.h
)

target_include_directories(mock_algo PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../algo_wrapper
)

target_compile_features(mock_algo PUBLIC cxx_std_17)

find_package(Qt6 REQUIRED COMPONENTS Core)
target_link_libraries(mock_algo PUBLIC Qt6::Core)