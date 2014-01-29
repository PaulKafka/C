/* File: mixed.cpp
Author: Paul Kafka
Description: This is the class deffinition for Mixed.
It deals with mixed fractions.
*/

#include "mixed.h"

Mixed::Mixed(int i, int n, int d)
// Constructer that takes in 3 parameters
{

	// If Multiple negative numbers
	if ((d <0 && n <0) || (d <0 && i <0) || (i <0 && n <0) || (d ==0))
	{
		integer = 0;
		numerator = 0;
		denominator =0;
	}
	
	// If Single negative numer
	else if (i <0 || n <0 || d < 0)		// if negative numer
	{
		if (i==0)  // No integer
		{
			if (d <0 && n >0)		// If Denominator is neg , switch neg with numerator
			{
				numerator = n * (-1);
				denominator = d * (-1);
				integer =0;
			}	
			else									
			{
				integer =0;
				denominator=d;
				numerator=n;
			}
		}
		else if (n < 0)				// If numerator is neg, switch neg with integer
		{
			numerator = n * (-1);
			integer = i * (-1);
			denominator = d;
		}
		else if (d <0)				// if denominator is neg, switch neg with integer
		{
			denominator = d* (-1);
			integer = i * (-1);
			numerator = n;
		}
		else						// If integer is neg
		{
			integer = i;
			numerator = n;
			denominator = d;
		}
	}
	else							// No negatives
	{
		integer = i;
		numerator = n;
		denominator = d;
	}
}
Mixed::Mixed(int x)
// Constuctor that has 1 paramter. 
// Conversion Constructor
{
	integer = x;
	numerator = 0;
	denominator = 1;
}

double Mixed::Evaluate()
// Return the decimal equivalent of the mixed number.
{
	if (integer < 0)	// Gets the negative out of calcualtion
	{
		return static_cast<double>((-1) * (((-1)*integer) * denominator +numerator)) / denominator;
	}
	else if (denominator == 0 || numerator ==0)		// If no fraction part, return integer as double
		return static_cast<double>(integer);
	else
		return static_cast<double>(numerator) / denominator + integer;
}
void Mixed::Simplify()
// Simplifies the mixed number representation to lowest terms.
{
	if (numerator !=0 && denominator !=0)
	{
		int remainder=99;								// Stores remainder
		int simpNum;			// Simplified
		int simpDen;			// Simplified
		int max,min;			// Used in calculation
		int nwNum= 0;			// Used so don't lose original data (if neg)
		int nwDen= 0;			// Used so don't lose original data (if neg)

		// Set new fraction values that arent negative
		if (numerator <0)			
		{
			nwNum = numerator*(-1);
			nwDen = denominator;
		}
		else if (denominator <0)
		{
			nwDen = denominator*(-1);
			nwNum = numerator;
		}
		else
		{
			nwNum = numerator;
			nwDen = denominator;
		}

		// Fraction components as a max or min value.
		if (nwNum >= nwDen)
			{max = nwNum;
			min = nwDen;}
		else
			{min = nwNum;
			max = nwDen;}

		// Calculates the GCD
		while (remainder !=0)
		{
		remainder = max % min;
		max = min;
		min = remainder;
		}
		
		// Simplified Fraction components
		simpNum = nwNum/max;
		simpDen = nwDen/max;

		// if improper, convert to mixed
		if (simpNum > simpDen)
		{
			integer += simpNum / simpDen;
			simpNum = simpNum % simpDen;
		}
		
		// Resets the negative back in
		if (numerator <0)
		{
			numerator = simpNum;
			integer = integer *(-1);
			denominator = simpDen;
		}
		else if (denominator <0)
		{
			denominator = simpDen;
			integer = integer *(-1);
			numerator = simpNum;
		}
		else
		{
			numerator = simpNum;
			denominator = simpDen;	
		}
    }											// end (numerator !=0 && denominator !=0 && integer !=0)
	
	if (numerator == denominator)
	{
		integer += 1;
		numerator =0;
		denominator=0;
	}

}
void Mixed::ToFraction()
// convert the mixed number into improper fraction form.
{
	if (integer < 0)	// Gets the negative out of calcualtion
	{
		numerator = (-1) * (((-1)*integer) * denominator +numerator);
		integer =0;
	}
	else				// Integer is not negative
	{
		numerator = integer*denominator+numerator;
		integer = 0;  
	}
}

