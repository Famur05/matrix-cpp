# Matrix Library: s21_matrix+

s21_matrix+ is a matrix manipulation library implemented in C++ using an object-oriented approach. The project is developed as part of the School 21 educational program.

## Description

This library provides the `S21Matrix` class with support for both fundamental and advanced matrix operations. All operations are implemented through class methods and overloaded operators. The class encapsulates:

- Private fields: `matrix_`, `rows_`, `cols_`
- Accessors and mutators for `rows_` and `cols_`
- Proper memory management using constructors, destructor, and rule of five
- Exception handling for invalid operations

## Implemented Operations

| Operation                  | Method / Operator                | Exception Cases                          |
|---------------------------|----------------------------------|-------------------------------------------|
| Equality Check            | `EqMatrix`, `==`                | —                                         |
| Addition                  | `SumMatrix`, `+`, `+=`          | Different matrix dimensions               |
| Subtraction               | `SubMatrix`, `-`, `-=`          | Different matrix dimensions               |
| Scalar Multiplication     | `MulNumber`, `*`, `*=`          | —                                         |
| Matrix Multiplication     | `MulMatrix`, `*`, `*=`          | Incompatible matrix dimensions            |
| Transpose                 | `Transpose`                     | —                                         |
| Algebraic Complements     | `CalcComplements`               | Matrix is not square                      |
| Determinant               | `Determinant`                   | Matrix is not square                      |
| Inverse Matrix            | `InverseMatrix`                 | Determinant is zero                       |
| Element Indexing          | `operator()(int i, int j)`      | Index out of bounds                       |

## Technical Details

- Language: C++17
- Compiler: GCC
- Style Guide: Google C++ Style Guide
- Testing Framework: Google Test(GTest)
- Build System: Makefile

## Project Structure

`src/`: Source files for matrix implementation  
`src/tests/`: Unit tests for all matrix operations using Google Test  
`src/Makefile`: Build and test automation
