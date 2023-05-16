#include "../s21_matrix_oop.h"

double S21Matrix::operator()(const size_t i, const size_t j) {
  return matrix_.at(i).at(j);
}

double S21Matrix::operator()(const size_t i, const size_t j) const {
  return matrix_.at(i).at(j);
}

std::vector<double> S21Matrix::operator[](size_t num) {
  return matrix_.at(num);
}

const std::vector<double> S21Matrix::operator[](size_t num) const {
  return matrix_.at(num);
}

void S21Matrix::operator=(const S21Matrix& matrix) {
  if (!(matrix == *this)) {
    SetRows(matrix.GetRows());
    SetCols(matrix.GetCols());

    for (size_t index_row = 0; index_row < matrix_.size(); ++index_row) {
      for (size_t index_col = 0; index_col < matrix_.at(index_row).size();
           ++index_col) {
        matrix_.at(index_row).at(index_col) = matrix(index_row, index_col);
      }
    }
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix& matrix) {
  S21Matrix result(*this);
  result.SumMatrix(matrix);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& matrix) {
  S21Matrix result(*this);
  result.SubMatrix(matrix);
  return result;
}

void S21Matrix::operator+=(const S21Matrix& matrix) { SumMatrix(matrix); }

void S21Matrix::operator-=(const S21Matrix& matrix) { SubMatrix(matrix); }

S21Matrix operator*(const double num, const S21Matrix& matrix) {
  S21Matrix result(matrix);
  result.MulNumber(num);
  return result;
}
S21Matrix operator*(const S21Matrix& matrix, const double num) {
  S21Matrix result = num * matrix;
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& matrix) {
  S21Matrix result(*this);
  result.MulMatrix(matrix);
  return result;
}

void S21Matrix::operator*=(const S21Matrix& matrix) { MulMatrix(matrix); }

void S21Matrix::operator*=(const double num) { MulNumber(num); }

bool S21Matrix::operator==(const S21Matrix matrix) { return EqMatrix(matrix); }
bool S21Matrix::operator==(const S21Matrix matrix) const {
  return EqMatrix(matrix);
}