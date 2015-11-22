#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
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

  // Print out the original matrices on the screen
  std::cout << "The original matrices are:" << std::endl;
  std::cout << std::endl;
  mat1.print();
  std::cout << std::endl;
  mat2.print();
  std::cout << std::endl;

  // Define a matrix as the sum of the first two
  Matrix<long double> mat3 = mat1 + mat2;

  // Print out the last result as a text array on the screen and save it into an external file
  std::cout << "The sum of the two original matrices is:" << std::endl;
  std::cout << std::endl;
  mat3.print();
  std::cout << std::endl;
  mat3.save("test_sum1.csv");

  // Define a matrix as the subtraction of the first two
  Matrix<long double> mat4 = mat1 - mat2;

  // Print out the last result as a text array and save it into an external file
  std::cout << "The subtraction of the first original matrix by the second one is:" << std::endl;
  std::cout << std::endl;
  mat4.print();
  std::cout << std::endl;
  mat4.save("test_subtraction");

  // Define a matrix as the product of the first two
  Matrix<long double> mat5 = mat1 * mat2;

  // Print out the last result as a text array and save it into an external file
  std::cout << "The product of the first original matrix by the second one is:" << std::endl;
  std::cout << std::endl;
  mat5.print();
  std::cout << std::endl;
  mat5.save("test_product1");

  // Define a matrix as the product of the number 5 by the first matrix
  Matrix<long double> mat6 = mat1 * 5;

  // Print out the last result as a text array and save it into an external file
  std::cout << "The product of the first original matrix by the number 5 is:" << std::endl;
  std::cout << std::endl;
  mat6.print();
  std::cout << std::endl;
  mat6.save("test_product2");

  // Define a matrix as the sum of the number 5 and the first matrix
  Matrix<long double> mat7 = mat1 + 5;

  // Print out the last result as a text array and save it into an external file
  std::cout << "The addition of 5 in each element of the first original matrix is:" << std::endl;
  std::cout << std::endl;
  mat7.print();
  std:: cout << std::endl;
  mat7.save("test_sum2");

  return 0;
}
