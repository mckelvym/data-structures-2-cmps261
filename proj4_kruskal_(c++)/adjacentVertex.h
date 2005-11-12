// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #4
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 15, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// adjacentVertex.h

#ifndef ADJACENTVERTEX_H
#define ADJACENTVERTEX_H

using namespace std;

// Class Information
// Name: adjacentVertex
// Description: Represents an adjacent vertex by name and weight, with a pointer
//   to (possibly) other adjacent vertices.
struct adjacentVertex{
     int name;
     int weight;
     adjacentVertex * next;
};

#endif
