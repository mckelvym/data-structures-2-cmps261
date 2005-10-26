// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #3
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 3, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// Cell.h

#ifndef CELL_H
#define CELL_H

using namespace std;

// Class Information
// Name: Cell
// Description: Represents a single cell in the maze, with values indicating
//   whether a wall is present or not on each side
struct Cell
{
  bool n;
  bool s;
  bool w;
  bool e;
};

#endif
