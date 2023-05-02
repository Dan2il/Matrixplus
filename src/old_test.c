#include <check.h>
#include <limits.h>
#include <time.h>

#include "s21_matrix.h"

double test_mass[10] = {1,     -1,      0,         0.000001, 0.00000001,
                        10000, 1000000, 1234.5678, 1234567,  12345678};

// ------------------------ GetMinorMatrix ------------------------

// ------------------------ s21_create_matrix ------------------------

START_TEST(s21_create_matrix_test_1) {
  matrix_t result;
  int check_errors = s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(check_errors, 0);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  matrix_t result;
  int check_errors = s21_create_matrix(100, 100, &result);
  ck_assert_int_eq(check_errors, NO_ERRORS);
  ck_assert_int_eq(result.rows, 100);
  ck_assert_int_eq(result.columns, 100);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  matrix_t result;
  int check_errors = s21_create_matrix(INT_MAX, 0, &result);
  ck_assert_int_eq(check_errors, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  matrix_t result;
  int check_errors = s21_create_matrix(-5, 5, &result);
  ck_assert_int_eq(check_errors, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  matrix_t result;
  int check_errors = s21_create_matrix(6, -5, &result);
  ck_assert_int_eq(check_errors, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  matrix_t result;
  int check_errors = s21_create_matrix(-7, -3, &result);
  ck_assert_int_eq(check_errors, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  matrix_t result;
  int check_errors = s21_create_matrix(+0, -3, &result);
  ck_assert_int_eq(check_errors, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_8) {
  int rows = -10;
  int columns = 10;
  matrix_t matrix = {0};
  int code = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(code, 1);

  if (code == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_9) {
  matrix_t *R = NULL;
  int res = s21_create_matrix(1, 2, R);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_create_matrix_test_10) {
  int rows = 100;
  int columns = 100;
  matrix_t matrix = {0};
  int code = s21_create_matrix(rows, columns, &matrix);
  if (code == 0) {
    s21_remove_matrix(&matrix);
    ck_assert_ptr_null(matrix.matrix);
    ck_assert_int_eq(matrix.rows, 0);
    ck_assert_int_eq(matrix.columns, 0);
  }
}
END_TEST

START_TEST(s21_create_matrix_test_11) {
  matrix_t *matrix = NULL;
  s21_remove_matrix(matrix);
}
END_TEST

// ------------------------ s21_eq_matrix ------------------------

// ------------------------ s21_sum_matrix ------------------------

// ------------------------ s21_sub_matrix ------------------------

// ------------------------ s21_mult_number ------------------------

// ------------------------ s21_mult_matrix ------------------------

// ------------------------ s21_transpose ------------------------

// ------------------------ s21_calc_complements ------------------------

START_TEST(s21_calc_complements_test_1) {
  matrix_t matrix;
  int error_type = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(error_type, NO_ERRORS);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;

  matrix.matrix[1][0] = 0;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 2;

  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 1;
  matrix_t result;
  error_type = s21_calc_complements(&matrix, &result);
  ck_assert_int_eq(error_type, NO_ERRORS);

  matrix_t answer;
  error_type = s21_create_matrix(3, 3, &answer);
  ck_assert_int_eq(error_type, NO_ERRORS);

  answer.matrix[0][0] = 0;
  answer.matrix[0][1] = 10;
  answer.matrix[0][2] = -20;

  answer.matrix[1][0] = 4;
  answer.matrix[1][1] = -14;
  answer.matrix[1][2] = 8;

  answer.matrix[2][0] = -8;
  answer.matrix[2][1] = -2;
  answer.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&answer);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t matrix;
  int error_type = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(error_type, NO_ERRORS);
  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 5;
  matrix.matrix[0][2] = 7;

  matrix.matrix[1][0] = 6;
  matrix.matrix[1][1] = 3;
  matrix.matrix[1][2] = 4;

  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -3;
  matrix_t result;
  error_type = s21_calc_complements(&matrix, &result);
  ck_assert_int_eq(error_type, NO_ERRORS);

  matrix_t answer;
  error_type = s21_create_matrix(3, 3, &answer);
  ck_assert_int_eq(error_type, NO_ERRORS);

  answer.matrix[0][0] = -1;
  answer.matrix[0][1] = 38;
  answer.matrix[0][2] = -27;

  answer.matrix[1][0] = 1;
  answer.matrix[1][1] = -41;
  answer.matrix[1][2] = 29;

  answer.matrix[2][0] = -1;
  answer.matrix[2][1] = 34;
  answer.matrix[2][2] = -24;
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&answer);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 3, &result);
  matrix_t m;
  result.matrix[0][0] = 0;
  result.matrix[0][1] = 10;
  result.matrix[0][2] = -20;
  result.matrix[1][0] = 4;
  result.matrix[1][1] = -14;
  result.matrix[1][2] = 8;
  result.matrix[2][0] = -8;
  result.matrix[2][1] = -2;
  result.matrix[2][2] = 4;

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;
  s21_calc_complements(&a, &m);
  ck_assert_int_eq(s21_eq_matrix(&result, &m), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[0][2] = -20.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  C.matrix[1][2] = 8.0;
  C.matrix[2][0] = -8.0;
  C.matrix[2][1] = -2.0;
  C.matrix[2][2] = 4.0;
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  ck_assert_int_eq(s21_calc_complements(&A, &B), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_test_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  ck_assert_int_eq(s21_calc_complements(&A, &B), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_7) {
  const int size = 3;
  matrix_t val1;
  s21_create_matrix(size, size, &val1);
  val1.matrix[0][0] = 1;
  val1.matrix[0][1] = 2;
  val1.matrix[0][2] = 3;

  val1.matrix[1][0] = 0;
  val1.matrix[1][1] = 4;
  val1.matrix[1][2] = 2;

  val1.matrix[2][0] = 5;
  val1.matrix[2][1] = 2;
  val1.matrix[2][2] = 1;

  matrix_t expected;
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;

  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;

  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;

  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&val1, &result), NO_ERRORS);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&val1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_calc_complements_test_8) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &A);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 4;
  B.matrix[1][2] = 2;
  B.matrix[2][0] = 5;
  B.matrix[2][1] = 2;
  B.matrix[2][2] = 1;

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 10;
  A.matrix[0][2] = -20;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -14;
  A.matrix[1][2] = 8;
  A.matrix[2][0] = -8;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = 4;

  int code = s21_calc_complements(&B, &R);
  ck_assert_int_eq(s21_eq_matrix(&R, &A), SUCCESS);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_9) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;

  s21_calc_complements(&A, &R);

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[0][2] = -3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 14;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -7;
  B.matrix[2][1] = -18;
  B.matrix[2][2] = 17;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_calc_complements_test_10) {
  matrix_t B, R;
  s21_create_matrix(2, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 4;
  B.matrix[1][2] = 2;

  int code = s21_calc_complements(&B, &R);

  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_11) {
  matrix_t A, B, R;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 5;

  s21_calc_complements(&A, &R);

  B.matrix[0][0] = 5;
  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_calc_complements_test_12) {
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = s21_calc_complements(B, R);
  ck_assert_int_eq(res, 1);
}
END_TEST

// ------------------------ s21_determinant ------------------------

START_TEST(s21_determinant_test_1) {
  matrix_t matrix;
  int error_type = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(error_type, NO_ERRORS);
  int i = 0;
  CYCLE_FOR_MATRIX(matrix.rows, matrix.columns,
                   { matrix.matrix[counter_rows][counter_columns] = ++i; })
  double result = 0;
  error_type = s21_determinant(&matrix, &result);
  ck_assert_int_eq(error_type, NO_ERRORS);
  ck_assert_double_eq(result, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t matrix;
  int error_type = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(error_type, NO_ERRORS);

  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 5;
  matrix.matrix[0][2] = 7;

  matrix.matrix[1][0] = 6;
  matrix.matrix[1][1] = 3;
  matrix.matrix[1][2] = 4;

  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -3;

  double result = 0;
  error_type = s21_determinant(&matrix, &result);
  ck_assert_int_eq(error_type, NO_ERRORS);
  ck_assert_double_eq(result, -1);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  int size = 5;
  matrix_t val1 = {0};
  s21_create_matrix(size, size, &val1);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      val1.matrix[i][j] = j;
    }
  }
  double result = 0;
  ck_assert_int_eq(s21_determinant(&val1, &result), NO_ERRORS);
  ck_assert_double_eq_tol(result, 0, 1e-6);

  s21_remove_matrix(&val1);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  int size = 4;
  matrix_t val1 = {0};
  s21_create_matrix(size, size, &val1);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      val1.matrix[i][j] = j + i;
    }
  }
  double result = 0;
  ck_assert_int_eq(s21_determinant(&val1, &result), NO_ERRORS);
  ck_assert_double_eq_tol(result, 0, 1e-6);

  s21_remove_matrix(&val1);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  int size = 5;
  matrix_t val1 = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(size, size, &val1);

  val1.matrix[0][0] = 6;
  val1.matrix[0][1] = -2;
  val1.matrix[0][2] = -1;
  val1.matrix[0][3] = 5;
  val1.matrix[0][4] = 667;

  val1.matrix[1][0] = 3;
  val1.matrix[1][1] = -5;
  val1.matrix[1][2] = -9;
  val1.matrix[1][3] = -7;
  val1.matrix[1][4] = 7;

  val1.matrix[2][0] = 15;
  val1.matrix[2][1] = 35;
  val1.matrix[2][2] = 0;
  val1.matrix[2][3] = 0;
  val1.matrix[2][4] = -4;

  val1.matrix[3][0] = 0;
  val1.matrix[3][1] = -1;
  val1.matrix[3][2] = -11;
  val1.matrix[3][3] = -2;
  val1.matrix[3][4] = -1;

  val1.matrix[4][0] = -2;
  val1.matrix[4][1] = -2;
  val1.matrix[4][2] = 3;
  val1.matrix[4][3] = 0;
  val1.matrix[4][4] = -2;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&val1, &result), NO_ERRORS);
  ck_assert_double_eq_tol(result, 2028624, 1e-6);

  s21_remove_matrix(&val1);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  const int size = 3;
  matrix_t val1 = {0};
  s21_create_matrix(size, size, &val1);
  val1.matrix[0][0] = 2;
  val1.matrix[0][1] = 3;
  val1.matrix[0][2] = 1;
  val1.matrix[1][0] = 7;
  val1.matrix[1][1] = 4;
  val1.matrix[1][2] = 1;
  val1.matrix[2][0] = 9;
  val1.matrix[2][1] = -2;
  val1.matrix[2][2] = 1;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&val1, &result), NO_ERRORS);
  ck_assert_double_eq_tol(result, -32, 1e-6);

  s21_remove_matrix(&val1);
}
END_TEST

