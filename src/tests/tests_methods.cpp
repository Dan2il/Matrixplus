#include "tests.h"

TEST(tests_methods, assign) {
  S21Matrix matrix(2, 4);
  matrix.Assign({1, 1, 1, 1, 4, 4, 4, 4});
  CheckMatrixRange({1, 1, 1, 1, 4, 4, 4, 4}, matrix);
}

TEST(tests_methods, assign_few_argument) {
  S21Matrix matrix(1, 10);
  matrix.Assign({1, 1, 1, 1, 4, 4, 4, 4});
  CheckMatrixRange({1, 1, 1, 1, 4, 4, 4, 4}, matrix);
}

TEST(tests_methods, assign_much_argument) {
  S21Matrix matrix(2, 3);
  matrix.Assign({1, 1, 1, 1, 4, 4, 4, 4});
  CheckMatrixRange({1, 1, 1, 1, 4, 4, 4, 4}, matrix);
}