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

// Class Information
// Name: BinaryTree
// Description: Simulates a mathematical binary tree, allows for traversals, and 
// emptiness checking.
// Base Class: N/A
template<class Type>
class BinaryTree
{
public:
// Prototype: BinaryTree();
// Description: Default Constructor
// Precondition: N/A
// Postcondition: Creates a binary tree that is empty
// Cost Analysis: O(c)
// Visibility: public
    BinaryTree(); 
    
// Prototype: BinaryTree(Type info);
// Description: Parameterized Constructor for one-node tree
// Precondition: N/A
// Postcondition: Creates a binary tree with only one node, with that node having
// the information of "Type info" and two empty subtrees.
// Cost Analysis: O(c)
// Visibility: public
    BinaryTree(Type info); 
    
// Prototype: BinaryTree(Type info, BinaryTree<Type> * left, BinaryTree<Type> * right);
// Description: Parameterized Constructor for a tree made up of subtrees
// Precondition: N/A
// Postcondition: Creates a binary tree with a node having the information of "info"
// and two subtrees *left and *right.
// Cost Analysis: O(c)
// Visibility: public
    BinaryTree(Type info, BinaryTree<Type> * left, BinaryTree<Type> * right);

// Prototype: ~BinaryTree()
// Description: Destructor
// Precondition: The binary tree has been allocated
// Postcondition: deallocates the memory used by this object
// Cost Analysis: O(n)
// Visibility: public
    ~BinaryTree();   

// Prototype: void inOrder();
// Description: Performs an inorder traversal of this tree, outputting the value 
// at the root node.
// Precondition: The binary tree must be initialized.
// Postcondition: N/A
// Cost Analysis: O(n)
// Visibility: public
    void inOrder() const;

// Prototype: void preOrder();
// Description: Performs a preorder traversal of this tree, outputting the value 
// at the root node.
// Precondition: The binary tree must be initialized.
// Postcondition: N/A
// Cost Analysis: O(n)
// Visibility: public    
    void preOrder() const;

// Prototype: void postOrder();
// Description: Performs a postorder traversal of this tree, outputting the value at the root node.
// Precondition: The binary tree must be initialized.
// Postcondition: N/A
// Cost Analysis: O(n)
// Visibility: public
    void postOrder() const;
    
// Prototype: bool isEmpty();
// Description: Helps to determine if there are any values stored in the binary tree.
// Precondition: The binary tree must be initialized.
// Postcondition: Returns true if the tree is empty, false if the tree is not empty.
// Cost Analysis: O(n)
// Visibility: public
    bool isEmpty() const; 

private:
        
// Name: root
// Description: The root of this binary tree. Contains information to two subtrees (possibly). 
// Contains information about itself (this node).
// Type: Node<Type>
// Range of acceptable values: Any value that corresponds to the template Node<Type>.
    Node<Type> * root;
};

#endif
