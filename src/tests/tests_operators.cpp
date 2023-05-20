#include "tests.h"

TEST(tests_operators, correct_argument) {
  S21Matrix matrix(2, 3, {1, 1, 1, 1, 4, 4, 4, 4});
  std::vector<double> data = {1, 1, 1};
  std::vector<double> check = matrix[0];
  EXPECT_TRUE(std::equal(data.begin(), data.end(), check.begin()));
}

TEST(tests_operators, correct_argument_2) {
  S21Matrix matrix(2, 3, {1, 1, 1, 1, 4, 4, 4, 4});
  std::vector<double> data = {1, 4, 4};
  std::vector<double> check = matrix[1];
  EXPECT_TRUE(std::equal(data.begin(), data.end(), check.begin()));
}

TEST(tests_operators, uncorrect_argument) {
  S21Matrix matrix(2, 3, {1, 1, 1, 1, 4, 4, 4, 4});
  EXPECT_ANY_THROW(std::vector<double> check = matrix[3]);
}

TEST(tests_operators, uncorrect_argument_2) {
  S21Matrix matrix(2, 3, {1, 1, 1, 1, 4, 4, 4, 4});
  EXPECT_ANY_THROW(std::vector<double> check = matrix[-1]);
}