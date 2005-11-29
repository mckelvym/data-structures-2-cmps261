// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #5
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm December 1, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work, aside from original
//  implementation by Damon Dischler and modifications/corrections by Mark Radle.

// Matrix.cpp

#include "Matrix.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

// Class Information
// Name: matrix
// Description: Simulates an STL-version of a matrix by using vectors.
// Base Class: vector<T>

// Class Attributes

// Name: iterator
// Description: Create a iterator type for the Matrix class based on the 
//   M_Iterator class. The user will use this type definition for a 
//   Matrix iterator.
// Type: typedef M_Iterator
// Range of acceptable values: Those conforming to M_Iterator

// Name: row_len
// Description: The number of rows in the matrix
// Type: int
// Range of acceptable values: numbers greater than 0

// Name: col_len
// Description: The number of columns in the matrix
// Type: int
// Range of acceptable values: numbers greater than 0

// Name: myvec
// Description: The matrix itself, a Vector of Vectors of T
// Type: vector<vector<T> > myvec;
// Range of acceptable values: Any of type T

// Class Information
// Name: M_Iterator
// Description: Provides an iterator for the Matrix class. The iterator is based
//   on the vector iterator as the Matrix is implemented as a vector of vectors.
// Base Class: vector<T>::iterator

// Class Attributes

// Name: row
// Description: The Matrix is implemented using a vector of vectors.  We will
//   use two vector iterators to simulate the Matrix iterator.  We keep
//   track of the current row with vector< vector< T > > iterator, row,
//   and the current column with vector< T > iterator, col.  Together 
//   these two uniquely identify a cell in the Matrix.
// Type: vector< vector< T > >::iterator
// Range of acceptable values: Any type of vector<vector<T> >::iterator
	
// Name: col
// Description: The Matrix is implemented using a vector of vectors.  We will
//   use two vector iterators to simulate the Matrix iterator.  We keep
//   track of the current row with vector< vector< T > > iterator, row,
//   and the current column with vector< T > iterator, col.  Together 
//   these two uniquely identify a cell in the Matrix.
// Type: vector<T>::iterator
// Range of acceptable values: Any type of vector<T>::iterator

// Name: row_begin
// Description: Iterator for the beginning of a row in the matrix
// Type: vector<T>::iterator
// Range of acceptable values: Any of type vector<T>::iterator

// Name: row_end
// Description: Iterator for the end of a row in the matrix
// Type: vector<T>::iterator
// Range of acceptable values: Any of type vector<T>::iterator

// Name: col_begin
// Description: Iterator for the beginning of a column in the matrix
// Type: vector<vector<T> >::iterator
// Range of acceptable values: Any of type vector<vector<T> >::iterator

// Name: col_end
// Description: Iterator for the end of a column in the matrix
// Type: vector<vector<T> >::iterator
// Range of acceptable values: Any of type vector<vector<T> >::iterator

// Name: Void Default Constructor
// Prototype: matrix<T>(void)
// Description: Default constructor to produce an empty Matrix
// Precondition(s): None
// Postcondition(s): A matrix of vectors is created with default dimensions
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
matrix<T>::matrix<T>(void){
  row_len = col_len = GROW_SIZE;
  vector<T> v(col_len);  
  vector<vector<T> > v_squared(row_len, v);
  myvec = v_squared;
}

// Name: Default Constructor for m by n matrix
// Prototype: matrix<T>(int m, int n)
// Description: Default constructor to construct an m by n Matrix
// Precondition(s): M and N are supposed to be >= 1
// Postcondition(s): A matrix of vectors is created with m by n dimensions
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
matrix<T>::matrix<T>(int m, int n){
  if(m < 1){m = GROW_SIZE;}
  if(n < 1){n = GROW_SIZE;}
  row_len = m;
  col_len = n;
  vector<T> v(col_len);
  vector<vector<T> > v_squared(row_len, v);
  myvec = v_squared;
}

// Name: Default Constructor for m by n matrix with initial values
// Prototype: matrix<T>(int m, int n, T init)
// Description: Default constructor to construct m by n matrix where all values
//   are set to the initial value of init
// Precondition(s): M and N are supposed to be >= 1, init is a valid value of T
// Postcondition(s): A matrix of vectors is created with m by n dimensions,
//   and all initialized to the value of init.
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
matrix<T>::matrix<T>(int m, int n, T init){
  if(m < 1){m = GROW_SIZE;}
  if(n < 1){n = GROW_SIZE;}
  row_len = m;
  col_len = n;
  vector<T> v(col_len, init);
  vector<vector<T> > v_squared(row_len, v);
  myvec = v_squared;
}

// Name: Indexing Operator
// Prototype: vector<T> &operator[](int loc)
// Description: Overloaded [] operator for simulated array access
//   Returns the int vector< t > row
// Precondition(s): The matrix has been initialized with dimensions and/or 
//   default values. The value of "loc" is expected to be a valid index in the
//   array (0 <= loc < row_len).
// Postcondition(s): A segmentation fault will occur if the value of "loc" is 
//   outside of the range. Otherwise, the vector<T> stored at location "loc" in
//   myvec will be returned.
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
vector<T> &matrix<T>::operator[](int loc){
  return myvec[loc];
}

