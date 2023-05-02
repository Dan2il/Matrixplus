#include "tests.h"

TEST(tests_methods_transpose, correct_arg) {
  S21Matrix matrix_1(3, 2);
  S21Matrix answer(2, 3);

  matrix_1.Assign({1, 2, 3, 4, 5, 6});
  answer.Assign({1, 3, 5, 2, 4, 6});

  S21Matrix result = matrix_1.Transpose();

  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_methods_transpose, correct_arg_2) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  S21Matrix matrix_1(rows, columns);
  S21Matrix answer(columns, rows);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value1 = (rand() - 298.3) / (rand() + 1);
      matrix_1.Assign(i, j, value1);
      answer.Assign(j, i, value1);
    }
  }
  S21Matrix result = matrix_1.Transpose();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_methods_transpose, correct_arg_3) {
  S21Matrix matrix_1;
  S21Matrix answer;
  S21Matrix result = matrix_1.Transpose();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_methods_transpose, correct_arg_4) {
  S21Matrix matrix_1(1, 1);
  S21Matrix answer(1, 1);

  matrix_1.Assign(1.25);
  answer.Assign(1.25);

  S21Matrix result = matrix_1.Transpose();

  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_methods_transpose, correct_arg_5) {
  S21Matrix matrix_1(3, 3);
  S21Matrix answer(3, 3);

  matrix_1.Assign({0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});
  answer.Assign({0.25, 3.25, 6.25, 1.25, 4.25, 7.25, 2.25, 5.25, 8.25});

  S21Matrix result = matrix_1.Transpose();

  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}