#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
#include "file.h"
using namespace std;

File::File(string f)
// Constructor for the class.
// Takes in a filename and analyzes it
{ 
    filename = f;
	analyzed = false;
	Analyze();	// go get analyzed
}

void File::Analyze()
// This function calculates and stores the weight
// of all the words and the words in the file/object.
// I tried to check for delimeters, but I couldnt get it in time.
{
	string word;	// stores the word read from file
	
	// This just takes the strings with no concern from white space
	// Delemeters werent checked
	if (analyzed == false) {	// checked to see if it has been analyzed
		ifstream *infile=new ifstream(filename.c_str(), ios::in);	// allocate
		*infile >> word;
		while (!infile->eof()) {	// loop until end of file
			words.push_back(word);	// add to word vector
			*infile >> word;		// read next word
		}
		delete infile;	// deallocate
	}
	
	float tempWeight=0;	// stores the temp weight of a word
	  
	// loop through weight vecotr
	for (words_itr=words.begin(); words_itr !=words.end(); ++words_itr){	// Loop through the words vector
		tempWeight = (int) count (words.begin(), words.end(), *words_itr);	// store the word count
		tempWeight = 	(float)	tempWeight	/ words.size();					// change the count = weight using size function 
		weight.push_back(tempWeight);										// store in weight vector
		} 
	
	//removes duplicates in the weight vector
	// this is done so the relevance can be calculated correctly
	sort( weight.begin(), weight.end() );
	weight.erase( unique( weight.begin(), weight.end() ), weight.end() );

	analyzed = true;	// this file object was analyzed

	// The stuff below are all my failed attempts for parsing the string and
	// checking for delimeters.
/////////////////////////////////////////////////////////////////////////////
	/*
	for (words_itr=words.begin(); words_itr !=words.end(); ++words_itr)			// Loop through the words vector
			cout << "_" << *words_itr << "_" << endl;
			
	for (words_itr=words.begin(); words_itr !=words.end(); ++words_itr)	{		// Loop through the words vector
			if (*words_itr == "at")
			*words_itr.erase (words_itr, 1 );
			//if (*words_itr == "at")
				//words_itr->erase (std::remove(words.begin(), words.end(), *words_itr), words.end());
				}
			
	for (words_itr=words.begin(); words_itr !=words.end(); ++words_itr)			// Loop through the words vector
			cout << "_" << *words_itr << "_" << endl;
	
	//now that they are in a vector, i can go back through all the words and take out the delimeters and
	//push more words out.
	*/

	/*
	// set the ifstream pointer to a new ifstream object using filename
    ifstream *infile=new ifstream(filename.c_str(), ios::in);
	string line;
    string token;
    stringstream iss;
	
    while (getline(*infile, line)) {
        iss << line;
        while ((getline(iss, token, '\'')) || (getline(iss, token, '!')) || 
				(getline(iss, token, '(')) || (getline(iss, token, ')')) || 
				(getline(iss, token, '-')) || (getline(iss, token, ':')) || 
				(getline(iss, token, ';')) || (getline(iss, token, '\"')) || 
				(getline(iss, token, ',')) || (getline(iss, token, '.')) || 
				(getline(iss, token, '/')) || (getline(iss, token, '?')) || 
				(getline(iss, token, '\n')) || (getline(iss, token, ' ')) || 
				(getline(iss, token, '\t'))) 
        {
			getline(token, 
			words.push_back(token);
           // cout << token << endl;
        }
        iss.clear();
    } */
	
	// now find the weight and store in a container
	/*
	*infile >> temp;
	//temp = *infile.peek();
	while ((|| (temp != '-') || 
		  (temp != ':') || (temp != ';') || (temp != '\"') || (temp != ',') || 
		  (temp != '.') || (temp != '/') || (temp != '?') || (temp != '\n') || 
		  (temp != ' ') || (temp != '\t'))
	{
		*infile >> word;
		word += temp;
		words.push_back(word); 				// stores all the words in a vector
		*infile >> temp;//temp = *infile.peek(); //temp = cin.peek();
		cout << word << endl;
	}
    delete infile;				// deallocate memory
	*/
/////////////////////////////////////////////////////////////////////////////////////////
}

float File::Relevance(vector<string> s2)
// in main the command is "q n Word-List: "
// the vector of words are passed in.
// A document is relevant to a query(the input words) iff
// it contains each word in the query.
// relevance = sum of the weights of the words
// return -1 is not releative
{
	int numWords = s2.size();		// stores number of words in qury
	float relevance =0;			// Initializes relevance				

	vector<string>::iterator itr3;		// iterator for the passed in wordlist 

	// compare vector passed in with words vector to output use weight vector. 
	// If they have the same words, sum those words weight and return it
	// else return -1
	for (weight_itr=weight.begin(); weight_itr!=weight.end(); ++weight_itr) {	// loop through weights
	for (words_itr=words.begin(); words_itr!=words.end(); ++words_itr){			//loop through words
			for (itr3=s2.begin(); itr3 !=s2.end(); ++itr3){					// loop through the word list
				if (*words_itr == *itr3)	{							// If a word matches
					relevance += *weight_itr;	// record the relevance from weight vector and increment
					numWords--;					// countdown to see if all the words were found
				}
			}
		}
	}
	
	if (numWords > 0)	// No document had all the words
		return -1;
	else
		return relevance;
}

string File::Getfilename()
// Returns filename
{return filename;}

bool File::wasAnalyzed()
// Returns true if the file was analyzed
{return analyzed;}