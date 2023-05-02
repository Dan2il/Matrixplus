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