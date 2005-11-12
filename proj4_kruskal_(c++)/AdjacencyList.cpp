// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #4
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 15, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// AdjacencyList.cpp

#include <iostream>
#include "AdjacencyList.h"
#include "Edge.h"
#include "adjacentVertex.h"

using namespace std;

// Class Information
// Name: AdjacencyList
// Description: An implementation of of an Adjacency List of a sparse graph.
//   Keeps track of vertices adjacent to each vertex, as well as their weights.
//   Allows for adding of edges, and printing of the current list. 
// Base Class: N/A

// Class Information
// Name: node
// Description: Represents a vertex by name, with a pointer to (possibly)
//   adjacent vertices, and a pointer to (possibly) the next vertex in the graph


// Class Attributes

// Name: edgesAdded
// Description: Represents the total number of edges that have been added to the
//   graph.
// Type: int
// Range of acceptable values: Any value greater than or equal to "0".

// Name: totalVertices
// Description: Represents the total number of vertices in the graph.
// Type: int
// Range of acceptable values: Any value greater than or equal to "1".
   
// Name: arrayOfVertices
// Description: Represents the all of the vertices of the graph, as well as 
//   their adjacent vertices.
// Type: node *
// Range of acceptable values: Values that conform to the "node" type.


// Prototype: AdjacencyList();
// Description: Default constructor for an Adjacency List representing a graph
//   of "numberOfVertices" vertices.
// Precondition: The value of "numberOfVertices" is expected to be greater than
//   or equal to "1".
// Postcondition: Allocates memory for an adjacency list that has "numberOfVertices"
//   nodes to represent all the vertices.
// Cost Analysis: O(n)
// Visibility: public
AdjacencyList::AdjacencyList(int numberOfVertices){
  
  // the number of vertices in the tree
  if(numberOfVertices < 1)
    totalVertices = 1;
  else totalVertices = numberOfVertices + 1;
  
  // how many edges have been added so far
  //edgesAdded = 0;
  
  // create an empty array for each vertex
  int nodes = 1; // the name of each vertex
  node * temp;   // each vertex will be of this type
  
  arrayOfVertices = new node;
  temp = arrayOfVertices;
  
  while(nodes < totalVertices){
    temp->name = nodes; // set the name
    temp->next = NULL;  // so far it has no adjacent vertices
    // check to see if we need to add another vertex to the graph
    if((nodes + 1) < totalVertices){
      temp->nextNode = new node; // if so, create a new node
      temp = temp->nextNode;     // and move temp to it.
    }
    else{
      temp->next = NULL;         // otherwise, we are done with the vertices.
      temp->nextNode = NULL;
    }
    nodes++;                     // reflect that we've just added another node
  }
}
 
// Prototype: ~AdjacencyList();
// Description: Destructor.
// Precondition: "arrayOfVertices" has been initilized.
// Postcondition: Deallocates the memory used by this object.
// Cost Analysis: O(n^2)
// Visibility: public
AdjacencyList::~AdjacencyList(){
  if(arrayOfVertices != NULL)
    removeNextNode(arrayOfVertices);
}

// Prototype: void removeNextNode(node * current);
// Description: Helper of the destructor, deletes the chain of vertices.
// Precondition: "current" is not equal to NULL.
// Postcondition: Recursively deletes the "node" nodes connected to
//   the original "node" passed, including itself.
// Cost Analysis: O(n)
// Visibility: private
void AdjacencyList::removeNextNode(node * current){
  if(current->nextNode != NULL){
    removeNextNode(current->nextNode);
  }
  if(current->next != NULL)
    removeNext(current->next);
  delete current;
}

