#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (size_t index_row = 0; index_row < matrix_.size(); ++index_row) {
    for (size_t index_col = 0; index_col < matrix_.at(index_row).size();
         ++index_col) {
      result.Assign(index_col, index_row, matrix_.at(index_row).at(index_col));
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (cols_ != rows_) {
    throw std::invalid_argument("The matrix is not square");
  } else if (rows_ == 1) {
    result = matrix_.at(0).at(0);
  } else if (rows_ == 2) {
    result = matrix_.at(0).at(0) * matrix_.at(1).at(1) -
             matrix_.at(0).at(1) * matrix_.at(1).at(0);
  } else {
    int degree = 1;
    for (int counter_columns = 0; counter_columns < cols_; ++counter_columns) {
      S21Matrix rec_matrix = GetMinorMatrix(0, counter_columns);
      double recursion_result = rec_matrix.Determinant();
      result += degree * matrix_.at(0).at(counter_columns) * recursion_result;
      degree = -degree;
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }
  S21Matrix buffer_result(rows_, cols_);
  if (rows_ == 1) {
    buffer_result.Assign(matrix_.at(0).at(0));
  } else {
    for (size_t index_row = 0; index_row < matrix_.size(); ++index_row) {
      for (size_t index_col = 0; index_col < matrix_.at(index_row).size();
           ++index_col) {
        S21Matrix minor = GetMinorMatrix(index_row, index_col);
        double determinant = minor.Determinant();
        buffer_result.Assign(
            index_row, index_col,
            determinant * std::pow(-1, index_row + 1 + index_col + 1));
      }
    }
  }
  return buffer_result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (!determinant) {
    throw std::invalid_argument("Matrix determinant is 0");
  }
  S21Matrix calc_complements = CalcComplements();
  S21Matrix transpose = calc_complements.Transpose();
  if (rows_ == 1) {
    transpose.Assign(1.00 / matrix_.at(0).at(0));
  } else {
    transpose.MulNumber(1.00 / determinant);
  }
  return transpose;
}

S21Matrix S21Matrix::GetMinorMatrix(const int rows, const int columns) {
  if (rows < 0 || columns < 0 || rows >= rows_ || columns >= cols_) {
    throw std::invalid_argument("Uncorect row or col");
  }
  return S21Matrix(*this).Erace(rows, columns);
}