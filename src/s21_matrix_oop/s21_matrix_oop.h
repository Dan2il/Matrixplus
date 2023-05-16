

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <optional>
#include <vector>

class S21Matrix {
 public:
  S21Matrix();
  explicit S21Matrix(const int rows, const int cols);
  S21Matrix(const int rows, const int cols, std::vector<double> data);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  S21Matrix& Assign(const std::vector<double>& data);
  S21Matrix& Assign(const double num);
  S21Matrix& Assign(const size_t index_row, const size_t index_col,
                    const double num);

  S21Matrix& Erace(const int row, const int col);

  bool EqMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other) const;

  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  S21Matrix GetMinorMatrix(const int rows, const int columns);

  int GetRows() const;
  int GetCols() const;

  void SetRows(const int rows);
  void SetCols(const int cols);

  template <typename Function>
  void ForEachMatrix(const S21Matrix& other, Function func);

  template <typename Function>
  void ForEachMatrix(Function func);

  double operator()(const size_t i, const size_t j);
  double operator()(const size_t i, const size_t j) const;

  std::vector<double> operator[](size_t num);
  const std::vector<double> operator[](size_t num) const;

  void operator=(const S21Matrix& matrix);

  S21Matrix operator+(const S21Matrix& matrix);
  S21Matrix operator-(const S21Matrix& matrix);
  void operator+=(const S21Matrix& matrix);
  void operator-=(const S21Matrix& matrix);

  friend S21Matrix operator*(const double num, const S21Matrix& matrix);
  friend S21Matrix operator*(const S21Matrix& matrix, const double num);

  S21Matrix operator*(const S21Matrix& matrix);

  void operator*=(const S21Matrix& matrix);
  void operator*=(const double num);

  bool operator==(const S21Matrix matrix);
  bool operator==(const S21Matrix matrix) const;

  ~S21Matrix() = default;

 private:
  int rows_;
  int cols_;

  std::vector<std::vector<double>> matrix_;

  void CheckCorrectRowsAndCols();
  bool EqSizeMatrix(const S21Matrix& other) const;
};

S21Matrix operator*(const double num, const S21Matrix& matrix);
S21Matrix operator*(const S21Matrix& matrix, const double num);

template <typename Function>
void S21Matrix::ForEachMatrix(const S21Matrix& other, Function func) {
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
    for (size_t index_col = 0; index_col < matrix.at(index_row).size();
         ++index_col) {
      matrix.at(index_row).at(index_col) = func(
          matrix_.at(index_row).at(index_col), other(index_row, index_col));
    }
  }
  std::swap(matrix_, matrix);
}

template <typename Function>
void S21Matrix::ForEachMatrix(Function func) {
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
    for (size_t index_col = 0; index_col < matrix.at(index_row).size();
         ++index_col) {
      matrix.at(index_row).at(index_col) =
          func(matrix_.at(index_row).at(index_col));
    }
  }
  matrix_ = std::move(matrix);
}