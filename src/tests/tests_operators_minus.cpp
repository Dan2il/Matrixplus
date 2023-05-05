#include "tests.h"

TEST(tests_operator_sub_matrix, correct_arg) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  S21Matrix answer(3, 3);

  matrix_1.Assign(7);
  matrix_2.Assign(5);
  answer.Assign(2);

  S21Matrix result = matrix_1 - matrix_2;
  EXPECT_TRUE(answer.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(answer));

  matrix_1 -= matrix_2;
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
}

TEST(tests_operator_sub_matrix, correct_arg_2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  S21Matrix matrix_1(rows, columns);
  S21Matrix matrix_2(rows, columns);
  S21Matrix answer(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value1 = rand() % 100 + 1 / rand() % 100 + 1;
      double value2 = rand() % 100 + 1 / rand() % 100 + 1;
      matrix_1.Assign(value1);
      matrix_2.Assign(value2);

      answer.Assign(value1 - value2);
    }
  }

  S21Matrix result = matrix_1 - matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));

  matrix_1 -= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
}

TEST(tests_operator_sub_matrix, correct_arg_3) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  S21Matrix answer(3, 3);

  matrix_1.Assign({0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});
  matrix_2.Assign({9.25, 8.25, 7.25, 6.25, 5.25, 4.25, 3.25, 2.25, 1.25});

  answer.Assign({-9.0, -7.0, -5.0, -3.0, -1.0, 1.0, 3.0, 5.0, 7.0});

  S21Matrix result = matrix_1 - matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));

  matrix_1 -= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operator_sub_matrix, correct_arg_4) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);
  S21Matrix answer(1, 1);

  matrix_1.Assign(0, 0, 1.25);
  matrix_2.Assign(0, 0, 2.25);

  answer.Assign(0, 0, -1);

  S21Matrix result = matrix_1 - matrix_2;
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));

  matrix_1 -= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(matrix_1));
}

TEST(tests_operator_sub_matrix, uncorrect_arg) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  S21Matrix matrix_1(rows, columns);
  matrix_1.Assign(2);
  S21Matrix matrix_1_save(matrix_1);
  rows = rand() % 1000 + 1;
  columns = rand() % 1000 + 1;
  S21Matrix matrix_2(rows, columns);
  EXPECT_ANY_THROW(matrix_1 - matrix_2);
  EXPECT_ANY_THROW(matrix_1 -= matrix_2);
}
