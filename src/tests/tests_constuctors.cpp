#include "tests.h"

TEST(tests_constuctors, not_argument) {
  S21Matrix matrix;
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 1);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 1);
}

TEST(tests_constuctors, simple_argument) {
  S21Matrix matrix(5, 25);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 25);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);

  CheckMatrix(0, matrix);
}

TEST(tests_constuctors, simple_argument_2) {
  S21Matrix matrix(2, 2);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 2);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 2);

  CheckMatrix(0, matrix);
}

TEST(tests_constuctors, uncorrect_argument) {
  EXPECT_ANY_THROW(CreateMatrix(-5, 25));
  EXPECT_ANY_THROW(CreateMatrix(0, 25));
  EXPECT_ANY_THROW(CreateMatrix(24, 0));
  // подать числа больше int
}

TEST(tests_constuctors, copy_constructor) {
  S21Matrix other(5, 6);
  S21Matrix matrix(other);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 6);

  CheckMatrix(0, matrix);

  EXPECT_TRUE(matrix.EqMatrix(other));
  EXPECT_TRUE(other.EqMatrix(matrix));
}

TEST(tests_constuctors, copy_constructor_2) {
  S21Matrix other(3, 3);
  other.Assign({1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix matrix(other);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 3);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 3);

  EXPECT_TRUE(matrix.EqMatrix(other));
  EXPECT_TRUE(other.EqMatrix(matrix));
}
