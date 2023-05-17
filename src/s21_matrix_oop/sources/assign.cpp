#include "../s21_matrix_oop.h"

S21Matrix& S21Matrix::Assign(const std::vector<double>& data) {
  if (!data.empty()) {
    int counter_rows = 0;
    int counter_cols = 0;
    std::vector<std::vector<double>> matrix(rows_,
                                            std::vector<double>(cols_, 0));
    for (double num : data) {
      matrix.at(counter_rows).at(counter_cols++) = num;
      if (counter_cols == cols_) {
        counter_cols = 0;
        counter_rows++;
      }
      if (counter_rows >= rows_) {
        break;
      }
    }
    std::swap(matrix_, matrix);
  }
  return *this;
}

S21Matrix& S21Matrix::Assign(const double num) {
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
    for (size_t index_col = 0; index_col < matrix.at(index_row).size();
         ++index_col) {
      matrix.at(index_row).at(index_col) = num;
    }
  }
  std::swap(matrix_, matrix);
  return *this;
}

S21Matrix& S21Matrix::Assign(const size_t index_row, const size_t index_col,
                             const double num) {
  matrix_.at(index_row).at(index_col) = num;
  return *this;
}