

#include <algorithm>
#include <cassert>
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

  void Assign(std::vector<double> data);

  bool EqMatrix(const S21Matrix& other);

  void SumMatrix(const S21Matrix& other);
  // void SubMatrix(const S21Matrix& other);
  // void MulNumber(const double num);
  // void MulMatrix(const S21Matrix& other);

  // S21Matrix Transpose();
  // S21Matrix CalcComplements();
  // double Determinant();
  // S21Matrix InverseMatrix();

  int GetRows() const;
  int GetCols() const;

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
