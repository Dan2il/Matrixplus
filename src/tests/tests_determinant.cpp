#include "tests.h"

TEST(tests_determinant, correct_arg) {
  S21Matrix matrix(3, 3);
  matrix.Assign({1, 2, 3, 4, 5, 6, 7, 8, 9});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 0);
}

TEST(tests_determinant, correct_arg_2) {
  S21Matrix matrix(3, 3);
  matrix.Assign({2, 5, 7, 6, 3, 4, 5, -2, -3});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, -1);
}

TEST(tests_determinant, correct_arg_3) {
  S21Matrix matrix(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix.Assign(i, j, j);
    }
  }
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 0);
}

TEST(tests_determinant, correct_arg_4) {
  S21Matrix matrix(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix.Assign(i, j, j + i);
    }
  }
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 0);
}

TEST(tests_determinant, correct_arg_5) {
  S21Matrix matrix(5, 5);
  matrix.Assign({6, -2, -1, 5,  667, 3,  -5, -9, -7, 7, 15, 35, 0,
                 0, -4, 0,  -1, -11, -2, -1, -2, -2, 3, 0,  -2});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 2028624);
}

TEST(tests_determinant, correct_arg_6) {
  S21Matrix matrix(3, 3);
  matrix.Assign({2, 3, 1, 7, 4, 1, 9, -2, 1});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, -32);
}

TEST(tests_determinant, correct_arg_7) {
  S21Matrix matrix(2, 2);
  matrix.Assign({-5, -4, -2, -3});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 7);
}

TEST(tests_determinant, correct_arg_8) {
  S21Matrix matrix(8, 8);
  matrix.Assign({2, 8, 7, 4, 1, 8, 3, 9, 4, 2, 6, 2, 2, 1, 5, 8,
                 8, 6, 7, 7, 3, 4, 4, 1, 1, 7, 0, 4, 4, 3, 0, 5,
                 5, 7, 5, 6, 8, 3, 1, 9, 3, 7, 8, 0, 5, 7, 0, 2,
                 5, 8, 3, 5, 9, 1, 2, 0, 7, 8, 7, 4, 7, 9, 1, 5});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, -616458);
}

TEST(tests_determinant, correct_arg_9) {
  S21Matrix matrix(1, 1);
  matrix.Assign(678.345453);
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 678.345453);
}

TEST(tests_determinant, correct_arg_10) {
  S21Matrix matrix(3, 3);
  matrix.Assign({0.25, 1.25, 2.25, 3.25, 10, 5.25, 6.25, 7.25, 8.25});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, -69);
}

TEST(tests_determinant, correct_arg_11) {
  S21Matrix matrix(3, 3);
  matrix.Assign({2, 4, -6, -5, -7, 5, 3, 5, -6});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, -2);
}

TEST(tests_determinant, correct_arg_12) {
  S21Matrix matrix(3, 3);
  matrix.Assign({-3, 4, -6, 2, -7, 5, -4, 5, -6});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 25);
}

TEST(tests_determinant, correct_arg_13) {
  S21Matrix matrix(3, 3);
  matrix.Assign({-3, 2, -6, 2, -5, 5, -4, 3, -6});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 23);
}

TEST(tests_determinant, correct_arg_14) {
  S21Matrix matrix(3, 3);
  matrix.Assign({-3, 2, 4, 2, -5, -7, -4, 3, 5});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, -8);
}

TEST(tests_determinant, correct_arg_15) {
  S21Matrix matrix(4, 4);
  matrix.Assign({3, -3, -5, 8, -3, 2, 4, -6, 2, -5, -7, 5, -4, 3, 5, -6});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 18);
}

TEST(tests_determinant, correct_arg_16) {
  S21Matrix matrix(5, 5);
  matrix.Assign({0.25, 1.25, 2.25, 3.25, 2.25, 3.25, 10,   5.25, 5.25,
                 5.25, 6.25, 7.25, 8.25, 6.25, 6.25, 6.25, 7.25, 8.25,
                 6.25, 7.25, 6.25, 7.25, 8.25, 6,    8.25});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, -69.0 / 4.00);
}

TEST(tests_determinant, correct_arg_17) {
  S21Matrix matrix(4, 4);
  matrix.Assign({1, 2, 3, 13, 4, 5, 6, 16, 7, 8, 90, 19, 1, 7, 7, 17});
  double result = matrix.Determinant();
  EXPECT_DOUBLE_EQ(result, 13608);
}

TEST(tests_determinant, uncorrect_arg) {
  S21Matrix matrix(5, 4);
  EXPECT_ANY_THROW(matrix.Determinant());
}