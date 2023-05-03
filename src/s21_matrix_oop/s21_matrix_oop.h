

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
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

  template <typename Function>
  void ForEachMatrix(const S21Matrix& other, Function func);

  template <typename Function>
  void ForEachMatrix(Function func);

  double operator()(const size_t i, const size_t j);
  double operator()(const size_t i, const size_t j) const;

  std::vector<double> operator[](size_t num);
  const std::vector<double> operator[](size_t num) const;

  ~S21Matrix() = default;

 private:
  int rows_;
  int cols_;

  std::vector<std::vector<double>> matrix_;

  void CheckCorrectRowsAndCols();
  bool EqSizeMatrix(const S21Matrix& other);
};
