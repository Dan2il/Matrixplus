#include "tests.h"

TEST(tests_calccomplements, correct_arg) {
  S21Matrix matrix(3, 3, {1, 2, 3, 0, 4, 2, 5, 2, 1});
  S21Matrix answer(3, 3, {0, 10, -20, 4, -14, 8, -8, -2, 4});
  S21Matrix result = matrix.CalcComplements();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_calccomplements, correct_arg_2) {
  S21Matrix matrix(3, 3, {2, 5, 7, 6, 3, 4, 5, -2, -3});
  S21Matrix answer(3, 3, {-1, 38, -27, 1, -41, 29, -1, 34, -24});
  S21Matrix result = matrix.CalcComplements();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_calccomplements, correct_arg_3) {
  S21Matrix matrix(3, 3, {1, 2, 3, 0, 4, 2, 5, 2, 1});
  S21Matrix answer(3, 3, {0, 10, -20, 4, -14, 8, -8, -2, 4});
  S21Matrix result = matrix.CalcComplements();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_calccomplements, correct_arg_4) {
  S21Matrix matrix(3, 3, {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0});
  S21Matrix answer(3, 3, {0.0, 10.0, -20.0, 4.0, -14.0, 8.0, -8.0, -2.0, 4.0});
  S21Matrix result = matrix.CalcComplements();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_calccomplements, correct_arg_5) {
  S21Matrix matrix;
  S21Matrix answer;
  S21Matrix result = matrix.CalcComplements();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_calccomplements, correct_arg_6) {
  S21Matrix matrix;
  matrix.Assign(325234.23423);
  S21Matrix answer;
  answer.Assign(325234.23423);
  S21Matrix result = matrix.CalcComplements();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_calccomplements, correct_arg_7) {
  S21Matrix matrix(3, 3, {5, -1, 1, 2, 3, 4, 1, 0, 3});
  S21Matrix answer(3, 3, {9, -2, -3, 3, 14, -1, -7, -18, 17});
  S21Matrix result = matrix.CalcComplements();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_calccomplements, uncorrect_arg) {
  S21Matrix matrix(5, 2);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}