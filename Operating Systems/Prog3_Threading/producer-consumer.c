/* 
Project 3 - Concurrency with Threads (Part 2)
By: Paul Kafka
Description: gain experience with concurrency  using threads.
*/ 

// Libraries
#include "buffer.h"				// for the buffer size
#include <unistd.h>			// for sleep();
#include <stdlib.h>			// required for rand() 
#include <stdio.h>				// printf()
#include <pthread.h>			// for threads and mutex
#include <semaphore.h>	// for semephore sem_t full, empty
#define TRUE 1

// Function Prototypes
void *producer(void *param); 				// the producer thread
void *consumer(void *param); 				// the consumer thread
int insert_item(buffer_item item);			// Producer calls this to insert item into buffer
int remove_item(buffer_item *item);		// Consumer calls this to remove item from buffer

	// Variables
	pthread_mutex_t mutex; 	// The mutex lock
	sem_t full, empty;				// the semaphores
	int counter=0;					// buffer counter
	int i=0;
	pthread_t tid;       				//Thread ID
	pthread_attr_t attr; 			//Set of thread attributes
	buffer_item buffer[BUFFER_SIZE];

int main(int argc, char *argv[]) {

	// 1. Get Command Arguements
	int sleep_time = atoi(argv[1]);
	int num_consumers = atoi(argv[2]);
	int num_producers = atoi(argv[3]);

	// 2. Initialize
	pthread_mutex_init(&mutex, NULL); // Creates the mutex lock
	sem_init(&full, 0, 0); 						//Create the full semaphore and initialize to 0
	sem_init(&empty, 0, BUFFER_SIZE); 	//Create the empty semaphore and initialize to BUFFER_SIZE 
	pthread_attr_init(&attr);						// Get the default attributes 
	
	// 3. Create producer thread(s)
	for(i = 0; i < num_producers; i++) {
      pthread_create(&tid,&attr,producer,NULL);  //Create the thread
    }

	// 4. Create consumer thread(s)
	for(i = 0; i < num_consumers; i++) {
      pthread_create(&tid,&attr,consumer,NULL); //Create the thread
	}

	// 5. Sleep 
	sleep(sleep_time);

	// 6. End program
	exit(0);
}	

/* 
-------------------------------------------------------------------------
-                   FUNCTION DEFINITIONS               -
-------------------------------------------------------------------------
*/
void *producer(void *pararn) {
/* This function adds a random number to to the 
critical section (buffer)by using a mutex. */
	
	buffer_item item;

	while (TRUE) {
		// sleep for a random period of time
		int rNum = rand() / 400000000;
		sleep(rNum);
	
		item = rand();	// item is random number
		
		sem_wait(&empty);				// acquire the empty lock 
		pthread_mutex_lock(&mutex); // lock the thread
		
		// Insert the item into the buffer
		if (insert_item(item))
			fprintf(stderr, "report error condition for Producer");
		else
			printf("Producer produced %d\n",item);
		
		pthread_mutex_unlock(&mutex);		// unlock the thread
		sem_post(&full);							// signal is full
	}
}
/* ---------------------------------------------------------------------- */
void *consumer(void *pararn) {
/* This function adds a random number to to the 
critical section (buffer)by using a mutex. */

	buffer_item item;
	
	while (TRUE) {
		// sleep for a random period of time
		int rNum = rand() / 400000000;
		sleep (rNum);
		
		sem_wait(&full);						// aquire the full lock
		pthread_mutex_lock(&mutex); // aquire the mutex lock
	  
		// Remove Item from buffer
		if (remove_item(&item))
			fprintf(stderr, "report error condition for Consumer");
		else
			printf("Consumer consumed %d\n",item);
		
		pthread_mutex_unlock(&mutex); // unlock the thread
		sem_post(&empty);  					// signal is empty
	}
}
/* ---------------------------------------------------------------------- */
int insert_item(buffer_item item) {
/* Inserts the item into the buffer
return 0 if successful.
return -1 error */

   if(counter < BUFFER_SIZE) {	// If buffer not full.
      buffer[counter] = item;	// Add item
      counter++;					// Incremement count
      return 0;
	}
	else  // Error. buffer full
		return -1;
}
/* ---------------------------------------------------------------------- */
int remove_item(buffer_item *item) {
/* Removes the item from buffer
return 0 if successful.
return -1 error */

   if(counter > 0) {		// If buffer is not empty
      *item = buffer[(counter-1)];	// Remove item
      counter--;							// Decrement count
      return 0;
	}
   else {  // Error. buffer empty
		return -1;
   }
}
/* ---------------------------------------------------------------------- */