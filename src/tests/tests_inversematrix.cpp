#include "tests.h"

TEST(tests_inverse_matrix, correct_arg) {
  S21Matrix matrix(3, 3);
  S21Matrix answer(3, 3);

  matrix.Assign({3, 27, 18, 0, 18, 15, 24, 9, 9});
  answer.Assign({0.0133333, -0.04, 0.04, 0.177778, -0.2, -0.0222222, -0.213333,
                 0.306667, 0.0266667});
  S21Matrix result = matrix.InverseMatrix();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_inverse_matrix, correct_arg_2) {
  S21Matrix matrix(3, 3);
  S21Matrix answer(3, 3);

  matrix.Assign({4, 6, 8, 9, 2, 7, 9, 1, 0});
  answer.Assign({-0.02517985612, 0.02877697842, 0.09352517986, 0.226618705,
                 -0.2589928058, 0.1582733813, -0.03237410072, 0.1798561151,
                 -0.1654676259});
  S21Matrix result = matrix.InverseMatrix();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_inverse_matrix, correct_arg_3) {
  S21Matrix matrix(3, 3);
  S21Matrix answer(3, 3);

  matrix.Assign({4, 7, 3, 8, 8, 3, 9, 4, 7});
  answer.Assign({-0.2993197279, 0.2517006803, 0.02040816327, 0.1972789116,
                 -0.006802721088, -0.08163265306, 0.2721088435, -0.3197278912,
                 0.1632653061});
  S21Matrix result = matrix.InverseMatrix();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}

TEST(tests_inverse_matrix, correct_arg_4) {
  S21Matrix matrix(7, 7);
  S21Matrix answer(7, 7);

  matrix.Assign({2, 8, 7, 4, 1, 8, 3, 4, 2, 6, 2, 2, 1, 5, 8, 6, 7,
                 7, 3, 4, 4, 1, 7, 0, 4, 4, 3, 0, 5, 7, 5, 6, 8, 3,
                 1, 3, 7, 8, 0, 5, 7, 0, 5, 8, 3, 5, 9, 1, 2});
  answer.Assign({-0.7535885167,  0.5062200957,   0.2870813397,  0.985645933,
                 -0.1153110048,  0.3449760766,   -0.6516746411, 1.612440191,
                 -1.728229665,   0.004784688995, -2.550239234,  -0.6535885167,
                 -0.5425837321,  2.219138756,    1.705741627,   -1.689952153,
                 -0.1259968102,  -2.843700159,   -0.222169059,  -0.6119617225,
                 2.029346093,    0.3755980861,   -0.3177033493, -0.04784688995,
                 -0.4976076555,  0.2358851675,   -0.2741626794, 0.2086124402,
                 -1.248803828,   1.364593301,    -0.0956937799, 2.004784689,
                 0.4717703349,   0.4516746411,   -1.58277512,   -2.346889952,
                 2.467942584,    0.08452950558,  3.945773525,   0.6199362041,
                 0.914354067,    -3.128548644,   -1.270334928,  1.601913876,
                 -0.03987240829, 2.25199362,     0.2132376396,  0.4215311005,
                 -1.6261563});
  S21Matrix result = matrix.InverseMatrix();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}