#include "s21_matrix_oop.h"

S21Matrix::S21Matrix()
    : rows_(1), cols_(1), matrix_(1, std::list<double>(1, 1)) {}

S21Matrix::S21Matrix(const int rows, const int cols)
    : rows_(rows), cols_(cols) {
  CheckCorrectRowsAndCols();
  std::list<std::list<double>> matrix(rows, std::list<double>(cols, 0));
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.GetRows()), cols_(other.GetCols()) {
  std::list<std::list<double>> matrix(rows_, std::list<double>(cols_, 0));
  std::swap(matrix_, matrix);
}

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::CheckCorrectRowsAndCols() {
  if (rows_ <= 0 || cols_ <= 0) {
    std::cerr << "Uncorrect rows or cols" << '\n';
    throw std::invalid_argument("Uncorrect rows or cols");
  }
}