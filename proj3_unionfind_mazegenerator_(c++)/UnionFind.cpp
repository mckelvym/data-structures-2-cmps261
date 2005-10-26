// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #3
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 3, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// UnionFind.cpp

#include "UnionFind.h"

using namespace std;

// Class Information
// Name: UnionFind
// Description: A class representing the Union/Find construct containing 
//   partitions. It has member functions allowing it to perform a find on an
//   element, as well as union on members of different partitions.
// Base Class: N/A

// Class Attributes

// Name: array
// Description: Represents the Union/Find data structure in an array
// Type: int *
// Range of acceptable values: Any value of type "int"

// Name: max
// Description: Represents the maximum number of partitions
// Type: int 
// Range of acceptable values: Any value greater than 0

// Name: currentPartitions
// Description: Represents the current number of partitions
// Type: int
// Range of acceptable value: Any value greater than 0 and less than or equal to
//   "max".


// Prototype: UnionFind(int maxPartitions);
// Description: Default Constructor
// Preconditions:
//   1. The value of "maxPartitions" must be > 0
//   2. There must be enough memory to allocate an array of size "maxPartitions"                 
// Postcondition: 
//   1. If "maxPartitions" is > 0
//      a. The value of "max" is set to the value of "maxPartitions"
//      b. An array of size "maxPartitions" is allocated in memory
//   2. If "maxPartitions" is <= 0
//      a. The value of "max" is set to the value of "1"
//      b. An array of size "1" is allocated in memory
//   3. "currentPartitions" is set to the value of "max"
// Cost Analysis: O(n)
// Visibility: public
UnionFind::UnionFind(int maxPartitions){
  // the max number of partitions must be greater than 0
  if(maxPartitions > 0)
    max = maxPartitions;
  else 
    max = 1;

  // create a new array of size "max"
  array = new int[max];
  
  // assign the values and leaders to each partition
  for(int x = 0; x < max; x++){
    // each partition is its own leader of size 1
    array[x] = -1;
  }
  
  // set the total number of current partitions
  currentPartitions = max;
}

// Prototype: ~UnionFind();
// Description: Destructor
// Precondition: The dynamic int array "array" has been allocated
// Postcondition: Deallocates the memory used by this object
// Cost Analysis: O(1)
// Visibility: public
UnionFind::~UnionFind(){
  delete array;
}

// Prototype: int Find(int x);
// Description: Finds the partition that an element is in
// Precondition: The UnionFind object must be initialized and the item must be 
//               of type "int".
// Postcondition:
//   1. If the value of "x" < "0" or >= "max" a "-1" is returned indicating that
//      there is no leader for an invalid partition
//   2. If the element at the current array position is a negative number, then
//      the current index is returned indicating that the position in the array
//      is a leader of "x"
//   3. If the element at the current array position is a positive number or 
//      zero, then through a series of recursive steps until the partition
//      leader is found, each node not pointing to the partition leader is made
//      to do so (path compression).
// Cost Analysis: O(log*(n)) ~ O(1)
// Visibility: public
int UnionFind::Find(int x){
  // the object to be found is not in the range of acceptable values
  if((x < 0) || (x >= max))
    return -1;
  // a partition leader has been found
  else if(array[x] < 0)
    return x;
  // make this elements parent be the leader of the partition (recursively)  
  else
    return array[x] = Find(array[x]);
}

// Prototype: void Union(int x, int y);
// Description: Unions (merges) two partitions together into a new partition
// Precondition: The UnionFind object must be initialized and the "x" and "y" 
//   must be integers
// Postcondition: 
//   1. If the values of "x" or "y" are invalid, nothing is done
//   2. If the partition leaders of "x" and "y" are the same, nothing is done
//   3. If the partition leaders of "x" and "y" are unique, then merge them by
//      making the smaller partition leader a leader of the larger partition.
//   4. Change the value of "currentPartitions" if two partitions are merged.
// Cost Analysis: O(log*(n)) ~ O(1)
// Visibility: public
void UnionFind::Union(int x, int y){
     // either the index indicated by "x" and/or "y" is invalid because it is 
     // out of the range, do nothing
     if((x < 0) || (y < 0) || (x >= max) || (y >= max))
       return;
     else{
          // get the partition leader of "x";
          int a = Find(x);
          // get the partition leader of "y";
          int b = Find(y);
          
          // if the elements are not in the same partition, merge them
          if(a != b){
            // the partition containing "x" is larger or equal to the partition
            // containing "y"
            if(array[a] <= array[b]){
              // change the size of the new partition
              array[a] += array[b];
              // make "a" the partition leader of "b"
              array[b] = a;                      
            }
            // the partition containing "y" is larger than the partition containing
            // "x"
            else{
              // change the size of the new partition
              array[b] += array[a];
              // make "b" the partition leader of "a"
              array[a] = b;                      
            }
            currentPartitions--;
          }
     }
}

// Prototype: int numberOfPartitions();
// Description: Finds the number of partitions in the UnionFind's current state
// Precondition: The UnionFind object must be initialized.
// Postcondition: The value of "currentPartitions" is returned.
// Cost Analysis: O(1)
// Visibility: public
int UnionFind::numberOfPartitions(){
  return currentPartitions;
}

