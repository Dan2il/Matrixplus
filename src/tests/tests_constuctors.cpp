#include <gtest/gtest.h>

#include "../s21_matrix_oop/s21_matrix_oop.h"

TEST(tests_constuctors, not_argument) {
  S21Matrix matrix;
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 1);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 1);
}
