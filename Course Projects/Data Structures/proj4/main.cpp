/* 
Assignment 4
Find the relevance of documents
Due: 7 Nov 2012
By: Paul Kafka
This program uses my Binary Search Tree class to store
all the words from each file.
*/
// Libraries used
#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<algorithm>

using namespace std;
#include "file.h"

int main(int argc, char* argv[])
/* assuming the user follows the iput form corectly like: 
n >=0. a or q followed by a string or int*/
{
	vector<File> file_vector; 		// a vector container of Relevance objcts named relobjects
    vector<File>::iterator itr;		// iterator for the vector
	bool anyRelevant = 0;	// used to output message
	bool flag2 = false;
	
	// if there are more arguments besides the program name
	if (argc != 1) {
		for (int k=1; k < argc; k++) {					
			string filename = argv[k],input;		// loop the commands equal a string
			file_vector.push_back(File(filename));  // make a file object for each string
		}
	}

	// Variables
	char read1;		// for first charcter read (a, q, x)
	int  read2;		// If the 2nd input was a int, read this in
	string read3;	// stores the word list
	
	bool found = false; 					// to store if a file object already exists
	vector<string> words_vector; 			// a vector container of words
    vector<string>::iterator words_itr;		// iterator for the words vector
	vector<float> relative_vector; 			// a vector container of relevance word list
    vector<float>::iterator rel_itr;		// iterator for the wordlist vector
	char temp;								// temp char for peeking at keyboard input
	vector<float>::iterator maxy; 			// stores the temp max data,
	
	
	cin >> read1; 				// Start Reading input (first char)
	if ( read1 == 'x')
		return 0; 				// terminate program
	
	// Main Loop
	while ( read1 != 'x') {
		if (read1 == 'a'){				// USER INPUTTED a :Analyzed a File
			cin >> read3;
			//Find inputed file object and Analyzes it again (if found)
			for (itr = file_vector.begin(); itr != file_vector.end(); ++itr){
				if (itr->Getfilename() == read3) { 
					itr->Analyze();
					found = true;
				}
			}
			if (found ==false) 	// If the file wasnt found, output
					cout << "File " << read3 << " does not exist\n";
		}						
		else if (read1 =='q'){ 			// USER INPUTTED q	: Print Relevance List									
			cin >> read2;
			// Loops until all the words are inputed
			temp = cin.peek();
			while (temp != '\n') {
				cin >> read3;
				words_vector.push_back(read3); 	// stores the query in a vector
				temp = cin.peek();
			}
			
			// cylce through files and stores the relevance into vector of same size
			// if the file had no relevance than returns =-1.
			for (itr = file_vector.begin(); itr != file_vector.end(); ++itr)	
					relative_vector.push_back(itr->
					Relevance(words_vector));
			
			// from the relevance vector, I print the top n filenames that are most relevant
			// using max() to get most relevant. Then delete that from the list and use max() again n times
			// if it is less than n, no more files output because they = -1.
			for (int j=0; j < read2; j++) {		// cycles n times
				
				maxy = max_element(relative_vector.begin(), relative_vector.end());			// Find max relevance
				for (rel_itr = relative_vector.begin(); rel_itr != relative_vector.end(); ++rel_itr) {	// cycle relevance
					for (itr = file_vector.begin(); itr != file_vector.end(); ++itr)	{				// cycle file objects
						if (*maxy == *rel_itr)	{				// if max is found in the relative vector
							if (*maxy >0)	{// if the max is positive
								cout << itr->Getfilename() << " " << *maxy <<  endl;   // output filename and relevance
								anyRelevant = 1;
							}
							*rel_itr =-1; // removes the max value(by setting to -1) so can calculate a the next one
						}
					}
				}
			}
			if (anyRelevant == 0)
				cout << "No matching document " << endl;
			anyRelevant =0;
		} 
		else if (read1 =='p'){ 			// USER INPUTTED p	: Print Relevance List	
			cin >> read2; // reads in n
			cin >> read3; // reads filename
			for (itr = file_vector.begin(); itr != file_vector.end(); ++itr){
				if ((itr->Getfilename() == read3) && (itr->wasAnalyzed() == true))  { 
						itr->Print(read2);// output first n words in preorder traversal
						flag2 = true;
				} 
			}
			if (flag2 == false)
				cerr << "File " << read3 << " has not been analyzed" <<endl;	
		}
		else
			cout << "invalid command" << endl;
		cin >> read1; // read command 1 again.
	}
	return 0;
}
