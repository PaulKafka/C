// Assignment 2
// Recursive Function
// By: Paul Kafka

#include <iostream>
#include <cstdlib>		// converting strings to ints
#include <string>

using namespace std;

int recurse(int[],int,string); 	 // Function decleration

int main(int argc, char* argv[]) // read from command line
{
	if( argc != 14) {
		cout << argv[0] << "Invalid Input" << endl;
		exit(1);
	}
	
	int array[11]; //initializes my array
	// N1 C1 A1 M1 M2 M3 M4 D1 D2 S1 S2 Arg Op
	
	//convert string arguments to numbers
	for(int i = 0; i < (argc-3); i++)
		array[i] = atoi(argv[i+1]);
		
	string op = argv[argc-1];			//the +/- operator
	int Arg = atoi(argv[argc-2]);
	
	//prints the recursion output
	cout << recurse(array, Arg, op) << endl;
	
	return 0;
 }

int recurse(int number[],int N, string op)
// takes the array of numbers, the N, and the operator
{
	//f(N) = 0, if N < N1
	if(N < number[0])				
		return 0;
	//f(N1) = C1
	else if (N == number[0])		
		return number[1];
	else {							
		// f(N)= A1 + M1*f(M2*N/D1 - S1) Op M3*f(M4*N/D2 - S2), if N > N1
		if (op == "-") {	// MINUS
			return (number[2] + number[3]*recurse(number,
			(number[4] * N/number[7]-number[9]),op)-
			(number[5]*recurse(number,(number[6]*N/number[8] 
			- number[10]),op)));
		}
		else {				// PLUS
			return (number[2] + number[3]*recurse(number,
			(number[4] * N/number[7]-number[9]),op)+ 
			(number[5]*recurse(number,(number[6]* N/number[8] 
			- number[10]),op)));
		}
	}
}
























