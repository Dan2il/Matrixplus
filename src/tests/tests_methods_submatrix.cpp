#include "tests.h"

TEST(tests_methods_sub_matrix, correct_arg) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  S21Matrix result(3, 3);
  matrix_1.Assign(7);
  matrix_2.Assign(5);
  result.Assign(2);
  matrix_1.SubMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_sub_matrix, correct_arg_2) {
  S21Matrix matrix_1(3, 3,
                     {0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});
  S21Matrix matrix_2(3, 3,
                     {9.25, 8.25, 7.25, 6.25, 5.25, 4.25, 3.25, 2.25, 1.25});
  S21Matrix result(3, 3, {-9.0, -7.0, -5.0, -3.0, -1.0, 1.0, 3.0, 5.0, 7.0});
  matrix_1.SubMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_sub_matrix, correct_arg_3) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);
  S21Matrix result(1, 1);
  matrix_1.Assign(0, 0, 1.25);
  matrix_2.Assign(0, 0, 2.25);
  result.Assign(0, 0, -1);
  matrix_1.SubMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_sub_matrix, correct_arg_4) {
  S21Matrix matrix1(3, 3);
  S21Matrix matrix2(3, 3);
  matrix2.Assign(5);
  matrix1.SubMatrix(matrix2);
  matrix2.Assign(-5);
  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(tests_methods_sub_matrix, uncorrect_arg) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  S21Matrix matrix_1(rows, columns);
  matrix_1.Assign(2);
  S21Matrix matrix_1_save(matrix_1);
  rows = rand() % 1000 + 1;
  columns = rand() % 1000 + 1;
  S21Matrix matrix_2(rows, columns);
  EXPECT_ANY_THROW(matrix_1.SubMatrix(matrix_2));
}

TEST(tests_methods_sub_matrix, uncorrect_arg_2) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);
  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}

TEST(tests_methods_sub_matrix, uncorrect_arg_3) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);
  EXPECT_ANY_THROW(matrix1.SetCols(0));
  EXPECT_ANY_THROW(matrix1.SetRows(0));
  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}
