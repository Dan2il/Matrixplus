#include "tests.h"

TEST(tests_methods_get_minor_matrix, correct_arg) {
  S21Matrix matrix(5, 5);
  S21Matrix answer(4, 4);
  int i = 0;
  for (int index_row = 0; index_row < matrix.GetRows(); ++index_row) {
    for (int index_col = 0; index_col < matrix.GetCols(); ++index_col) {
      matrix.Assign(index_row, index_col, ++i);
    }
  }
  i = 6;
  for (int index_row = 0; index_row < answer.GetRows(); ++index_row) {
    for (int index_col = 0; index_col < answer.GetCols(); ++index_col) {
      answer.Assign(index_row, index_col, ++i);
      if (index_col == answer.GetCols() - 1) {
        ++i;
      }
    }
  }

  S21Matrix minor = matrix.GetMinorMatrix(0, 0);
  EXPECT_TRUE(answer.EqMatrix(minor));
  EXPECT_TRUE(minor.EqMatrix(answer));
}

TEST(tests_methods_get_minor_matrix, correct_arg_2) {
  S21Matrix matrix(4, 4);
  S21Matrix answer(3, 3, {1, 2, 4, 5, 6, 8, 13, 14, 16});
  int i = 0;
  for (int index_row = 0; index_row < matrix.GetRows(); ++index_row) {
    for (int index_col = 0; index_col < matrix.GetCols(); ++index_col) {
      matrix.Assign(index_row, index_col, ++i);
    }
  }
  S21Matrix minor = matrix.GetMinorMatrix(2, 2);
  EXPECT_TRUE(answer.EqMatrix(minor));
  EXPECT_TRUE(minor.EqMatrix(answer));
}

TEST(tests_methods_get_minor_matrix, correct_arg_3) {
  S21Matrix matrix(5, 5);
  S21Matrix answer(4, 4,
                   {1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 16, 17, 18, 19});
  int i = 0;
  for (int index_row = 0; index_row < matrix.GetRows(); ++index_row) {
    for (int index_col = 0; index_col < matrix.GetCols(); ++index_col) {
      matrix.Assign(index_row, index_col, ++i);
    }
  }
  S21Matrix minor = matrix.GetMinorMatrix(4, 4);
  EXPECT_TRUE(answer.EqMatrix(minor));
  EXPECT_TRUE(minor.EqMatrix(answer));
}

TEST(tests_methods_get_minor_matrix, correct_arg_4) {
  S21Matrix matrix(3, 3, {2, 5, 7, 6, 3, 4, 5, -2, -3});
  S21Matrix answer(2, 2, {3, 4, -2, -3});
  S21Matrix minor = matrix.GetMinorMatrix(0, 0);
  EXPECT_TRUE(answer.EqMatrix(minor));
  EXPECT_TRUE(minor.EqMatrix(answer));
}

TEST(tests_methods_get_minor_matrix, uncorrect_arg) {
  S21Matrix matrix(3, 3);
  EXPECT_ANY_THROW(matrix.GetMinorMatrix(-1, 2));
  EXPECT_ANY_THROW(matrix.GetMinorMatrix(1, 4));
}