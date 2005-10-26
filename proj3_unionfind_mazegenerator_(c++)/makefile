# Class    : CMPS 261
# Section  : 001
# Problem  : Programming Assignment #3
# Name     : McKelvy, James Markus
# CLID     : jmm0468
# Due Date : 12:30pm November 3, 2005
#  --* Certification of Authenticity *--
#  I certify that this assignment is entirely my own work.
# makefile

main : main.o main.o MazeGenerator.o UnionFind.o
	CC -o main main.o MazeGenerator.o UnionFind.o
main.o : main.cpp MazeGenerator.h
	CC -c main.cpp
MazeGenerator.o : MazeGenerator.cpp MazeGenerator.h UnionFind.h
	CC -c MazeGenerator.cpp
UnionFind.o : UnionFind.cpp UnionFind.h
	CC -c UnionFind.cpp

clean:
	rm -rf *.o SunWS_cache
