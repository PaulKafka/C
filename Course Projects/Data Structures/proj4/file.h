//// Assignment 4
// By: Paul Kafka
// The assignment asked to store the words in a binary search tree , and
// below they are stored in my template BST class as "words"

#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <string>
#include "binarysearchtree.h"
#include <vector>

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
		void Print(int n);	// prints the first n words of a filename from BST by preorder

    private:
		int numWords;
        BST<string> words;		// stores words from filename in Binary Search Tree
		vector<float> weight;					// weight of the words (has same index)
		vector<float>::iterator weight_itr;		// Iterator for the weight vector	
		string filename;		// stores the filename of the object
		bool analyzed;			// stores if the file had been analyzed
};
#endif

