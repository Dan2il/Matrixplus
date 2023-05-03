#include "tests.h"

TEST(tests_determinant, correct_atg) {
  S21Matrix matrix(3, 3);
  matrix.Assign({1, 2, 3, 4, 5, 6, 7, 8, 9});
  double result = matrix.Determinant();
  std::cerr << "result = " << result << std::endl;
  EXPECT_DOUBLE_EQ(result, 0);
}