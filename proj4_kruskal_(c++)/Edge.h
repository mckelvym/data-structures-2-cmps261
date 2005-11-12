// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #4
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 15, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// Edge.h

#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

// Class Information
// Name: Edge
// Description: Represents an Edge in a graph, with values for the edge weight
//   and the vertices connected by the edge.
// Base Class: N/A
class Edge{
public:
// Prototype: Edge();
// Description: Default constructor to create an edge with no data.
// Precondition: None
// Postcondition: An edge is created with vertex 1 being "-1", vertex 2 being
//   "-1", and the weight being "-1" to symbolize that the edge is not really
//   valid.
// Cost Analysis: O(1)
// Visibility: public
   Edge();

// Prototype: Edge( int v1, int v2, int w);
// Description: Default constructor to create an edge with incident vertices 
//   v1 and v2, and the weight of the edge.
// Precondition: v1, v2, and w are expected to be of type "int" and all greater
//   than zero.
// Postcondition: An edge is created with vertex 1 being "v1", vertex 2 being
//   "v2", and the weight being "w", unless one of the values is less than or
//   equal to "0", then they all will have the value of "-1".
// Cost Analysis: O(1)
// Visibility: public
   Edge( int v1, int v2, int w);

// Prototype: ~Edge();
// Description: Destructor.
// Precondition: None
// Postcondition: None, no memory was allocated, no memory needs to be deleted
// Cost Analysis: O(1)
// Visibility: public
   ~Edge();

// Prototype: int first();
// Description: Member function to return the integer representation of the 
//   first incident vertex.
// Precondition: None
// Postcondition: The integer form of the first vertex is returned. If the Edge
//   has not been initialized with proper values, "-1" may be returned.
// Cost Analysis: O(1)
// Visibility: public
   int first();

// Prototype: int second();
// Description: Member function to return the integer representation of the 
//   second incident vertex.
// Precondition: None
// Postcondition: The integer form of the second vertex is returned. If the Edge
//   has not been initialized with proper values, "-1" may be returned.
// Cost Analysis: O(1)
// Visibility: public
   int second();

// Prototype: int edgeWeight();
// Description: Member function to return the integer weight of the edge.
// Precondition: None
// Postcondition: Returns the weight of this edge. If the Edge has not been 
//   initialized with proper values, "-1" may be returned.
// Cost Analysis: O(1)
// Visibility: public
   int edgeWeight();

// Prototype: void operator=( Edge rhs );
// Description: Overloaded assignment operator.
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values.
// Postcondition: This edge will take on the exact same values as the right
//   hand side Edge, even if it has improper values.
// Cost Analysis: O(1)
// Visibility: public
   void operator=( Edge rhs );

// Prototype: bool operator<=( Edge rhEdge );
// Description: Overloaded less than or equal to operator
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values. 
// Postcondition: Returns true if the value of the weight of this Edge is less
//   than or equal to the weight of right hand side Edge.
// Cost Analysis: O(1)
// Visibility: public
   bool operator<=( Edge rhEdge );

// Prototype: bool operator<( Edge rhEdge );
// Description: Overloaded less than operator
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values. 
// Postcondition: Returns true if the value of the weight of this Edge is less
//   than the weight of right hand side Edge.
// Cost Analysis: O(1)
// Visibility: public
   bool operator<( Edge rhEdge );

// Prototype: bool operator>( Edge rhEdge );
// Description: Overloaded greater than or equal to operator
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values. 
// Postcondition: Returns true if the value of the weight of this Edge is greater
//   than or equal to the weight of right hand side Edge.
// Cost Analysis: O(1)
// Visibility: public
   bool operator>( Edge rhEdge );
   
// Prototype: ostream & operator<<(ostream & out, Edge & e);
// Description: Overloaded extraction operator
// Precondition: A reference to an ostream object is received, a reference to an
//   edge object is received.
// Postcondition: Print out the values of this edge in the format of 
//   "(vertex1, vertex2, weight)" and returns a reference to an ostream object.
// Cost Analysis: O(1)
// Visibility: friend
   friend ostream & operator<<(ostream & out, Edge & e);

// Prototype: istream & operator>>(istream & in, Edge * e);
// Description: Overloaded insertion operator
// Precondition: A reference to an istream object is received, a pointer alreay
//   initialized of an Edge is received.
// Postcondition: Sets the values of vertex1, vertex2, and weight as taken from 
//   the input. Returns a reference to an istream object.
// Cost Analysis: O(1)
// Visibility: friend
   friend istream & operator>>(istream & in, Edge * e);
    
private:
// Class Attributes

// Name: vertex1
// Description: Holds the name of the first vertex connected by this edge.
// Type: int
// Range of acceptable values: Any greater than or equal to 1. 
   int vertex1;

// Name: vertex2
// Description: Holds the name of the second vertex connected by this edge.
// Type: int 
// Range of acceptable values: Any greater than or equal to 1. 
   int vertex2;

// Name: weight
// Description: Holds the edge weight of this edge.
// Type: int 
// Range of acceptable values: Any greater than or equal to 1.
   int weight;
};

#endif
