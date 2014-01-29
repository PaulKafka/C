/* ========================================================================== */
/*	PROGRAM Lawn Time: Calculate time it takes to mow a lawn

    AUTHOR: <Paul Kafka>
    FSU MAIL NAME: <PLK09d>
    RECITATION SECTION NUMBER: <1>
    RECITATION INSTRUCTOR NAME: <Joshua Lawrence>
    COP 3014 - Spring 2010
    PROJECT NUMBER: 2 
    DUE DATE: Wednesday 2/03/2010
    PLATFORM: Windows OS / Microsoft Visual C++ Express 2008 compiler 

SUMMARY

This program asks the user which package he/she purchased and how many
hours were used in the month. Then, the program calculates and displays 
the monthly bill and the savings if the customer purchased the other 
packages.

INPUT

The package and hours used by the customer are read 
interactively.

	BAD DATA CHECKING: This program verifies that the
	user only selects A, B or C for the service package
	and checks for upper or lower case. It also verifies
	the number of hours in a month cannot be less than 
	zero and cannot exceed 744.

OUTPUT

A welcome message is printed and the user is prompted for the input 
items. The bill and money that could be saved is printed.

ASSUMPTIONS

When asked for a character, the user types a single non-blank
character and then hits enter. Also, when asked for a whole 
number, the user types an integer value and then hits enter.

/* ========================================================================== */

#include <iostream>
#include <iomanip>

using namespace std;


int main ()
{   // begin main function

	// declare named constants
	const double PACKAGE_A_RATE = 9.95;   // package A 10 hour rate
	const double PACKAGE_B_RATE = 14.95;  // package B 20 hour rate
	const double PACKAGE_C_RATE = 19.95;  // package B unlimited hour rate

	// input data items 
	char package;                         // package used
	int hours;                            // hours used
	
	// calculated variables
	double chargesA;                      // package A bill
	double chargesB;                      // package B bill
	double chargesC;                      // package C bill
	double savingA_B;                     // savings from package A to B
	double savingA_C;                     // savings from package A to C
	double savingB_C;                     // savings from package B to C
	
	bool isValid = true;                  // a flag: true if the calculation

	// introduction message
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
	     << "Welcome to the ISP Billing Calculator\n"
		 << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

	// asking the user for ISP package
	cout << "Which package does the customer use (A, B, or C)? : ";
	cin >> package;
	
	// testing package choice
	if (package == 'A' || package == 'a')      // if A or a
		cout << " " << endl;                   // do nothing
	else if (package == 'B' || package == 'b') // if B or b
		cout << " " << endl;                   // do nothing
	else if (package == 'C' || package == 'c') // if C or c
		cout << " " << endl;                   // do nothing
	else
	{                                       // package choice invalid
		cout << "Package choice input invalid.\n";
		isValid = false;                    // reset flag, operation failed
	}                                       // package choice invalid
	
	if (isValid == true)
	{                                       // if isValid is true (1)

		// asking how many hours used
		cout << "How many hours did the customer use last month? : ";
		cin >> hours;
		
		if ((hours >= 0) && (hours <= 744)) // hours is inbetween 0 and 744
			cout << " " << endl;            // do nothing
		else
		{                                   // inputted hours invalid
			cout << "Hours input invalid" << endl;
			isValid = false;                // reset flag, operation failed
		}                                   // inputted hours invalid


		if (isValid == true)
		{                                   // isValid is true (2)
		

		// calculate the bill
		chargesA = (PACKAGE_A_RATE);             // bill if package A
			if ((hours >= 0) && (hours <=10));   // if hours between 0 and 10
			                                     // then no additional fees
			else                                 // else over 10, add 2 hourly
				chargesA = (((hours - 10) * (2)) + (PACKAGE_A_RATE));
		chargesB = (PACKAGE_B_RATE);             // bill if package B
			if ((hours >= 0) && (hours <=20));   // if hours between 0 and 20
			                                     // then no additional fees
			else                                 // else over 20, add 1 hourly
				chargesB = ((PACKAGE_B_RATE) + (hours - 20));
		chargesC = (PACKAGE_C_RATE);             // bill if package C


		// print the results of the bill
		if (package == 'A' || package == 'a')        // if A or a
			cout << endl << "Charges: $" << chargesA << endl;
		else if (package == 'B' || package == 'b')   // if A or a
			cout << endl << "Charges: $" << chargesB << endl;
		else                                         // else C or c
			cout << endl << "Charges: $" << chargesC << endl;
		
		// calculate the savings
		savingA_B = (chargesA) - (chargesB);
		savingA_C = (chargesA) - (chargesC);
		savingB_C = (chargesB) - (chargesC);

		// test for validity of the caculated savings
		isValid = (savingA_B > 0.0) && (savingA_C > 0.0) && (savingB_C > 0.0);

			// print output only if all savings are valid 
			if (isValid == true)
			{                          // if isValid is true (3)

			// set up output formatting
			cout << fixed << showpoint << setprecision(2);

				// print the results of the savings
				if (package == 'A' || package == 'a')
				{                                      // if package is A or a
					cout << endl << "By switching to Package B "; 
					cout << "you would save: $" << savingA_B << endl;
					cout << endl << "By switching to Package C ";
					cout << "you would save: $" << savingA_C << endl;
				}                                      // if package is A or a
				else if (package == 'B' || package == 'b')
				{
					cout << endl << "By switching to Package C ";
					cout << endl << "you would save: $" << savingB_C << endl;
				}
				else if (package == 'C' || package == 'c') // else package C
					cout << endl << " " << endl;           // do nothing
			}                     // if isValid is true (3)        
				else                          
				{   // isValid is false; the savings is negative
					cout << endl << " " << endl;       // do Nothing
					isValid = false;                   // reset flag, 
					                                   // operation failed
		    	}                 // isValid is false; the savings is negative
		}                         // if isValid is true (2)
		else 
		cout << endl << " " << endl;   // do nothing

	}                                  // if isValid is true (1)
	else 
	cout << endl << " " << endl;  // do nothing
	
	cout << endl << "Execution Terminated Normally.\n";   // end of program
	
	
	return 0;
}                                 // end main function


/* ========================================================================== */
/*                           END OF PROGRAM                                   */
/* ========================================================================== */