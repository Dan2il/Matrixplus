#include <gtest/gtest.h>

#include "../s21_matrix_oop/s21_matrix_oop.h"

void CreateMatrix(int rows, int cols) { S21Matrix matrix(rows, cols); }

TEST(tests_constuctors, not_argument) {
  S21Matrix matrix;
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 1);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 1);
}

TEST(tests_constuctors, simple_argument) {
  S21Matrix matrix(5, 25);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 25);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);
}

TEST(tests_constuctors, simple_argument_2) {
  S21Matrix matrix(2, 2);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 2);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << "i == " << i << std::endl;
      std::cout << "matrix(i, j) == "
                << "'" << matrix(i, j) << "'" << std::endl;
      EXPECT_DOUBLE_EQ(matrix(i, j), 0);
    }
  }
}

TEST(tests_constuctors, uncorrect_argument) {
  EXPECT_ANY_THROW(CreateMatrix(-5, 25));
  EXPECT_ANY_THROW(CreateMatrix(0, 25));
  EXPECT_NO_THROW(CreateMatrix(24, 25));
}

TEST(tests_constuctors, copy_constructor) {
  S21Matrix other(5, 6);
  S21Matrix matrix(other);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 6);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << "i == " << i << std::endl;
      std::cout << "matrix(i, j) == "
                << "'" << matrix(i, j) << "'" << std::endl;
      EXPECT_DOUBLE_EQ(matrix(i, j), other(i, j));
    }
  }
}

TEST(tests_constuctors, copy_constructor_2) {
  S21Matrix other(3, 3);

  other.Assign({1, 2, 3, 4, 5, 6, 7, 8, 9});

  S21Matrix matrix(other);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 3);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << "i == " << i << std::endl;
      std::cout << "matrix(i, j) == "
                << "'" << matrix(i, j) << "'" << std::endl;
      EXPECT_DOUBLE_EQ(matrix(i, j), other(i, j));
    }
  }
}

// TEST(tests_constuctors, copy_constructor) {
//   S21Matrix other(5, 6);
//   S21Matrix matrix(other);
//   EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);
//   EXPECT_DOUBLE_EQ(matrix.GetCols(), 6);
// }
