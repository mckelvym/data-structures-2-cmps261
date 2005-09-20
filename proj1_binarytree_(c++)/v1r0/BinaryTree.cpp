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
#include "Node.h"

using namespace std;

template<class Type>
BinaryTree<Type>::BinaryTree()
{
  root = NULL;                              
}

template<class Type>
BinaryTree<Type>::BinaryTree(Type info)
{
  root = new Node<Type>();
  root->NodeType_Info = info;
  root->left = NULL;
  root->right = NULL;                                
}

template<class Type>
BinaryTree<Type>::BinaryTree(Type info, BinaryTree<Type> * left, BinaryTree<Type> * right)
{
  root = new Node<Type>();
  root->NodeType_Info = info;
  root->left = left;
  root->right = right;                                 
}

template<class Type>
BinaryTree<Type>::~BinaryTree()
{
  if(root != NULL){
    if(root->left != NULL)
      delete root->left;
    if(root->right != NULL)
      delete root->right;
    delete root;
  }                              
}

template<class Type>
void BinaryTree<Type>::inOrder() const
{
  if(root != NULL){
    if(root->left != NULL){
      root->left.inOrder();
    }
    cout << root->NodeType_Info;
    if(root->right != NULL){
      root->right.inOrder();
    }
  }   
}

template<class Type>
void BinaryTree<Type>::preOrder() const
{
  if(root != NULL){
    cout << root->NodeType_Info;
    if(root->left != NULL){
      root->left.preOrder();
    }
    if(root->right != NULL){
      root->right.preOrder();
    }
  } 
}

template<class Type>
void BinaryTree<Type>::postOrder() const
{
  if(root != NULL){
    if(root->left != NULL){
      root->left.postOrder();
    }
    if(root->right != NULL){
      root->right.postOrder();
    }
    cout << root->NodeType_Info;
  }  
}

template<class Type>
bool BinaryTree<Type>::isEmpty() const
{
	return (root == NULL);
}
