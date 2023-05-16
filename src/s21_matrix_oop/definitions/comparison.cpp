#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = EqSizeMatrix(other);
  for (int index = 0; index < rows_ && result == true; ++index) {
    result = std::equal(matrix_[index].begin(), matrix_[index].end(),
                        other[index].begin(), [](double left, double right) {
                          return std::fabs(std::fabs(left) - std::fabs(right)) <
                                 1e-6;
                        });
  }
  return result;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool result = EqSizeMatrix(other);
  for (int index = 0; index < rows_ && result == true; ++index) {
    result = std::equal(matrix_[index].begin(), matrix_[index].end(),
                        other[index].begin(), [](double left, double right) {
                          return std::fabs(std::fabs(left) - std::fabs(right)) <
                                 1e-6;
                        });
  }
  return result;
}

bool S21Matrix::EqSizeMatrix(const S21Matrix& other) const {
  bool result = false;
  if (rows_ == other.GetRows() && cols_ == other.GetCols()) {
    result = true;
  }
  return result;
}