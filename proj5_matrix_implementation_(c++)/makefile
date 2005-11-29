# Class    : CMPS 261
# Section  : 001
# Problem  : Programming Assignment #5
# Name     : McKelvy, James Markus
# CLID     : jmm0468
# Due Date : 12:30pm December 1, 2005
#  --* Certification of Authenticity *--
# I certify that this assignment is entirely my own work, aside from original
# implementation by Damon Dischler and modifications/corrections by Mark Radle.
# makefile

main : main.o Matrix.o
	CC -o main main.o Matrix.o
main.o : main.cpp Matrix.h
	CC -c main.cpp
Matrix.o : Matrix.cpp Matrix.h
	CC -c Matrix.cpp

clean:
	rm -rf *.o SunWS_cache
