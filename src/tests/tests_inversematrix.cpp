#include "tests.h"

TEST(tests_inverse_matrix, correct_arg) {
  S21Matrix matrix(3, 3);
  S21Matrix answer(3, 3);

  matrix.Assign({3, 27, 18, 0, 18, 15, 24, 9, 9});
  answer.Assign({0.0133333, -0.04, 0.04, 0.177778, -0.2, -0.0222222, -0.213333,
                 0.306667, 0.0266667});
  S21Matrix result = matrix.InverseMatrix();

  std::cerr << "result == " << result(0, 0) << std::endl;
  std::cerr << "result == " << result(0, 1) << std::endl;
  std::cerr << "result == " << result(0, 2) << std::endl;

  std::cerr << "result == " << result(1, 0) << std::endl;
  std::cerr << "result == " << result(1, 1) << std::endl;
  std::cerr << "result == " << result(1, 2) << std::endl;

  std::cerr << "result == " << result(2, 0) << std::endl;
  std::cerr << "result == " << result(2, 1) << std::endl;
  std::cerr << "result == " << result(2, 2) << std::endl;

  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}