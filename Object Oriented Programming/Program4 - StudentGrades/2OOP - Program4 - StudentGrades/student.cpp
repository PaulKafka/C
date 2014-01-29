/* File: student.cpp
Author: Paul Kafka
Description: This is the definition for the student class. It makes
a heterogeneous list of students. 
*/

#include <iostream>		
#include <cstring>		//for strcmp
#include "student.h"
#include <iomanip>		// for formatting
using namespace std;

Student::Student(char* fn, char* ln, char* c, int s)
// Constructor
{
	strcpy(firstName,fn);		// copy firstname
	strcpy(lastName,ln);		// copy lastname
	strcpy(course,c);			// copy course
	numStudents =s;				// copy number of students
	finalAvg =0;				// initailize final avg to 0;
}

void English_Students::Summary()
// Output on Visual and G++ is fine, pygraders may be different
{
	// Output English Student Information
	cout << firstName << " ";	
	cout << lastName;
	if (strlen(firstName)+strlen(lastName) >= 14)
		cout << "\t\t\t";
	else 
		cout << "\t\t\t\t";
	cout << Get_finalExamGrade();
	cout << "\t ";
    cout << fixed << setprecision(2) << FinalAvg(); 
	cout << "\t   ";
	if (finalAvg < 60)
		cout << "F\n";
	else if ((finalAvg >= 60) && (finalAvg < 70))
		cout << "D\n";
	else if ((finalAvg >= 70) && (finalAvg < 80))
		cout << "C\n";
	else if ((finalAvg >= 80) && (finalAvg < 90))
		cout << "B\n";
	else
		cout << "A\n";
}

void History_Students::Summary()
// Output on Visual and G++ is fine, pygraders may be different
{
	// Output History Student Information	
	cout << firstName << " ";
	cout << lastName;
	if (strlen(firstName)+strlen(lastName) >= 15)
		cout << "\t\t\t";
	else 
		cout << "\t\t\t\t";
	cout << Get_finalExamGrade();
	cout << "\t ";
    cout << fixed << setprecision(2) << FinalAvg(); 
	cout << "\t   ";
	if (finalAvg < 60)
		cout << "F\n";
	else if ((finalAvg >= 60) && (finalAvg < 70))
		cout << "D\n";
	else if ((finalAvg >= 70) && (finalAvg < 80))
		cout << "C\n";
	else if ((finalAvg >= 80) && (finalAvg < 90))
		cout << "B\n";
	else
		cout << "A\n";
}

void Math_Students::Summary()
// Output on Visual and G++ is fine, pygraders may be different
{
	// Output Math Student Information
	cout << firstName << " ";
	cout << lastName;
	if (strlen(firstName)+strlen(lastName) >= 14)
		cout << "\t\t\t";
	else 
		cout << "\t\t\t\t";
	cout << Get_finalExamGrade();
	cout << "\t ";
	cout << fixed << setprecision(2) << FinalAvg(); 
	cout << "\t   ";
	if (finalAvg < 60)
		cout << "F\n";
	else if ((finalAvg >= 60) && (finalAvg < 70))
		cout << "D\n";
	else if ((finalAvg >= 70) && (finalAvg < 80))
		cout << "C\n";
	else if ((finalAvg >= 80) && (finalAvg < 90))
		cout << "B\n";
	else
		cout << "A\n";
}
English_Students::English_Students(char* fn, char* ln, char* c, int s,
								   double a, double p, double m, int f) : Student(fn, ln, c, s)
// Contructor for English_Students
{
attendanceGrade = a; // Store info
projectGrade = p;
midtermGrade = m;
finalExamGrade =f;
}

History_Students::History_Students(char* fn, char* ln, char* c, int s,
							 double tp, double m, int f) : Student(fn, ln, c, s)
// Contructor for History_Students
{
termPaperGrade = tp;  // store info
midtermGrade = m;
finalExamGrade = f;
}

Math_Students::Math_Students(char* fn, char* ln, char* c, int s,
							 double q1, double q2, double q3, 
							 double q4, double q5, double t1, 
							 double t2, int f) : Student(fn, ln, c, s)
// Contructor for Math_Students
{
quiz1Grade = q1;	// store info
quiz2Grade = q2;
quiz3Grade = q3;
quiz4Grade = q4;
quiz5Grade = q5;
test1Grade = t1;
test2Grade = t2;
finalExamGrade = f;
}

double English_Students::FinalAvg()
//Attendance = 10%, Project = 30%, Midterm = 30%, Final Exam = 30%
{
	finalAvg = (attendanceGrade*.1) + (projectGrade*.3) 
				+ (midtermGrade*.3) + ((double)finalExamGrade*.3);

	return finalAvg;
}

double History_Students::FinalAvg()
//Term Paper = 25%, Midterm = 35%, Final Exam = 40%
{
	finalAvg = termPaperGrade*.25 + midtermGrade*.35
				+ (double)finalExamGrade*.4; 

	return finalAvg;
}

double Math_Students::FinalAvg()
// Quiz Average = 15%, Test 1 = 25%, Test 2 = 25%, Final Exam = 35% 
{
	finalAvg = ((quiz1Grade + quiz2Grade + quiz3Grade + 
		       quiz4Grade + quiz5Grade)/5)*(.15) 
			   + test1Grade*(.25) + test2Grade*(.25) + (double)finalExamGrade*(.35);

	return finalAvg;
}

void Student::DisplayTitle()
// Prints out main Title.
{
	cout << "Student Grade Summary\n"
	 << "---------------------";
}

void Student::SubDisplayTitle(int c)
// Prints out SubTitle
// Passed in course to output correct subTitle
// Output on Visual and G++ is fine, not pygraders though
{
if (c == 1)
{cout << "\n\nENGLISH CLASS\n\n";
cout << "Student \t\t\t\t Final   Final   Letter\n";
cout << "Name \t\t\t\t\t Exam    Avg     Grade\n"
<< "----------------------------------------------------------------\n";}
else if (c == 2)
{cout << "\n\nHISTORY CLASS\n\n";
cout << "Student \t\t\t\t Final   Final   Letter\n";
cout << "Name \t\t\t\t\t Exam    Avg     Grade\n"
<<"----------------------------------------------------------------\n";}
else
{cout << "\n\nMATH CLASS\n\n";
cout << "Student \t\t\t\t Final   Final   Letter\n";
cout << "Name \t\t\t\t\t Exam    Avg     Grade\n"
<< "----------------------------------------------------------------\n";}
}

//Accessor Deffinitions
int English_Students::Get_finalExamGrade() const
{return finalExamGrade;}			// return final exam grade for English
int History_Students::Get_finalExamGrade() const
{return finalExamGrade;}			// return final exam grade for History
int Math_Students::Get_finalExamGrade() const
{return finalExamGrade;}			// return final exam grade for Math
char Student::Get_course() const
{return course[0];}					// return first letter in course name