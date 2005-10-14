// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #2
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm October 20, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// minHeap.cpp

#include <iostream>
#include "minHeap.h"

using namespace std;

// Class Information
// Name: minHeap
// Description: Simulates a minimum heap with the ability to have items inserted into it and its minimum element removed.
// Base Class: N/A

// Class Attributes

// Name: heap
// Description: This is a pointer to an array of elements that represent the minimum heap tree.
// Type: Type *
// Range of acceptable values: Any value that corresponds to the template class "Type".

// Name: maxSize
// Description: Keeps track of the maximum size of this heap
// Type: int
// Range of acceptable values: Any number greater than zero.

// Name: count
// Description: Keeps track of the current number of elements in the heap.
// Type: int
// Range of acceptable values: Any number greater than or equal to zero.

// Prototype: minHeap(int size);
// Description: Default Constructor
// Precondition: There is enough memory to be allocated
// Postcondition: Creates an empty minimum heap with a max size of maxSize if and
//                only if maxSize > 0, else the max size will be set to a default 
//                value of 15.
// Cost Analysis: O(1)
// Visibility: public
template<class Type>
minHeap<Type>::minHeap(int size)
{
  if(size > 0){
    maxSize = size;
  }
  else maxSize = 15;              
  heap = new Type[maxSize];
  count = 0;                                                      
}

// Prototype: ~minHeap()
// Description: Destructor
// Precondition: The minimum heap has been allocated
// Postcondition: deallocates the memory used by this object
// Cost Analysis: O(1)
// Visibility: public
template<class Type>
minHeap<Type>::~minHeap()
{
  delete heap;                                                  
}

// Prototype: bool insert(Type item);
// Description: Inserts the item into the heap.
// Precondition: The heap must be initialized and the item must be of type Type.
// Postcondition: The item is inserted to the heap and is moved to the correct level in the tree.
// Cost Analysis: log(n)
// Visibility: public
template<class Type>
bool minHeap<Type>::insert(Type item)
{
  int hole;
  
  // there is no room to add a new item
  if(count >= maxSize){
    return false;
  }
  
  hole = count;
  // increase the size
  count++;
  // stick the item at the next available position
  heap[hole] = item;
  
  while((parent(hole) != -1) && (heap[hole] < heap[parent(hole)])){
    Type temp = heap[hole];
    heap[hole] = heap[parent(hole)];
    heap[parent(hole)] = temp;
    hole = parent(hole);
  }        
  
  return true;                                    
}

// Prototype: Type removeMin();
// Description: Removes the minimum item from the heap
// Precondition: The heap must be initialized and have an item to remove.
// Postcondition: The minimum item is removed from the heap (if it exists) and returned,
//                otherwise null is returned.
// Cost Analysis: log(n)
// Visibility: public
template<class Type>
Type minHeap<Type>::removeMin()
{
  if(count == 0)
    return NULL;
  if(count == 1){
    count = 0;
    return heap[0];
  }
  
  int hole = 0;
  Type item = heap[hole];
  
  count--;
  heap[0] = heap[count];
  
  while(true)
  {
    int l = leftChild(hole);
    int r = rightChild(hole);
    
    // a left child and right child exist
    if((l != -1) && (r != -1)){
      // the right child is the minimum
      if(heap[l] > heap[r]){
        // the right child is less than the parent, swap
        if(heap[r] < heap[hole]){
          Type temp = heap[hole];
          heap[hole] = heap[r];
          heap[r] = temp;
          hole = r;
        }
        // the right child is greater than the parent, end
        else return item;
      }
      // the left child is the minimum or equal
      else if(heap[l] <= heap[r]){
        // the left child is less than the parent, swap
        if(heap[l] < heap[hole]){
          Type temp = heap[hole];
          heap[hole] = heap[l];
          heap[l] = temp;
          hole = l;
        }
        // the left child is greater than the parent, end
        else return item;
      }
    }
    // only a left child exists
    else if((l != -1) && (r == -1)){
      // the left child is less than the parent, swap
      if(heap[l] < heap[hole]){
        Type temp = heap[hole];
        heap[hole] = heap[l];
        heap[l] = temp;
      }
      return item;
    }
    // leaf has been reached, done.
    else if((l == -1) && (r == -1)){
      return item;
    }
  }
}

// Prototype: bool isLeaf(int index);
// Description: Checks to see if the current index is a leaf in the heap.
// Precondition: The heap must be initialized.
// Postcondition: Returns true if the item is a leaf node, false otherwise.
// Cost Analysis: O(1)
// Visibility: private
template<class Type>
bool minHeap<Type>::isLeaf(int index)
{
     if((leftChild(index) == -1) && (rightChild(index) == -1))
       return true;
     else return false;
}

// Prototype: int leftChild(int index);
// Description: Finds the position of the left child from the given index.
// Precondition: The index must be valid and the heap must be initialized
// Postcondition: Returns the index of the left child (if it exists), or a -1 otherwise.
// Cost Analysis: O(1)
// Visibility: private
template<class Type>
int minHeap<Type>::leftChild(int index)
{
  int l;
  if(index < 0)
    return -1;
  if(index >= count)
    return -1;
  l = (index * 2) + 1;
  if(l >= count)
    return -1;
  return l;  
}

// Prototype: int rightChild(int index);
// Description: Finds the position of the right child from the given index.
// Precondition: The index must be valid and the heap must be initialized
// Postcondition: Returns the index of the right child (if it exists), or a -1 otherwise.
// Cost Analysis: O(1)
// Visibility: private
template<class Type>
int minHeap<Type>::rightChild(int index)
{
  int r;
  if(index < 0)
    return -1;
  if(index >= count)
    return -1;
  r = (index * 2) + 2;
  if(r >= count)
    return -1;
  return r;
}

// Prototype: int parent(int index);
// Description: Finds the position of the parent from the given index.
// Precondition: The index must be valid and the heap must be initialized
// Postcondition: Returns the index of the parent (if it exists), or a -1 otherwise.
// Cost Analysis: O(1)
// Visibility: private
template<class Type>
int minHeap<Type>::parent(int index)
{
  // invalid index: does not exist
  if(index <= 0)
    return -1;
  // invalid index: no elements present here
  if(index >= count){
    return -1;
  }
  return (index - 1) / 2;
}
