

#include <algorithm>
#include <iostream>
#include <list>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  //   S21Matrix(const S21Matrix& other);
  //   S21Matrix(S21Matrix&& other);

  int GetRows();
  int GetCols();

  ~S21Matrix() = default;

 private:
  int rows_;
  int cols_;

  std::list<std::list<double>> matrix_;

  void CheckCorrectRowsAndCols();
};
