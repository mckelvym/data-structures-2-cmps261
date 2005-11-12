// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #4
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 15, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// minHeap.h

#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

using namespace std;

// Class Information
// Name: minHeap
// Description: Simulates a minimum heap with the ability to have items inserted into it and its minimum element removed.
// Base Class: N/A
template<class Type>
class minHeap
{
public:
// Prototype: minHeap(int size);
// Description: Default Constructor
// Precondition: There is enough memory to be allocated
// Postcondition: Creates an empty minimum heap with a max size of maxSize if and
//                only if maxSize > 0, else the max size will be set to a default 
//                value of 15.
// Cost Analysis: O(1)
// Visibility: public
    minHeap(int size); 
    
// Prototype: ~minHeap()
// Description: Destructor
// Precondition: The minimum heap has been allocated
// Postcondition: deallocates the memory used by this object
// Cost Analysis: O(1)
// Visibility: public
    ~minHeap();   

// Prototype: bool insert(Type item);
// Description: Inserts the item into the heap.
// Precondition: The heap must be initialized and the item must be of type Type.
// Postcondition: The item is inserted to the heap and is moved to the correct level in the tree.
// Cost Analysis: log(n)
// Visibility: public
    bool insert(Type item); 

// Prototype: Type removeMin();
// Description: Removes the minimum item from the heap
// Precondition: The heap must be initialized and have an item to remove.
// Postcondition: The minimum item is removed from the heap (if it exists) and returned,
//                otherwise null is returned.
// Cost Analysis: log(n)
// Visibility: public
    Type removeMin(); 

private:
        
// Prototype: bool isLeaf(int index);
// Description: Checks to see if the current index is a leaf in the heap.
// Precondition: The heap must be initialized.
// Postcondition: Returns true if the item is a leaf node, false otherwise.
// Cost Analysis: O(1)
// Visibility: private
    bool isLeaf(int index);

// Prototype: int leftChild(int index);
// Description: Finds the position of the left child from the given index.
// Precondition: The index must be valid and the heap must be initialized
// Postcondition: Returns the index of the left child (if it exists), or a -1 otherwise.
// Cost Analysis: O(1)
// Visibility: private
    int leftChild(int index);

// Prototype: int rightChild(int index);
// Description: Finds the position of the right child from the given index.
// Precondition: The index must be valid and the heap must be initialized
// Postcondition: Returns the index of the right child (if it exists), or a -1 otherwise.
// Cost Analysis: O(1)
// Visibility: private
    int rightChild(int index);
    
// Prototype: int parent(int index);
// Description: Finds the position of the parent from the given index.
// Precondition: The index must be valid and the heap must be initialized
// Postcondition: Returns the index of the parent (if it exists), or a -1 otherwise.
// Cost Analysis: O(1)
// Visibility: private
    int parent(int index);

// Class Attributes

// Name: heap
// Description: This is a pointer to an array of elements that represent the minimum heap tree.
// Type: Type *
// Range of acceptable values: Any value that corresponds to the template class "Type".
    Type * heap;

// Name: maxSize
// Description: Keeps track of the maximum size of this heap
// Type: int
// Range of acceptable values: Any number greater than zero.
    int maxSize;

// Name: count
// Description: Keeps track of the current number of elements in the heap.
// Type: int
// Range of acceptable values: Any number greater than or equal to zero.
    int count;
};

#endif
