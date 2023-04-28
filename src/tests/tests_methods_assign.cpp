#include "tests.h"

TEST(tests_methods, assign) {
  S21Matrix matrix(2, 4);
  matrix.Assign({1, 1, 1, 1, 4, 4, 4, 4});
  CheckMatrixRange({1, 1, 1, 1, 4, 4, 4, 4}, matrix);
}

TEST(tests_methods, assign_few_argument) {
  S21Matrix matrix(1, 10);
  matrix.Assign({1, 1, 1, 1, 4, 4, 4, 4});
  CheckMatrixRange({1, 1, 1, 1, 4, 4, 4, 4, 0, 0}, matrix);
}

TEST(tests_methods, assign_much_argument) {
  S21Matrix matrix(2, 3);
  matrix.Assign({1, 1, 1, 1, 4, 4, 4, 4});
  CheckMatrixRange({1, 1, 1, 1, 4, 4, 4, 4}, matrix);
}

TEST(tests_methods, assign_much_simple_argument) {
  S21Matrix matrix(6, 8);
  matrix.Assign({1,          2,       3,      4,      5,    6,           7,
                 8,          9,       0,      0,      9,    8,           7,
                 6,          5,       4,      3,      2,    1,           1,
                 2,          3,       4,      5,      6,    7,           8,
                 9,          0,       1,      2,      3,    234,         245235,
                 2352343245, 56345,   23423,  325235, 2355, 876,         452532,
                 46524,      3452345, 345345, 345,    2,    89089.345345});
  CheckMatrixRange(
      {1,   2,      3,      4,          5,      6,     7,      8,
       9,   0,      0,      9,          8,      7,     6,      5,
       4,   3,      2,      1,          1,      2,     3,      4,
       5,   6,      7,      8,          9,      0,     1,      2,
       3,   234,    245235, 2352343245, 56345,  23423, 325235, 2355,
       876, 452532, 46524,  3452345,    345345, 345,   2,      89089.345345},
      matrix);
}