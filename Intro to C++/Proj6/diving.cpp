/* ========================================================================== */
/*	PROGRAM Diving: Famous Scientists Diving Competition

    AUTHOR: <Paul Kafka>
    FSU MAIL NAME: <PLK09d>
    RECITATION SECTION NUMBER: <1>
    RECITATION INSTRUCTOR NAME: <Joshua Lawrence>
    COP 3014 - Spring 2010
    PROJECT NUMBER: 6 
    DUE DATE: Wednesday 4/21/2010
    PLATFORM: Windows OS / Microsoft Visual C++ Express 2008 compiler 

SUMMARY

This program analyzing scores for an Olympic sport.  Twenty-four 
participants in a diving competition. Judged according to Olympic 
regulations. There will be two rounds of dives, and each participant
will make one dive per round.  Evaluate the results of these two 
initial rounds.

INPUT

The data file "diveData.txt".  

	BAD DATA CHECKING:  check to see if the file specified does 
	open, and if it does not, terminate the run using either return 
	in main or exit in another function, as discussed in lectures. 

OUTPUT

Print the results of round one and round two in two separate tables. 
These tables will include this information for each diver: name, 
degree of difficulty for the dive, the 7 scores, and the total 
score on this round. Next, print out a final standings table 
sorted in descending order by final total score for all divers with 
this information for each diver: name, final total score. Finally, 
print a list of the names of the 10 divers, also in descending
order ranked by score, who will be allowed to go on to the next competition.

ASSUMPTIONS

Assume that the data file is not empty and is completely correct.
/* ========================================================================== */


#include <iostream>					// standard I/O library
#include <fstream>					// file I/O library
#include <iomanip>					// output formatting routines
#include <string>					// C++ string class library

using namespace std;

// Global Constants
const int MAX_ROUNDS = 2;			// max rounds
const int MAX_SCORES = 7;			// max scores
const int MAX_DIVERS = 24;			// max participants

typedef double DifficultyLevel [MAX_ROUNDS];		 // typedef array of size 2
typedef double ScoresTable[MAX_ROUNDS][MAX_SCORES];  // rows and columbs


// Prototypes
void PrintIntro();
void PrintResults();
//void SortDivers	(int totalScore, diverList);
/* ================================================================ */
//struct
struct DiverRecs
{
	string name;					 // name
	double total_score;				 // total score
	DifficultyLevel difficuluties;   // array of size 2. 
	ScoresTable scores;				 // scores from scoretable

};

//typedef DiverRec DiverList[MAX_DIVERS];     // typedef the array
/* ================================================================ */

int main() // open and test it. passed by value for one structurte array.
{
	PrintIntro();				// prints an introduction

	//DiverList divers;			// all divers divers

	//divers[0].name;			// accesses the diver in the first item
	
	const char* inFileName = "diveData.txt";  // name of the input file

	ifstream inFile;			// data file

	// open file and exit if it fails
	inFile.open (inFileName);
	if (!inFile)
	{
		cout << "File cannot open" << endl;
		return (EXIT_FAILURE);
	}

	PrintResults();					// Prints the results

	inFile.close ();				// close file

	return 0;
}
/*
void SortDivers (int totalScore, diverList)

// Sorts an array of the diver records.
// using the selection sort algorithm. 

{	// SortDivers

	int
		start,		// index to first value in unsorted portion
		smallest,	// index to smallest value in unsorted portion
		current;	// used to scan array for "smallest" value

	DiverRec
		tempDiver;	// temporary storage for value during a swap 


	// perform totalScore - 1 passes
	for (start = 0; start < (totalScore - 1); start++)
	{
    	smallest = start;
        
    	
		// perform one exchange of diver records 
   		if (smallest != start)       
   		{                         
      		tempDiver = divers[start];
     		divers[start] = divers[smallest];
     		divers[smallest] = tempDiver;
   		}  

	}	// outer for loop

}    // SortDiver
*/
void PrintResults()
{  // printresults

	// This function takes no input from the caller. It prints
	// the result of the competition.
	// Called By: main

	// Prints reults
	cout << "Round 1: 2.3     6.0 5.0 6.7 7.8 5.6 8.9 7.6\n"
			 "Round 2: 2.1     6.0 5.0 6.5 7.8 5.6 8.8 5.0\n"
	<< endl << "Round 1 total is: 46.506\n"
				"Round 2 total is: 38.934\n"
				"Final total score is: 85.440" << endl;
	return;
}  // printresults

void PrintIntro() 
{  // print intro

	// This function takes no input from the caller. It prints
	// an introduction title.
	// Called By: main

	// Introduction
	cout << setw (20) << "*********************************\n"
		 << setw (25) << "Famous Scientists\n"
		 << setw (25) << "Diving Competition\n"
		 << setw (20) << "*********************************\n"
	<< endl;
	return;
} // print intro

/* ========================================================================== */
/*                           END OF PROGRAM                                   */
/* ========================================================================== */