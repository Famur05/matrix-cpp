#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(EqMatrix, Subtest_1) {
  S21Matrix a(3, 3);
  a.SetMatrixInNumberFade();
  S21Matrix b(3, 3);
  b.SetMatrixInNumberFade();
  EXPECT_TRUE(a.EqMatrix(b));
}

TEST(EqMatrix, Subtest_2) {
  S21Matrix a;
  a.SetMatrixInNumberFade();
  S21Matrix b;
  b.SetMatrixInNumberFade();
  EXPECT_THROW(a.EqMatrix(b), std::invalid_argument);
}

TEST(EqMatrix, Subtest_3) {
  S21Matrix a(3, 3);
  a.SetMatrixInNumberFade();
  S21Matrix b(3, 3);
  b.SetMatrixInNumber(2);
  EXPECT_FALSE(a.EqMatrix(b));
}

TEST(SumMatrix, Subtest_1) {
  S21Matrix a(3, 3);
  a.SetMatrixInNumber(1);
  S21Matrix b(3, 3);
  b.SetMatrixInNumber(1);
  a.SumMatrix(b);
  S21Matrix result(3, 3);
  result.SetMatrixInNumber(2);
  EXPECT_TRUE(a == result);
}

TEST(SumMatrix, Subtest_2) {
  S21Matrix a(3, 3);
  a.SetMatrixInNumberFade();
  S21Matrix b(2, 3);
  b.SetMatrixInNumberFade();
  EXPECT_THROW(a.SumMatrix(b), std::out_of_range);
}

TEST(SubMatrix, Subtest_1) {
  S21Matrix a(3, 3);
  a.SetMatrixInNumber(2);
  S21Matrix b(3, 3);
  b.SetMatrixInNumber(1);
  a.SubMatrix(b);
  S21Matrix result(3, 3);
  result.SetMatrixInNumber(1);
  EXPECT_TRUE(a == result);
}

TEST(SubMatrix, Subtest_2) {
  S21Matrix a(3, 3);
  a.SetMatrixInNumber(2);
  S21Matrix b(2, 3);
  b.SetMatrixInNumber(1);
  EXPECT_THROW(a.SubMatrix(b), std::out_of_range);
}

TEST(MulNumber, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double res[] = {6.28, 1.12, -138.6, 0};
  a.SetMatrixInArr(arr1);
  Res.SetMatrixInArr(res);
  a.MulNumber(2);
  EXPECT_TRUE(a == Res);
}

TEST(MulNumber, Subtest_2) {
  S21Matrix a(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double res[] = {1.57, 0.28, -34.65, 0};
  a.SetMatrixInArr(arr1);
  Res.SetMatrixInArr(res);
  a.MulNumber(0.5);
  EXPECT_TRUE(a == Res);
}

TEST(MulNumber, Subtest_3) {
  S21Matrix a(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double res[] = {0, 0, 0, 0};
  a.SetMatrixInArr(arr1);
  Res.SetMatrixInArr(res);
  a.MulNumber(0);
  EXPECT_TRUE(a == Res);
}

TEST(MulMatrix, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.1, 0.5, -70.3, 0};
  double arr2[] = {0.5, -10, -2, 2};
  double res[] = {0.55, -30, -35.15, 703};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  a.MulMatrix(b);
  EXPECT_TRUE(a == Res);
}

TEST(MulMatrix, Subtest_2) {
  S21Matrix a(1, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(1, 2);
  double arr1[] = {3.1, 0.5};
  double arr2[] = {0.5, -10, -2, 2};
  double res[] = {0.55, -30};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  a.MulMatrix(b);
  EXPECT_TRUE(a == Res);
}

TEST(MulMatrix, Subtest_3) {
  S21Matrix a(1, 3);
  S21Matrix b(2, 1);
  double arr1[] = {3.1, 0.5, 0};
  double arr2[] = {-78.14, 0};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  EXPECT_THROW(a.MulMatrix(b), std::out_of_range);
}

TEST(Transpose, Subtest_1) {
  S21Matrix a(2, 2);
  a.SetMatrixInNumberFade();
  S21Matrix result(2, 2);
  result = a.Transpose();
  S21Matrix b(2, 2);
  double arr[] = {1, 3, 2, 4};
  b.SetMatrixInArr(arr);
  EXPECT_TRUE(result == b);
}

TEST(CalcComplements, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {1, 2, 3, 4};
  double res[] = {4, -3, -2, 1};
  a.SetMatrixInArr(arr1);
  Res.SetMatrixInArr(res);
  a = a.CalcComplements();
  EXPECT_TRUE(a == Res);
}

TEST(CalcComplements, Subtest_2) {
  S21Matrix a(2, 1);
  double arr1[] = {1, 2};
  a.SetMatrixInArr(arr1);
  EXPECT_THROW(a.CalcComplements(), std::invalid_argument);
}

TEST(Determinant, Subtest_1) {
  S21Matrix a(2, 2);
  double arr1[] = {1, 2, 3, 4};
  a.SetMatrixInArr(arr1);
  EXPECT_EQ(a.Determinant(), -2);
}

TEST(Determinant, Subtest_2) {
  S21Matrix a(3, 3);
  double arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  a.SetMatrixInArr(arr1);
  EXPECT_EQ(a.Determinant(), 0);
}

TEST(Determinant, Subtest_3) {
  S21Matrix a(3, 3);
  double arr1[] = {1, 2, 3, 4, 15, 6, 7, 8, 9};
  a.SetMatrixInArr(arr1);
  EXPECT_EQ(a.Determinant(), -120);
}

TEST(Determinant, Subtest_4) {
  S21Matrix a(1, 1);
  double arr1[] = {5};
  a.SetMatrixInArr(arr1);
  EXPECT_EQ(a.Determinant(), 5);
}

TEST(Determinant, Subtest_5) {
  S21Matrix a(4, 4);
  double arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100, 11, 12, 13, 14, 15, 160};
  a.SetMatrixInArr(arr1);
  EXPECT_EQ(a.Determinant(), 103680);
}

TEST(Determinant, Subtest_6) {
  S21Matrix a(2, 1);
  double arr1[] = {1, 2};
  a.SetMatrixInArr(arr1);
  EXPECT_THROW(a.Determinant(), std::invalid_argument);
}

TEST(InverseMatrix, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {1, 2, 3, 4};
  double res[] = {-2, 1, 1.5, -0.5};
  a.SetMatrixInArr(arr1);
  Res.SetMatrixInArr(res);
  a = a.InverseMatrix();
  EXPECT_TRUE(a == Res);
}

TEST(InverseMatrix, Subtest_2) {
  S21Matrix a(2, 1);
  double arr1[] = {1, 2};
  a.SetMatrixInArr(arr1);
  EXPECT_THROW(a.InverseMatrix(), std::invalid_argument);
}

TEST(OperatorEqMatrix, Subtest_1) {
  S21Matrix a(2, 2);
  a.SetMatrixInNumberFade();
  S21Matrix b(2, 2);
  b.SetMatrixInNumberFade();
  EXPECT_TRUE(a == b);
}

TEST(OperatorEqMatrix, Subtest_2) {
  S21Matrix a(2, 2);
  a.SetMatrixInNumberFade();
  S21Matrix b(3, 3);
  b.SetMatrixInNumberFade();
  a = b;
  EXPECT_TRUE(a == b);
}

TEST(OperatorSumMatrix, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double arr2[] = {-78.14, 0, -0.3, 2};
  double res[] = {-75, 0.56, -69.6, 2};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a + b) == Res);
}