START_TEST(s21_determinant_test_7) {
  const int size = 2;
  matrix_t val1 = {0};
  s21_create_matrix(size, size, &val1);
  val1.matrix[0][0] = -5;
  val1.matrix[0][1] = -4;
  val1.matrix[1][0] = -2;
  val1.matrix[1][1] = -3;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&val1, &result), NO_ERRORS);
  ck_assert_double_eq_tol(result, 7, 1e-6);

  s21_remove_matrix(&val1);
}
END_TEST

START_TEST(s21_determinant_test_8) {
  const int size = 8;
  matrix_t val1 = {0};
  s21_create_matrix(size, size, &val1);
  val1.matrix[0][0] = 2;
  val1.matrix[0][1] = 8;
  val1.matrix[0][2] = 7;
  val1.matrix[0][3] = 4;
  val1.matrix[0][4] = 1;
  val1.matrix[0][5] = 8;
  val1.matrix[0][6] = 3;
  val1.matrix[0][7] = 9;
  val1.matrix[1][0] = 4;
  val1.matrix[1][1] = 2;
  val1.matrix[1][2] = 6;
  val1.matrix[1][3] = 2;
  val1.matrix[1][4] = 2;
  val1.matrix[1][5] = 1;
  val1.matrix[1][6] = 5;
  val1.matrix[1][7] = 8;
  val1.matrix[2][0] = 8;
  val1.matrix[2][1] = 6;
  val1.matrix[2][2] = 7;
  val1.matrix[2][3] = 7;
  val1.matrix[2][4] = 3;
  val1.matrix[2][5] = 4;
  val1.matrix[2][6] = 4;
  val1.matrix[2][7] = 1;
  val1.matrix[3][0] = 1;
  val1.matrix[3][1] = 7;
  val1.matrix[3][2] = 0;
  val1.matrix[3][3] = 4;
  val1.matrix[3][4] = 4;
  val1.matrix[3][5] = 3;
  val1.matrix[3][6] = 0;
  val1.matrix[3][7] = 5;
  val1.matrix[4][0] = 5;
  val1.matrix[4][1] = 7;
  val1.matrix[4][2] = 5;
  val1.matrix[4][3] = 6;
  val1.matrix[4][4] = 8;
  val1.matrix[4][5] = 3;
  val1.matrix[4][6] = 1;
  val1.matrix[4][7] = 9;
  val1.matrix[5][0] = 3;
  val1.matrix[5][1] = 7;
  val1.matrix[5][2] = 8;
  val1.matrix[5][3] = 0;
  val1.matrix[5][4] = 5;
  val1.matrix[5][5] = 7;
  val1.matrix[5][6] = 0;
  val1.matrix[5][7] = 2;
  val1.matrix[6][0] = 5;
  val1.matrix[6][1] = 8;
  val1.matrix[6][2] = 3;
  val1.matrix[6][3] = 5;
  val1.matrix[6][4] = 9;
  val1.matrix[6][5] = 1;
  val1.matrix[6][6] = 2;
  val1.matrix[6][7] = 0;
  val1.matrix[7][0] = 7;
  val1.matrix[7][1] = 8;
  val1.matrix[7][2] = 7;
  val1.matrix[7][3] = 4;
  val1.matrix[7][4] = 7;
  val1.matrix[7][5] = 9;
  val1.matrix[7][6] = 1;
  val1.matrix[7][7] = 5;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&val1, &result), NO_ERRORS);
  ck_assert_double_eq_tol(result, -616458, 1e-6);

  s21_remove_matrix(&val1);
}
END_TEST

