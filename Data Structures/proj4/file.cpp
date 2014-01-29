// Assignment 4
// By: Paul Kafka
// This class uses my BST class to 
// store the words from each file

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<ctype.h>
#include<cstdlib>
#include<algorithm>
#include "file.h"   // This file contains my "binarysearchtree.h" class
					// where the words are stored like the
					// Assignment asked for.

// This function Declaration is used to parce the string input
static string nxtWrd(string &S, string::size_type &p1, string::size_type &p2);

using namespace std;

File::File(string f)
// Constructor for the class.
// Takes in a filename and analyzes it
{ 
	numWords=0;
    filename = f;
	analyzed = false;
	Analyze();	// go get analyzed
}

void File::Analyze()
// This function calculates and stores the weight
// of all the words and the words in the file/object.
// Srinivasan's examlpe solution to Assignment 1
// helped me understand and write the string parcing.
{
	string word;	// stores the word read from file
	string::size_type position1=0, position2=0;
	//int count = 0;
	
	if (analyzed == false) {	// checked to see if it has been analyzed
		ifstream InputFile(filename.data(), ios::in|ios::binary|ios::ate); // get pointer at end of file
  		ifstream::pos_type size;	// get size
  		string FileContent;			// holds all the file data
		if(!InputFile)
    		return;
		size = InputFile.tellg();    	// Find file size
		char *buffer = new char[size]; 	// Allocate memory to store file contents
	  	InputFile.seekg(0, ios::beg);
		InputFile.read(buffer, size); 	// Read the file contents
	  	FileContent.clear();
	  	FileContent.append(buffer, buffer+size);
	  	delete [] buffer;
	  	InputFile.close();
 	
		// Parcing the FileContent, and adding to BST
		while(position1 != string::npos) {
			word = nxtWrd(FileContent, position1, position2);
		  	if(position1 == string::npos)
				break;
			if (words.search(word) == false) {
				words.push(word);			// add to BST if it is NEW
				weight.push_back(1);
			}
			else {
				//weight.pop;
				//weight.push_back(1);
			// it is found, so delete it, pop a weight, and then add it again with an incremented weight
				//for (weight_itr=weight.begin(); weight_itr !=weight.end(); ++weight_itr) {
				//	if (*weight_itr) 
					//	*weight.itr++;
			}
			numWords++;	// counts number of words in file
			position1 = position2;
		}
		for (weight_itr=weight.begin(); weight_itr !=weight.end(); ++weight_itr)
			*weight_itr = *weight_itr/numWords;
	}
	analyzed = true;	// this file object was analyzed
	
	//words.PrintPreorder(-2);
	//cout << endl;
	
	//float tempWeight=0;	// stores the temp weight of a word
	// stores the weight 
	/* 
	List<string>::iterator temp_itr;	// temp iterator 
	// loop through weight vector
	for (words_itr=words.begin(); words_itr !=words.end(); ++words_itr){	// Loop through the words linked list
			for (temp_itr=words.begin(); temp_itr !=words.end(); ++temp_itr) {
				if (*words_itr == *temp_itr) 
					count++; 
			}
		tempWeight = 	(float)	count	/ words.Size();					// change the count = weight using size function 
		weight.push_back(tempWeight);										// store in weight vector
		//cout << *words_itr << "_";  // prints inputed words
		count = 0;	// reset counter
		
	} 
	
	// removes duplicates in the weight vector
	// this is done so the relevance can be calculated correctly
	sort( weight.begin(), weight.end() );
				//cout << endl;
				//for (weight_itr=weight.begin(); weight_itr !=weight.end(); ++weight_itr)
				//cout << " " <<  *weight_itr; 
				//cout << endl;
	weight.erase( unique( weight.begin(), weight.end() ), weight.end() );
				//for (weight_itr=weight.begin(); weight_itr !=weight.end(); ++weight_itr)
				//cout << " " <<  *weight_itr;
	*/
	
}

float File::Relevance(vector<string> s2)
// in main the command is "q n Word-List: "
// the vector of words are passed in.
// A document is relevant to a query(the input words) iff
// it contains each word in the query.
// relevance = sum of the weights of the words
// return -1 is not releative
{
	int numWords2 = s2.size();	// stores number of words in qury
	float relevance =0;			// Initializes relevance				

	vector<string>::iterator itr3;		// iterator for the passed in wordlist 

	// compare vector passed in with words vector to output use weight vector. 
	// If they have the same words, sum those words weight and return it
	// else return -1
	for (weight_itr=weight.begin(); weight_itr!=weight.end(); ++weight_itr) {	// loop through weights
		for (itr3=s2.begin(); itr3 !=s2.end(); ++itr3){					// loop through the word list
			if (words.search(*itr3) == true)	{							// If a word matches
					relevance = *weight_itr;	// record the relevance from weight vector and increment
					numWords2--;					// countdown to see if all the words were found
					//words.RotateUp(*itr3); // move that word two steps to the front
			}	// SELF ORGANIZATION!!!
		}
	}
	if (numWords2 > 0)	// No document had all the words
		return -1;
	else
		return relevance;
}

string File::Getfilename()
// Returns filename
{return filename;}

void File::Print(int n)
// prints the first n words of a filename from BST by preorder
{
	words.PrintPreorder(n);
}

bool File::wasAnalyzed()
// Returns true if the file was analyzed
{return analyzed;}

static string nxtWrd(string &S, string::size_type &p1, string::size_type &p2) {
// I learned how to do this from Srinivasan's examlpe solution to Assignment 1.
	static char delimiters[] = " \n\t!()-:;\",.?/";
  	
	if(p1 == string::npos)
    	return string("");
	p1 = S.find_first_not_of(delimiters, p1);
	if(p1 == string::npos)
    	return string("");
	p2 = S.find_first_of(delimiters, p1);
	if(p2 != string::npos)
    	return S.substr(p1, p2-p1);
	else
    	return S.substr(p1, S.size()-p1);  
}


