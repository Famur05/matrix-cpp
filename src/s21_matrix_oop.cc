#include "s21_matrix_oop.h"

void S21Matrix::Allocation() {
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::Deallocation() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != nullptr) {
        delete[] matrix_[i];
      }
    }
    delete[] matrix_;
  }
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

// constructors and destructors
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  Allocation();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  Allocation();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { Deallocation(); }

// operations on matrices
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool flag = true;
  if ((matrix_ != nullptr) && (other.matrix_ != nullptr)) {
    if ((rows_ == other.rows_) && (cols_ == other.cols_)) {
      for (int i = 0; i < rows_ && flag; i++) {
        for (int j = 0; j < cols_ && flag; j++) {
          if (fabs((matrix_[i][j]) - (other.matrix_[i][j])) >= 1e-7) {
            flag = false;
          }
        }
      }
    } else {
      flag = false;
    }
  } else {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
  return flag;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if ((matrix_ != nullptr) && (other.matrix_ != nullptr)) {
    if ((rows_ == other.rows_) && (cols_ == other.cols_)) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          matrix_[i][j] += other.matrix_[i][j];
        }
      }
    } else {
      throw std::out_of_range(
          "Incorrect input, matrices should have the same size");
    }
  } else {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if ((matrix_ != nullptr) && (other.matrix_ != nullptr)) {
    if ((rows_ == other.rows_) && (cols_ == other.cols_)) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          matrix_[i][j] -= other.matrix_[i][j];
        }
      }
    } else {
      throw std::out_of_range(
          "Incorrect input, matrices should have the same size");
    }
  } else {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
}

void S21Matrix::MulNumber(const double num) {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] *= num;
      }
    }
  } else {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if ((matrix_ != nullptr) && (other.matrix_ != nullptr)) {
    if (cols_ == other.rows_) {
      S21Matrix result(rows_, other.cols_);
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
          for (int l = 0; l < cols_; l++) {
            result.matrix_[i][j] += matrix_[i][l] * other.matrix_[l][j];
          }
        }
      }
      *this = result;
    } else {
      throw std::out_of_range(
          "Incorrect input, the number of columns of the first matrix must be "
          "equal to the number of rows of the second matrix");
    }
  } else {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
}

S21Matrix S21Matrix::Transpose() {
  if (matrix_ == nullptr) {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (matrix_ == nullptr) {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect input, the matrix is not square");
  }
  int new_rows = rows_, new_cols = cols_;
  if (rows_ > 1) {
    new_rows = rows_ - 1;
    new_cols = cols_ - 1;
  }
  S21Matrix new_matrix(new_rows, new_cols);
  double res_det = 0;
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (rows_ == 1) {
        new_matrix.matrix_[0][0] = matrix_[0][0];
      } else {
        int m_for_new_matrix = 0, n_for_new_matrix = 0;
        for (int m = 0; m < rows_; m++) {
          for (int n = 0; n < cols_; n++) {
            if (m != i && n != j) {
              new_matrix.matrix_[m_for_new_matrix][n_for_new_matrix] =
                  matrix_[m][n];
              n_for_new_matrix++;
            }
          }
          if (m != i) {
            m_for_new_matrix++;
            n_for_new_matrix = 0;
          }
        }
      }
      res_det = new_matrix.Determinant();
      result.matrix_[i][j] = pow(-1, i + j) * res_det;
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (matrix_ == nullptr) {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect input, the matrix is not square");
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }
  // матрицы >= 3
  else {
    double res_det = 0;
    S21Matrix new_matrix(rows_ - 1, cols_ - 1);

    for (int i = 0; i < cols_; i++) {
      int m_for_new_matrix = 0, n_for_new_matrix = 0;
      for (int m = 0; m < rows_; m++) {
        for (int n = 0; n < cols_; n++) {
          if (m != 0 && n != i) {
            new_matrix.matrix_[m_for_new_matrix][n_for_new_matrix] =
                matrix_[m][n];
            n_for_new_matrix++;
          }
        }
        if (m != 0) {
          m_for_new_matrix++;
          n_for_new_matrix = 0;
        }
      }
      res_det = new_matrix.Determinant();
      result += pow(-1, i) * matrix_[0][i] * res_det;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (matrix_ == nullptr) {
    throw std::invalid_argument(
        "Incorrect input, no memory allocated for some matrix");
  }
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect input, the matrix is not square");
  }
  double res_det = 0;
  res_det = Determinant();
  if (res_det == 0) {
    throw std::invalid_argument(
        "Incorrect input, the determinant of the matrix is 0");
  }
  S21Matrix new_matrix = CalcComplements();
  S21Matrix new_matrix_tr = new_matrix.Transpose();
  new_matrix_tr.MulNumber(1 / res_det);
  return new_matrix_tr;
}

// operators
S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix new_matrix(*this);
  new_matrix.SumMatrix(other);
  return new_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix new_matrix(*this);
  new_matrix.SubMatrix(other);
  return new_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix new_matrix(*this);
  new_matrix.MulMatrix(other);
  return new_matrix;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix new_matrix(*this);
  new_matrix.MulNumber(num);
  return new_matrix;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }

  rows_ = other.rows_;
  cols_ = other.cols_;

  Allocation();

  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int rows, int cols) {
  if ((0 > rows) || (rows >= rows_) || (0 > cols) || (rows >= cols_)) {
    throw std::out_of_range(
        "Incorrect input, index cannot be outside the matrix");
  }
  return matrix_[rows][cols];
}

// accessor and mutator
int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::GetMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void S21Matrix::SetRows(const int rows) {
  if (rows <= 0) {
    throw std::invalid_argument(
        "Incorrect input, the number cannot be negative or zero");
  }
  S21Matrix new_matrix(rows, cols_);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i >= rows_) {
        new_matrix.matrix_[i][j] = 0;
      } else {
        new_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = new_matrix;
}

void S21Matrix::SetCols(const int cols) {
  if (cols <= 0) {
    throw std::invalid_argument(
        "Incorrect input, the number cannot be negative or zero");
  }
  S21Matrix new_matrix(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols; j++) {
      if (j >= cols_) {
        new_matrix.matrix_[i][j] = 0;
      } else {
        new_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = new_matrix;
}

void S21Matrix::SetMatrixInArr(const double arr[]) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = arr[i * cols_ + j];
    }
  }
}

void S21Matrix::SetMatrixInNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = num;
    }
  }
}

void S21Matrix::SetMatrixInNumberFade() {
  int count = 1;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = count++;
    }
  }
}