START_TEST(s21_determinant_test_9) {
  matrix_t source;
  double determinant = 0;

  int error_type = s21_create_matrix(1, 1, &source);
  ck_assert_int_eq(error_type, NO_ERRORS);

  source.matrix[0][0] = 678.345453;

  error_type = s21_determinant(&source, &determinant);
  ck_assert_int_eq(error_type, NO_ERRORS);
  ck_assert_ldouble_eq_tol(determinant, 678.345453, E8);
  s21_remove_matrix(&source);
}
END_TEST

START_TEST(s21_determinant_test_10) {
  matrix_t source = {.rows = 3, .columns = 3, .matrix = NULL};
  double determinant = 0;
  int error_type = s21_determinant(&source, &determinant);
  ck_assert_int_eq(error_type, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_test_11) {
  matrix_t A;
  double B, R = 1.25;
  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 1.25;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_12) {
  matrix_t A;
  double B, R = -69;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_13) {
  matrix_t A;
  double B, R = -2;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = -5;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_14) {
  matrix_t A;
  double B, R = 25;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_15) {
  matrix_t A;
  double B, R = 23;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_16) {
  matrix_t A;
  double B, R = -8;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = -7;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 5;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_17) {
  matrix_t A;
  double B, R = 18;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -5;
  A.matrix[0][3] = 8;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = -6;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = -5;
  A.matrix[2][2] = -7;
  A.matrix[2][3] = 5;
  A.matrix[3][0] = -4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = -6;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_18) {
  matrix_t A;
  double B, R = -69.0 / 4.0;
  s21_create_matrix(5, 5, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[0][3] = 3.25;
  A.matrix[0][4] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[1][3] = 5.25;
  A.matrix[1][4] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  A.matrix[2][3] = 6.25;
  A.matrix[2][4] = 6.25;
  A.matrix[3][0] = 6.25;
  A.matrix[3][1] = 7.25;
  A.matrix[3][2] = 8.25;
  A.matrix[3][3] = 6.25;
  A.matrix[3][4] = 7.25;
  A.matrix[4][0] = 6.25;
  A.matrix[4][1] = 7.25;
  A.matrix[4][2] = 8.25;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8.25;

  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_19) {
  matrix_t A;
  double B;
  s21_create_matrix(4, 5, &A);
  int res = s21_determinant(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_20) {
  matrix_t a;
  double number;
  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[0][3] = 13;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[1][3] = 16;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 90;
  a.matrix[2][3] = 19;
  a.matrix[3][0] = 1;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = 7;
  a.matrix[3][3] = 17;

  s21_determinant(&a, &number);
  ck_assert_int_eq(number, 13608);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test_21) {
  matrix_t *B = NULL;
  double re = 0;
  int res = s21_determinant(B, &re);
  ck_assert_int_eq(res, 1);
}
END_TEST

// ------------------------ s21_inverse_matrix ------------------------

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t val1 = {0}, result = {0}, expected = {0};
  int size = 3;
  s21_create_matrix(size, size, &val1);
  s21_create_matrix(size, size, &expected);

  val1.matrix[0][0] = 3;
  val1.matrix[0][1] = 27;
  val1.matrix[0][2] = 18;
  val1.matrix[1][0] = 0;
  val1.matrix[1][1] = 18;
  val1.matrix[1][2] = 15;
  val1.matrix[2][0] = 24;
  val1.matrix[2][1] = 9;
  val1.matrix[2][2] = 9;

  expected.matrix[0][0] = 0.01333333333;
  expected.matrix[0][1] = -0.04;
  expected.matrix[0][2] = 0.04;
  expected.matrix[1][0] = 0.1777777778;
  expected.matrix[1][1] = -0.2;
  expected.matrix[1][2] = -0.02222222222;
  expected.matrix[2][0] = -0.2133333333;
  expected.matrix[2][1] = 0.3066666667;
  expected.matrix[2][2] = 0.02666666667;

  ck_assert_int_eq(s21_inverse_matrix(&val1, &result), NO_ERRORS);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&val1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t val1 = {0}, result = {0}, expected = {0};
  int size = 3;
  s21_create_matrix(size, size, &val1);
  s21_create_matrix(size, size, &expected);

  val1.matrix[0][0] = 4;
  val1.matrix[0][1] = 6;
  val1.matrix[0][2] = 8;
  val1.matrix[1][0] = 9;
  val1.matrix[1][1] = 2;
  val1.matrix[1][2] = 7;
  val1.matrix[2][0] = 9;
  val1.matrix[2][1] = 1;
  val1.matrix[2][2] = 0;

  expected.matrix[0][0] = -0.02517985612;
  expected.matrix[0][1] = 0.02877697842;
  expected.matrix[0][2] = 0.09352517986;
  expected.matrix[1][0] = 0.226618705;
  expected.matrix[1][1] = -0.2589928058;
  expected.matrix[1][2] = 0.1582733813;
  expected.matrix[2][0] = -0.03237410072;
  expected.matrix[2][1] = 0.1798561151;
  expected.matrix[2][2] = -0.1654676259;

  ck_assert_int_eq(s21_inverse_matrix(&val1, &result), NO_ERRORS);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&val1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t val1 = {0}, result = {0}, expected = {0};
  int size = 3;
  s21_create_matrix(size, size, &val1);
  s21_create_matrix(size, size, &expected);

  val1.matrix[0][0] = 4;
  val1.matrix[0][1] = 7;
  val1.matrix[0][2] = 3;
  val1.matrix[1][0] = 8;
  val1.matrix[1][1] = 8;
  val1.matrix[1][2] = 3;
  val1.matrix[2][0] = 9;
  val1.matrix[2][1] = 4;
  val1.matrix[2][2] = 7;

  expected.matrix[0][0] = -0.2993197279;
  expected.matrix[0][1] = 0.2517006803;
  expected.matrix[0][2] = 0.02040816327;
  expected.matrix[1][0] = 0.1972789116;
  expected.matrix[1][1] = -0.006802721088;
  expected.matrix[1][2] = -0.08163265306;
  expected.matrix[2][0] = 0.2721088435;
  expected.matrix[2][1] = -0.3197278912;
  expected.matrix[2][2] = 0.1632653061;

  ck_assert_int_eq(s21_inverse_matrix(&val1, &result), NO_ERRORS);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&val1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t val1 = {0}, result = {0}, expected = {0};
  int size = 7;
  s21_create_matrix(size, size, &val1);
  s21_create_matrix(size, size, &expected);

  val1.matrix[0][0] = 2;
  val1.matrix[0][1] = 8;
  val1.matrix[0][2] = 7;
  val1.matrix[0][3] = 4;
  val1.matrix[0][4] = 1;
  val1.matrix[0][5] = 8;
  val1.matrix[0][6] = 3;

  val1.matrix[1][0] = 4;
  val1.matrix[1][1] = 2;
  val1.matrix[1][2] = 6;
  val1.matrix[1][3] = 2;
  val1.matrix[1][4] = 2;
  val1.matrix[1][5] = 1;
  val1.matrix[1][6] = 5;

  val1.matrix[2][0] = 8;
  val1.matrix[2][1] = 6;
  val1.matrix[2][2] = 7;
  val1.matrix[2][3] = 7;
  val1.matrix[2][4] = 3;
  val1.matrix[2][5] = 4;
  val1.matrix[2][6] = 4;

  val1.matrix[3][0] = 1;
  val1.matrix[3][1] = 7;
  val1.matrix[3][2] = 0;
  val1.matrix[3][3] = 4;
  val1.matrix[3][4] = 4;
  val1.matrix[3][5] = 3;
  val1.matrix[3][6] = 0;

  val1.matrix[4][0] = 5;
  val1.matrix[4][1] = 7;
  val1.matrix[4][2] = 5;
  val1.matrix[4][3] = 6;
  val1.matrix[4][4] = 8;
  val1.matrix[4][5] = 3;
  val1.matrix[4][6] = 1;

  val1.matrix[5][0] = 3;
  val1.matrix[5][1] = 7;
  val1.matrix[5][2] = 8;
  val1.matrix[5][3] = 0;
  val1.matrix[5][4] = 5;
  val1.matrix[5][5] = 7;
  val1.matrix[5][6] = 0;

  val1.matrix[6][0] = 5;
  val1.matrix[6][1] = 8;
  val1.matrix[6][2] = 3;
  val1.matrix[6][3] = 5;
  val1.matrix[6][4] = 9;
  val1.matrix[6][5] = 1;
  val1.matrix[6][6] = 2;

  expected.matrix[0][0] = -0.7535885167;
  expected.matrix[0][1] = 0.5062200957;
  expected.matrix[0][2] = 0.2870813397;
  expected.matrix[0][3] = 0.985645933;
  expected.matrix[0][4] = -0.1153110048;
  expected.matrix[0][5] = 0.3449760766;
  expected.matrix[0][6] = -0.6516746411;

  expected.matrix[1][0] = 1.612440191;
  expected.matrix[1][1] = -1.728229665;
  expected.matrix[1][2] = 0.004784688995;
  expected.matrix[1][3] = -2.550239234;
  expected.matrix[1][4] = -0.6535885167;
  expected.matrix[1][5] = -0.5425837321;
  expected.matrix[1][6] = 2.219138756;

  expected.matrix[2][0] = 1.705741627;
  expected.matrix[2][1] = -1.689952153;
  expected.matrix[2][2] = -0.1259968102;
  expected.matrix[2][3] = -2.843700159;
  expected.matrix[2][4] = -0.222169059;
  expected.matrix[2][5] = -0.6119617225;
  expected.matrix[2][6] = 2.029346093;

  expected.matrix[3][0] = 0.3755980861;
  expected.matrix[3][1] = -0.3177033493;
  expected.matrix[3][2] = -0.04784688995;
  expected.matrix[3][3] = -0.4976076555;
  expected.matrix[3][4] = 0.2358851675;
  expected.matrix[3][5] = -0.2741626794;
  expected.matrix[3][6] = 0.2086124402;

  expected.matrix[4][0] = -1.248803828;
  expected.matrix[4][1] = 1.364593301;
  expected.matrix[4][2] = -0.0956937799;
  expected.matrix[4][3] = 2.004784689;
  expected.matrix[4][4] = 0.4717703349;
  expected.matrix[4][5] = 0.4516746411;
  expected.matrix[4][6] = -1.58277512;

  expected.matrix[5][0] = -2.346889952;
  expected.matrix[5][1] = 2.467942584;
  expected.matrix[5][2] = 0.08452950558;
  expected.matrix[5][3] = 3.945773525;
  expected.matrix[5][4] = 0.6199362041;
  expected.matrix[5][5] = 0.914354067;
  expected.matrix[5][6] = -3.128548644;

  expected.matrix[6][0] = -1.270334928;
  expected.matrix[6][1] = 1.601913876;
  expected.matrix[6][2] = -0.03987240829;
  expected.matrix[6][3] = 2.25199362;
  expected.matrix[6][4] = 0.2132376396;
  expected.matrix[6][5] = 0.4215311005;
  expected.matrix[6][6] = -1.6261563;

  ck_assert_int_eq(s21_inverse_matrix(&val1, &result), NO_ERRORS);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);

  s21_remove_matrix(&val1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_inverse_matrix_test_7) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 44300.0 / 367429.0;
  C.matrix[0][1] = -236300.0 / 367429.0;
  C.matrix[0][2] = 200360.0 / 367429.0;
  C.matrix[1][0] = 20600.0 / 367429.0;
  C.matrix[1][1] = 56000.0 / 367429.0;
  C.matrix[1][2] = -156483.0 / 367429.0;
  C.matrix[2][0] = 30900.0 / 367429.0;
  C.matrix[2][1] = 84000.0 / 367429.0;
  C.matrix[2][2] = -51010.0 / 367429.0;
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

END_TEST

START_TEST(s21_inverse_matrix_test_8) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_test_9) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_double_eq_tol(result.matrix[0][0], (1.0 / m.matrix[0][0]), 1e-06);
    ck_assert_int_eq(code, NO_ERRORS);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_test_11) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_test_12) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_test_13) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (!codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (!codec1 && !codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, NO_ERRORS);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_test_14) {
  /* const int size = rand() % 100 + 1; */
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_inverse_matrix_test_15) {
  matrix_t source;
  matrix_t result;

  int error_type = s21_create_matrix(4, 4, &source);
  ck_assert_int_eq(error_type, NO_ERRORS);

  source.columns = -345345;

  error_type = s21_inverse_matrix(&source, &result);
  ck_assert_int_eq(error_type, CALCULATION_ERROR);

  source.columns = -4;
  s21_remove_matrix(&source);
}
END_TEST

