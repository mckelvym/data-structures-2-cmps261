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
#include<string>
#include "BinaryTree.h"

using namespace std;

int main(){
    cout << "Creating an empty binary tree." << endl;
    BinaryTree<char> * tree1 = new BinaryTree();
    cout << "Is tree1 empty? ";
    if(tree1.isEmpty())
      cout << "Yes." << endl;
    else
      cout << "No." << endl;
    cout << "Performing inorder traversal. " << endl;
    tree1.inOrder();
    cout << "Performing preorder traversal. " << endl;
    tree1.preOrder();
    cout << "Performing postorder traversal. " << endl;
    tree1.postOrder();
    delete tree1;
    
    system("PAUSE");
    
    cout << endl << "Creating a non-empty binary tree." << endl;
    BinaryTree<char> * tree2 = new BinaryTree('2');
    cout << "Is tree2 empty? ";
    if(tree2.isEmpty())
      cout << "Yes." << endl;
    else
      cout << "No." << endl;
    delete tree2;
    
    system("PAUSE");
    
    cout << endl << "Creating a binary tree with only one node." << endl;
    BinaryTree<char> * tree3 = new BinaryTree('3');
    cout << "Performing inorder traversal. " << endl;
    tree3.inOrder();
    cout << "Performing preorder traversal. " << endl;
    tree3.preOrder();
    cout << "Performing postorder traversal. " << endl;
    tree3.postOrder();
    delete tree3;
    
    cout << endl << "Creating a populated binary tree." << endl;
    BinaryTree<string> * ll2 = new BinaryTree("ll2", NULL, NULL);
    BinaryTree<string> * lr2 = new BinaryTree("lr2", NULL, NULL);
    BinaryTree<string> * l1 = new BinaryTree("l1", ll2, lr2);
    
    BinaryTree<string> * rl2 = new BinaryTree("rl2", NULL, NULL);
    BinaryTree<string> * rr2 = new BinaryTree("rr2", NULL, NULL);
    BinaryTree<string> * r1 = new BinaryTree("r1", rl2, rl2);
    
    BinaryTree<string> * root = new BinaryTree("root", l1, r1);
    
    cout << "Is root empty? ";
    if(root.isEmpty())
      cout << "Yes." << endl;
    else
      cout << "No." << endl;
    cout << "Performing inorder traversal. " << endl;
    root.inOrder();
    cout << "Performing preorder traversal. " << endl;
    root.preOrder();
    cout << "Performing postorder traversal. " << endl;
    root.postOrder();
    delete root;
    
    system("PAUSE");
    
    return 0;
}
