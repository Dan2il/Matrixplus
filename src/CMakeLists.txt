cmake_minimum_required(VERSION 2.8)

project(S21Matrix LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra")

set(SOURCE main_test.cpp)

set(SOURCE_LIB s21_matrix_oop.cpp)

add_library(s21_matrix_oop STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE})

target_link_libraries(main s21_matrix_oop)