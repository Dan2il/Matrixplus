#include "s21_matrix_oop.h"

S21Matrix::S21Matrix()
    : rows_(1), cols_(1), matrix_(1, std::vector<double>(1, 0)) {}

S21Matrix::S21Matrix(const int rows, const int cols)
    : rows_(rows), cols_(cols) {
  CheckCorrectRowsAndCols();
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(const int rows, const int cols, std::vector<double> data)
    : rows_(rows), cols_(cols) {
  CheckCorrectRowsAndCols();
  Assign(data);
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
  int counter_rows = 0;
  int counter_cols = 0;
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
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

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = EqSizeMatrix(other);
  for (int index = 0; index < rows_ && result == true; ++index) {
    result = std::equal(matrix_[index].begin(), matrix_[index].end(),
                        other[index].begin());
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (EqSizeMatrix(other)) {
    for (size_t index_row = 0; index_row < matrix_.size(); ++index_row) {
      for (size_t index_col = 0; index_col < matrix_.at(index_row).size();
           ++index_col) {
        matrix_.at(index_row).at(index_col) += other(index_row, index_col);
      }
    }
  }
}

void S21Matrix::CheckCorrectRowsAndCols() {
  if (rows_ <= 0 || cols_ <= 0) {
    std::cerr << "Uncorrect rows or cols" << '\n';
    throw std::invalid_argument("Uncorrect rows or cols");
  }
}

bool S21Matrix::EqSizeMatrix(const S21Matrix& other) {
  bool result = false;
  if (rows_ == other.GetRows() && cols_ == other.GetCols()) {
    result = true;
  }
  return result;
}

double S21Matrix::operator()(const size_t i, const size_t j) {
  // добавить проверку исключений
  return matrix_.at(i).at(j);
}

double S21Matrix::operator()(const size_t i, const size_t j) const {
  // добавить проверку исключений
  return matrix_.at(i).at(j);
}

std::vector<double> S21Matrix::operator[](size_t num) {
  return matrix_.at(num);
}

const std::vector<double> S21Matrix::operator[](size_t num) const {
  return matrix_.at(num);
}
