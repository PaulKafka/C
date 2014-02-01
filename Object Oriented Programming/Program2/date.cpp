//--------------- Date.CPP ---------------
// The class definition for the date.
// By: Paul Kafka

#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int m, int d, int y)
// initializes date to 1/1/200
// validation of input added in
{
	if (Set(m,d,y) == false)
	{
		month = 1;
		day = 1;
		year = 2000;
	}
	else
	{
		month = m;
        day = d;
	    year = y;
	}
}

bool Date::Set(int m, int d, int y)
//	checks for correct date
//  return true for success and false for failure
{
if (((m > 12) || (m < 1)) || (m,y,d < 0))
	return false;
else 
   if ((m == 1) && !((d >= 1) && (d <= 31)))			// Jan
		return false;
   else if ((m == 3) && !((d >= 1) && (d <= 31)))		// March
	   return false;
   else if ((m == 4) && !((d >= 1) && (d <= 30)))		// April
	   return false;
   else if ((m == 5) && !((d >= 1) && (d <= 31)))		// May
	   return false;
   else if ((m == 6) && !((d >= 1) && (d <= 30)))		// June
	   return false;
   else if ((m == 7) && !((d >= 1) && (d <= 31)))		// July
	   return false;
   else if ((m == 8) && !((d >= 1) && (d <= 31)))		// Aug
	   return false;
   else if ((m == 9) && !((d >= 1) && (d <= 30)))		// Sep
	   return false;
   else if ((m == 10) && !((d >= 1) && (d <= 31)))		// Oct
	   return false;
   else if ((m == 11) && !((d >= 1) && (d <= 30)))		// Nov
	   return false;
   else if ((m == 12) && !((d >= 1) && (d <= 31)))		// Dec 
	   return false;
   else		// Feb and Leap Year		
        if ((m == 2) && !((d >= 1) && (d <= 28)) && !((y%400 ==0) || ((y%100 != 0) && (y%4 == 0))))
			return false;
		else if ((m == 2) && (((y%400 ==0) || ((y%100 != 0) && (y%4 == 0))) && ((d >= 1) && (d <= 29))))
			return true;
		else if ((m == 2) && (((y%400 ==0) || ((y%100 != 0) && (y%4 == 0))) && !((d >= 1) && (d <= 29))))
			return false;
		else
			return true;
}

void Date::Input()
// Prompt user to enter date
{
	char slash;

	cout << endl;
	cout << "Please enter a valid date: ";
    cin >> month >> slash >> day >> slash >> year;
      while (Set(month,day,year) == false)				// if date != correct, ask again
	  {
            cout << "Invalid date. Please re-enter: "; cout << endl;
			cout << "Please enter a valid date: ";
			cin >> month >> slash >> day >> slash >> year;  
      }
      cout << "Thank you for entering a valid date!" << endl;
}

void Date::Show()
// Output data to screen according to format
{
if (format == 'D')
	cout << month << "/" << day << "/" << year;
else if (format== 'T')
{
	cout << month << "/" << day << "/";
	if (year >= 2000)
	{
		if ((year - 2000) == 0)
			cout << (year-2000) << "0";		// Shows last couple digits
		else
			cout << (year - 2000);
	}
	else
	{
		if ((year - 1900) == 0)
		{cout << (year - 1900) << "0";}		// Shows last couple digits
		else 
		cout << (year - 1900);
	}
}
else if (format == 'L')
{
			if (month == 1)
				cout << "Jan " << day << ", " << year;
			else if (month == 2)
				cout << "Feb " << day << ", " << year;
			else if (month == 3)
				cout << "Mar " << day << ", " << year;
			else if (month == 4)
				cout << "April " << day << ", " << year;
			else if (month == 5)
				cout << "May " << day << ", " << year;
			else if (month == 6)
				cout << "June " << day << ", " << year;
			else if (month == 7)
				cout << "July " << day << ", " << year;
			else if (month == 8)
				cout << "Aug " << day << ", " << year;
			else if (month == 9)
				cout << "Sept " << day << ", " << year;
			else if (month == 10)
				cout << "Oct " << day << ", " << year;
			else if (month == 11)
				cout << "Nov " << day << ", " << year;
			else if (month == 12)
				cout << "Dec " << day << ", " << year;
			else 
				;
		}
else
cout << month << "/" << day << "/" << year;
cout << endl;
}

bool Date:: SetFormat(char f)
// Sets format. Returns true for success and false for unchanged.
// D = Default, T = Two-Digit, L = Long: Formats
{
	if ((f == 'T') || (f == 'D') || (f == 'L'))
	{	format = f;
		return true;
	}
	else
		return false;
}

void Date::Increment(int numDays)
// Move date forward by # in argument.
// Default is 1
{
	if ((month == 1) && ((day+numDays) > 31))		// Jan
	{month++;
	day = (numDays+day)-31;}
	else if ((month == 2) && !((year%400 ==0) || ((year%100 != 0) && (year%4 == 0))) && ((day+numDays) > 28)) // Feb
	{month++;
	day = (numDays+day)-28;}
	else if ((month == 2) && ((year%400 ==0) || ((year%100 != 0) && (year%4 == 0))) && ((day+numDays) > 29))  // Leap year
	{month++;
	day = (numDays+day)-29;}
	else if ((month == 3) && ((day+numDays) > 31))	// March
	{month++;
	day = (numDays+day)-31;}
	else if ((month == 4) && ((day+numDays) > 30))	// April
	{month++;
	day = (numDays+day)-30;}
	else if ((month == 5) && ((day+numDays) > 31))	// May
	{month++;
	day = (numDays+day)-31;}
	else if ((month == 6) && ((day+numDays) > 30))	// June
	{month++;
	day = (numDays+day)-30;}
	else if ((month == 7) && ((day+numDays) > 31))	// July
	{month++;
	day = (numDays+day)-31;}
	else if ((month == 8) && ((day+numDays) > 31))	// Aug
	{month++;
	day = (numDays+day)-31;}
	else if ((month == 9) && ((day+numDays) > 30))	// Sept
	{month++;
	day = (numDays+day)-30;}
	else if ((month == 10) && ((day+numDays) > 31))	// Oct
	{month++;
	day = (numDays+day)-31;}
	else if ((month == 11) && ((day+numDays) > 30))	// Nov
	{month++;
	day = (numDays+day)-30;}
	else if ((month == 12) && ((day+numDays) > 31))	// Dec
	{month++;
	day = (numDays+day)-31;}
	else
		day += numDays;			// If doesnt overflow, just simply add

}

int Date::Compare(const Date &d)
// compare two dates
// return -1 id calling object comes first
// return 1 is paramter object comes first
// return 0 if they are the same date.
{
	if (d.year < year)
		return 1;
	else if ((d.year == year) && (d.month < month))
		return 1;
	else if ((d.year == year) && (d.month == month) && (d.day < day))
		return 1;
	else if (d.year > year)
		return -1;
	else if ((d.year == year) && (d.month > month))
		return -1;
	else if ((d.year == year) && (d.month == month) && (d.day > day))
		return -1;
	else				// the objects are the same date
		return 0;

}

int Date::GetMonth()
{return month;}			// return month as an int

int Date::GetDay()
{return day;}			// return day as an int

int Date::GetYear()
{return year;}			// return year as an int