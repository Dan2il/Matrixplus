#include "../s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!EqSizeMatrix(other)) {
    throw std::invalid_argument("Different matrix dimensions");
  }
  ForEachMatrix(other, [](double n1, double n2) { return n1 + n2; });
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!EqSizeMatrix(other)) {
    throw std::invalid_argument("Different matrix dimensions");
  }
  ForEachMatrix(other, [](double n1, double n2) { return n1 - n2; });
}

void S21Matrix::MulNumber(const double num) {
  ForEachMatrix([num](double n1) { return n1 * num; });
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.GetRows()) {
    std::vector<std::vector<double>> matrix(
        rows_, std::vector<double>(other.GetCols(), 0));
    for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
      for (size_t index_col = 0; index_col < matrix.at(index_row).size();
           ++index_col) {
        double num = 0;
        for (int k = 0; k < cols_; ++k) {
          num += matrix_.at(index_row).at(k) * other(k, index_col);
        }
        matrix.at(index_row).at(index_col) = num;
      }
    }
    cols_ = other.GetCols();
    for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
      matrix_.at(index_row).resize(other.GetCols());
    }
    matrix_ = std::move(matrix);
    cols_ = other.GetCols();

  } else {
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the "
        "number "
        "of rows of the second matrix");
  }
}