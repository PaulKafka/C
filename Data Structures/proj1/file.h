#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<string>

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
        vector<string> words;	// word inventory
		vector<float> weight;	// what of the words (has same index)
		vector<float>::iterator weight_itr;		// Iterator for the weight vector
		vector<string>::iterator words_itr;		// Iterator for the words vector
		string filename;		// stores the filename of the object
		bool analyzed;			// stores if the file had been analyzed
};
#endif