// Name: At Function
// Prototype: T at(int x, int y)
// Description: Return the value stored at location x, y
// Precondition(s): x and y are assumed to be valid in the matrix
// Postcondition(s): returns the value stored at location x, y
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
T matrix<T>::at( int x, int y ){
  return myvec[x][y];
}

// Name: Back Retrieval Function
// Prototype: T back()
// Description: Return the last element in the Matrix
// Precondition(s): The matrix is assumed to be created.
// Postcondition(s): Returns the value located at the back of the matrix
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
T matrix<T>::back(){
  //myvec[row_len - 1][col_len - 1];
  return *((*(myvec.end() - 1)).end() - 1);
}

// Name: Front Retrieval Function
// Prototype: T front()
// Description: Return the first element in the Matrix
// Precondition(s): The matrix is assumed to be created.
// Postcondition(s): Returns the value located at the front of the matrix
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
T matrix<T>::front(){
  //myvec[0][0];
  return *(*myvec.begin()).begin();
}

// Name: Check If Empty Function
// Prototype: bool empty()
// Description: Return true if the Matrix is empty, false otherwise
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Returns true if the matrix is empty, false otherwise
// Cost Analysis: O(n)
// Visibility: public
template<typename T>
bool matrix<T>::empty(){
  bool state = true;
  for(int i = 0; i < row_len; i++){
    if(myvec[i].empty() == false){
      state = false;
      break;
    }
  }
  return state;
}

// Name: Matrix Begin Iterator
// Prototype: matrix<T>::iterator begin()
// Description: Return iterator to first element
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Returns an iterator to the beginning of the matrix
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
matrix<T>::iterator matrix<T>::begin(){
  matrix<T>::iterator mi;
  mi.row = myvec.begin();
  mi.col = (*myvec.begin()).begin();
  mi.row_begin = (*myvec.begin()).begin();
  mi.row_end = (*(myvec.end() - 1)).end() - 1;
  mi.col_begin = myvec.begin();
  mi.col_end = myvec.end() - 1;
  
  return mi;  
}

// Name: Matrix End Iterator
// Prototype: matrix<T>::iterator end()
// Description: Return last iterator
// Precondition(s): The matrix is assumed to be initialized	
// Postcondition(s): Returns an iterator to the end of the matrix 
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
matrix<T>::iterator matrix<T>::end(){
  matrix<T>::iterator mi;
  mi.row = myvec.end() - 1;
  mi.col = (*(myvec.end() - 1)).end() - 1;
  mi.row_begin = (*myvec.begin()).begin();
  mi.row_end = (*(myvec.end() - 1)).end() - 1;
  mi.col_begin = myvec.begin();
  mi.col_end = myvec.end() - 1;
  
  return mi;
}

// Name: Assign Value Function
// Prototype: 
//   void assign(T value, matrix<T>::iterator start, matrix<T>::iterator end)
// Description: Assign value to all cells between start and end
// Precondition(s): value is a valid T object, start and end are valid 
//   matrix<T>::iterator's
// Postcondition(s): Assigns the value to everything in the matrix between
//   start and end
// Cost Analysis: O(n^2)
// Visibility: public
template<typename T>
void matrix<T>::assign(T value, matrix<T>::iterator start, matrix<T>::iterator end){
  matrix<T>::iterator mi = start;
  
  while(mi.col <= end.col){
    *(mi.col) = value;
    mi += 1;  
  }
  
  return;
}

// Name: Clear All Elements Function
// Prototype: void clear()
// Description: Erase all elements in the Matrix
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Erases all elements that are in the matrix
// Cost Analysis: O(n)
// Visibility: public
template<typename T>
void matrix<T>::clear(){
  for(int i = 0; i < row_len; i++){
    myvec[i].clear();
  }
  return;
}

// Name: Erase One Cell Function
// Prototype: void erase(matrix<T>::iterator m)
// Description: Erase the contents of the cell indicated by iterator 
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Erases the contents at the location specified by the
//   matrix<T>::iterator m
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
void matrix<T>::erase(matrix<T>::iterator m){
  (*(m.row)).erase(m.col);
  return;
}

// Name: Erase Many Cells Function
// Prototype: void erase(matrix<T>::iterator start, matrix<T>::iterator end)
// Description: Erase the contents of the cells from start to end
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Erases the values in the matrix from the iterator
//   start to the iterator end
// Cost Analysis: O(n^2) 
// Visibility: public
template<typename T>
void matrix<T>::erase(matrix<T>::iterator start, matrix<T>::iterator end){
  while(start.col <= end.col){
    (*(start.row)).erase(start.col);
    ++start;
  }
  return;
}
    
// Name: Dereferencing Operator
// Prototype: T operator*();
// Description: Simulates the use of an M_Iterator as a pointer by returning the
//   contents of the cell in the Matrix pointed to by the vector<T> iterator.
// Precondition(s): The Matrix must have been allocate by one of the constructors.
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
template<typename T>
T matrix<T>::iterator::operator*(){
  return *col;
}

