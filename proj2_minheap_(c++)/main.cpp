// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #2
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm October 20, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// main.cpp

/* 
   Name: Generic Templated Minimum Heap Class
   Problem Statement: A generic templated minimum heap needs to be implemented, 
   with functions that allow the insertion of items as well as the removal of 
   the minimum item from the heap.
   
   Problem Specification: The program will create several minimum heaps to test 
   the correctness of the implementation. Each heap will be instanciated using 
   the default constructor, creating empty minimum heaps of a predetermined 
   size. Each heap will be filled with a unique series of numbers and then the 
   removeMin function will be used until no more elements can be removed from 
   the heap. There will be no user input into the program, it is simply used to 
   test this implementation. The output of the program will show what size of 
   minimum heap will be created; the number set that will be inserted into the 
   heap; and the numbers in order of removal.
*/

#include<iostream>
#include<cstdlib>
#include "minHeap.h"

using namespace std;

// Prototype: void pause();
// Description: Pauses for the user.
// Precondition: None.
// Postcondition: Continues execution of the program.
// Cost Analysis: O(1)
// Visibility: public
void pause();

int main(){
    // used for removing items from the minHeap
    int temp = -1;
    
    // these are used to test the min heap
    
    // set 1, numbers are in order, size 10
    int numset1[] = {1,2,3,4,5,6,7,8,9,10};
    // set 2, numbers are reverse order, size 10
    int numset2[] = {10,9,8,7,6,5,4,3,2,1};
    // set 3, numbers are in semi-random order, size 10
    int numset3[] = {3,4,2,1,5,7,6,9,8,10};
    // set 4, numbers are in semi-random order, size 10
    int numset4[] = {5,4,3,2,1,6,7,8,9,10};
    // set 5, numbers are randomly ordered, size 15
    int numset5[] = {34, 21, 35, 98, 32, 45, 12, 87, 76, 65, 52, 100, 223, 9, 214};
    // set 6, numbers are randomly ordered, size 24
    int numset6[] = {2, 7, 4, 13, 1983, -1, 76, 3, 13, 27, 49, 44, 550, 261, 134, 543, 
                     246, 86, 5556, 2005, 58, -4, 64, 667};
    
    // set 1
    cout << "Creating a minHeap object with a size of 10." << endl;
    minHeap<int> * h1 = new minHeap<int>(10);
    
    cout << "Inserting the following elements into the heap:" << endl << endl;
    for(int i = 0; i < 10; i++){
      cout << " " << numset1[i];
    }
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
      h1->insert(numset1[i]);
    }
    
    cout << "Removing all elements from the heap: " << endl << endl;
    while(temp != NULL){
      temp = h1->removeMin();
      if(temp != NULL)
        cout << " " << temp;
    }
    cout << endl;
    temp = -1;
    delete h1;
    
    pause();
    
    // set 2
    cout << "Creating a minHeap object with a size of 10." << endl;
    minHeap<int> * h2 = new minHeap<int>(10);
    
    cout << "Inserting the following elements into the heap:" << endl << endl;
    for(int i = 0; i < 10; i++){
      cout << " " << numset2[i];
    }
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
      h2->insert(numset2[i]);
    }
    
    cout << "Removing all elements from the heap: " << endl << endl;
    while(temp != NULL){
      temp = h2->removeMin();
      if(temp != NULL)
        cout << " " << temp;
    }
    cout << endl;
    temp = -1;
    delete h2;
    
    pause();
    
    // set 3
    cout << "Creating a minHeap object with a size of 10." << endl;
    minHeap<int> * h3 = new minHeap<int>(10);
    
    cout << "Inserting the following elements into the heap:" << endl << endl;
    for(int i = 0; i < 10; i++){
      cout << " " << numset3[i];
    }
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
      h3->insert(numset3[i]);
    }
    
    cout << "Removing all elements from the heap: " << endl << endl;
    while(temp != NULL){
      temp = h3->removeMin();
      if(temp != NULL)
        cout << " " << temp;
    }
    cout << endl;
    temp = -1;
    delete h3;
    
    pause();
    
    // set 4
    cout << "Creating a minHeap object with a size of 10." << endl;
    minHeap<int> * h4 = new minHeap<int>(10);
    
    cout << "Inserting the following elements into the heap:" << endl << endl;
    for(int i = 0; i < 10; i++){
      cout << " " << numset4[i];
    }
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
      h4->insert(numset4[i]);
    }
    
    cout << "Removing all elements from the heap: " << endl << endl;
    while(temp != NULL){
      temp = h4->removeMin();
      if(temp != NULL)
        cout << " " << temp;
    }
    cout << endl;
    temp = -1;
    delete h4;
    
    pause();
    
    // set 5
    cout << "Creating a minHeap object with a size of 14." << endl;
    minHeap<int> * h5 = new minHeap<int>(14);
    
    cout << "Inserting the following elements into the heap:" << endl << endl;
    for(int i = 0; i < 15; i++){
      cout << " " << numset5[i];
    }
    cout << endl << endl;
    for(int i = 0; i < 15; i++){
      h5->insert(numset5[i]);
    }
    
    cout << "Removing all elements from the heap: " << endl << endl;
    while(temp != NULL){
      temp = h5->removeMin();
      if(temp != NULL)
        cout << " " << temp;
    }
    cout << endl;
    temp = -1;
    delete h5;
    
    pause();
    
    // set 6
    cout << "Creating a minHeap object with a size of 22." << endl;
    minHeap<int> * h6 = new minHeap<int>(22);
    
    cout << "Inserting the following elements into the heap:" << endl << endl;
    for(int i = 0; i < 22; i++){
      cout << " " << numset6[i];
    }
    cout << endl << endl;
    for(int i = 0; i < 24; i++){
      h6->insert(numset6[i]);
    }
    
    cout << "Removing all elements from the heap: " << endl << endl;
    while(temp != NULL){
      temp = h6->removeMin();
      if(temp != NULL)
        cout << " " << temp;
    }
    cout << endl;
    temp = -1;
    delete h6;
    
    pause();
    
    return 0;
}

void pause(){
  cout << "Press ENTER.";
  // wait for user input
  getchar();
  cout << endl << "---------------------------" << endl; 
}
