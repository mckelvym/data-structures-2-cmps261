// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #1
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm September 22, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// BinaryTree.cpp

#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

using namespace std;

template<class Type>
BinaryTree<Type>::BinaryTree()
{
  // empty binary tree
  // root is equal to NULL                              
  root = NULL;                              
}

template<class Type>
BinaryTree<Type>::BinaryTree(Type info)
{
  // one node binary tree                                  
  root = new Node<Type>;
  root->NodeType_Info = info;
  
  // children are NULL
  root->left = NULL;
  root->right = NULL;                                  
}

template<class Type>
BinaryTree<Type>::BinaryTree(Type info, BinaryTree<Type> * left, BinaryTree<Type> * right)
{
  // create a binary tree with subtrees                                  
  root = new Node<Type>;
  root->NodeType_Info = info;
  
  // make sure the left tree is not empty before pointing to it
  if(!(left == NULL) && !(left->isEmpty()))
    root->left = left;
  else root->left = NULL;
  
  // make sure the right tree is not empty before pointint to it
  if(!(right == NULL) && !(right->isEmpty()))
    root->right = right;                                   
  else root->right = NULL;
}

template<class Type>
BinaryTree<Type>::~BinaryTree()
{
  // check that this tree is not empty                               
  if(root != NULL){
    // check that the left child is not empty          
    if(root->left != NULL)
      delete root->left;
    // check that the right child is not empty      
    if(root->right != NULL)
      delete root->right;
    delete root;
  }                               
}

template<class Type>
void BinaryTree<Type>::inOrder() const
{
  // check that this tree is not empty     
  if(root != NULL){
    if(root->left != NULL){
      root->left->inOrder();
    }
    // output info to screen
    visit(root->NodeType_Info);
    if(root->right != NULL){
      root->right->inOrder();
    }
  }   
}

template<class Type>
void BinaryTree<Type>::preOrder() const
{
  // check that this tree is not empty
  if(root != NULL){
    // output the info to the screen           
    visit(root->NodeType_Info);
    if(root->left != NULL){
      root->left->preOrder();
    }
    if(root->right != NULL){
      root->right->preOrder();
    }
  } 
}

template<class Type>
void BinaryTree<Type>::postOrder() const
{
  // check that this tree is not empty
  if(root != NULL){
    if(root->left != NULL){
      root->left->postOrder();
    }
    if(root->right != NULL){
      root->right->postOrder();
    }
    // output the info to the screen
    visit(root->NodeType_Info);
  }  
}

template<class Type>
bool BinaryTree<Type>::isEmpty() const
{
  // if the tree is empty, true is returned
  // else false is returned
  return(root == NULL);
}

// Prototype: void visit(Type info);
// Description: Function to output the information at a node.
// Precondition: Must be passed data of type 'Type'
// Postcondition: Outputs the data passed to it to the standard output stream.
// Cost Analysis: O(c)
// Visibility: private
template<class Type>
void visit(Type info){
  cout << info << " ";
}
