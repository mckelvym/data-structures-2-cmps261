// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #3
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 3, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// MazeGenerator.h

#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include "Cell.h"
#include "UnionFind.h"

using namespace std;

// Class Information
// Name: MazeGenerator
// Description: A class representing a maze. It will generate a random maze
//   immediately after construction.
// Base Class: UnionFind
class MazeGenerator
{
public:
// Prototype: MazeGenerator(int x, int y);
// Description: Default Constructor
// Preconditions: 
//   1. The value of "x" is assumed to be > 2
//   2. The value of "y" is assumed to be > 2
//   3. There is enough memory for the object to be allocated
// Postcondition: 
//   1. If the value of "x" is < 1, then the number of rows will be 4. Otherwise
//      the number of rows will be "x".
//   2. If the value of "y" is < 1, then the number of columns will be 4.
//      Otherwise the number of columns will be "y". 
//   3. "cell" is allocated to be the size of "rows" * "columns"
//   4. "maze" is allocated to have the number of partitions: "rows" * "columns"   
// Cost Analysis: O(n log*(n))
// Visibility: public
  MazeGenerator(int x, int y);

// Prototype: ~MazeGenerator();
// Description: Destructor
// Precondition: 
//   1. The dynamic cell array "cells" has been allocated
//   2. The dynamic UnionFind array "maze" has been allocated
// Postcondition: Deallocates the memory used by this object
// Cost Analysis: O(1)
// Visibility: public
  ~MazeGenerator();

// Prototype: void print();
// Description: Prints the maze to the screen using "cout"
// Preconditions: None
// Postcondition: Prints the maze to the screen using "cout"
// Cost Analysis: O(1)
// Visibility: public
  void print();
    
private:
// Prototype: void generate();
// Description: Handles the generation of a random path through the maze
// Preconditions: 
//   1. The variables "rows" and "columns" have been set
//   2. The variables "cells" and "maze" have been allocated
// Postcondition: A completely random path is made through the maze
// Cost Analysis: O(n log*(n)) ~ O(n)
// Visibility: private
  void generate();

// Prototype: bool knockDown(int location);
// Description: Knocks down the appropriate walls for a given location only if 
//   the cell chosen and the random wall chosen are not currently connected by 
//   a path
// Preconditions: 
//   1. The value of "location" is assumed to be a valid index in the maze
// Postcondition: 
//   1. For the location, the walls which are not allowed to be knocked down are
//      eliminated.
//   2. If the neighboring cell is not already connected by a path, the walls of
//      both cells are "knocked down" and the value of "true" is returned.
//   3. If the neighboring cell is already connected by a path, the value of
//      "false" is returned.
// Cost Analysis: O(log*(n))
// Visibility: private
  bool knockDown(int location);

// Prototype: int isEdge(int location)
// Description: Finds where in the matrix a particular location is: a corner, a
//              side, or inner
// Preconditions: 
//   1. The variable "location" is assumed to be a valid index of the "cells" 
//      array
//   2. The variable "rows" is assumed to be defined and > 0
//   3. The variable "columns" is assumed to be defined and > 0
// Postcondition: 
//   1. An int is returned based upon the location in the maze that a particular
//      index is.
//      a. 1 if it is the top left corner
//      b. 2 if it is the top and not a corner
//      c. 3 if it is the top right corner
//      d. 4 if it is the left and not a corner
//      e. 5 if it is the right and not a corner
//      f. 6 if it is the bottom left corner
//      g. 7 if it is the bottom and not a corner
//      h. 8 if it is the bottom right corner
//      i. 0 if it is none of the above (an inner cell)
// Cost Analysis: O(1)
// Visibility: private
  int isEdge(int location);

// Class Attributes

// Name: rows
// Description: Represents the numbers of rows in the maze
// Type: int 
// Range of acceptable values: Any value greater than 0
  int rows;

// Name: columns
// Description: Represents the numbers of columns in the maze
// Type: int 
// Range of acceptable values: Any value greater than 0
  int columns;

// Name: cells
// Description: Represents the cells of the maze
// Type: Cell * 
// Range of acceptable values: boolean
  Cell * cells;
  
// Name: maze
// Description: Represents the paths formed by cells of the maze
// Type: UnionFind * 
// Range of acceptable values: Any value of type "int"
  UnionFind * maze;	
};

#endif
