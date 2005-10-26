// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #3
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 3, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// main.cpp

/* Name: Random Maze Generator
   Problem Statement: A program that will automatically generate a random maze 
   needs to be designed and implemented. The program must output the walls of 
   each cell that are still standing after a disjoint set has been used to 
   generate the random maze.
   Problem Specification: The program will create a random maze and output it to 
   the screen as long as many times as the user chooses to do so. Each 
   mazeGenerator will use a UnionFind to keep track of the path it has created.
*/

#include<iostream>
#include<cstdlib>
#include "MazeGenerator.h"

using namespace std;

// Prototype: void pause();
// Description: Pauses for the user.
// Precondition: None.
// Postcondition: Continues execution of the program.
// Cost Analysis: O(1)
// Visibility: public
void pause();

int main(){
    bool done = false;
    char choice;
    
    do{
        cout << endl << "Do you want to create a maze (y/n)? ";
        cin >> choice;
        if(!(choice == 'y' || choice == 'Y'))
          done = true;
        else{
          int rows;
          int cols;
          MazeGenerator * m;
          
          cout << endl << "How many rows? ";
          cin >> rows;
          cout << endl << "How many columns? ";
          cin >> cols;
          cout << endl;
          m = new MazeGenerator(rows, cols);
          m->print();
          delete m;
          pause();
        }
    }while(!done);

    return 0;
}

void pause(){
  cout << "Press ENTER.";
  getchar();
  cout << endl << "---------------------------" << endl; 
}
