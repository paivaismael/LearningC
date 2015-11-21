#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "matrix.h"

int main() {
  // Define two 10x10 matrices with element types of long double
  // The first has all elements set to 1.0
  // The second has all elements set to 2.0
  Matrix<long double> mat1(10, 10, 1.0);
  Matrix<long double> mat2(10, 10, 2.0);

  // Set a few elements differently as a test of accessors
  mat1(3,4) = 10.0;
  mat2(1,2) = -15.0;

  // Define a matrix as the sum of the first two
  Matrix<long double> mat3 = mat1 + mat2;

  // Print out the last result as a text array on the screen and save it into an external file
  mat3.print();
  mat3.save("output.csv");

  // Define a matrix as the subtraction of the first two
  Matrix<long double> mat4 = mat1 - mat2;

  // Print out the last result as a text array
  mat4.print();

  // Define a matrix as the product of the first two
  Matrix<long double> mat5 = mat1 * mat2;

  // Print out the last result as a text array
  mat5.print();

  // Define a matrix as the product of the number 5 by the first matrix
  Matrix<long double> mat6 = mat1 * 5;

  // Print out the last result as a text array
  mat6.print();

  // Define a matrix as the sum of the number 5 and the first matrix
  Matrix<long double> mat7 = mat1 + 5;

  // Print out the last result as a text array
  mat7.print();

  return 0;
}
