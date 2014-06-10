/* File: mixed.h
Author: Paul Kafka
Description: This is the class delcaration for Mixed.
It deals with mixed fractions.
*/

#ifndef _MIXED_H
#define _MIXED_H

#include <iostream>
using namespace std;

class Mixed
{
	// Friend operator overloads
	friend ostream& operator<< ( ostream& s, const Mixed& t);
	friend istream& operator>> (istream& c, Mixed& y);
	friend bool operator< (const Mixed& t1, const Mixed& t2);
	friend bool operator> (const Mixed& t1, const Mixed& t2);
	friend bool operator>= (const Mixed& t1, const Mixed& t2);
	friend bool operator<= (const Mixed& t1, const Mixed& t2);
	friend bool operator== (const Mixed& t1, const Mixed& t2);
	friend bool operator!= (const Mixed& t1, const Mixed& t2);

public:
		Mixed(int i, int n, int d);		// Constructor with 3 parameters
		Mixed(int x=0);					// Conversion Constructor
		double Evaluate();		// Returns fraction as a double
		void ToFraction();		// Converts Mixed fraction to improper fraction
		void Simplify();		// Simplifies fraction

	// Member Function Operator Overloads
	Mixed operator+ (const Mixed& t) const;		// Addition
	Mixed operator- (const Mixed& t) const;		// Subtraction
	Mixed operator* (const Mixed& t) const;		// Multiplication
	Mixed operator/ (const Mixed& t) const;		// Devision
	Mixed operator++();							//Prefix
    Mixed operator++(int);						//Postfix
	Mixed operator-- ();						//Prefix
	Mixed operator-- (int);						//Postfix	

private:
		int integer;		// Stores integer as int
		int numerator;		// Stores numerator as int
		int denominator;	// Stores denominator as int

};

#endif