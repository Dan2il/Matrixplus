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

TEST(tests_methods_mult_matrix, correct_arg_4) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  S21Matrix result(3, 3);

  matrix_1.Assign({3, 27, 18, 0, 18, 15, 24, 9, 9});
  matrix_2.Assign({3, 18, 24, 21, 15, 24, 0, 27, 3});
  result.Assign({576, 945, 774, 378, 675, 477, 261, 810, 819});

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, correct_arg_5) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix result;

  matrix_1.Assign(-1);
  matrix_2.Assign(2);
  result.Assign(-2);

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, correct_arg_6) {
  S21Matrix matrix_1(3, 2);
  S21Matrix matrix_2(2, 3);
  S21Matrix result(3, 3);

  matrix_1.Assign({0, 1, 3, 4, 6, 7});
  matrix_2.Assign({9, 8, 7, 6, 5, 4});
  result.Assign({6, 5, 4, 51, 44, 37, 96, 83, 70});

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, correct_arg_7) {
  S21Matrix matrix_1(3, 2);
  S21Matrix matrix_2(2, 4);
  S21Matrix result(3, 4);

  matrix_1.Assign({0, 1, 3, 4, 6, 7});
  matrix_2.Assign({9, 8, 7, 7, 6, 5, 4, 7});
  result.Assign({6, 5, 4, 7, 51, 44, 37, 49, 96, 83, 70, 91});

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, correct_arg_8) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix result;

  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, uncorrect_arg) {
  S21Matrix matrix_1;
  S21Matrix matrix_2(3, 4);

  EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
  EXPECT_ANY_THROW(matrix_2.MulMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, uncorrect_arg_2) {
  S21Matrix matrix_1(rand() % 1000 + 1, rand() % 1000 + 1);
  S21Matrix matrix_2(rand() % 1000 + 1, rand() % 1000 + 1);

  EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
  EXPECT_ANY_THROW(matrix_2.MulMatrix(matrix_1));
}

TEST(tests_methods_mult_matrix, uncorrect_arg_3) {
  S21Matrix matrix_1(5, 5);
  S21Matrix matrix_2(6, 6);

  EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
  EXPECT_ANY_THROW(matrix_2.MulMatrix(matrix_1));
}