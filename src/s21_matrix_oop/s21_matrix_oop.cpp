#include "s21_matrix_oop.h"

S21Matrix::S21Matrix()
    : rows_(1), cols_(1), matrix_(1, std::list<double>(1, 1)) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  try {
    CheckCorrectRowsAndCols();
    std::list<std::list<double>> matrix(rows, std::list<double>(cols, 0));
    std::swap(matrix_, matrix);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

int S21Matrix::GetRows() { return rows_; }
int S21Matrix::GetCols() { return cols_; }

void S21Matrix::CheckCorrectRowsAndCols() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("Uncorrect rows or cols");
  }
}