#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <math.h>

#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  void Allocation();
  void Deallocation();

 public:
  // constructors and destructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // operations on matrices
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int rows, int cols);

  // accessor and mutator
  int GetRows();
  int GetCols();
  void GetMatrix();
  void SetRows(const int rows);
  void SetCols(const int cols);
  void SetMatrixInArr(const double arr[]);
  void SetMatrixInNumber(const double num);
  void SetMatrixInNumberFade();
};

#endif  // S21_MATRIX_OOP_H