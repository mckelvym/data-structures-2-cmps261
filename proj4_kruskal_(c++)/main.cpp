// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #4
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm November 15, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// main.cpp

/* Name: Minimal Spanning Tree using Kruskal's Algorithm
   Problem Statement: Implement Kruskal's Algorithm for generating the Minimal 
   Spanning Tree for a graph. The implementations should input a graph and 
   output the set of edges from the graph that make up the MST.
   Problem Specification: The implementation must utilize a templated minHeap 
   class to hold the edges that will be processed from smallest to largest, by 
   weight. The graph should be stored internally using an Adjacency List Class. 
   The implementation must also utilize a UnionFind class to assist in 
    when an edge will cause a cycle.
*/

#include<iostream>
#include<cstdlib>
#include "Edge.h"
#include "AdjacencyList.h"
#include "minHeap.h"
#include "UnionFind.h"

using namespace std;

int main(){
    int vertices;            // number of vertices in the graph
    int edges;               // number of edges in the graph
    int edges_accepted = 0;  // total edges in the mst
    int p1, p2;              // used for "find()" on edges
    AdjacencyList * adjlist; // holds the mst
    Edge * e = new Edge;     // an edge on the graph
    minHeap<Edge> * heap;    // for getting the smallest edge
    UnionFind * unionfind;   // checking if an edge will create a cycle
    
    // how many edges?
    cout << "|E|: ";
    cin >> edges;
    // how many vertices?
    cout << "|V|: ";
    cin >> vertices;
    cout << endl << "Input: vertex1 vertex2 weight" 
         << endl << endl;
    
    // allocate memory for our objects
    
    // will have "vertices" number of vertices
    adjlist = new AdjacencyList(vertices);
    // will have "edges" number of edges
    heap = new minHeap<Edge>(edges);
    // will have "vertices" number of partitions
    unionfind = new UnionFind(vertices);
    
    // get the edges from the user
    // will ask only as many times as there are edges
    for(int i = 0; i < edges; i++){
      cout << i+1 << ": ";
      cin >> e;
      heap->insert(*e);
    }
    
    // prepare to output the mst
    cout << "\n\nThe Minimal Spanning Tree for this graph contains the edges:\n\n";
    
    // loop until we have all the vertices connected
    while(edges_accepted < (vertices - 1)){
      // get the smallest edge off the heap
      *e = heap->removeMin();  
      // check to see that the two vertices are not already connected
      p1 = unionfind->Find(e->first());
      p2 = unionfind->Find(e->second());
      if(p1 != p2){
        // add this edge to the mst
        adjlist->addEdge(e);
        // update our union find so that we won't create a cycle
        unionfind->Union(e->first(), e->second());
        // update the number of edges on our mst
        edges_accepted++;
        // output the newly added edge to our mst to the user
        cout << edges_accepted << ". From vertex " << e->first() << " to "
             << e->second() << ", at a cost of " << e->edgeWeight() << ".\n";
      }
    }
    
    // and we're done        
    
    return 0;
}
