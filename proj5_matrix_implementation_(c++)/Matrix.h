// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #5
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm December 1, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work, aside from original
//  implementation by Damon Dischler and modifications/corrections by Mark Radle.

// Matrix.h

#ifndef _MATRIX_H
#define _MATRIX_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

#define GROW_SIZE 10	//default size for matrix rows/columns

// Class Information
// Name: matrix
// Description: Simulates an STL-version of a matrix by using vectors.
// Base Class: vector<T>
template<typename T>
class matrix{

// Class Information
// Name: M_Iterator
// Description: Provides an iterator for the Matrix class. The iterator is based
//   on the vector iterator as the Matrix is implemented as a vector of vectors.
// Base Class: vector<T>::iterator
  class M_Iterator{
  	public:

// Name: row;
// Description: The Matrix is implemented using a vector of vectors.  We will
//   use two vector iterators to simulate the Matrix iterator.  We keep
//   track of the current row with vector< vector< T > > iterator, row,
//   and the current column with vector< T > iterator, col.  Together 
//   these two uniquely identify a cell in the Matrix.
// Type: vector< vector< T > >::iterator
// Range of acceptable values: Any type of vector<vector<T> >::iterator
  	  vector< vector< T > >::iterator row;

// Name: col;
// Description: The Matrix is implemented using a vector of vectors.  We will
//   use two vector iterators to simulate the Matrix iterator.  We keep
//   track of the current row with vector< vector< T > > iterator, row,
//   and the current column with vector< T > iterator, col.  Together 
//   these two uniquely identify a cell in the Matrix.
// Type: vector<T>::iterator
// Range of acceptable values: Any type of vector<T>::iterator
	  vector< T >::iterator col;

// Name: Default Constructor
// Prototype:  M_Iterator()
// Description: Default constructor for the class
// Precondition(s): None
// Postcondition(s): None
// Cost Analysis: O(1)
// Visibility: public
      M_Iterator(){};
        
// Name: Dereferencing Operator
// Prototype: T operator*();
// Description: Simulates the use of an M_Iterator as a pointer by returning the
//   contents of the cell in the Matrix pointed to by the vector<T> iterator.
// Precondition(s): The Matrix must have been allocate by one of the constructors.
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
	  T operator*();

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
	  M_Iterator operator+(int);

// Name: Auto-increment Pointer Operator
// Prototype: M_Iterator operator++()
// Description: An overloading of the prefix ++ operator to simulate pointer
//   addition. This function is equivalent to + 1 as expressed in the preceeding
//   function. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
	  M_Iterator operator++();

// Name: Auto-increment Pointer Operator
// Prototype: M_Iterator operator++(int)
// Description: An overloading of the postfix ++ operator to simulate pointer
//   addition. This function is identical to the previous function and its 
//   parameter is totally ignored. The old value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
	  M_Iterator operator++(int);

// Name: Combination Addition and Assignment Operator
// Prototype: M_Iterator operator+=(int)
// Description: An overloading of the combination += operator to simulate pointer
//   addition. This function is equivalent to + int as express in the Pointer
//   Addition Operator Above. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
	  M_Iterator operator+=(int);

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
	  M_Iterator operator-(int);

// Name: Auto-decrement Pointer Operator
// Prototype: M_Iterator operator--()
// Description: An overloading of the prefix -- operator to simulate pointer
//   subtraction. This function is equivalent to - 1 as expressed in the 
//   preceeding function. The old value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
	  M_Iterator operator--();

// Name: Auto-decrement Pointer Operator
// Prototype: M_Iterator operator--(int)
// Description: An overloading of the postfix -- operator to simulate pointer
//   subtraction. This function is identical to the previous function and its 
//   parameter is totally ignored. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
      M_Iterator operator--(int);

// Name: Combination Subtraction and Assignment Operator
// Prototype: M_Iterator operator-=(int)
// Description: An overloading of the combination -= operator to simulate pointer
//   subtraction. This function is equivalent to - int as express in the Pointer
//   Subtraction Operator Above. The new value of col is returned.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): col will have a new value, row may also have a new value.
// Cost Analysis: O(1)
// Visibility: public
	  M_Iterator operator-=(int);

// Name: Equality Operator
// Prototype: bool operator==(M_Iterator b)
// Description: An overloading of the equality operator == to test whether one
//   M_Iterator is equal to another M_Iterator
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): Returns true if this M_Iterator's values are the same as b's
//   values.
// Cost Analysis: O(1)
// Visibility: public
      bool operator== (M_Iterator);

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
	  bool operator<(M_Iterator);

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
	  bool operator>(M_Iterator);

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
	  bool operator!=(M_Iterator);

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
	  bool operator<=(M_Iterator);

// Name: The Boolean Comparision Operators
// Prototype: Various, see below.
// Description: These overloaded comparision operators will perform the
//   appropriate comparision of the operand with the current value of the 
//   iterators.
// Precondition(s): The Matrix must have been allocated by one of the constructors
// Postcondition(s): None.
// Cost Analysis: O(1)
// Visibility: public
	  bool operator>=(M_Iterator);

// Name: row_begin
// Description: Iterator for the beginning of a row in the matrix
// Type: vector<T>::iterator
// Range of acceptable values: Any of type vector<T>::iterator
	  vector< T >::iterator row_begin;

// Name: row_end
// Description: Iterator for the end of a row in the matrix
// Type: vector<T>::iterator
// Range of acceptable values: Any of type vector<T>::iterator
	  vector< T >::iterator row_end;

// Name: col_begin
// Description: Iterator for the beginning of a column in the matrix
// Type: vector<vector<T> >::iterator
// Range of acceptable values: Any of type vector<vector<T> >::iterator
	  vector< vector< T > >::iterator col_begin;
// Name: col_end
// Description: Iterator for the end of a column in the matrix
// Type: vector<vector<T> >::iterator
// Range of acceptable values: Any of type vector<vector<T> >::iterator
 	  vector< vector< T > >::iterator col_end;
  }; // End of class M_Iterator specification.

