#include "s21_matrix_oop.h"

// S21Matrix::MatrixIterator::MatrixIterator(double* point) : it_(point) {}

// S21Matrix::MatrixIterator::MatrixIterator(std::vector<double>::iterator it)
//     : it_(it) {}

// S21Matrix::MatrixIterator S21Matrix::MatrixIterator::operator++() {
//   auto result = it_++;

//   return result;
// }

// S21Matrix::MatrixIterator S21Matrix::MatrixIterator::operator++(int counter)
// {
//   return ++it_;
// }

// S21Matrix::MatrixIterator S21Matrix::begin() {
//   return (*matrix_.begin()).begin();
// }
// S21Matrix::MatrixIterator S21Matrix::end() {
//   return (*matrix_.begin()).begin() + matrix_.size();
// }

S21Matrix::S21Matrix() : rows_(1), cols_(1) {}

S21Matrix::S21Matrix(const int rows, const int cols)
    : rows_(rows), cols_(cols) {
  CheckCorrectRowsAndCols();
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.GetRows()),
      cols_(other.GetCols()),
      matrix_(rows_, std::vector<double>(cols_, 0)) {
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  std::copy(other.matrix_.begin(), other.matrix_.end(), matrix.begin());
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.GetRows()),
      cols_(other.GetCols()),
      matrix_(std::move(other.matrix_)) {}

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::Assign(std::vector<double> data) {
  int counter_cols = 0;
  auto it_data = data.begin();
  for (auto row = matrix_.begin(); row != matrix_.end(); row++) {
    for (auto it = (*row).begin(); it != (*row).end(); it++) {
      if (it_data != data.end()) {
        it = it_data;
      } else {
        break;
      }
      it_data++;
    }
  }
}

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