// Class    : CMPS 261
// Section  : 001
// Problem  : Programming Assignment #1
// Name     : McKelvy, James Markus
// CLID     : jmm0468
// Due Date : 12:30pm September 22, 2005

//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// main.cpp

// Name: Generic Templated Binary Tree
// Problem Statement: A generic templated binary tree needs to be implemented, 
// with functions that allow inorder, preorder, and postorder traversal.
// Problem Specification: The program needs to be able to create an empty binary 
// tree, a binary tree with only one node and two empty subtrees, and a binary 
// tree with a root node and two (possibly) non-empty subtrees. Also the binary 
// tree needs to be able to tell if it is empty or not, meaning, is there data 
// stored in the nodes. The binary tree must also have its own methods of 
// traversal using inorder, preorder, and postorder traveral. There will be no 
// input into the binary tree aside from the initial creation of the binary 
// tree. The only output should be from a visit function that simply reveals 
// the contents of its root node.

// The main objective of the application is to utilize the implementation of the 
// BinaryTree class. The application's main driver will be used to test the 
// overall stability and integrity of the implementation of the BinaryTree class 
// by testing its creation and its various member methods including traversals. 
// The main driver will create three types of binary trees: an empty binary 
// tree; a binary tree with only one node; and a binary tree that has a root and 
// two subtrees that are referred to as leftTree and rightTree. The BinaryTree 
// class will create BinaryTree objects will that interact with each other in a 
// way that some BinaryTrees will be parents, and others children of each other.

#include<iostream>
#include<cstdlib>
#include<string>
#include "BinaryTree.h"

using namespace std;

// pauses for the user
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
    
    cout << "Is the tree empty? ";
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
    
    cout << endl << "Creating another populated tree." << endl;
    cout << "       o" << endl;
    cout << "     /   \\" << endl;
    cout << "   m       n" << endl;
    cout << "  / \\     / \\" << endl;
    cout << " i   j   k   l" << endl;
    cout << "/ \\ / \\ / \\ / \\" << endl;
    cout << "a b c d e f g h" << endl;
    
    BinaryTree<char> * i = new BinaryTree<char>('i', new BinaryTree<char>('a'), new BinaryTree<char>('b'));
    BinaryTree<char> * j = new BinaryTree<char>('j', new BinaryTree<char>('c'), new BinaryTree<char>('d'));
    BinaryTree<char> * k = new BinaryTree<char>('k', new BinaryTree<char>('e'), new BinaryTree<char>('f'));
    BinaryTree<char> * l = new BinaryTree<char>('l', new BinaryTree<char>('g'), new BinaryTree<char>('h'));

    BinaryTree<char> * m = new BinaryTree<char>('m', i, j);
    BinaryTree<char> * n = new BinaryTree<char>('n', k, l);
    
    BinaryTree<char> * o = new BinaryTree<char>('o', m, n);
    
    cout << "Is this tree empty? ";
    if(o->isEmpty())
      cout << "Yes." << endl;
    else
      cout << "No." << endl;
    
    cout << endl << "Performing inorder traversal. " << endl;
    o->inOrder();
    cout << endl << "Performing preorder traversal. " << endl;
    o->preOrder();
    cout << endl << "Performing postorder traversal. " << endl;
    o->postOrder();
    cout << endl;
    delete o;
    
    pause();

    return 0;
}

void pause(){
  cout << "Press ENTER.";
  getchar();
  cout << endl << "---------------------------" << endl;
}
