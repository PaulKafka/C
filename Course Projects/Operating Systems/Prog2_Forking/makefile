CC = gcc47

all: myshell
	
myshell : myshell.o
	$(CC) -o myshell.x myshell.o

myshell.o : myshell.c 
	$(CC) -c myshell.c

clean :
	rm -f *.o myshell
