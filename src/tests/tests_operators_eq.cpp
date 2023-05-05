#include "tests.h"

TEST(tests_methods_eq_matrix, correct_arg) {
  S21Matrix matrix_1(3, 6);
  S21Matrix matrix_2(3, 6);
  matrix_1.Assign({234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345});
  matrix_2.Assign({234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345});
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_1));
}

TEST(tests_methods_eq_matrix, correct_arg_2) {
  S21Matrix r_matrix(3, 3);
  S21Matrix l_matrix(3, 3);
  r_matrix.Assign(5);
  l_matrix.Assign(5);
  EXPECT_TRUE(l_matrix.EqMatrix(r_matrix));
  EXPECT_TRUE(r_matrix.EqMatrix(l_matrix));
}

TEST(tests_methods_eq_matrix, correct_arg_3) {
  S21Matrix r_matrix(3, 3);
  S21Matrix l_matrix(3, 3);
  r_matrix.Assign(5);
  l_matrix.Assign(4);

  EXPECT_FALSE(l_matrix.EqMatrix(r_matrix));
  EXPECT_FALSE(r_matrix.EqMatrix(l_matrix));
  EXPECT_TRUE(l_matrix.EqMatrix(l_matrix));
  EXPECT_TRUE(r_matrix.EqMatrix(r_matrix));
}

TEST(tests_methods_eq_matrix, correct_arg_5) {
  S21Matrix r_matrix(3, 2);
  S21Matrix l_matrix(3, 3);
  r_matrix.Assign(5);
  l_matrix.Assign(5);
  EXPECT_FALSE(l_matrix.EqMatrix(r_matrix));
  EXPECT_FALSE(r_matrix.EqMatrix(l_matrix));
  EXPECT_TRUE(l_matrix.EqMatrix(l_matrix));
  EXPECT_TRUE(r_matrix.EqMatrix(r_matrix));
}

TEST(tests_methods_eq_matrix, correct_arg_6) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  S21Matrix matrix_1(rows, columns);
  S21Matrix matrix_2(rows, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double val = rand() % 1000 + 1;
      matrix_1.Assign(i, j, val);
      matrix_2.Assign(i, j, val);
    }
  }
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
}

TEST(tests_methods_eq_matrix, correct_arg_7) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  S21Matrix matrix_1(rows, columns);
  S21Matrix matrix_2(rows, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double val = rand() % 1000 + 1;
      matrix_1.Assign(i, j, val);
      val = rand() % 1000 + 1;
      matrix_2.Assign(i, j, val);
    }
  }
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
  EXPECT_FALSE(matrix_2.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
}

TEST(tests_methods_eq_matrix, correct_arg_8) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  matrix_1.Assign({0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});
  matrix_2.Assign({0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});

  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
}

TEST(tests_methods_eq_matrix, correct_arg_9) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  matrix_1.Assign({0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25});
  matrix_2.Assign({0.25, 1.25, 2.25, 3.25, 4.25});

  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
  EXPECT_FALSE(matrix_2.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
}

TEST(tests_methods_eq_matrix, correct_arg_10) {
  S21Matrix matrix_1(rand() % 1000 + 1, rand() % 1000 + 1);
  S21Matrix matrix_2(rand() % 1000 + 1, rand() % 1000 + 1);
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
  EXPECT_FALSE(matrix_2.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
}

TEST(tests_methods_eq_matrix, uncorrect_arg) {
  S21Matrix matrix_1(3, 6);
  S21Matrix matrix_2;
  matrix_1.Assign({234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345});
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(tests_methods_eq_matrix, uncorrect_arg_2) {
  S21Matrix r_matrix(3, 2);
  EXPECT_ANY_THROW(r_matrix.EqMatrix(S21Matrix(0, 0)));
  EXPECT_ANY_THROW(r_matrix.EqMatrix(S21Matrix((int)NULL, (int)NULL)));
}

TEST(tests_methods_eq_matrix, few_correct_arg) {
  S21Matrix matrix_1(3, 6);
  S21Matrix matrix_2(3, 6);
  matrix_1.Assign({234.32423, 234234.432, 3, 324, 23432, 0, -345345, 234.32423,
                   234234.432, 3, 324, 23432, 0, -345345, 234.32423,
                   234234.432});
  matrix_2.Assign({234.32423, 234234.432, 3, 324, 23432, 0, -345345, 234.32423,
                   234234.432, 3, 324, 23432, 0, -345345, 234.32423,
                   234234.432});
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_1));
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_2));
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_1));
}