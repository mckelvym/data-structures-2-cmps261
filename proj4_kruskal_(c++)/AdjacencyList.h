// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #4
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 15, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// AdjacencyList.h

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include "Edge.h"
#include "adjacentVertex.h"

using namespace std;

// Class Information
// Name: AdjacencyList
// Description: An implementation of of an Adjacency List of a sparse graph.
//   Keeps track of vertices adjacent to each vertex, as well as their weights.
//   Allows for adding of edges, and printing of the current list. 
// Base Class: N/A
class AdjacencyList{
public:
// Prototype: AdjacencyList();
// Description: Default constructor for an Adjacency List representing a graph
//   of "numberOfVertices" vertices.
// Precondition: The value of "numberOfVertices" is expected to be greater than
//   or equal to "1".
// Postcondition: Allocates memory for an adjacency list that has "numberOfVertices"
//   nodes to represent all the vertices.
// Cost Analysis: O(n)
// Visibility: public
   AdjacencyList(int numberOfVertices);
   
// Prototype: ~AdjacencyList();
// Description: Destructor.
// Precondition: "arrayOfVertices" has been initilized.
// Postcondition: Deallocates the memory used by this object.
// Cost Analysis: O(n^2)
// Visibility: public
   ~AdjacencyList();
   
// Prototype: void addEdge(Edge * e);
// Description: Member function to add an edge to the adjacency edge.
// Precondition: The value of "e" is not NULL and has been allocated. Also, "e"
//   does not contain any vertices in it that are out of the range of this
//   adjacency list.
// Postcondition: Adds an adjacent vertex to the vertex specified by calling
//   e->first(). Adds an adjacent vertex to the vertex specifid by calling
//   e->second().
// Cost Analysis: O(n^2)
// Visibility: public
   void addEdge(Edge * e);

// Prototype: void printAll();
// Description: Prints the values that are stored in the adjacency list, 
//   starting with the first vertex and listing all adjacent vertices, and 
//   proceeding to the last vertex and listing all adjacent vertices.
// Precondition: The variable "arrayOfVertices" has been allocated. 
// Postcondition: Calls "printNextNode()" on the first vertex.
// Cost Analysis: O(n^2)
// Visibility: public
   void printAll();   
    
private:
// Class Information
// Name: node
// Description: Represents a vertex by name, with a pointer to (possibly)
//   adjacent vertices, and a pointer to (possibly) the next vertex in the graph
   struct node{
     int name;
     node * nextNode;
     adjacentVertex * next;
   };
   
// Prototype: adjacentVertex * createNode(Edge * e, bool useFirst);
// Description: Creates a pointer to an adjacentVertex using an Edge.
// Precondition: The value of "e" is not NULL and has been allocated. "useFirst"
//   is either given as true or false.
// Postcondition: Creates a new adjacent vertex with either the name of e->first()
//   or e->second() depending on the value of "useFirst". Sets the value of 
//   weight to be e->edgeWeight(), and sets "next" to be NULL.
// Cost Analysis: O(1)
// Visibility: private
   adjacentVertex * createNode(Edge * e, bool useFirst);
   
// Prototype: void removeNextNode(node * current);
// Description: Helper of the destructor, deletes the chain of vertices.
// Precondition: "current" is not equal to NULL.
// Postcondition: Recursively deletes the "node" nodes connected to
//   the original "node" passed, including itself.
// Cost Analysis: O(n)
// Visibility: private
   void removeNextNode(node * current);

// Prototype: void removeNext(adjacentVertex * current);
// Description: Helper of the destructor, deletes the chain hanging off a vertex.
// Precondition: "current" is not equal to NULL.
// Postcondition: Recursively deletes the "adjacentVertex" nodes connected to
//   the original "adjacentVertex" passed, including itself.
// Cost Analysis: O(n)
// Visibility: private
   void removeNext(adjacentVertex * current);

// Prototype: void printNextNode(node * current);
// Description: Prints the values that are stored in the adjacency list, 
//   starting with the "current" vertex and listing all adjacent vertices, and 
//   proceeding to the last vertex and listing all adjacent vertices.
// Precondition: The variable "current" has been allocated. 
// Postcondition: Prints information about the current vertex, recursively calls
//   "printNext()" and then recursively calls "printNextNode()".
// Cost Analysis: O(n^2)
// Visibility: private
   void printNextNode(node * current);

// Prototype: void printNext(adjacentVertex * current);
// Description: Prints the values that are stored in adjacent vertices.
// Precondition: The variable "current" has been allocated. 
// Postcondition: Prints information about the current adjacent vertex and then
//   recursively calls "printNext()".
// Cost Analysis: O(n)
// Visibility: private
   void printNext(adjacentVertex * current);

// Class Attributes

// Name: edgesAdded
// Description: Represents the total number of edges that have been added to the
//   graph.
// Type: int
// Range of acceptable values: Any value greater than or equal to "0".
   int edgesAdded;

// Name: totalVertices
// Description: Represents the total number of vertices in the graph.
// Type: int
// Range of acceptable values: Any value greater than or equal to "1".
   int totalVertices;
   
// Name: arrayOfVertices
// Description: Represents the all of the vertices of the graph, as well as 
//   their adjacent vertices.
// Type: node *
// Range of acceptable values: Values that conform to the "node" type.
   node * arrayOfVertices;
};

#endif
