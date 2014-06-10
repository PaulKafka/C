#Paul Kafka's Makfile
#Program 1

CC = gcc 

all: myshell.x
	
myshell.x : myshell.o
	$(CC) -o myshell.x myshell.o

myshell.o : myshell.c 
	$(CC) -c myshell.c

clean :
	rm -f *.o myshell