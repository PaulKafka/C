/* 
Project 3 - Concurrency with Threads (Part 1)
By: Paul Kafka
Description: gain experience with concurrency using threads.
*/ 

// Libraries
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Definitions
#define M 3
#define K 2
#define N 3

// Matricies
int A [M][K] = { {1,4}, {2,5} ,{3,6}};
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];

// Struct for a Matrix Element
struct v {
	int i; // Row
	int j; // Column
};

void *runner(void *param); // The thread function

int main(int argc, char *argv[]) {

	int i,j,count;
	
	//Print A
	printf("Matrix A:\n");
	for(i = 0; i < M; i++) {
		for(j = 0; j < K; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
   
    //Print B
	printf("Matrix B:\n");
	for(i = 0; i < K; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	// Create the Threads
	printf("Matrix C = AB:\n");
	i,j, count = 0;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
		 //Assign a row and column for each thread
		 struct v *data = (struct v *) malloc(sizeof(struct v));
		 data->i = i;
		 data->j = j;
		 pthread_t tid;       //Thread ID
		 pthread_attr_t attr; //Set of thread attributes
		 pthread_attr_init(&attr); //Get the default attributes
		 pthread_create(&tid,&attr,runner,data); //Create the thread
		 pthread_join(tid, NULL);//Make sure the parent waits for all thread to complete
		 count++;
		 }
	}

	// Print Matrix C 
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}	// End of Main


void *runner(void *param) {
// The Thread Function

	struct v *data = param; // struct with data
	int n, sum = 0; //the counter and sum
	
	//Row x Column
	for(n = 0; n< K; n++){
		sum += A[data->i][n] * B[n][data->j];
	}
  
   C[data->i][data->j] = sum; //assign the sum to its coordinate

  
   pthread_exit(0);  //Exit the thread
}