TEST(OperatorSumMatrix, Subtest_2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double arr2[] = {-78.14, 0, -0.3, 2};
  double res[] = {-75, 0.56, -69.6, 2};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a += b) == Res);
}

TEST(OperatorSumMatrix, Subtest_3) {
  S21Matrix a(2, 2);
  S21Matrix b(1, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double arr2[] = {-78.14, 0};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  EXPECT_THROW((a + b), std::out_of_range);
}

TEST(OperatorSumMatrix, Subtest_4) {
  S21Matrix a(2, 1);
  S21Matrix b(2, 2);
  double arr1[] = {3.14, 0.56};
  double arr2[] = {-78.14, 0, -0.3, 2};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  EXPECT_THROW((a += b), std::out_of_range);
}

TEST(OperatorSubMatrix, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double arr2[] = {78.14, 0, -0.3, 2};
  double res[] = {-75, 0.56, -69, -2};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a - b) == Res);
}

TEST(OperatorSubMatrix, Subtest_2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double arr2[] = {78.14, 0, -0.3, 2};
  double res[] = {-75, 0.56, -69, -2};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a -= b) == Res);
}

TEST(OperatorSubMatrix, Subtest_3) {
  S21Matrix a(2, 2);
  S21Matrix b(1, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double arr2[] = {-78.14, 0};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  EXPECT_THROW((a - b), std::out_of_range);
}

TEST(OperatorSubMatrix, Subtest_4) {
  S21Matrix a(2, 1);
  S21Matrix b(2, 2);
  double arr1[] = {3.14, 0.56};
  double arr2[] = {-78.14, 0, -0.3, 2};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  EXPECT_THROW((a -= b), std::out_of_range);
}

TEST(OperatorMulNumber, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double res[] = {6.28, 1.12, -138.6, 0};
  a.SetMatrixInArr(arr1);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a * 2) == Res);
}

TEST(OperatorMulNumber, Subtest_2) {
  S21Matrix a(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.14, 0.56, -69.3, 0};
  double res[] = {6.28, 1.12, -138.6, 0};
  a.SetMatrixInArr(arr1);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a *= 2) == Res);
}

TEST(OperatorMulMatrix, Subtest_1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.1, 0.5, -70.3, 0};
  double arr2[] = {0.5, -10, -2, 2};
  double res[] = {0.55, -30, -35.15, 703};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a * b) == Res);
}

TEST(OperatorMulMatrix, Subtest_2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix Res(2, 2);
  double arr1[] = {3.1, 0.5, -70.3, 0};
  double arr2[] = {0.5, -10, -2, 2};
  double res[] = {0.55, -30, -35.15, 703};
  a.SetMatrixInArr(arr1);
  b.SetMatrixInArr(arr2);
  Res.SetMatrixInArr(res);
  EXPECT_TRUE((a *= b) == Res);
}

TEST(OperatorIndexMatrix, Subtest_1) {
  S21Matrix a(1, 2);
  double arr1[] = {3.14, 0.56};
  a.SetMatrixInArr(arr1);
  EXPECT_TRUE(a(0, 0) == 3.14);
}

TEST(OperatorIndexMatrix, Subtest_2) {
  S21Matrix a(1, 2);
  double arr1[] = {3.14, 0.56};
  a.SetMatrixInArr(arr1);
  EXPECT_TRUE(a(0, 1) == 0.56);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}