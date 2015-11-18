#include <iostream>
#include "matrix.h"
#include "matrix.cpp"

int main() {
  // Define two 10x10 matrices with element types of long double
  // The first has all elements set to 1.0
  // The second has all elements set to 2.0
  Matrix<long double> mat1(10, 10, 1.0);
  Matrix<long double> mat2(10, 10, 2.0);

  // Set a few elements differently as a test of accessors
  mat1(3,4) = 10.0;
  mat2(1,2) = -15.0;

  // Define a third matrix as the sum of the first two
  Matrix<long double> mat3 = mat1 + mat2;

  // Print out the third matrix as a text array
  mat3.print();

  return 0;
}