START_TEST(s21_inverse_matrix_test_16) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &m);
  m.matrix[0][0] = 5;
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_17) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_18) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 4, &m);
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_19) {
  matrix_t m, B, R;
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &B);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = -38;
  B.matrix[1][1] = 41;
  B.matrix[1][2] = -34;
  B.matrix[2][0] = 27;
  B.matrix[2][1] = -29;
  B.matrix[2][2] = 24;

  int code = s21_inverse_matrix(&m, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&R);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_20) {
  matrix_t A, B, R;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 0.8;

  s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_test_21) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = -1;
  A.matrix[0][1] = -10;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;

  s21_inverse_matrix(&A, &R);

  B.matrix[0][0] = -0.5;
  B.matrix[0][1] = -11.0 / 18.0;
  B.matrix[0][2] = 10.0 / 9.0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 1.0 / 9.0;
  B.matrix[1][2] = -1.0 / 9.0;
  B.matrix[2][0] = 0.5;
  B.matrix[2][1] = 0.5;
  B.matrix[2][2] = 0;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_inverse_matrix_test_22) {
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = s21_inverse_matrix(B, R);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_23) {
  matrix_t m, result;
  s21_create_matrix(1, 1, &m);
  m.matrix[0][0] = 0;
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&m);
}
END_TEST

