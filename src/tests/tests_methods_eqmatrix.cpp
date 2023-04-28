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

TEST(tests_methods_eq_matrix, uncorrect_arg) {
  S21Matrix matrix_1(3, 6);
  S21Matrix matrix_2;
  matrix_1.Assign({234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345,
                   234.32423, 234234.432, 3, 324, 23432, 0, -345345});
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
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