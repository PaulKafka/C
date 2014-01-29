// getline to read name
// degree of difficulty is a double
// dont use getline to get numbers, use conversion. read them with a loop 7 times.
// learn typedef. arrays.
// use cpp in lecture to do function to sort. change numbooks to totalscore, booklist to diverlist, bookrec to diver rec(1 diver).
// dont have to do copy part. (copy1st, copy2nd sting lower etc.
// everything that u read from the file goes into the struct.
// echoprint. index the rounds(2), use forloop.

#include <iostream>  // this is all a 2d ray
#include <fstream>
#include <string>

using namespace std;

const int MAX_ROUNDS = 2;
const int MAX_SCORES = 7;
const int MAX_DIVERS = 24;

typedef double DifficultyLevel [MAX_ROUNDS];   // typedef array of size 2
typedef double ScoresTable[MAX_ROUNDS][MAX_SCORES];  // rows and columbs

//struct
struct DiverRecs
{
	string name;
	double total_score;     // calculated not read. initial value is 0. in the end += to the other.
	DifficultyLevel difficuluties; // array of size 2. 
	ScoresTable scores;

};

typedef DiverRec DiverList[MAX_DIVERS];     // typedef the array

int main() // open and test it. passed by value for one structurte array.
{
	DiverList divers;		// all divers divers

	divers[0].name;			// accesses the diver in the first item
	


	return 0;
}