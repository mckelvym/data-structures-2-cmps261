// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #1
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm September 22, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// BinaryTree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "Node.h"

using namespace std;

template<class Type>
class BinaryTree
{
public:
    // empty tree constructor
    BinaryTree(); 
    
    // one-node tree constructor
    BinaryTree(Type info); 
    
    // tree with subtrees constructor
    BinaryTree(Type info, BinaryTree<Type> * left, BinaryTree<Type> * right);

    // destructor
    ~BinaryTree();   
    
    void inOrder() const;
    
    void preOrder() const;
    
    void postOrder() const;
    
    bool isEmpty() const; 

private:
    Node<Type> * root;
};

#endif
