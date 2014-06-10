#By: Paul Kafka
SHELL = /bin/sh
CCC = g++
CCFLAGS = -Wall  -g -pedantic
#CCFLAGS = -Wall  -O3 -pedantic
INCLUDES = -I. 

Retrieve: main.o file.o
	$(CCC) $(CCFLAGS) -o Retrieve main.o file.o
 
main.o : main.cpp file.h
	$(CCC) -c $(CCFLAGS) $(INCLUDES) main.cpp
 
file.o : file.cpp file.h binarysearchtree.h
	$(CCC) -c $(CCFLAGS) $(INCLUDES) file.cpp
 
 
.SUFFIXES :
 
clean :
	rm -f *.o *~ *.i
 
realclean :
	rm -f *.o *~ *.i
