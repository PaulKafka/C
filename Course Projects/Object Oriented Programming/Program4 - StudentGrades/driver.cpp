/* File: driver.cpp
Author: Paul Kafka
Description: This is the driver for the student class. It makes
a heterogeneous list of students. 
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "student.h"

using namespace std;

int main()
{
///////////////////////INPUT////////////////////////////////////////////

//Variables
int numStudents;	// size
char fn[20];		// Stores students first name
char ln[20];		// Stores students last name
char c[8];			// Stores course
// math class variables
double q1, q2, q3,q4, q5, t1, t2; 
int mf;	
// history class variables
double tp, hm; 
int hf;	
// egnlish class variables
double at, pr, em; 
int ef;
//-----------------------------------------------------------------------
cin >> numStudents;								// copy number of students
Student ** list = new Student * [numStudents];	// an array of Student pointers 
cin.ignore(80, '\n');							// next line

	for (int i=0; i<numStudents; i++)
	{
	cin.getline(ln, 20, ',');		// copy last name
	cin.ignore(1);					// skip space
	cin.get(fn, 80, '\n');			// copy first name     	
	cin.ignore(80, '\n');			// next line
	cin.getline(c, 8, ' ');			// copy course name
	if (c[0] == 'M')  // Math Class
		{
		cin >> q1;		// copy quiz1
		cin >> q2;		// copy quiz2
		cin >> q3;		// copy quiz3
		cin >> q4;		// copy quiz4
		cin >> q5;		// copy quiz5
		cin >> t1;		// copy test1
		cin >> t2;		// copy test2
		cin >> mf;		// copy finalexam
		cin.ignore(80, '\n');		// next line
		// sends to English_Student Class (Dynamically)
		list[i] = new Math_Students(fn, ln, c, numStudents,q1,q2,q3,q4,q5,t1,t2,mf);
		}
	else if (c[0] == 'H')  // History Class
		{
		cin >> tp;				// copy term paper
		cin >> hm;				// copy midterm
		cin >> hf;				// copy final	
		cin.ignore(80, '\n');	// next line
		// sends to History_Student Class (Dynamically)
		list[i] = new History_Students(fn, ln, c, numStudents, tp, hm, hf);	
		}
	else  // English Student
		{
		cin >> at;				// copy attendance
		cin.ignore(1);			// skip space
		cin >> pr;				// copy project
		cin.ignore(1);			// skip space
		cin >> em;				// copy midtermexam
		cin.ignore(1);			// skip space
		cin >> ef;				// copy finalexam	
		cin.ignore(80, '\n');	// next line
		// sends to Math_Student Class (Dynamically)
		list[i] = new English_Students(fn, ln, c, numStudents, at, pr, em, ef);	
		}
	}
///////////////////////OUTPUT//////////////////////////////////////
	list[0]->DisplayTitle();			// Display Main Title
	list[0]->SubDisplayTitle(1);		// Display English SubTitle
	// Output all English Students
	for (int i=0; i<numStudents; i++)			
	{
	if (list[i]->Get_course() == 'E')
		list[i]->Summary();
	}
	
	list[0]->SubDisplayTitle(2);		// Display History SubTitle
    // Output all History Students
	for (int i=0; i<numStudents; i++)			
	{
	if (list[i]->Get_course() == 'H')
		list[i]->Summary();
	}
		
	list[0]->SubDisplayTitle(3);		// Display Math SubTitle
	// Output all Math Students
	for (int i=0; i<numStudents; i++)			
	{
	if (list[i]->Get_course() == 'M')
		list[i]->Summary();
	}
/////////////////////////////////////////////
	// deallocate data
	for (int i=0; i<numStudents; i++)			
		delete list[i];	
	delete [] list;

   return 0;
}