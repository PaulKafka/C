CC = g++ -Wall -pedantic -O3

all: proj2
	
proj2 : main.o
	$(CC) -o proj2 main.o

main.o : main.cpp 
	$(CC) -c  main.cpp

tar: clean
	tar cvf proj2.tar ./*

clean :
	rm -f *.o proj2
