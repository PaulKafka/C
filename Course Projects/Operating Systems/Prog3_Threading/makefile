#Paul Kafka's Makfile
#Program 3
CC = gcc -lpthread

all: producer-consumer matrix
	
producer-consumer : producer-consumer.o
	$(CC) -o producer-consumer.x producer-consumer.o

producer-consumer.o : producer-consumer.c 
	$(CC) -c producer-consumer.c
	
matrix : matrix.o
	$(CC) -o matrix.x matrix.o

matrix.o : matrix.c 
	$(CC) -c matrix.c

clean :
	rm -f *.o matrix
	rm -f *.o producer-consumer