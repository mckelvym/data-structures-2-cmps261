// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #1
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm September 22, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// main.cpp

#include<iostream>
#include<cstdlib>
#include<string>
#include "BinaryTree.h"

using namespace std;

void pause();

int main(){
    cout << "Creating an empty binary tree." << endl;
    BinaryTree<char> * tree1 = new BinaryTree<char>();
    cout << "Is tree1 empty? ";
    if(tree1->isEmpty())
      cout << "Yes." << endl;
    else
      cout << "No." << endl;
    cout << endl << "Performing inorder traversal. " << endl;
    tree1->inOrder();
    cout << endl << "Performing preorder traversal. " << endl;
    tree1->preOrder();
    cout << endl << "Performing postorder traversal. " << endl;
    tree1->postOrder();
    delete tree1;
    
    pause();
    
    
    cout << endl << "Creating a non-empty binary tree." << endl;
    BinaryTree<char> * tree2 = new BinaryTree<char>('2');
    cout << "Is tree2 empty? ";
    if(tree2->isEmpty())
      cout << "Yes." << endl;
    else
      cout << "No." << endl;
    delete tree2;
    
    pause();
    
    cout << endl << "Creating a binary tree with only one node." << endl;
    BinaryTree<char> * tree3 = new BinaryTree<char>('3');
    cout << endl << "Performing inorder traversal. " << endl;
    tree3->inOrder();
    cout << endl << "Performing preorder traversal. " << endl;
    tree3->preOrder();
    cout << endl << "Performing postorder traversal. " << endl;
    tree3->postOrder();
    cout << endl;
    delete tree3;
    
    pause();
    
    cout << endl << "Creating a populated binary tree." << endl;
    cout << "       root" << endl;
    cout << "      /    \\" << endl;
    cout << "    l1      r1" << endl;
    cout << "   /  \\    /  \\" << endl;
    cout << "ll2  lr2  rl2  rr2" << endl;
    cout << endl;
    BinaryTree<string> * ll2 = new BinaryTree<string>("ll2", NULL, NULL);
    BinaryTree<string> * lr2 = new BinaryTree<string>("lr2", NULL, NULL);
    BinaryTree<string> * l1 = new BinaryTree<string>("l1", ll2, lr2);
    
    BinaryTree<string> * rl2 = new BinaryTree<string>("rl2", NULL, NULL);
    BinaryTree<string> * rr2 = new BinaryTree<string>("rr2", NULL, NULL);
    BinaryTree<string> * r1 = new BinaryTree<string>("r1", rl2, rl2);
    
    BinaryTree<string> * root = new BinaryTree<string>("root", l1, r1);
    
    cout << "Is root empty? ";
    if(root->isEmpty())
      cout << "Yes." << endl;
    else
      cout << "No." << endl;
    cout << endl << "Performing inorder traversal. " << endl;
    root->inOrder();
    cout << endl << "Performing preorder traversal. " << endl;
    root->preOrder();
    cout << endl << "Performing postorder traversal. " << endl;
    root->postOrder();
    cout << endl;
    delete root;
    
    pause();

    return 0;
}

void pause(){
  cout << "Press ENTER.";
  getchar();
  cout << endl;
}