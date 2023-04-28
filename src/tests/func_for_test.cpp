#include "tests.h"

void CreateMatrix(int rows, int cols) { S21Matrix matrix(rows, cols); }

void CheckMatrix(double num, S21Matrix& matrix) {
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(matrix(i, j), num);
    }
  }
}

void CheckMatrixRange(std::vector<double> nums, S21Matrix& matrix) {
  std::vector<double>::iterator it = nums.begin();
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(matrix(i, j), *it);
      it++;
    }
  }
}