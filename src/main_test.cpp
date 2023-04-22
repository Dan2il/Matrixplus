#include <iostream>
#include <list>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix matrix;

  std::cout << matrix.GetCols() << " " << matrix.GetRows() << std::endl;

  S21Matrix matrix_2(5, 5);

  std::cout << matrix_2.GetCols() << " " << matrix_2.GetRows() << std::endl;

  S21Matrix matrix_3(-3, 5);
}
