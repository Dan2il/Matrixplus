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
  int counter_rows = 0;
  int counter_cols = 0;
  for (double num : nums) {
    EXPECT_DOUBLE_EQ(matrix(counter_rows++, counter_cols++), num);
    if (counter_rows == matrix.GetRows()) {
      counter_rows = 0;
      if (counter_cols == matrix.GetCols()) {
        break;
      }
    }
  }
}