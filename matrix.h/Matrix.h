//matrix.h
//	STL-ish matrix implementation.
//	Based on a Matrix implentation written by Damon Dischler
//
//	CMPS261 Advanced Data Structures
//	Computer Science Department
//	University of Louisiana at Lafayette
//	Modified and corrected by Mark G. Radle
//
#ifndef _MATRIX_H
#define _MATRIX_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

#define GROW_SIZE 10	//default size for matrix rows/columns


template<typename T>
class matrix
{


	class M_Iterator
	{
	// The M_Iterator class provides an iterator for the Matrix class.
    	// The iterator is based on the vector iterator as the Matrix is
 	// implemented as a vector of vectors.
	public:


		// The Matrix is implemented using a vector of vectors.  We will
		// use two vector iterators to simulate the Matrix iterator.  We keep
		// track of the current row with vector< vector< T > > iterator, row,
		// and the current column with vector< T > iterator, col.  Together 
		// these two uniquely identify a cell in the Matrix.
		vector< vector< T > >::iterator row;
		vector< T >::iterator col;

		// Name: Default Constructor
		// Prototype:  M_Iterator()
		// Description: Default constructor for the class
		// Precondition(s): None
		// Postcondition(s): None
		M_Iterator(){};

		// Name: Dereference Operator
		// Prototype:  T operator*()
		// Description: Simulates the use of a M_Iterator as a pointer by returning
		//              the contents of the cell in the Matrix pointed to by the
		//              vector< T > iterator.
		// Precondition(s): Matrix must have been allocated by one of the constructors.
		// Postcondition(s):  None.
		T operator*();

		// Name: Pointer Addition Operator
		// Prototype:  M_Iterator operator+()
		// Description: An overloading of the + operator to simulate pointer addition.
		//		The vector< T > iterator is incremented by int.  If the result
		//		is larger than the number of columns the the vector< vector< T > >
		//		iterator is incremented and the vector< T > iterator is set to
		//		the modulo n element of this row.  The new value of col is returned.
		// Precondition(s): Matrix must have been allocated by one of the constructors.
		// Postcondition(s): col will have a new value, row may also have a new value.
		// Overloaded + operator to simulate pointer addition
		M_Iterator operator+(int);

		// Name: Autoincrement Pointer Operator
		// Prototype:  M_Iterator operator++()
		// Description:  An overloading of the prefix ++ operator to simulate pointer
		//		 addition.  This function is equivalent to + 1 as expressed
		//		 in the preceeding function.  The new value of col is returned.
		// Precondition(s): Matrix must have been allocated by one of the constructors.
		// Postcondition(s): col will have a new value, row may also have a new value.
		// Overloaded auto increment operator for pointer addition
		M_Iterator operator++();

		// Name: Autoincrement Pointer Operator
		// Prototype:  M_Iterator operator++(int)
		// Description:  An overloading of the postfix ++ operator to simulate pointer
		//		 addition.  This function is identical to the previous function
		//		 and it's parameter is totally ignored. The old value of col is
		//               returned.
		// Precondition(s):  See previous function.	
		// Postcondition(s):  See previous function.	
		// Overloaded auto increment (postfix) operator for pointer addition
		M_Iterator operator++(int);

		// Name: Combination Addition and Assignment Operator
		// Prototype:  M_Iterator operator+=(int)
		// Description:  An overloading of the combination += operator to simulate
		//               pointer addition.  This function is equivalent to + int as
		//               expressed in the Pointer Addition Operator above.  The new
		//               value of col is returned.
		// Precondition(s): See Pointer Addition Operator
		// Postcondition(s): See Pointer Addition Operator
		// Overloaded addition-assignment operator for pointer addition
		M_Iterator operator+=(int);

		// Name: Pointer Subtraction Operator
		// Prototype:  M_Iterator operator-(int)
		// Description:  An overloading of the - operator to simulate pointer subtraction.
		//               The vector< T > iterator is decremented by int.  If the result
		//               is logically before the first column then the
		//               vector< vector< T > > iterator is decremented and the vector< T >
		//               iterator is set to the modulo n element in this row.  The new
		//               value in col is returned.
		// Precondition(s): Matrix must have been allocated by one of the constructors.
		// Postcondition(s): col will have a new value, row may also have a new value.
		// Overloaded minus operator for pointer subtraction.
		M_Iterator operator-(int);