// Prototype: void removeNext(adjacentVertex * current);
// Description: Helper of the destructor, deletes the chain hanging off a vertex.
// Precondition: "current" is not equal to NULL.
// Postcondition: Recursively deletes the "adjacentVertex" nodes connected to
//   the original "adjacentVertex" passed, including itself.
// Cost Analysis: O(n)
// Visibility: private
void AdjacencyList::removeNext(adjacentVertex * current){
  if(current->next != NULL){
    removeNext(current->next);
  }
  delete current;
}

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
void AdjacencyList::addEdge(Edge * e){
  adjacentVertex * tempAdjacentVertex;
  node * tempNode;
  
  for(int i = 0; i < 2; i++){
    tempNode = arrayOfVertices;
    
    if(i == 0){
      tempAdjacentVertex = createNode(e, false);
      if(tempNode->name != e->first()){
        while(tempNode->name != e->first()){
          tempNode = tempNode->nextNode;
        }
      }
    }
    else{
      tempAdjacentVertex = createNode(e, true);
      if(tempNode->name != e->second()){
        while(tempNode->name != e->second()){
          tempNode = tempNode->nextNode;
        }
      }
    }
    if(tempNode->next == NULL){
      tempNode->next = tempAdjacentVertex;
    }
    else{
      adjacentVertex * current = tempNode->next;
      while(current->next != NULL){
        current = current->next;
      }
      current->next = tempAdjacentVertex;
    }
  }
}

// Prototype: adjacentVertex * createNode(Edge * e, bool useFirst);
// Description: Creates a pointer to an adjacentVertex using an Edge.
// Precondition: The value of "e" is not NULL and has been allocated. "useFirst"
//   is either given as true or false.
// Postcondition: Creates a new adjacent vertex with either the name of e->first()
//   or e->second() depending on the value of "useFirst". Sets the value of 
//   weight to be e->edgeWeight(), and sets "next" to be NULL.
// Cost Analysis: O(1)
// Visibility: private
adjacentVertex * AdjacencyList::createNode(Edge * e, bool useFirst){
  adjacentVertex * tempAdjacentVertex = new adjacentVertex;
  if(useFirst)
    tempAdjacentVertex->name = e->first();
  else tempAdjacentVertex->name = e->second();
  tempAdjacentVertex->weight = e->edgeWeight();
  tempAdjacentVertex->next = NULL;
  
  return tempAdjacentVertex;
}

// Prototype: void printAll();
// Description: Prints the values that are stored in the adjacency list, 
//   starting with the first vertex and listing all adjacent vertices, and 
//   proceeding to the last vertex and listing all adjacent vertices.
// Precondition: The variable "arrayOfVertices" has been allocated. 
// Postcondition: Calls "printNextNode()" on the first vertex.
// Cost Analysis: O(n^2)
// Visibility: public
void AdjacencyList::printAll(){
  if(arrayOfVertices != NULL)
    printNextNode(arrayOfVertices);
}

// Prototype: void printNextNode(node * current);
// Description: Prints the values that are stored in the adjacency list, 
//   starting with the "current" vertex and listing all adjacent vertices, and 
//   proceeding to the last vertex and listing all adjacent vertices.
// Precondition: The variable "current" has been allocated. 
// Postcondition: Prints information about the current vertex, recursively calls
//   "printNext()" and then recursively calls "printNextNode()".
// Cost Analysis: O(n^2)
// Visibility: private
void AdjacencyList::printNextNode(node * current){
  if(current != NULL){
    cout << "Node " << current->name << " - ";
    printNext(current->next);
    cout << endl;
    printNextNode(current->nextNode);
  }
}

// Prototype: void printNext(adjacentVertex * current);
// Description: Prints the values that are stored in adjacent vertices.
// Precondition: The variable "current" has been allocated. 
// Postcondition: Prints information about the current adjacent vertex and then
//   recursively calls "printNext()".
// Cost Analysis: O(n)
// Visibility: private
void AdjacencyList::printNext(adjacentVertex * current){
  if(current != NULL){
    cout << "(" << current->name << ":" << current->weight << ") ";
    printNext(current->next);
  }
}