public:

// Name: iterator
// Description: Create a iterator type for the Matrix class based on the 
//   M_Iterator class. The user will use this type definition for a 
//   Matrix iterator.
// Type: typedef M_Iterator
// Range of acceptable values: Those conforming to M_Iterator
  typedef M_Iterator iterator;

// Constructor functions:

// Name: Void Default Constructor
// Prototype: matrix<T>(void)
// Description: Default constructor to produce an empty Matrix
// Precondition(s): None
// Postcondition(s): A matrix of vectors is created with default dimensions
// Cost Analysis: O(1)
// Visibility: public
  matrix(void);

// Name: Default Constructor for m by n matrix
// Prototype: matrix<T>(int m, int n)
// Description: Default constructor to construct an m by n Matrix
// Precondition(s): M and N are supposed to be >= 1
// Postcondition(s): A matrix of vectors is created with m by n dimensions
// Cost Analysis: O(1)
// Visibility: public
  matrix(int m, int n);

// Name: Default Constructor for m by n matrix with initial values
// Prototype: matrix<T>(int m, int n, T init)
// Description: Default constructor to construct m by n matrix where all values
//   are set to the initial value of init
// Precondition(s): M and N are supposed to be >= 1, init is a valid value of T
// Postcondition(s): A matrix of vectors is created with m by n dimensions,
//   and all initialized to the value of init.
// Cost Analysis: O(1)
// Visibility: public
  matrix(int m,int n,T init);

// Inspector functions:

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
  vector<T> &operator[](int loc);

// Name: At Function
// Prototype: T at(int x, int y)
// Description: Return the value stored at location x, y
// Precondition(s): x and y are assumed to be valid in the matrix
// Postcondition(s): returns the value stored at location x, y
// Cost Analysis: O(1)
// Visibility: public
  T at( int x, int y );

// Name: Back Retrieval Function
// Prototype: T back()
// Description: Return the last element in the Matrix
// Precondition(s): The matrix is assumed to be created.
// Postcondition(s): Returns the value located at the back of the matrix
// Cost Analysis: O(1)
// Visibility: public
  T back();

// Name: Front Retrieval Function
// Prototype: T front()
// Description: Return the first element in the Matrix
// Precondition(s): The matrix is assumed to be created.
// Postcondition(s): Returns the value located at the front of the matrix
// Cost Analysis: O(1)
// Visibility: public
  T front();

// Name: Check If Empty Function
// Prototype: bool empty()
// Description: Return true if the Matrix is empty, false otherwise
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Returns true if the matrix is empty, false otherwise
// Cost Analysis: O(n)
// Visibility: public
  bool empty();

// Iterator functions:

// Name: Matrix Begin Iterator
// Prototype: matrix<T>::iterator begin()
// Description: Return iterator to first element
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Returns an iterator to the beginning of the matrix
// Cost Analysis: O(1)
// Visibility: public
  matrix<T>::iterator begin();

// Name: Matrix End Iterator
// Prototype: matrix<T>::iterator end()
// Description: Return last iterator
// Precondition(s): The matrix is assumed to be initialized	
// Postcondition(s): Returns an iterator to the end of the matrix 
// Cost Analysis: O(1)
// Visibility: public
  matrix<T>::iterator end();

// Mutation functions:

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
  void assign(T value, matrix<T>::iterator start, matrix<T>::iterator end);

// Destructor functions:

// Name: Clear All Elements Function
// Prototype: void clear()
// Description: Erase all elements in the Matrix
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Erases all elements that are in the matrix
// Cost Analysis: O(n)
// Visibility: public
  void clear();

// Name: Erase One Cell Function
// Prototype: void erase(matrix<T>::iterator m)
// Description: Erase the contents of the cell indicated by iterator 
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Erases the contents at the location specified by the
//   matrix<T>::iterator m
// Cost Analysis: O(1)
// Visibility: public
  void erase(matrix<T>::iterator);

// Name: Erase Many Cells Function
// Prototype: void erase(matrix<T>::iterator start, matrix<T>::iterator end)
// Description: Erase the contents of the cells from start to end
// Precondition(s): The matrix is assumed to be initialized
// Postcondition(s): Erases the values in the matrix from the iterator
//   start to the iterator end
// Cost Analysis: O(n^2) 
// Visibility: public
  void erase(matrix<T>::iterator start, matrix<T>::iterator end);

protected:
// Name: row_len
// Description: The number of rows in the matrix
// Type: int
// Range of acceptable values: numbers greater than 0
  int row_len;
	
// Name: col_len
// Description: The number of columns in the matrix
// Type: int
// Range of acceptable values: numbers greater than 0
  int col_len;

// Name: myvec
// Description: The matrix itself, a Vector of Vectors of T
// Type: vector<vector<T> > myvec;
// Range of acceptable values: Any of type T
  vector<vector<T> > myvec;

};  // End of class Matrix specification.
#endif
