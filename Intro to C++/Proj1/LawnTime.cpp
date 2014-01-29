/* ========================================================================== */
/*	PROGRAM Lawn Time: Calculate time it takes to mow a lawn

    AUTHOR: <Paul Kafka>
    FSU MAIL NAME: <PLK09d>
    RECITATION SECTION NUMBER: <1>
    RECITATION INSTRUCTOR NAME: <Joshua Lawrence>
    COP 3014 - Spring 2010
    PROJECT NUMBER: 1 
    DUE DATE: Wednesday 1/20/2010
    PLATFORM: Windows OS / Microsoft Visual C++ Express 2008 compiler 

SUMMARY

This program reads in the user's name and the length and width of a 
yard, along with the length and width of a house in that yard. 
The program then calculates how long it will take to mow the lawn in 
minutes and seconds, assuming that a constant number of square feet can 
be mowed in one second.

INPUT

The name, length and width of the house and yard, in feet, are read 
interactively.

OUTPUT

A welcome message is printed and the user is prompted for the input 
items. Finally the time to mow the lawn is printed, in minutes and 
seconds.

ASSUMPTIONS

All input data is valid and correctly entered by the user.
The house and yard are both perfectly rectangular. */                 

/* ========================================================================== */

#include <iostream>					// include standard I/O routines
#include <string>					// include C++ string class header
using namespace std;

int main ()
{
	const int MOW_RATE = 3;			// square feet which can be mowed
									// per second
	const int SEC_PER_MINUTE = 60;	// seconds in one minute

	string username;				// name of program user
	 
	int		yardWidth,				// yard width in feet
			yardLength,				// yard length in feet
			houseWidth,				// house width in feet
			houseLength,			// house length in feet

			areaToMow,				// area to mow in square feet		
			mowTimeTotal,			// total seconds required to mow
									// the lawn
			mowTimeMinutes,			// minutes required
			mowTimeSeconds;			//   and additional seconds required
		
	// print the overall output title
	cout << "-------------------------------------------" << endl;
	cout << "Welcome to the Lawn Mowing Time Calculator!" << endl;
	cout << "-------------------------------------------" << endl << endl;

	// enter the user's name (may contain blanks) and then say hello
	cout << "Enter your name -> ";
	getline (cin, username);
	cout << endl << "Hello " << username << "! Let's do your calculations."
		<< endl << endl;

	// inform user about how input should be entered
	cout << "Please enter all measurements in feet." << endl;
	cout << "  and the input values as whole numbers." << endl << endl;

	// ask the user to type in the yard measurements
	cout << "Enter the width of the yard -> ";
	cin >> yardWidth;
	cout << "Enter the length of the yard -> ";
	cin >> yardLength;
	
	// now ask the user to type in the house measurements
	cout << endl << "Enter the width of the house -> ";
	cin >> houseWidth;
	cout << "Enter the length of the house -> ";
	cin >> houseLength;

	// calculate the area to be mowed and output
	areaToMow = (yardWidth * yardLength) - (houseWidth * houseLength);
	cout << endl << "The yard area to mow in square feet: " << areaToMow 
		 << endl;

	// now calculate the time to mow, first total seconds, then
	// break down into minutes and seconds
	mowTimeTotal = areaToMow / MOW_RATE;
	mowTimeMinutes = mowTimeTotal / SEC_PER_MINUTE;
	mowTimeSeconds = mowTimeTotal % SEC_PER_MINUTE;
	
	// print the time required to mow the lawn in minutes and seconds 
	cout << "Time you will need to mow this lawn: ";
	cout << mowTimeMinutes << " minutes and " << mowTimeSeconds 
	     << " seconds." << endl;
	
	// print closing message and signal normal termination
	cout << endl << "------------------------------" << endl;
	cout << "Program finished successfully." << endl;
	cout <<  "------------------------------" << endl;
	return (0);
}

/* ========================================================================== */
/*                           END OF PROGRAM                                   */
/* ========================================================================== */
