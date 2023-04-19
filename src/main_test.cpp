#include <gtest/gtest.h>

#include <iostream>
#include <list>

#include "s21_matrix_oop.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  S21Matrix matrix;

  std::cout << matrix.GetCols() << " " << matrix.GetRows() << std::endl;

  S21Matrix matrix_2(5, 5);

  std::cout << matrix_2.GetCols() << " " << matrix_2.GetRows() << std::endl;

  S21Matrix matrix_3(-3, 5);

  return RUN_ALL_TESTS();
}
