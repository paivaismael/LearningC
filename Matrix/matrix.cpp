// Pre-processor directives to prevent redundant library loading
#ifndef __MATRIX_CPP
#define __MATRIX_CPP

// iostream: contains basic io streaming operations (cin, cout, etc.)
#include <iostream>
#include <string>
// convert strings to streams with stringstream
#include <sstream>
// write files easily as streams
#include <fstream>

// include the header declarations
#include "matrix.h"

//*************
//
// CONSTRUCTORS
//
//*************

// Default constructor
template<typename T> 
Matrix<T>::Matrix(unsigned int _rows, unsigned int _cols, const T& _initial) {
  // use vector method to resize outer vector of rows to length _rows
  mat.resize(_rows);
  for (unsigned int i=0; i<mat.size(); i++) {
    // for each row, resize to length _cols of columns
    // and initialize elements to value _initial
    mat[i].resize(_cols, _initial);
  }
  // set private fields rows and cols properly
  rows = _rows;
  cols = _cols;
}

// Copy-constructor
template<typename T> Matrix<T>::Matrix(const Matrix<T>& rhs) {
  // Simply set private fields according to fields
  // of existing Matrix<T> object
  mat = rhs.mat;
  rows = rhs.get_rows();
  cols = rhs.get_cols();
}

// Destructor
// No memory is dynamically allocated in the class,
// so just use default compiler cleanup of memory 
template<typename T> Matrix<T>::~Matrix() {}


//*************
//
// ACCESSORS
//
//*************

// Access individual elements
template<typename T>
T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col) {
  return this->mat[row][col];
}

// Access individual elements (const)
template<typename T>
const T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col) 
const {
  return this->mat[row][col];
}

// Get number of rows
template<typename T>
unsigned int Matrix<T>::get_rows() const {
  return this->rows;
}

// Get number of cols
template<typename T>
unsigned int Matrix<T>::get_cols() const {
  return this->cols;
}


//*********************
//
// OPERATOR OVERLOADING
//
//*********************

// Assignment operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  // If assigning to itself, just return itself
  if (&rhs == this)
    return *this;

  // Store new rows and cols
  unsigned int new_rows = rhs.get_rows();
  unsigned int new_cols = rhs.get_cols();

  // resize to new number of rows
  mat.resize(new_rows);
  // resize each row to new number of cols
  for (unsigned int i=0; i<mat.size(); i++) {
    mat[i].resize(new_cols);
  }

  // assign each element 
  for (unsigned int i=0; i<new_rows; i++) {
    for (unsigned int j=0; j<new_cols; j++) {
      mat[i][j] = rhs(i, j);
    }
  }

  // store new number of rows and columns
  rows = new_rows;
  cols = new_cols;

  // return newly modified object
  return *this;
}


// Addition of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
  // Create new matrix to store result, initialize to zero
  Matrix result(rows, cols, 0.0);

  // Add each matrix element-by-element
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] + rhs(i,j);
    }
  }

  return result;
}

// Multiplication of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& rhs) {
  // Create new matrix to store result, initialize to zero
  Matrix result(rows, rhs.get_cols(), 0.0);
  if(cols==rhs.get_rows()){
    for (unsigned int i=0; i<rows; i++) {
      for (unsigned int j=0; j<rhs.get_cols(); j++) {
        for (unsigned int k=0; k<cols; k++) {
          result(i,j) = result(i,j)+this->mat[i][k] * rhs(k,j);
        }
      }
    }
  }
  else{
    std::cout << "The product between the matrix is not well defined." << std::endl;
  }
  return result;
}

// Multiplication a matrix by a scalar
template<typename T>
Matrix<T> Matrix<T>::operator*(const T c) {
  // Create new matrix to store result, initialize to zero
  Matrix result(rows, cols, 0.0);
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j)=this->mat[i][j]*c;
    }
  }
  return result;
}

// Addition of a matrix and a scalar
template<typename T>
Matrix<T> Matrix<T>::operator+(const T c) {
  // Create new matrix to store result, initialize to zero
  Matrix result(rows, cols, 0.0);

  // Add each matrix element-by-element
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] + c;
    }
  }

  return result;
}

// Subtraction of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& rhs) {
  // Create new matrix to store result, initialize to zero
  Matrix result(rows, cols, 0.0);

  result= *this + rhs *(T)(-1);

  return result;
}


//***************
//
// PRINTERS
//
//***************

// Generating a string with the matrix elements in csv format
template<typename T>
std::string Matrix<T>::printer(){
  std::stringstream matrix;
  for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
      matrix << this->mat[i][j] << ", ";
    }
    matrix << std::endl;
  }
  return matrix.str();
}

// Printing a matrix
template<typename T>
void Matrix<T>::print(){
  std::cout << this->printer();
}

// Saving the matrix in a csv file
template<typename T>
void Matrix<T>::save(char const* filename){
  // check if the filename include the extension '.csv'
  // add the correct extension if it is not included in filename
  std::string s(filename);
  std::stringstream ss;
  if(s.size()>4){
    std::stringstream ss;
    for(unsigned int i=0; i<4; ++i){
      unsigned int j = s.length()-4+i;
      ss << s.at(j);
    }
    if(ss.str()!=".csv"){
      std::stringstream ss;
      ss << s << ".csv";
      s=ss.str();
    }
  }
  else{
    ss << s << ".csv";
    s=ss.str();
  }
  char const* name = s.c_str();
  // file handle*/
  std::ofstream output;
  // open file
  output.open(name);
  output << this->printer();
  output.close();
}

#endif
