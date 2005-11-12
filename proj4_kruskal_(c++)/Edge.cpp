// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #4
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 15, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// Edge.cpp

#include <iostream>
#include "Edge.h"

using namespace std;

// Class Information
// Name: Edge
// Description: Represents an Edge in a graph, with values for the edge weight
//   and the vertices connected by the edge.
// Base Class: N/A


// Class Attributes

// Name: vertex1
// Description: Holds the name of the first vertex connected by this edge.
// Type: int
// Range of acceptable values: Any greater than or equal to 1. 

// Name: vertex2
// Description: Holds the name of the second vertex connected by this edge.
// Type: int 
// Range of acceptable values: Any greater than or equal to 1. 

// Name: weight
// Description: Holds the edge weight of this edge.
// Type: int 
// Range of acceptable values: Any greater than or equal to 1.


// Prototype: Edge();
// Description: Default constructor to create an edge with no data.
// Precondition: None
// Postcondition: An edge is created with vertex 1 being "-1", vertex 2 being
//   "-1", and the weight being "-1" to symbolize that the edge is not really
//   valid.
// Cost Analysis: O(1)
// Visibility: public
Edge::Edge(){
  vertex1 = (-1);
  vertex2 = (-1);
  weight = (-1);
}

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
Edge::Edge( int v1, int v2, int w){
  if(v1 > 0 && v2 > 0 && w > 0){
    vertex1 = (v1);
    vertex2 = (v2);
    weight = (w);  
  }
  else{
    vertex1 = (-1);
    vertex2 = (-1);
    weight = (-1);
  }
}

// Prototype: ~Edge();
// Description: Destructor.
// Precondition: None
// Postcondition: None, no memory was allocated, no memory needs to be deleted
// Cost Analysis: O(1)
// Visibility: public
Edge::~Edge(){
}

// Prototype: int first();
// Description: Member function to return the integer representation of the 
//   first incident vertex.
// Precondition: None
// Postcondition: The integer form of the first vertex is returned. If the Edge
//   has not been initialized with proper values, "-1" may be returned.
// Cost Analysis: O(1)
// Visibility: public
int Edge::first(){
  return vertex1;
}

// Prototype: int second();
// Description: Member function to return the integer representation of the 
//   second incident vertex.
// Precondition: None
// Postcondition: The integer form of the second vertex is returned. If the Edge
//   has not been initialized with proper values, "-1" may be returned.
// Cost Analysis: O(1)
// Visibility: public
int Edge::second(){
  return vertex2;
}

// Prototype: int edgeWeight();
// Description: Member function to return the integer weight of the edge.
// Precondition: None
// Postcondition: Returns the weight of this edge. If the Edge has not been 
//   initialized with proper values, "-1" may be returned.
// Cost Analysis: O(1)
// Visibility: public
int Edge::edgeWeight(){
  return weight;
}

// Prototype: void operator=( Edge rhs );
// Description: Overloaded assignment operator.
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values.
// Postcondition: This edge will take on the exact same values as the right
//   hand side Edge, even if it has improper values.
// Cost Analysis: O(1)
// Visibility: public
void Edge::operator=( Edge rhs ){
  vertex1 = rhs.vertex1;
  vertex2 = rhs.vertex2;
  weight = rhs.weight;
}

// Prototype: bool operator<=( Edge rhEdge );
// Description: Overloaded less than or equal to operator
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values. 
// Postcondition: Returns true if the value of the weight of this Edge is less
//   than or equal to the weight of right hand side Edge.
// Cost Analysis: O(1)
// Visibility: public
bool Edge::operator<=( Edge rhEdge ) {
  if(weight <= rhEdge.weight){
    return true;
  }
  else{
    return false;
  }
}

// Prototype: bool operator<( Edge rhEdge );
// Description: Overloaded less than operator
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values. 
// Postcondition: Returns true if the value of the weight of this Edge is less
//   than the weight of right hand side Edge.
// Cost Analysis: O(1)
// Visibility: public
bool Edge::operator<( Edge rhEdge ) {
  if(weight < rhEdge.weight){
    return true;
  }
  else{
    return false;
  }
}

// Prototype: bool operator>( Edge rhEdge );
// Description: Overloaded greater than or equal to operator
// Precondition: The right hand side Edge is expected to be initialized already
//   with proper values. 
// Postcondition: Returns true if the value of the weight of this Edge is greater
//   than or equal to the weight of right hand side Edge.
// Cost Analysis: O(1)
// Visibility: public
bool Edge::operator>( Edge rhEdge ) {
  if(weight > rhEdge.weight){
    return true;
  }
  else{
    return false;
  }
}

// Prototype: ostream & operator<<(ostream & out, Edge & e);
// Description: Overloaded extraction operator
// Precondition: A reference to an ostream object is received, a reference to an
//   edge object is received.
// Postcondition: Print out the values of this edge in the format of 
//   "(vertex1, vertex2, weight)" and returns a reference to an ostream object.
// Cost Analysis: O(1)
// Visibility: friend
ostream & operator<<(ostream & out, Edge & e){    
	out << "(" << e.first() << ", " << e.second() << ", " << e.edgeWeight() << ")";
	return out;
}

// Prototype: istream & operator>>(istream & in, Edge * e);
// Description: Overloaded insertion operator
// Precondition: A reference to an istream object is received, a pointer alreay
//   initialized of an Edge is received.
// Postcondition: Sets the values of vertex1, vertex2, and weight as taken from 
//   the input. Returns a reference to an istream object.
// Cost Analysis: O(1)
// Visibility: friend
istream & operator>>(istream & in, Edge * e){
    int v1,v2,w;
    in >> v1 >> v2 >> w;
    e->vertex1 = v1;
    e->vertex2 = v2;
    e->weight = w;
    return in;
}
