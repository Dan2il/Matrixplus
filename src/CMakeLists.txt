cmake_minimum_required(VERSION 3.10.2)

project(S21Matrix)
include(FetchContent)
FetchContent_Declare(
    googletest

    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0 -std=c++17 -Wall -Werror -Wextra")

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
    s21_matrix_oop
    s21_matrix_oop/sources/constructors.cpp
    s21_matrix_oop/sources/assign.cpp
    s21_matrix_oop/sources/comparison.cpp
    s21_matrix_oop/sources/arithmetic_operations.cpp
    s21_matrix_oop/sources/operators.cpp
    s21_matrix_oop/sources/matrix_operations.cpp
    s21_matrix_oop/sources/other_methods.cpp
    s21_matrix_oop/s21_matrix_oop.h)

add_executable(
    s21_matrix_tests
    tests/tests_constuctors.cpp
    tests/func_for_test.cpp
    tests/tests_methods_assign.cpp
    tests/tests_operators.cpp
    tests/tests_methods_eqmatrix.cpp
    tests/tests_methods_summatrix.cpp
    tests/tests_methods_submatrix.cpp
    tests/tests_methods_multnumber.cpp
    tests/tests_methods_multmatrix.cpp
    tests/tests_methods_transpose.cpp
    tests/tests_methods_minor_matrix.cpp
    tests/tests_determinant.cpp
    tests/tests_calccomplements.cpp
    tests/tests_inversematrix.cpp
    tests/tests_operators_plus.cpp
    tests/tests_operators_minus.cpp
    tests/tests_operators_mul.cpp
    tests/tests_operators_eq.cpp
    tests/tests_operators_assign.cpp
    tests/tests_methods_inversematrix.cpp
    tests/tests.h
)

target_link_libraries(
    s21_matrix_tests
    s21_matrix_oop
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(s21_matrix_tests)