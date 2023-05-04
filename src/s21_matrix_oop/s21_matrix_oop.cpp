#include "s21_matrix_oop.h"

S21Matrix::S21Matrix()
    : rows_(1), cols_(1), matrix_(1, std::vector<double>(1, 0)) {}

S21Matrix::S21Matrix(const int rows, const int cols)
    : rows_(rows), cols_(cols) {
  CheckCorrectRowsAndCols();
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(const int rows, const int cols, std::vector<double> data)
    : rows_(rows), cols_(cols) {
  CheckCorrectRowsAndCols();
  Assign(data);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.GetRows()),
      cols_(other.GetCols()),
      matrix_(rows_, std::vector<double>(cols_, 0)) {
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  std::copy(other.matrix_.begin(), other.matrix_.end(), matrix.begin());
  std::swap(matrix_, matrix);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.GetRows()),
      cols_(other.GetCols()),
      matrix_(std::move(other.matrix_)) {}

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

S21Matrix& S21Matrix::Assign(const std::vector<double>& data) {
  if (!data.empty()) {
    int counter_rows = 0;
    int counter_cols = 0;
    std::vector<std::vector<double>> matrix(rows_,
                                            std::vector<double>(cols_, 0));
    for (double num : data) {
      matrix.at(counter_rows).at(counter_cols++) = num;
      if (counter_cols == cols_) {
        counter_cols = 0;
        counter_rows++;
      }
      if (counter_rows >= rows_) {
        break;
      }
    }
    std::swap(matrix_, matrix);
  }
  return *this;
}

S21Matrix& S21Matrix::Assign(const double num) {
  std::vector<std::vector<double>> matrix(rows_, std::vector<double>(cols_, 0));
  for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
    for (size_t index_col = 0; index_col < matrix.at(index_row).size();
         ++index_col) {
      matrix.at(index_row).at(index_col) = num;
    }
  }
  std::swap(matrix_, matrix);
  return *this;
}

S21Matrix& S21Matrix::Assign(const size_t index_row, const size_t index_col,
                             const double num) {
  matrix_.at(index_row).at(index_col) = num;
  return *this;
}

S21Matrix& S21Matrix::Erace(const int row, const int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::invalid_argument("Uncorect row or col");
  }

  for (int index_row = 0; index_row < rows_; ++index_row) {
    matrix_.at(index_row).erase(matrix_.at(index_row).begin() + col);
  }

  matrix_.erase(matrix_.begin() + row);
  --rows_;
  --cols_;
  return *this;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = EqSizeMatrix(other);
  for (int index = 0; index < rows_ && result == true; ++index) {
    result = std::equal(matrix_[index].begin(), matrix_[index].end(),
                        other[index].begin(), [](double left, double right) {
                          return std::fabs(std::fabs(left) - std::fabs(right)) <
                                 1e-6;
                        });
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (EqSizeMatrix(other)) {
    ForEachMatrix(other, [](double n1, double n2) { return n1 + n2; });
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (EqSizeMatrix(other)) {
    ForEachMatrix(other, [](double n1, double n2) { return n1 - n2; });
  }
}

void S21Matrix::MulNumber(const double num) {
  ForEachMatrix([num](double n1) { return n1 * num; });
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.GetRows()) {
    std::vector<std::vector<double>> matrix(
        rows_, std::vector<double>(other.GetCols(), 0));
    for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
      for (size_t index_col = 0; index_col < matrix.at(index_row).size();
           ++index_col) {
        double num = 0;
        for (int k = 0; k < cols_; ++k) {
          num += matrix_.at(index_row).at(k) * other(k, index_col);
        }
        matrix.at(index_row).at(index_col) = num;
      }
    }
    cols_ = other.GetCols();
    for (size_t index_row = 0; index_row < matrix.size(); ++index_row) {
      matrix_.at(index_row).resize(other.GetCols());
    }
    matrix_ = std::move(matrix);
    cols_ = other.GetCols();

  } else {
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the "
        "number "
        "of rows of the second matrix");
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (size_t index_row = 0; index_row < matrix_.size(); ++index_row) {
    for (size_t index_col = 0; index_col < matrix_.at(index_row).size();
         ++index_col) {
      result.Assign(index_col, index_row, matrix_.at(index_row).at(index_col));
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (cols_ != rows_) {
    throw std::invalid_argument("The matrix is not square");
  } else if (rows_ == 1) {
    result = matrix_.at(0).at(0);
  } else if (rows_ == 2) {
    result = matrix_.at(0).at(0) * matrix_.at(1).at(1) -
             matrix_.at(0).at(1) * matrix_.at(1).at(0);
  } else {
    int degree = 1;
    for (int counter_columns = 0; counter_columns < cols_; ++counter_columns) {
      S21Matrix rec_matrix = GetMinorMatrix(0, counter_columns);
      double recursion_result = rec_matrix.Determinant();
      result += degree * matrix_.at(0).at(counter_columns) * recursion_result;
      degree = -degree;
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }
  S21Matrix buffer_result(rows_, cols_);
  if (rows_ == 1) {
    buffer_result.Assign(matrix_.at(0).at(0));
  } else {
    for (size_t index_row = 0; index_row < matrix_.size(); ++index_row) {
      for (size_t index_col = 0; index_col < matrix_.at(index_row).size();
           ++index_col) {
        S21Matrix minor = GetMinorMatrix(index_row, index_col);
        double determinant = minor.Determinant();
        buffer_result.Assign(
            index_row, index_col,
            determinant * std::pow(-1, index_row + 1 + index_col + 1));
      }
    }
  }
  return buffer_result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (!determinant) {
    throw std::invalid_argument("Matrix determinant is 0");
  }
  S21Matrix result;
  // if (rows_ == 1) {
  //   result.Assign(1 / matrix_.at(0).at(0));
  // } else {
  S21Matrix calc_complements = CalcComplements();
  S21Matrix transpose = calc_complements.Transpose();
  transpose.MulNumber(1.00 / determinant);
  // }
  return transpose;
}

S21Matrix S21Matrix::GetMinorMatrix(const int rows, const int columns) {
  if (rows < 0 || columns < 0 || rows >= rows_ || columns >= cols_) {
    throw std::invalid_argument("Uncorect row or col");
  }
  return S21Matrix(*this).Erace(rows, columns);
}

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

void S21Matrix::CheckCorrectRowsAndCols() {
  if (rows_ <= 0 || cols_ <= 0) {
    std::cerr << "Uncorrect rows or cols" << '\n';
    throw std::invalid_argument("Uncorrect rows or cols");
  }
}

bool S21Matrix::EqSizeMatrix(const S21Matrix& other) {
  bool result = false;
  if (rows_ == other.GetRows() && cols_ == other.GetCols()) {
    result = true;
  }
  return result;
}

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
