// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #3
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 3, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// MazeGenerator.cpp

#include "MazeGenerator.h"
#include "Cell.h"
#include "UnionFind.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

// Class Information
// Name: MazeGenerator
// Description: A class representing a maze. It will generate a random maze
//   immediately after construction.
// Base Class: UnionFind

// Class Attributes

// Description: Represents a single cell in the maze, with values indicating
//   whether a wall is present or not on each side
// Type: struct cell
// Range of acceptable values: boolean

// Name: rows
// Description: Represents the numbers of rows in the maze
// Type: int 
// Range of acceptable values: Any value greater than 0

// Name: columns
// Description: Represents the numbers of columns in the maze
// Type: int 
// Range of acceptable values: Any value greater than 0

// Name: cells
// Description: Represents the cells of the maze
// Type: cell * 
// Range of acceptable values: boolean
  
// Name: maze
// Description: Represents the paths formed by cells of the maze
// Type: UnionFind * 
// Range of acceptable values: Any value of type "int"

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
MazeGenerator::MazeGenerator(int x, int y){
  if(x < 3)
    rows = 4;
  else
    rows = x;
  if(y < 3)
    columns = 4;
  else
    columns = y;
  cells = new Cell[rows * columns];
  for(int i = 0; i < (rows * columns); i++){
    cells[i].n = cells[i].s = cells[i].w = cells[i].e = true;
  }
  maze = new UnionFind(rows * columns); // O(n)
  generate(); // O(n log*(n))
}

// Prototype: ~MazeGenerator();
// Description: Destructor
// Preconditions: 
//   1. The dynamic cell array "cells" has been allocated
//   2. The dynamic UnionFind array "maze" has been allocated
// Postcondition: Deallocates the memory used by this object
// Cost Analysis: O(1)
// Visibility: public
MazeGenerator::~MazeGenerator(){
  delete cells;
  delete maze;
}

// Prototype: void print();
// Description: Prints the maze to the screen using "cout"
// Preconditions: None
// Postcondition: Prints the maze to the screen using "cout"
// Cost Analysis: O(1)
// Visibility: public
void MazeGenerator::print(){
  for(int x = 0; x < (rows*columns); x++){
    cout << "Cell " << x+1  << ": ";
    if((cells[x].n == false) && (cells[x].s == false) && 
       (cells[x].w == false) && (cells[x].e == false))
      cout << "[none]";
    else{
      if(cells[x].n == true)
        cout << "[N] ";
      if(cells[x].s == true)
        cout << "[S] ";
      if(cells[x].w == true)
        cout << "[W] ";
      if(cells[x].e == true)
        cout << "[E] ";
    }
    cout << endl;
  }
}

// Prototype: void generate();
// Description: Handles the generation of a random path through the maze
// Preconditions: 
//   1. The variables "rows" and "columns" have been set
//   2. The variables "cells" and "maze" have been allocated
// Postcondition: A completely random path is made through the maze
// Cost Analysis: O(n log*(n)) ~ O(n)
// Visibility: private
void MazeGenerator::generate(){
  srand(time(NULL));
  
  bool done = false;
  int location = -1;
  int wall = -1;
  int previous = -1;
  
  // knocks down all internal walls
  // probably O(n log*(n))
  do{
    wall++;
    
    // O(?)
    location = rand()%(rows * columns);
    
    // O(log*(n))
    knockDown(location);
        
    // O(1)
    if(maze->numberOfPartitions() == 1)
      done = true;
            
  }while(!done);
  
  // create a path to the outside
  location = rand()%columns;
  cells[location].n = false;
  location = (rows*columns) - rand()%columns - 1;
  cells[location].s = false;
                            
}

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
bool MazeGenerator::knockDown(int location){
// wall values
//      0(N)

//  1(W)    2(E)

//      3(S)     
        
  // this variable will be used for the random choice of the wall to knock down
  int wall = -1;

  // this variable will be used to help determine if a wall should not be
  // knocked down
  int loc = isEdge(location);

  // this variable will be used to indicate the position of a neighboring cell
  int location2 = -1;
  
  // this variable will be used to determine if a wall was knocked down or not
  bool wallKnockedDown = false;

  // any wall can be knocked down
  if(loc == 0)
    wall = rand()%4;
  // not north(0), not west(1)
  else if(loc == 1)
    wall = rand()%2 + 2;
  // not north(0)
  else if(loc == 2){
    wall = rand()%3 + 1;
  }
  // not north(0), not east(2)
  else if(loc == 3){
    do{
      wall = rand()%4;
    }while((wall == 0) || (wall == 2));
  }
  // not west(1)
  else if(loc == 4){
    do{
      wall = rand()%4;
    }while(wall == 1);
  }
  // not east(2)
  else if(loc == 5){
    do{
      wall = rand()%4;
    }while(wall == 2);    
  }    
  // not west(1), not south(3)
  else if(loc == 6){
    do{
      wall = rand()%4;
    }while((wall == 1) || (wall == 3));
  }
  // not south(3)
  else if(loc == 7)
    wall = rand()%3;
  // not east(2), not south(3)
  else if(loc == 8)
    wall = rand()%2;
    
  // at this point, walls that should not be knocked down (because they are on 
  // an edge) are eliminated from the possibility of being knocked down
  
  // check if the wall should be knocked down

  // the north wall
  if(wall == 0){
    location2 = location - columns;
    if(maze->Find(location2) != maze->Find(location)){
      maze->Union(location, location2);
      cells[location].n = false;
      cells[location2].s = false; 
      wallKnockedDown = true;   
    }
  }
  // the west wall
  else if(wall == 1){
    location2 = location - 1;
    if(maze->Find(location2) != maze->Find(location)){
      maze->Union(location, location2);
      cells[location].w = false;
      cells[location2].e = false;    
      wallKnockedDown = true;
      }
  }
  // the east wall
  else if(wall == 2){
    location2 = location + 1;
    if(maze->Find(location2) != maze->Find(location)){
      maze->Union(location, location2);
      cells[location].e = false;
      cells[location2].w = false;    
      wallKnockedDown = true;
    }
  }
  // the south wall
  else if(wall == 3){
    location2 = location + columns;
    if(maze->Find(location2) != maze->Find(location)){
      maze->Union(location, location2);
      cells[location].s = false;
      cells[location2].n = false;    
      wallKnockedDown = true;
    }
  }  
  return wallKnockedDown;
}     

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
int MazeGenerator::isEdge(int location){
// return values for location
// 1 2 3
// 4 0 5
// 6 7 8

  // top left corner
  if(location == 0)
    return 1;
  // top right corner
  if(location == (columns - 1))
    return 3;
  // bottom left corner
  if(location == ((rows * columns) - columns))
    return 6;
  // bottom right corner
  else if(location == ((rows * columns) - 1))
    return 8;
  // not a corner, on top
  if(location < (columns - 1))
    return 2;
  // not a corner, on left
  if((location % columns) == 0)
    return 4;
  // not a corner, on right
  if((location % columns) == (columns - 1))
    return 5;
  // not a corner, on bottom
  if(location > ((rows * columns) - columns))
    return 7;
  // not an edge
  else
    return 0;
}