ostream& operator<< (ostream& s, const Mixed& t)
// Extraction operator overload.
{
	if (t.integer == 0 && t.numerator == 0)			// If Object is Zero
		{s << "0";}
	else if (t.integer ==0)							// If integer is Zero
		s << t.numerator << "/" << t.denominator;
	else if (t.numerator ==0)						// If Fraction is Zero
		s << t.integer;
	else
		s << t.integer << " " << t.numerator << "/" << t.denominator;
	
	return s;		// returns fraction
}
istream& operator>> (istream& c, Mixed& y)
// Insertion Operator Overload
{
	
	char divide; 
	c >> y.integer >> y.numerator >> divide >> y.denominator;
	
	if (y.denominator <=0 || y.numerator < 0)	// If denominator is Zero, or components are neg
	{
		y.integer = 0;
		y.numerator = 0;
		y.denominator = 0;
	}

	return c;	// returns fraction to input stream
}
bool operator<= (const Mixed& t1, const Mixed& t2)
// Comparison Overload
{
	if (t1.integer <= t2.integer)
		return true;
	else if (t1.integer == t2.integer)
	{
		if ((t1.numerator * t2.denominator) <= (t2.numerator * t1.denominator)) // sets a commom denominator
			return true;		// returns true
		else
			return false;
	}
	else 
	   return false;	// returns false
}
bool operator>= (const Mixed& t1, const Mixed& t2)
// Comparison Overload
{
	// Should simplify t1 and t2 first (didn't do!!!)

	if (t1.integer >= t2.integer)
		return true;
	else if (t1.integer == t2.integer)
	{
		if ((t1.numerator * t2.denominator) >= (t2.numerator * t1.denominator)) // sets a commom denominator
			return true;	// returns true
		else
			return false;
	}
	else 
	   return false;	// returns false
}
bool operator< (const Mixed& t1, const Mixed& t2)
// Comparison Overload
{
	if (t1.integer < t2.integer)
		return true;
	else if (t1.integer == t2.integer)
	{
		if ((t1.numerator * t2.denominator) < (t2.numerator * t1.denominator)) // sets a commom denominator
			return true;	// returns true
		else
			return false;
	}
	else 
	   return false;	// returns false
}
bool operator> (const Mixed& t1, const Mixed& t2)
// Comparison Overload
{
	if (t1.integer > t2.integer)
		return true;
	else if (t1.integer == t2.integer)
	{
		if ((t1.numerator * t2.denominator) > (t2.numerator * t1.denominator)) // sets a commom denominator
			return true;	// returns true
		else
			return false;
	}
	else 
	   return false;	// returns false
}
bool operator== (const Mixed& t1, const Mixed& t2)
// Comparison Overload
{
	if (t1.integer == t2.integer)
	{
		if ((t1.numerator * t2.denominator) == (t2.numerator * t1.denominator)) // sets a commom denominator
			return true;	// returns true
		else
			return false;
	}
	else 
	   return false;	// returns false
}
bool operator!= (const Mixed& t1, const Mixed& t2)
// Comparison Overload
{
	if (t1.integer != t2.integer)
		return true;
	else if (t1.integer == t2.integer)
	{
		if ((t1.numerator * t2.denominator) != (t2.numerator * t1.denominator)) // sets a commom denominator
			return true;	// returns true
		else
			return false;
	}
	else 
	   return false;	// returns false
}

Mixed Mixed::operator+(const Mixed& t) const
// operator overload for +.
{
   Mixed x; 

    x.integer = 0;
   if (integer < 0 || t.integer <0)
		x.numerator = (((numerator+(denominator*integer))*t.denominator) - ((t.numerator+(t.denominator*t.integer*(-1)))*denominator));
   else
		x.numerator = ( ((numerator+(denominator*integer))*t.denominator) + ((t.numerator+(t.denominator*t.integer))*denominator)  );

   x.denominator = (denominator * t.denominator);		// common denominator

   // Simplifies the added fraction
	x.Simplify();
   
	return x;  // returns result
}
Mixed Mixed::operator-(const Mixed& t) const
// operator overload for -.
{
   Mixed x; 

   x.integer = 0;
   if (integer < 0 || t.integer <0)
		x.numerator = (((numerator+(denominator*integer))*t.denominator) 
					+ ((t.numerator+(t.denominator*t.integer*(-1)))*denominator));
   else				 
		x.numerator = ( ((numerator+(denominator*integer))*t.denominator) 
					- ((t.numerator+(t.denominator*t.integer))*denominator));

   // common denominator
   x.denominator = (denominator * t.denominator);		

   // Simplifies the added fraction
   x.Simplify();
   
	return x;  // returns result
}
Mixed Mixed::operator*(const Mixed& t) const
// operator overload for *.
{
   Mixed x; 

   x.integer = 0;

   // as improper fraction
   if (integer < 0 && t.integer <0)		// If integers are negative
		x.numerator = -1*((denominator*integer+numerator*(-1)) * (t.denominator*t.integer+t.numerator*(-1)));
   else if (integer < 0)
		x.numerator = -1*((denominator*integer+numerator*(-1)) * (t.denominator*t.integer+t.numerator));
   else if (t.integer <0)
		x.numerator = -1*((denominator*integer+numerator*(-1)) * (t.denominator*t.integer+t.numerator*(-1)));
   else
		x.numerator = ((denominator*integer+numerator) * (t.denominator*t.integer+t.numerator));

   x.denominator = (denominator * t.denominator);		// common denominator

   // Simplifies the added fraction
	x.Simplify();
   
	return x;  // returns result
}
Mixed Mixed::operator/(const Mixed& t) const
// operator overload for -.
{
   Mixed x; 

   x.integer = 0;

   // as improper fraction
   x.numerator = ((denominator*integer+numerator) * (t.denominator));
   x.denominator = (denominator*(t.denominator*t.integer+t.numerator));		// common denominator
   // Simplifies the added fraction
	x.Simplify();
   
	return x;  // returns result
}
Mixed Mixed::operator++( ) 
//prefix increment operator overload 
{
    integer++;

    return Mixed(integer, numerator, denominator);
}
Mixed Mixed::operator++(int ignoreMe) 
//postfix increment operator overload 
{
	int temp1 = integer;
    integer++;

    return Mixed(temp1, numerator, denominator);
}

Mixed Mixed::operator--(int ignoreMe)
//postfix decrement operator overload 
{
    int temp1 = integer;
    integer--;

    return Mixed(temp1, numerator, denominator);
}

Mixed Mixed::operator--( )
//prefix increment operator overload 
{
    integer--;

    return Mixed(integer, numerator, denominator);
}