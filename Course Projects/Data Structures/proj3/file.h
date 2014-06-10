//// Assignment 3
// By: Paul Kafka
// The assignment asked to store the words in a list, and
// below they are stored in my template List class as "words"

#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<string>
#include"Linklist.h"
#include<vector>

using namespace std;

class File
// Creates an object that stores the file data
{
    public:
       	File(string f); 		// Constructor.
		void Analyze();			// Analyzes a file
		float Relevance(vector<string> s2);	// Calculates the relevance of this file
		string Getfilename(); 	// returns filename
		bool wasAnalyzed(); 	// returns filename

    private:
        List<string> words;		// word inventory
		vector<float> weight;	// weight of the words (has same index)
		vector<float>::iterator weight_itr;		// Iterator for the weight vector
		List<string>::iterator words_itr;		// Iterator for the weight vector	
		string filename;		// stores the filename of the object
		bool analyzed;			// stores if the file had been analyzed
};
#endif

