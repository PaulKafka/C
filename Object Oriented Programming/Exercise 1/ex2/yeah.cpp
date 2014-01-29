/* File: filename.cpp
Author: Paul Kafka
Description: This is Exercise 1 for COP3330. 
This program will take an input of five numbers
and output the greatest value and least value.
*/

#include <iostream>
using namespace std;

void main()
{
	// Stores integers inputed
	int num1, num2, num3, num4, num5;	

	// Input
	cin >> num1 >> num2 >> num3 >> num4 >> num5;
	cout << "\n";

	// Greater than output
	if ((num1 >= num2) && (num1 >= num3) && (num1 >= num4) && (num1 >= num5))
		cout << num1;
	else if ((num2 >= num1) && (num2 >= num3) && (num2 >= num4) && (num2 >= num5))
		cout << num2;
	else if ((num3 >= num1) && (num3 >= num2) && (num3 >= num4) && (num3 >= num5))
		cout << num3;
	else if ((num4 >= num1) && (num4 >= num2) && (num4 >= num3) && (num1 >= num5))
		cout << num4;
	else //((num5 >= num1) && (num5 >= num2) && (num5 >= num3) && (num5 >= num4))
		cout << num5;

	cout << "\n";	// Newline

	// Less than output
	if ((num1 <= num2) && (num1 <= num3) && (num1 <= num4) && (num1 <= num5))
		cout << num1;
	else if ((num2 <= num1) && (num2 <= num3) && (num2 <= num4) && (num2 <= num5))
		cout << num2;
	else if ((num3 <= num1) && (num3 <= num2) && (num3 <= num4) && (num3 <= num5))
		cout << num3;
	else if ((num4 <= num1) && (num4 <= num2) && (num4 <= num3) && (num4 <= num5))
		cout << num4;
	else //((num5 <= num1) && (num5 <= num2) && (num5 <= num3) && (num5 <= num4))
		cout << num5;

	cout << "\n";	// Newline
} // End Main