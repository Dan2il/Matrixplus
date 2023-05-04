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

// ------------------------ s21_determinant ------------------------

// ------------------------ s21_inverse_matrix ------------------------

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
