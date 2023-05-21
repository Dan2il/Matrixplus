#include "../s21_matrix_oop.h"

double S21Matrix::operator()(const size_t i, const size_t j) {
  return matrix_.at(i).at(j);
}

double S21Matrix::operator()(const size_t i, const size_t j) const {
  return matrix_.at(i).at(j);
}

std::vector<double> S21Matrix::operator[](const size_t num) {
  return matrix_.at(num);
}

const std::vector<double> S21Matrix::operator[](const size_t num) const {
  return matrix_.at(num);
}

void S21Matrix::operator=(const S21Matrix& matrix) {
  if (!(matrix == *this)) {
    SetRows(matrix.GetRows());
    SetCols(matrix.GetCols());
    ForEachMatrix([matrix](int index_row, int index_col) {
      return matrix(index_row, index_col);
    });
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

bool S21Matrix::operator==(const S21Matrix& matrix) { return EqMatrix(matrix); }
bool S21Matrix::operator==(const S21Matrix& matrix) const {
  return EqMatrix(matrix);
}