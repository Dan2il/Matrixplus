#include "tests.h"

TEST(tests_methods_mult_matrix, correct_arg) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  S21Matrix result(3, 3);

  matrix_1.Assign({1, 1, 2, 2, 4, 5, 12, 13, 14});
  matrix_2.Assign({1, -4, -4, -7, -7, -16, -16, -17, -17});

  result.Assign({-38, -45, -54, -106, -121, -157, -303, -377, -494});

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, correct_arg_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 1);
  S21Matrix result(3, 1);

  matrix_1.Assign({5, 8, -4, 6, 9, -5, 4, 7, -2});
  matrix_2.Assign({2, -3, 1});
  result.Assign({-18, -20, -15});

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, correct_arg_3) {
  S21Matrix matrix_1(2, 4);
  S21Matrix matrix_2(4, 6);
  S21Matrix result(2, 6);

  matrix_1.Assign({9, 9, 2, 8, 6, 7, 8, 5});
  matrix_2.Assign(
      {2, 5, 6, 8, 5, 1, 0, 7, 6, 4, 8, 9, 0, 7, 1, 6, 2, 7, 1, 4, 8, 4, 0, 6});
  result.Assign({26, 154, 174, 152, 121, 152, 17, 155, 126, 144, 102, 155});

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}