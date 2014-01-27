#Paul Kafka's Makfile
#Program 4

CC = gcc 

all: clone
	
clone.x : clone.o
	$(CC) -o clone.x clone.o

clone.o : clone.c 
	$(CC) -c clone.c

clean :
	rm -f *.o clone