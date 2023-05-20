#include "../s21_matrix_oop.h"

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(const int rows) {
  rows_ = rows;
  CheckCorrectRowsAndCols();
  matrix_.resize(rows_);
}
void S21Matrix::SetCols(const int cols) {
  cols_ = cols;
  CheckCorrectRowsAndCols();
  for (std::vector<double> row : matrix_) {
    row.resize(cols_);
  }
}

S21Matrix& S21Matrix::Erace(const int row, const int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::invalid_argument("Uncorect row or col");
  }

  for (int index_row = 0; index_row < rows_; ++index_row) {
    matrix_.at(index_row).erase(matrix_.at(index_row).begin() + col);
  }

  matrix_.erase(matrix_.begin() + row);
  --rows_;
  --cols_;
  return *this;
}

void S21Matrix::CheckCorrectRowsAndCols() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("Uncorrect rows or cols");
  }
}