		// Name: Autodecrement Pointer Operator
		// Prototype:  M_Iterator operator--()
		// Description:  An overloading of the prefix -- operator to simulate pointer
		//               subtraction.  This function is equivalent to - 1 as expressed
		//               in the preceeding function.  The new value of col is returned.
		// Precondition(s):  Matrix must have been allocated by one of the constructors.
		// Postcondition(s):  col will have a new value, row may also have a new value.
		// Overloaded auto decrement operator for pointer subtraction.
		M_Iterator operator--();

		// Name:  Autodecrement Pointer Operator
		// Prototype:  M_Iterator operator--(int)
		// Description:  An overloading of the postfix -- operator to simulate pointer
		//               subtraction.  This function is identical to the previous
		//               function and it's parameter is totally ignored.  The old
		//               value of col is returned.
		// Precondition(s):  See previous function
		// Postcondition(s):  See previous function
		// Overloaded auto decrement (postfix) operator for pointer subtraction
		M_Iterator operator--(int);

		// Name:  Combination Subtraction and Assignment Operator
		// Prototype:  M_Iterator operator-=(int)
		// Description:  An overloading of the combination -= operator to simulate
		//               pointer subtration.  This function is equivalent to - int as
		//               expressed in the Pointer Subtraction Operator above.  The 
		//               new value of col is returned.
		// Precondition(s): See Pointer Subtraction Operator
		// Postcondition(s): See Pointer Subtraction Operator
		// Overloaded minus-assignment operator for pointer subtraction
		M_Iterator operator-=(int);

		// Name:  The Boolean Comparison Operators
		// Prototype:  Various, see below.
		// Description:  These overloaded comparison operators will perform the
		//               appropriate comparison of the operand with the current
		//               value of the iterators.
		// Precondition(s):  Matrix must have been allocated by one of the constructors.
		// Postcondition(s):  None.
		// Overloaded comparison operators
		bool operator== (M_Iterator);
		bool operator< (M_Iterator);
		bool operator> (M_Iterator);
		bool operator!= (M_Iterator);
		bool operator<= (M_Iterator);
		bool operator>= (M_Iterator);

		// Iterators for the beginning and ending of a row in the matrix
		vector< T >::iterator row_begin, row_end;
		// Iterators for the beginning and ending of a column in the matrix
		vector< vector< T > >::iterator col_begin, col_end;
	}; // End of class M_Iterator specification.

public:

// Create a iterator type for the Matrix class based on the M_Iterator class
// The user will use this type definition for a Matrix iterator.
typedef M_Iterator iterator;

// Constructor functions:

	// Default constructor to produce an empty Matrix
	matrix(void);

	// Default constructor to construct an m by n Matrix	
	matrix(int, int);

	// Default constructor to construct m by n matrix where all values
	// are set to the initial value of init
	matrix(int m,int n,T init);

// Inspector functions:

	// Overloaded [] operator for simulated array access
	// Returns the int vector< t > row
	vector<T> &operator[] (int);

	// return the value stored at location x, y
	T at( int x, int y );

	// Return the last element in the Matrix
	T back();

	// Return the first element in the Matrix
	T front();

	// Return true if the Matrix is empty, false otherwise
	bool empty();

// Iterator functions:

	// Return iterator to first element
	matrix<T>::iterator begin();

	// Return last iterator
	matrix<T>::iterator end();

// Mutation functions:

	// Assign value to all cells between start and end
	void assign(T value, matrix<T>::iterator start, matrix<T>::iterator end);

// Destructor functions:

	// Erase all elements in the Matrix
	void clear();


	// Erase the contents of the cell indicated by iterator 
	void erase(matrix<T>::iterator);

	// Erase the contents of the cells from start to end
	void erase(matrix<T>::iterator start, matrix<T>::iterator end);

protected:

	// The number of rows in the matrix
	int row_len;
	
	// The number of columns in the matrix
	int col_len;

	// The matrix itself, a Vector of Vectors of T
	vector<vector<T> > myvec;

};  // End of class Matrix specification.
#endif
