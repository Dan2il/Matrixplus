

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
  S21Matrix(const int rows, const int cols, const std::vector<double>& data);
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

  void SetRows(const size_t rows);
  void SetCols(const size_t cols);

  template <typename Function>
  void ForEachMatrix(Function func);

  double operator()(const size_t i, const size_t j);
  double operator()(const size_t i, const size_t j) const;

  std::vector<double> operator[](const size_t num);
  const std::vector<double> operator[](const size_t num) const;

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

  bool operator==(const S21Matrix& matrix);
  bool operator==(const S21Matrix& matrix) const;

  ~S21Matrix() = default;

 private:
  int rows_;
  int cols_;

  std::vector<std::vector<double>> matrix_;

  void CheckCorrectRowsAndCols();
  bool EqSizeMatrix(const S21Matrix& other) const;

  bool CheckBreakCols(const S21Matrix& matrix, const int index_col_begin,
                      const int index_col_end);
};
S21Matrix operator*(const double num, const S21Matrix& matrix);
S21Matrix operator*(const S21Matrix& matrix, const double num);

template <typename Function>
void S21Matrix::ForEachMatrix(Function func) {
  S21Matrix mat(rows_, cols_);

  struct Indexs {
    int col_begin;
    int col_end;
    Indexs operator++() { return Indexs{++col_begin, --col_end}; }
  };

  for (int index_row = 0; index_row < mat.GetRows(); ++index_row) {
    Indexs indexs = {0, mat.GetCols() - 1};
    while (!CheckBreakCols(mat, indexs.col_begin, indexs.col_end)) {
      mat.Assign(index_row, indexs.col_begin,
                 func(index_row, indexs.col_begin));
      mat.Assign(index_row, indexs.col_end, func(index_row, indexs.col_end));
      ++indexs;
    }
    if (indexs.col_begin == indexs.col_end) {
      mat.Assign(index_row, indexs.col_begin,
                 func(index_row, indexs.col_begin));
    }
  }
  std::swap(matrix_, mat.matrix_);
}