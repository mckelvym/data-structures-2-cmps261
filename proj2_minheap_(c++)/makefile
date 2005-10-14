# Class    : CMPS 261
# Section  : 001
# Problem  : Programming Assignment #2
# Name     : McKelvy, James Markus
# CLID     : jmm0468
# Due Date : 12:30pm October 20, 2005
#  --* Certification of Authenticity *--
#  I certify that this assignment is entirely my own work.
# makefile

main : main.o minHeap.o
	CC -o main main.o minHeap.o
main.o : main.cpp minHeap.h
	CC -c main.cpp
minHeap.o : minHeap.cpp minHeap.h
	CC -c minHeap.cpp

clean:
	rm -rf *.o SunWS_cache
