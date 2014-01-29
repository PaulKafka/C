/* ========================================================================== */
/*	PROGRAM Lawn Time: Calculate time it takes to mow a lawn

    AUTHOR: <Paul Kafka>
    FSU MAIL NAME: <PLK09d>
    RECITATION SECTION NUMBER: <1>
    RECITATION INSTRUCTOR NAME: <Joshua Lawrence>
    COP 3014 - Spring 2010
    PROJECT NUMBER: 3 
    DUE DATE: Wednesday 2/17/2010
    PLATFORM: Windows OS / Microsoft Visual C++ Express 2008 compiler 

SUMMARY

This program analyzes a HTML file. It reads various attributes in the
code and prints a report to the console window. This program will ask 
the user for the name of a file and will find the number of lines, tags,
links, comments, charcaters, and characters inside tags. It will aslo
find the percentage of characters which occur inside tags.

INPUT

This program asks the user for the interactive input of the file name.
The program input is to be read from a text file. 

	BAD DATA CHECKING: This program verifies the interactive 
	input of the file name.

OUTPUT

A welcome message is printed and the user is prompted for the file
name. Then, an echoprint of the file and data values is printed. These
values include: number of lines, tags, links, comments, charcaters, 
characters inside tags, and percentage of characters which occur inside tags.

ASSUMPTIONS

Assume that file names don't contain blanks. You may also assume that a 
less-than symbol ALWAYS indicates the start of a tag. Also, assume the 
HTML files uses a very limited subset of basic HTML. Assume these are the
only HTML language elements you need to recognize, and that the HTML
files you process contain absolutely no HTML syntax errors.
/* ========================================================================== */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main ()
{									// begin main function
	
	
	ifstream inFile;
	string fileName;				// name of file

	// data items
	char	ch,						// characters in file
			prevChar = 'z',			// previous character
			currChar;				// current character

	// declare variables
	int		numChars = 0,			// number of character
			numLines = 0,			// number of lines
			numTags = 0,			// number of tags
			numCmnts = 0,			// number of comments
			numLinks = 0,			// number of links
			numChar_Tag = 0;		// number os characters in tags
	double	PercChar_Tag = 0.00;	// percent of characters of tags

	// declare named constants
	const char	LINK_LC = 'a',		// lowercase link
				LINK_UC = 'A',		// upercase link
				EOLN = '\n',		// end of line
				TAG_OPEN = '<',		// open tag
				TAG_CLOSE = '>',	// close tag
				COMMENT = '!';		// comment marker

	bool in_tag = false;			// a flag: false

	// print introduction message
cout << "===============================";
cout << "=======================================" << endl;
cout << "HTML file analyzer" << endl;
cout << "================================";
cout << "======================================" << endl;

	// asking the user for the file name
	cout << "Please enter the filename(no blanks!): ";
	cin >> fileName;

	//attempt to open file
	inFile.open(fileName.c_str());

	// keep asking for a filename until it is valid
	while (!inFile)                    // infle not valid
	{
		cout << "Please re-enter a valid filename: ";
		cin >> fileName;
		inFile.clear();				   // clears any fail state
		inFile.open(fileName.c_str()); // opens file
	}
cout << " " << endl;				   // do nothing

	// print title of the file text
cout << "===============================";
cout << "=======================================" << endl;
cout << "Text of file" << endl;
cout << "================================";
cout << "======================================" << endl;

	inFile.get(currChar);          // priming read
	while (inFile)                 //loop to read the rest of the file
	{ // while infile is true
		cout << currChar;          
		++numChars;                
		if (currChar == EOLN)								   // /n= lines
			++numLines;				// number of lines
		if ((prevChar == TAG_OPEN) &&                          // <a = link
			((currChar == LINK_LC) || (currChar == LINK_UC)))  
				numLinks++;			// number of links
		if ((prevChar == TAG_OPEN) && (currChar == COMMENT))   // <!= comment
				numCmnts++;			// number of comments
		if (prevChar == TAG_OPEN)	// if < is true, then get # of tags
		{
			in_tag = true;				// if intag is true
				numTags++;				// number of tags
		}
		else if(prevChar == TAG_CLOSE)	// else if closing tag
		{
			in_tag = false;				// intag is false
		}
		if ((in_tag == true) &&			// if intag is true
			(prevChar != TAG_OPEN))		// and not open tag
			numChar_Tag++;				// number of chars in tag

		prevChar = currChar;			// sets previous to current character
		inFile.get (currChar);			// gets every character
	} // while infile is true
	
	// set up output formatting
	cout << fixed << showpoint << setprecision(2);

	// calculates the percent character in tags
	PercChar_Tag = 100 * static_cast<double>(numChar_Tag) / (numChars);

cout << " " << endl;			// do nothing

	// prints title of end of text
cout << "===============================";
cout << "=======================================" << endl;
cout << "End of Text" << endl;
cout << "================================";
cout << "======================================" << endl <<endl;

	// File analysis title
cout << "Analysis of file" << endl;
cout << "----------------" << endl << endl;

	// output of values
cout << "Number of lines: " << numLines << endl;
cout << "Number of tags: " << numTags << endl;
cout << "Number of comments: " << numCmnts << endl;
cout << "Number of links: " << numLinks << endl;
cout << "Number of chars in file: " << numChars << endl;
cout << "Number of chars in tags: " << numChar_Tag << endl;
cout << "Percentage of characters in tags: " << PercChar_Tag;
cout << "%" << endl;
cout << " " << endl;			// do nothing

	// prints ending tile
cout << "===============================";
cout << "=======================================" << endl;
cout << "Thanks for using the HTML File Analyzer" << endl;
cout << "================================";
cout << "======================================" << endl;
	
	return 0;
}								// end main function

/* ========================================================================== */
/*                           END OF PROGRAM                                   */
/* ========================================================================== */