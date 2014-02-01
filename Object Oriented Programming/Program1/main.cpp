// main.cpp -- Bob Myers
//
// Driver program to demonstrate the behavior of the Mixed class
// 
// You can add more tests of your own, or write other drivers to test your
// class -- this is NOT a comprehensive set of tests.  This is just a
// sample, which should help check whether your function declarations are
// appropriate, and can test a few sample cases.
 
#include <iostream>
#include "mixed.h"
 
using namespace std;
 
int main()
{
 
  // demonstrate behavior of the two constructors and the << overload
 
  Mixed x(3,20,6), y(-4,9,2), m1(0,-35,10), m2(-1,-2,4), 
		m3(4), m4(-11), m6(0,-35,-10), m7(1,-35,10), m5;

  char answer;
  cout << "Initial values: \nx = " << x << "\ny = " << y
       << "\nm1 = " << m1 << "\nm2 = " << m2  << "\nm3 = " << m3 
       << "\nm4 = " << m4 << "\nm5 = " << m5  << "\nm6 = " << m6 
	   << "\nm7 = " << m7 << "\n\n";

  // Trying Simplify
  x.Simplify();
  m1.Simplify();
  cout << "x simplified: " << x << " and m1 simplified " << m1 << "\n\n";
 
  // Trying ToFraction
  x.ToFraction();
  y.ToFraction();
  m1.ToFraction();
  cout << "Values as fractions: \nx = " << x << "\ny = " << y
       << "\nm1 = " << m1 << "\n\n";
  
  // demonstrate >> overload
 
  cout << "Enter first number: ";
  cin >> x;
  cout << "Enter second number: ";
  cin >> y;
 
  cout << "You entered:\n";
  cout << "  x = " << x << '\n';
  cout << "  y = " << y << '\n';
 
  // demonstrate comparison overloads
  if (x < y) cout << "(x < y) is TRUE\n";
  if (x > y) cout << "(x > y) is TRUE\n";
  if (x <= y)cout << "(x <= y) is TRUE\n";
  if (x >= y)cout << "(x >= y) is TRUE\n";
  if (x == y)cout << "(x == y) is TRUE\n";
  if (x != y)cout << "(x != y) is TRUE\n";
 
  // demonstrating Evaluate
  cout << "\nDecimal equivalent of " << x << " is " << x.Evaluate() << '\n';
  cout << "Decimal equivalent of " << y << " is " << y.Evaluate() << "\n\n";
  
  cout << "x++ " << x++ << endl;       //  prints 2~04:07:58, t1 is now 2~04:07:59
  cout << "++x " << ++x << endl;          //  prints 2~04:08:00, t1 is now 2~04:08:00
  cout << "x-- " << x-- << endl;       //  prints 2~04:07:58, t1 is now 2~04:07:59
  cout << "--x " << --x << endl;  


  // demonstrating arithmetic overloads
  Mixed a, b, c, d;
  a = x + y;
  b = x - y;
  c = x * y;
  d = x / y;
  cout << "(x + y) = " << a << "       " << a.Evaluate() << '\n';
  cout << "(x - y) = " << b << "       " << b.Evaluate() << '\n';
  cout << "(x * y) = " << c << "       " << c.Evaluate() << '\n';
  cout << "(x / y) = " << d << "       " << d.Evaluate() << '\n';

  // demonstrating arithmetic that uses conversion constructor
  //  to convert the integer operand to a Mixed object
  cout << "(x + 10) = " << x + 10 << '\n';
  cout << "(x - 4) = " << x - 4 << '\n';
  cout << "(x * -13) = " << x * -13 << '\n';
  cout << "(x / 7) = " << x / 7 << '\n';

  return 0;
}