int main() {
  Suite *suite = suite_create("Matrix_test");
  TCase *getCase = tcase_create("Core");
  SRunner *runner = srunner_create(suite);

  suite_add_tcase(suite, getCase);

  tcase_add_test(getCase, GetMinorMatrix_test_1);
  tcase_add_test(getCase, GetMinorMatrix_test_2);
  tcase_add_test(getCase, GetMinorMatrix_test_3);
  tcase_add_test(getCase, GetMinorMatrix_test_4);
  tcase_add_test(getCase, GetMinorMatrix_test_5);

  tcase_add_test(getCase, s21_create_matrix_test_1);
  tcase_add_test(getCase, s21_create_matrix_test_2);
  tcase_add_test(getCase, s21_create_matrix_test_3);
  tcase_add_test(getCase, s21_create_matrix_test_4);
  tcase_add_test(getCase, s21_create_matrix_test_5);
  tcase_add_test(getCase, s21_create_matrix_test_6);
  tcase_add_test(getCase, s21_create_matrix_test_7);
  tcase_add_test(getCase, s21_create_matrix_test_8);
  tcase_add_test(getCase, s21_create_matrix_test_9);
  tcase_add_test(getCase, s21_create_matrix_test_10);
  tcase_add_test(getCase, s21_create_matrix_test_11);

  tcase_add_test(getCase, s21_eq_matrix_test_1);
  tcase_add_test(getCase, s21_eq_matrix_test_2);
  tcase_add_test(getCase, s21_eq_matrix_test_3);
  tcase_add_test(getCase, s21_eq_matrix_test_4);
  tcase_add_test(getCase, s21_eq_matrix_test_5);
  tcase_add_test(getCase, s21_eq_matrix_test_6);
  tcase_add_test(getCase, s21_eq_matrix_test_7);
  tcase_add_test(getCase, s21_eq_matrix_test_8);
  tcase_add_test(getCase, s21_eq_matrix_test_9);
  tcase_add_test(getCase, s21_eq_matrix_test_10);
  tcase_add_test(getCase, s21_eq_matrix_test_11);
  tcase_add_test(getCase, s21_eq_matrix_test_12);

  tcase_add_test(getCase, s21_sum_matrix_test_1);
  tcase_add_test(getCase, s21_sum_matrix_test_2);
  tcase_add_test(getCase, s21_sum_matrix_test_3);
  tcase_add_test(getCase, s21_sum_matrix_test_4);
  tcase_add_test(getCase, s21_sum_matrix_test_5);
  tcase_add_test(getCase, s21_sum_matrix_test_6);
  tcase_add_test(getCase, s21_sum_matrix_test_7);
  tcase_add_test(getCase, s21_sum_matrix_test_8);

  tcase_add_test(getCase, s21_sub_matrix_test_1);
  tcase_add_test(getCase, s21_sub_matrix_test_2);
  tcase_add_test(getCase, s21_sub_matrix_test_3);
  tcase_add_test(getCase, s21_sub_matrix_test_4);
  tcase_add_test(getCase, s21_sub_matrix_test_5);
  tcase_add_test(getCase, s21_sub_matrix_test_6);
  tcase_add_test(getCase, s21_sub_matrix_test_7);
  tcase_add_test(getCase, s21_sub_matrix_test_8);

  tcase_add_test(getCase, s21_mult_number_test_1);
  tcase_add_test(getCase, s21_mult_number_test_2);
  tcase_add_test(getCase, s21_mult_number_test_3);
  tcase_add_test(getCase, s21_mult_number_test_4);
  tcase_add_test(getCase, s21_mult_number_test_5);
  tcase_add_test(getCase, s21_mult_number_test_6);
  tcase_add_test(getCase, s21_mult_number_test_7);
  tcase_add_test(getCase, s21_mult_number_test_8);
  tcase_add_test(getCase, s21_mult_number_test_9);

  tcase_add_test(getCase, s21_mult_matrix_test_1);
  tcase_add_test(getCase, s21_mult_matrix_test_2);
  tcase_add_test(getCase, s21_mult_matrix_test_3);
  tcase_add_test(getCase, s21_mult_matrix_test_4);
  tcase_add_test(getCase, s21_mult_matrix_test_5);
  tcase_add_test(getCase, s21_mult_matrix_test_6);
  tcase_add_test(getCase, s21_mult_matrix_test_7);
  tcase_add_test(getCase, s21_mult_matrix_test_8);
  tcase_add_test(getCase, s21_mult_matrix_test_9);
  tcase_add_test(getCase, s21_mult_matrix_test_10);
  tcase_add_test(getCase, s21_mult_matrix_test_11);
  tcase_add_test(getCase, s21_mult_matrix_test_12);

  tcase_add_test(getCase, s21_transpose_test_1);
  tcase_add_test(getCase, s21_transpose_test_2);
  tcase_add_test(getCase, s21_transpose_test_3);
  tcase_add_test(getCase, s21_transpose_test_4);
  tcase_add_test(getCase, s21_transpose_test_5);
  tcase_add_test(getCase, s21_transpose_test_6);
  tcase_add_test(getCase, s21_transpose_test_7);
  tcase_add_test(getCase, s21_transpose_test_8);

  tcase_add_test(getCase, s21_determinant_test_1);
  tcase_add_test(getCase, s21_determinant_test_2);
  tcase_add_test(getCase, s21_determinant_test_3);
  tcase_add_test(getCase, s21_determinant_test_4);
  tcase_add_test(getCase, s21_determinant_test_5);
  tcase_add_test(getCase, s21_determinant_test_6);
  tcase_add_test(getCase, s21_determinant_test_7);
  tcase_add_test(getCase, s21_determinant_test_8);
  tcase_add_test(getCase, s21_determinant_test_9);
  tcase_add_test(getCase, s21_determinant_test_10);
  tcase_add_test(getCase, s21_determinant_test_11);
  tcase_add_test(getCase, s21_determinant_test_12);
  tcase_add_test(getCase, s21_determinant_test_13);
  tcase_add_test(getCase, s21_determinant_test_14);
  tcase_add_test(getCase, s21_determinant_test_15);
  tcase_add_test(getCase, s21_determinant_test_16);
  tcase_add_test(getCase, s21_determinant_test_17);
  tcase_add_test(getCase, s21_determinant_test_18);
  tcase_add_test(getCase, s21_determinant_test_19);
  tcase_add_test(getCase, s21_determinant_test_20);
  tcase_add_test(getCase, s21_determinant_test_21);

  tcase_add_test(getCase, s21_calc_complements_test_1);
  tcase_add_test(getCase, s21_calc_complements_test_2);
  tcase_add_test(getCase, s21_calc_complements_test_3);
  tcase_add_test(getCase, s21_calc_complements_test_4);
  tcase_add_test(getCase, s21_calc_complements_test_5);
  tcase_add_test(getCase, s21_calc_complements_test_6);
  tcase_add_test(getCase, s21_calc_complements_test_7);
  tcase_add_test(getCase, s21_calc_complements_test_8);
  tcase_add_test(getCase, s21_calc_complements_test_9);
  tcase_add_test(getCase, s21_calc_complements_test_10);
  tcase_add_test(getCase, s21_calc_complements_test_11);
  tcase_add_test(getCase, s21_calc_complements_test_12);

  tcase_add_test(getCase, s21_inverse_matrix_test_2);
  tcase_add_test(getCase, s21_inverse_matrix_test_3);
  tcase_add_test(getCase, s21_inverse_matrix_test_5);
  tcase_add_test(getCase, s21_inverse_matrix_test_6);
  tcase_add_test(getCase, s21_inverse_matrix_test_7);
  tcase_add_test(getCase, s21_inverse_matrix_test_8);
  tcase_add_test(getCase, s21_inverse_matrix_test_9);
  tcase_add_test(getCase, s21_inverse_matrix_test_11);
  tcase_add_test(getCase, s21_inverse_matrix_test_12);
  tcase_add_test(getCase, s21_inverse_matrix_test_13);
  tcase_add_test(getCase, s21_inverse_matrix_test_14);
  tcase_add_test(getCase, s21_inverse_matrix_test_15);
  tcase_add_test(getCase, s21_inverse_matrix_test_16);
  tcase_add_test(getCase, s21_inverse_matrix_test_17);
  tcase_add_test(getCase, s21_inverse_matrix_test_18);
  tcase_add_test(getCase, s21_inverse_matrix_test_19);
  tcase_add_test(getCase, s21_inverse_matrix_test_20);
  tcase_add_test(getCase, s21_inverse_matrix_test_21);
  tcase_add_test(getCase, s21_inverse_matrix_test_22);
  tcase_add_test(getCase, s21_inverse_matrix_test_23);

  srunner_run_all(runner, CK_ENV);
  srunner_free(runner);
}
