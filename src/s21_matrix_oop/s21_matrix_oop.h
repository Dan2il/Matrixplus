

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <vector>

class S21Matrix {
 public:
  double operator()(const size_t i, const size_t j);

  S21Matrix();
  explicit S21Matrix(const int rows, const int cols);
  S21Matrix(const int rows, const int cols, std::vector<double> data);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  void Assign(std::vector<double> data);

  int GetRows() const;
  int GetCols() const;

  ~S21Matrix() = default;

 private:
  int rows_;
  int cols_;

  std::vector<std::vector<double>> matrix_;

  void CheckCorrectRowsAndCols();
};
