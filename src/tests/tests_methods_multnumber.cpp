#include "tests.h"

TEST(tests_methods_mult_matrix_number, correct_arg) {
  S21Matrix matrix(5, 3);
  S21Matrix result(5, 3);

  matrix.Assign(7);
  result.Assign(28);

  matrix.MulNumber(4);
  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}

TEST(tests_methods_mult_matrix_number, correct_arg_2) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  double value2 = rand() / rand() + 1;

  S21Matrix matrix(rows, columns);
  S21Matrix result(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value1 = rand() / rand() + 1;
      matrix.Assign(i, j, value1);
      result.Assign(i, j, value1 * value2);
    }
  }

  matrix.MulNumber(value2);

  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}

TEST(tests_methods_mult_matrix_number, correct_arg_3) {
  S21Matrix matrix(2, 3);

  matrix.Assign({5, 34, -4, 844.545, -0.452434, 87});

  S21Matrix result(matrix);

  matrix.MulNumber(1);
  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}

TEST(tests_methods_mult_matrix_number, correct_arg_4) {
  S21Matrix matrix(2, 3);
  S21Matrix result(2, 3);

  matrix.Assign({5, 34, -4, 844.545, -0.452434, 87}).MulNumber(0);

  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}

TEST(tests_methods_mult_matrix_number, correct_arg_5) {
  S21Matrix matrix(1, 1);
  S21Matrix result(1, 1);

  matrix.Assign(0, 0, 1.25).MulNumber(-4);
  result.Assign(0, 0, -5);

  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}

TEST(tests_methods_mult_matrix_number, correct_arg_6) {
  S21Matrix matrix(3, 3);
  S21Matrix result(3, 3);

  matrix.Assign({0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25})
      .MulNumber(4);

  result.Assign({1, 5, 9, 13, 17, 21, 25, 29, 33});

  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}