// Name: Pointer Addition Operator
// Prototype: M_Iterator operator+()
// Description: An overloading of the + operator to simulate pointer addition.
//   The vector<T> iterator is incremented by int. If the result is larger than
//   the number of columns, then the vector<vector<T> > iterator is incremented
//   and the vector<T> iterator is set to the modulo n element of this row. The
//   new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the
//   constructors.
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator+(int add){
  if((col + add) >= (*row).end()){
    while(col < (*row).end()){
      col++;
      add--;
    }
    if((row + 1) < col_end){
      row = row + 1;
      col = (*row).begin();
      if(add > 0)
        *this = *this + add;
    }
    else{
      col = row_end;
      row = col_end;
    }
  }
  else{
    col = col + add;
  }
  
  return *this;
}

// Name: Auto-increment Pointer Operator
// Prototype: M_Iterator operator++()
// Description: An overloading of the prefix ++ operator to simulate pointer
//   addition. This function is equivalent to + 1 as expressed in the preceeding
//   function. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator++(){
  return *this = (*this) + 1;
}

// Name: Auto-increment Pointer Operator
// Prototype: M_Iterator operator++(int)
// Description: An overloading of the postfix ++ operator to simulate pointer
//   addition. This function is identical to the previous function and its 
//   parameter is totally ignored. The old value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1) 
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator++(int add){
  M_Iterator temp = *this;
  ++(*this);
  return temp;
}

// Name: Equality Operator
// Prototype: bool operator==(M_Iterator b)
// Description: An overloading of the equality operator == to test whether one
//   M_Iterator is equal to another M_Iterator
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): Returns true if this M_Iterator's values are the same as b's
//   values.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
bool matrix<T>::iterator::operator==(M_Iterator b){
  if((col == b.col) && (row == b.row))
    return true;
  else return false;
}

// Name: Combination Addition and Assignment Operator
// Prototype: M_Iterator operator+=(int)
// Description: An overloading of the combination += operator to simulate pointer
//   addition. This function is equivalent to + int as express in the Pointer
//   Addition Operator Above. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator+=(int add){
  return ((*this) + add);
}

// Name: Pointer Subtraction Operator
// Prototype: M_Iterator operator-(int)
// Description: An overloading of the - operator to simulate pointer subtraction.
//   The vector<T> iterator is decremented by int. If the result is logically
//   before the first column then the vector<vector<T> > iterator is descremented
//   and the vector<T> iterator is set to the modulo n element in this row. The
//   new value in col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator-(int sub){
  if((col - sub) < (*row).begin()){
    while(col >= (*row).begin()){
      col--;
      sub--;
    }
    if(row > col_begin){
      row = row - 1;
      col = ((*row).end()) - 1;
      if(sub > 0)
        *this = *this - sub;
    }
    else{
      col = row_begin;
      row = col_begin;
    }
  }
  else{
    col = col - sub;
  }
  return *this;
}

// Name: Auto-decrement Pointer Operator
// Prototype: M_Iterator operator--()
// Description: An overloading of the prefix -- operator to simulate pointer
//   subtraction. This function is equivalent to - 1 as expressed in the 
//   preceeding function. The old value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator--(){
  return (*this) - 1;
}

// Name: Auto-decrement Pointer Operator
// Prototype: M_Iterator operator--(int)
// Description: An overloading of the postfix -- operator to simulate pointer
//   subtraction. This function is identical to the previous function and its 
//   parameter is totally ignored. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator--(int sub){
  M_Iterator temp = *this;
  --(*this);
  return temp;
}

// Name: Combination Subtraction and Assignment Operator
// Prototype: M_Iterator operator-=(int)
// Description: An overloading of the combination -= operator to simulate pointer
//   subtraction. This function is equivalent to - int as express in the Pointer
//   Subtraction Operator Above. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
matrix<T>::iterator matrix<T>::iterator::operator-=(int sub){
  return (*this) - sub;
}

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
bool matrix<T>::iterator::operator!=(M_Iterator b){
  if(row != b.row)
    return true;
  else if((row == b.row) && (col != b.col))
    return true;
  else return false;
}

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
bool matrix<T>::iterator::operator<(M_Iterator b){
  if(row < b.row)
    return true;
  else if((row == b.row) && (col < b.col))
    return true;
  else return false;
}

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
bool matrix<T>::iterator::operator<=(M_Iterator b){
  if(row <= b.row)
    return true;
  else if((row == b.row) && (col <= b.col))
    return true;
  else return false;
}

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
bool matrix<T>::iterator::operator>(M_Iterator b){
  if(row > b.row)
    return true;
  else if((row == b.row) && (col > b.col))
    return true;
  else return false;
}

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
template <typename T>
bool matrix<T>::iterator::operator>=(M_Iterator b){
  if(row >= b.row)
    return true;
  else if((row == b.row) && (col >= b.col))
    return true;
  else return false;
}
