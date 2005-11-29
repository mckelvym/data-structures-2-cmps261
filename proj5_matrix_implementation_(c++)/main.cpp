// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #5
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm December 1, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work, aside from original
//  implementation by Damon Dischler and modifications/corrections by Mark Radle.

// main.cpp

/* Name: STL-ish Matrix Implementation
   Problem Statement: Complete the implementation of a Matrix Container Class 
   following SGI's Standard Template Library conventions.
   Problem Specification: The solution must include a driver to test the 
   integrity of the implementation. The Matrix is assumed to be a static 
   structure and any attempts to access cells beyond the bounds of the 
   declaration will produce erros.
*/

#include<iostream>
#include<vector>
#include<string>
#include "Matrix.h"

using namespace std;

// Name: Print Function
// Prototype: void p(string s)
// Description: Used to print out various strings to the user
// Precondition(s): s is a valid string
// Postcondition(s): Prints s to the screen with a newline
// Cost Analysis: O(1)
void p(string s);

int main(){
    const int m2rows = 4, m2cols = 4;
    const int m3rows = 3, m3cols = 3, m3val = 10;
    
    // create a void matrix
    p("\ncreating a void matrix: m1");
    matrix<int> m1();
    
    // create a m2rows by m2cols matrix
    p("\ncreating a matrix with dimensions 4x4: m2");
    matrix<int> m2(m2rows, m2cols);
    
    // create a m3rows by m3cols matrix with all values initialized to m3val
    p("\ncreating a matrix with dimensions 3x3 with initial values of 10: m3");
    matrix<int> m3(m3rows, m3cols, m3val);
    
    p("\n *** let's test the [] operator ***");
    p(" * for m2 *");
    for(int i = 0; i < m2rows; i++){
        for(int j = 0; j < m2cols; j++){
            cout << "m2[" << i << "][" << j << "] = " << m2[i][j] << endl;
        }
    }
    
    p("\n *** let's test the [] operator ***");
    p(" * for m3 *");
    for(int i = 0; i < m3rows; i++){
        for(int j = 0; j < m3cols; j++){
            cout << "m3[" << i << "][" << j << "] = " << m3[i][j] << endl;
        }
    }
    
    p("\n *** let's test the at(x, y) function ***");
    p(" * for m2 *");
    for(int i = 0; i < m2rows; i++){
        for(int j = 0; j < m2cols; j++){
            cout << "m2.at(" << i << "," << j << ") = " << m2.at(i,j) << endl;
        }
    }
    
    p("\n *** let's test the at(x, y) function ***");
    p(" * for m3 *");
    for(int i = 0; i < m3rows; i++){
        for(int j = 0; j < m3cols; j++){
            cout << "m3.at(" << i << "," << j << ") = " << m3.at(i,j) << endl;
        }
    }
    
    p("\n *** let's test the back() and front() functions ***");
    cout << "m2.front() = " << m2.front() << " m2.back() = " << m2.back() << endl;
    cout << "m3.front() = " << m3.front() << " m3.back() = " << m3.back() << endl;
    
    p("\n *** let's test the empty() function ***");
    cout << "m2.empty() = " << m2.empty() << endl;
    cout << "m3.emtpy() = " << m3.empty() << endl;
    
    p("\n *** now we will test the begin()/end() iterator functions ***");
    cout << "*m2.begin() = " << *m2.begin() << endl;
    cout << "*m2.end()   = " << *m2.end() << endl;
    cout << "*m3.begin() = " << *m3.begin() << endl;
    cout << "*m3.end()   = " << *m3.end() << endl;
    
    p("\n *** now we will test the assign() & begin() functions ***");
    
    p("\nm2.assign(1, m2.begin()+1, m2.begin()+3);");
    m2.assign(1, m2.begin()+1, m2.begin()+3);
    for(int i = 0; i <= 16; i++)
      cout << "*(m2.begin() + " << i << ") = " << *(m2.begin() + i) << endl;
    
    p("\nm3.assign(15, m3.begin(), m3.begin());");
    m3.assign(15, m3.begin(), m3.begin());
    for(int i = 0; i <= 9; i++)
      cout << "*(m3.begin() + " << i << ") = " << *(m3.begin() + i) << endl;
    
    p("\n *** now we will test the assign() & end() functions ***");
    
    p("\nm2.assign(2, m2.end() - 3, m2.end() - 2);");
    m2.assign(2, m2.end() - 3, m2.end() - 2);
    for(int i = 16; i >= 0; i--)
      cout << "*(m2.end() - " << i << ") = " << *(m2.end() - i) << endl;
    
    p("\nm3.assign(25, m3.end() - 1, m3.end() - 1);");
    m3.assign(25, m3.end() - 1, m3.end() - 1);
    for(int i = 9; i >= 0; i--)
      cout << "*(m3.end() - " << i << ") = " << *(m3.end() - i) << endl;
        
    p("\n *** let's erase one cell in m2 ***");
    p("m2.erase(m2.begin() + 1)");
    m2.erase(m2.begin() + 1);
    for(int i = 0; i < m2rows; i++){
        for(int j = 0; j < m2cols; j++){
            cout << "m2[" << i << "][" << j << "] = " << m2[i][j] << endl;
        }
    }
    
    p("\n *** let's erase a few cells in m3 ***");
    p("m3.erase(m3.begin(), m3.begin() + 1)");
    m3.erase(m3.begin(), m3.begin() + 1);
    for(int i = 0; i < m3rows; i++){
        for(int j = 0; j < m3cols; j++){
            cout << "m3[" << i << "][" << j << "] = " << m3[i][j] << endl;
        }
    }
    
    p("\nClear all Elements in m2; m3");
    m2.clear();
    m3.clear();
    
    p("\n *** let's test the empty() function again ***");
    cout << "m2.empty() = " << m2.empty() << endl;
    cout << "m3.emtpy() = " << m3.empty() << endl;
        
    p("\n\nWe're done.");
    
    return 0;
}

// Name: Print Function
// Prototype: void p(string s)
// Description: Used to print out various strings to the user
// Precondition(s): s is a valid string
// Postcondition(s): Prints s to the screen with a newline
// Cost Analysis: O(1)
void p(string s){
  cout << s << endl;
}