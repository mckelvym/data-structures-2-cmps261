// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #1
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm September 22, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// node.h

#ifndef NODE_H
#define NODE_H

using namespace std;

template <class NodeType>
struct Node
{
	NodeType NodeType_Info;
	BinaryTree<NodeType> * left;
	BinaryTree<NodeType> * right;
};

#endif
