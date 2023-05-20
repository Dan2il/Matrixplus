#include "tests.h"

TEST(tests_operators_mul_matrix, correct_arg) {
  S21Matrix matrix_1(3, 3, {1, 1, 2, 2, 4, 5, 12, 13, 14});
  S21Matrix matrix_2(3, 3, {1, -4, -4, -7, -7, -16, -16, -17, -17});
  S21Matrix answer(3, 3, {-38, -45, -54, -106, -121, -157, -303, -377, -494});
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1.MulMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
  matrix_1.Assign({1, 1, 2, 2, 4, 5, 12, 13, 14});
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, correct_arg_2) {
  S21Matrix matrix_1(3, 3, {5, 8, -4, 6, 9, -5, 4, 7, -2});
  S21Matrix matrix_2(3, 1, {2, -3, 1});
  S21Matrix answer(3, 1, {-18, -20, -15});
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1.Assign({5, 8, -4, 6, 9, -5, 4, 7, -2});
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, correct_arg_3) {
  S21Matrix matrix_1(2, 4, {9, 9, 2, 8, 6, 7, 8, 5});
  S21Matrix matrix_2(4, 6, {2, 5, 6, 8, 5, 1, 0, 7, 6, 4, 8, 9,
                            0, 7, 1, 6, 2, 7, 1, 4, 8, 4, 0, 6});
  S21Matrix answer(2, 6,
                   {26, 154, 174, 152, 121, 152, 17, 155, 126, 144, 102, 155});
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1.Assign({9, 9, 2, 8, 6, 7, 8, 5});
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, correct_arg_4) {
  S21Matrix matrix_1(3, 3, {3, 27, 18, 0, 18, 15, 24, 9, 9});
  S21Matrix matrix_2(3, 3, {3, 18, 24, 21, 15, 24, 0, 27, 3});
  S21Matrix answer(3, 3, {576, 945, 774, 378, 675, 477, 261, 810, 819});
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1.Assign({3, 27, 18, 0, 18, 15, 24, 9, 9});
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, correct_arg_5) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix answer;
  matrix_1.Assign(-1);
  matrix_2.Assign(2);
  answer.Assign(-2);
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1.Assign(-1);
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, correct_arg_6) {
  S21Matrix matrix_1(3, 2, {0, 1, 3, 4, 6, 7});
  S21Matrix matrix_2(2, 3, {9, 8, 7, 6, 5, 4});
  S21Matrix answer(3, 3, {6, 5, 4, 51, 44, 37, 96, 83, 70});
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1.Assign({0, 1, 3, 4, 6, 7});
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, correct_arg_7) {
  S21Matrix matrix_1(3, 2, {0, 1, 3, 4, 6, 7});
  S21Matrix matrix_2(2, 4, {9, 8, 7, 7, 6, 5, 4, 7});
  S21Matrix answer(3, 4, {6, 5, 4, 7, 51, 44, 37, 49, 96, 83, 70, 91});
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1.Assign({0, 1, 3, 4, 6, 7});
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, correct_arg_8) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix answer;
  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
  matrix_1 *= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operators_mul_matrix, uncorrect_arg) {
  S21Matrix matrix_1;
  S21Matrix matrix_2(3, 4);
  EXPECT_ANY_THROW(matrix_1 * matrix_2);
  EXPECT_ANY_THROW(matrix_2 * matrix_1);
  EXPECT_ANY_THROW(matrix_1 *= matrix_2);
  EXPECT_ANY_THROW(matrix_2 *= matrix_1);
}

TEST(tests_operators_mul_matrix, uncorrect_arg_2) {
  S21Matrix matrix_1(rand() % 1000 + 1, rand() % 1000 + 1);
  S21Matrix matrix_2(rand() % 1000 + 1, rand() % 1000 + 1);
  EXPECT_ANY_THROW(matrix_1 * matrix_2);
  EXPECT_ANY_THROW(matrix_2 * matrix_1);
  EXPECT_ANY_THROW(matrix_1 *= matrix_2);
  EXPECT_ANY_THROW(matrix_2 *= matrix_1);
}

TEST(tests_operators_mul_matrix, uncorrect_arg_3) {
  S21Matrix matrix_1(5, 5);
  S21Matrix matrix_2(6, 6);
  EXPECT_ANY_THROW(matrix_1 * matrix_2);
  EXPECT_ANY_THROW(matrix_2 * matrix_1);
  EXPECT_ANY_THROW(matrix_1 *= matrix_2);
  EXPECT_ANY_THROW(matrix_2 *= matrix_1);
}

TEST(tests_operators_mult_matrix_number, correct_arg) {
  S21Matrix matrix(5, 3);
  S21Matrix answer(5, 3);
  matrix.Assign(7);
  answer.Assign(28);
  {
    S21Matrix result = matrix * 4;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    S21Matrix result = 2 * matrix * 2;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    matrix *= 4;
    EXPECT_TRUE(matrix.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix));
  }
}

TEST(tests_operators_mult_matrix_number, correct_arg_2) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  double value2 = rand() / rand() + 1;
  S21Matrix matrix(rows, columns);
  S21Matrix answer(rows, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value1 = rand() / rand() + 1;
      matrix.Assign(i, j, value1);
      answer.Assign(i, j, value1 * value2);
    }
  }
  {
    S21Matrix result = matrix * value2;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    S21Matrix result = value2 * matrix;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    matrix *= value2;
    EXPECT_TRUE(matrix.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix));
  }
}

TEST(tests_operators_mult_matrix_number, correct_arg_3) {
  S21Matrix matrix(2, 3, {5, 34, -4, 844.545, -0.452434, 87});
  S21Matrix answer(matrix);
  {
    S21Matrix result = matrix * 1;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    S21Matrix result = 1 * matrix;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    matrix *= 1;
    EXPECT_TRUE(matrix.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix));
  }
}

TEST(tests_operators_mult_matrix_number, correct_arg_4) {
  S21Matrix matrix(2, 3, {5, 34, -4, 844.545, -0.452434, 87});
  S21Matrix answer(2, 3);
  {
    S21Matrix result = matrix * 0;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    S21Matrix result = 0 * matrix;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    matrix *= 0;
    EXPECT_TRUE(matrix.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix));
  }
}

TEST(tests_operators_mult_matrix_number, correct_arg_5) {
  S21Matrix matrix(1, 1);
  S21Matrix answer(1, 1);
  matrix.Assign(0, 0, 1.25);
  answer.Assign(0, 0, -5);
  {
    S21Matrix result = matrix * -4;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    S21Matrix result = -4 * matrix;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    matrix *= -4;
    EXPECT_TRUE(matrix.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix));
  }
}

TEST(tests_operators_mult_matrix_number, correct_arg_6) {
  S21Matrix matrix(3, 3,
                   {0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});
  S21Matrix answer(3, 3, {1, 5, 9, 13, 17, 21, 25, 29, 33});
  {
    S21Matrix result = matrix * 4;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    S21Matrix result = 4 * matrix;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    matrix *= 4;
    EXPECT_TRUE(matrix.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix));
  }
}