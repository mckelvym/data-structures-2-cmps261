# Class    : CMPS 261
# Section  : 001
# Problem  : Programming Assignment #3
# Name     : McKelvy, James Markus
# CLID     : jmm0468
# Due Date : 12:30pm November 3, 2005
#  --* Certification of Authenticity *--
#  I certify that this assignment is entirely my own work.
# makefile

main : main.o Edge.o minHeap.o UnionFind.o AdjacencyList.o
	CC -o main main.o Edge.o minHeap.o UnionFind.o AdjacencyList.o
main.o : main.cpp Edge.h
	CC -c main.cpp
AdjacencyList.o : AdjacencyList.cpp AdjacencyList.h Edge.h adjacentVertex.h
	CC -c AdjacencyList.cpp
UnionFind.o : UnionFind.cpp UnionFind.h
	CC -c UnionFind.cpp
minHeap.o : minHeap.cpp minHeap.h
	CC -c minHeap.cpp
Edge.o : Edge.cpp Edge.h
	CC -c Edge.cpp

clean:
	rm -rf *.o SunWS_cache
