

#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <optional>

class S21Matrix {
 public:
  S21Matrix();
  explicit S21Matrix(const int rows, const int cols);
  S21Matrix(const S21Matrix& other);
  //   S21Matrix(S21Matrix&& other);

  int GetRows() const;
  int GetCols() const;

  ~S21Matrix() = default;

 private:
  int rows_;
  int cols_;

  std::list<std::list<double>> matrix_;

  void CheckCorrectRowsAndCols();
};
