# Class    : CMPS 261
# Section  : 001
# Problem  : Programming Assignment #1
# Name     : McKelvy, James Markus
# CLID     : jmm0468
# Due Date : 12:30pm September 22, 2005
#  --* Certification of Authenticity *--
#  I certify that this assignment is entirely my own work.
# makefile

main : main.o BinaryTree.o
	CC -o main main.o BinaryTree.o
main.o : main.cpp BinaryTree.h
	CC -c main.cpp
BinaryTree.o : BinaryTree.cpp BinaryTree.h Node.h
	CC -c BinaryTree.cpp

clean:
	rm -rf *.o SunWS_cache
