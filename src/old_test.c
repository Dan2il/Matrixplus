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
