#include "tests.h"

TEST(tests_operators_plus, correct_arg) {
  S21Matrix matrix_1(3, 6);
  S21Matrix matrix_2(3, 6,
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  {
    S21Matrix result = matrix_1 + matrix_2;
    EXPECT_TRUE(result.EqMatrix(matrix_2));
    EXPECT_TRUE(matrix_2.EqMatrix(result));
    EXPECT_TRUE(matrix_1.EqMatrix(S21Matrix(3, 6)));
    EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
    EXPECT_TRUE(result.EqMatrix(result));
  }
  {
    matrix_1 += matrix_2;
    EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
    EXPECT_TRUE(matrix_2.EqMatrix(matrix_1));
  }
}

TEST(tests_operators_plus, correct_arg_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  S21Matrix answer(3, 3);
  matrix_1.Assign(2);
  matrix_2.Assign(2);
  answer.Assign(4);
  {
    S21Matrix res = matrix_1 + matrix_2;
    EXPECT_TRUE(res.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(res));
  }
  {
    matrix_1 += matrix_2;
    EXPECT_TRUE(matrix_1.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix_1));
  }
}

TEST(tests_operators_plus, correct_arg_3) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  S21Matrix matrix_1(rows, columns);
  S21Matrix matrix_2(rows, columns);
  S21Matrix answer(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value1 = rand() % 10000 + 1;
      double value2 = rand() % 10000 + 1;
      matrix_1.Assign(i, j, value1);
      matrix_2.Assign(i, j, value2);
      answer.Assign(i, j, value1 + value2);
    }
  }
  {
    S21Matrix result = matrix_1 + matrix_2;
    EXPECT_TRUE(result.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(result));
  }
  {
    matrix_1 += matrix_2;
    EXPECT_TRUE(matrix_1.EqMatrix(answer));
    EXPECT_TRUE(answer.EqMatrix(matrix_1));
  }
}

TEST(tests_operators_plus, correct_arg_4) {
  S21Matrix matrix_1(3, 3,
                     {0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});
  S21Matrix matrix_2(3, 3,
                     {9.65, 8.65, 7.65, 6.65, 5.65, 4.65, 3.65, 2.65, 1.65});
  S21Matrix answer(3, 3);
  answer.Assign(9.9);
  {
    S21Matrix result = matrix_1 + matrix_2;
    EXPECT_TRUE(answer.EqMatrix(result));
    EXPECT_TRUE(result.EqMatrix(answer));
  }
  {
    matrix_1 += matrix_2;
    EXPECT_TRUE(answer.EqMatrix(matrix_1));
    EXPECT_TRUE(matrix_1.EqMatrix(answer));
  }
}

TEST(tests_operators_plus, uncorrect_matrix) {
  S21Matrix matrix_1(6, 3);
  S21Matrix matrix_2(3, 6,
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  EXPECT_ANY_THROW(S21Matrix result = matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_1 += matrix_2);
}

TEST(tests_operators_plus, uncorrect_matrix_2) {
  S21Matrix matrix_1(rand() % 1000 + 1, rand() % 1000 + 1);
  S21Matrix matrix_2(rand() % 1000 + 1, rand() % 1000 + 1);
  EXPECT_ANY_THROW(S21Matrix result = matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_1 += matrix_2);
}

TEST(tests_operators_plus, uncorrect_matrix_3) {
  S21Matrix matrix_1;
  S21Matrix matrix_2(2, 2);
  EXPECT_ANY_THROW(S21Matrix result = matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_1 += matrix_2);
}
