

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <vector>

class S21Matrix {
 public:
  // class MatrixIterator {
  //  public:
  //   MatrixIterator(double* point);
  //   MatrixIterator(std::vector<double>::iterator it);

  //   MatrixIterator operator++();
  //   MatrixIterator operator++(int counter);

  //   // MatrixIterator operator*();
  //   // MatrixIterator operator->();

  //   MatrixIterator begin();
  //   MatrixIterator end();

  //  private:
  //   std::vector<double>::iterator it_;
  // };

  double operator()(const size_t i, const size_t j);

  S21Matrix();
  explicit S21Matrix(const int rows, const int cols);
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
