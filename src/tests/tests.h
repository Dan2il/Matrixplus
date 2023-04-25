#include <gtest/gtest.h>

#include "../s21_matrix_oop/s21_matrix_oop.h"

void CreateMatrix(int rows, int cols);

void CheckMatrix(double num, S21Matrix& matrix);
void CheckMatrixRange(std::vector<double> nums, S21Matrix& matrix);
