#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1) {}

S21Matrix::S21Matrix(const int rows, const int cols)
    : rows_(rows), cols_(cols) {
  CheckCorrectRowsAndCols();
  std::vector<std::vector<double>> matrix;
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.GetRows()),
      cols_(other.GetCols()),
      matrix_(rows_, std::vector<double>(cols_, 0)) {
  std::vector<std::vector<double>> matrix;
  matrix.resize(rows_);
  std::copy(other.matrix_.begin(), other.matrix_.end(), matrix.begin());
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.GetRows()),
      cols_(other.GetCols()),
      matrix_(std::move(other.matrix_)) {}

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::CheckCorrectRowsAndCols() {
  if (rows_ <= 0 || cols_ <= 0) {
    std::cerr << "Uncorrect rows or cols" << '\n';
    throw std::invalid_argument("Uncorrect rows or cols");
  }
}

double S21Matrix::operator()(const size_t i, const size_t j) {
  // добавить проверку исключений
  return matrix_.at(i).at(j);
}