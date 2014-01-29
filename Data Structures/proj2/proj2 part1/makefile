# Makefile for Assignment 2
# By: Paul Kafka

CCC = g++
CCFLAGS = -Wall  -g -pedantic
INCLUDES = -I.

recurse: main.o
	$(CCC) $(CCFLAGS) -o recurse main.o

main.o : main.cpp 
	$(CCC) -c $(CCFLAGS) $(INCLUDES) main.cpp

tar: clean
	tar cvf proj2.tar ./*

.SUFFIXES :

clean :
	rm -f *.o *~ *.i core

realclean :
	rm -f *.o *~ *.i core proj2
