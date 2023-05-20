#include "../s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!EqSizeMatrix(other)) {
    throw std::invalid_argument("Different matrix dimensions");
  }
  ForEachMatrix([this, other](int index_row, int index_col) {
    return matrix_.at(index_row).at(index_col) + other(index_row, index_col);
  });
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!EqSizeMatrix(other)) {
    throw std::invalid_argument("Different matrix dimensions");
  }
  ForEachMatrix([this, other](int index_row, int index_col) {
    return matrix_.at(index_row).at(index_col) - other(index_row, index_col);
  });
}

void S21Matrix::MulNumber(const double num) {
  ForEachMatrix([this, num](int index_row, int index_col) {
    return matrix_.at(index_row).at(index_col) * num;
  });
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.GetRows()) {
    std::vector<std::vector<double>> matrix_buf(matrix_);
    cols_ = other.GetCols();
    for (int index_row = 0; index_row < rows_; ++index_row) {
      matrix_.at(index_row).resize(other.GetCols());
    }
    cols_ = other.GetCols();
    ForEachMatrix([this, other, matrix_buf](int index_row, int index_col) {
      double num = 0;
      for (size_t k = 0; k < matrix_buf.at(0).size(); ++k) {
        num += matrix_buf.at(index_row).at(k) * other(k, index_col);
      }
      return num;
    });
    std::cout << "for finish" << std::endl;
  } else {
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the "
        "number of rows of the second matrix");
  }
}