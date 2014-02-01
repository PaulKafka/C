/* File: driver.cpp
   Author: Paul Kafka
   Description: Driver file for MyString project. Test my  
   implemntation of the MyString class using this file.
*/

#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
	MyString S;			// creates an empty string
	MyString *tmp_ptr;
	MyString s2("Hello");	// use the conversion constructor
	MyString s3 = "Joes";	// uses copy construction ANd conversion constructor
	MyString s4;  
	s4 = "Fred";
	MyString s5; 

	cout << "\nS = " << S;
	cout << "\ns2 = " << s2;
	cout << "\ns3 = " << s3;
	cout << "\ns4 = " << s4;

	 // Testing plus operator
	 cout<<"\n\n   1.Testing plus operator:\ns2+s4";
     s5 = s2+s4;
     cout<<"\tExpected:\t HelloFred\n";
	 cout<<"\tActual:\t\t "<< s5 <<"\n";
     cout<<"END\n\n";
	
	 // Testing plus equal operator
	 cout<<"\n\n   2. Testing plus equal operator:\ns2+=s3";
     s2+=s3;
     cout<<"\tExpected:\t HelloJoes\n";
	 cout<<"\tActual:\t\t "<< s2 <<"\n";
     cout<<"END\n\n";

	 // Testing pre-increment operator
	 cout<<"\n\n   3. Testing pre-increment operator:\nTEST1 \n";
	 cout << "++s2";
     ++s2;
     cout<<"\tExpected:\t sHelloJoe\n";
	 cout<<"\tActual:\t\t "<< s2 <<"\n";
	 cout << "TEST2 \n++s3";
     ++s3;
     cout<<"\tExpected:\t sJoe\n";
	 cout<<"\tActual:\t\t "<< s3 <<"\n";
     cout<<"END\n\n";
	 
	 // Testing post-increment operator
	 cout<<"\n\n   4. Testing post-increment operator:\nTEST1 \n";
	 cout << "s2++\n";
     cout<<"\tExpected:\t sHelloJoe";
	 cout<<"\n\tActual:\t\t "<< s2++ <<"\n";
	 cout << "s2\n";
     cout<<"\tExpected:\t esHelloJo\n";
	 cout<<"\tActual:\t\t "<< s2 <<"\n";
	 cout << "TEST2 \ns3++\n";
     cout<<"\tExpected:\t sJoe";
	 cout<<"\n\tActual:\t\t "<< s3++ <<"\n";
	 cout << "s3\n";
     cout<<"\tExpected:\t esHelloJo\n";
	 cout<<"\tActual:\t\t "<< s3 <<"\n";
     cout<<"END\n\n";

	 // Testing pre-decrement operator
	 cout<<"\n\n   5. Testing pre-decrement operator:\nTEST1 \n";
	 cout << "--s2";
     --s2;
     cout<<"\tExpected:\t sHelloJoe\n";
	 cout<<"\tActual:\t\t "<< s2 <<"\n";
	 cout << "TEST2 \n++s3";
     --s3;
     cout<<"\tExpected:\t sJoe\n";
	 cout<<"\tActual:\t\t "<< s3 <<"\n";
     cout<<"END\n\n";
	 
	 // Testing post-decrement operator
	 cout<<"\n\n   6. Testing post-decrement operator:\nTEST1 \n";
	 cout << "s2--\n";
     cout<<"\tExpected:\t sHelloJoe";
	 cout<<"\n\tActual:\t\t "<< s2-- <<"\n";
	 cout << "s2\n";
     cout<<"\tExpected:\t HelloJoes\n";
	 cout<<"\tActual:\t\t "<< s2 <<"\n";
	 cout << "TEST2 \ns3--\n";
     cout<<"\tExpected:\t sJoe";
	 cout<<"\n\tActual:\t\t "<< s3-- <<"\n";
	 cout << "s3\n";
     cout<<"\tExpected:\t Joes\n";
	 cout<<"\tActual:\t\t "<< s3 <<"\n";
     cout<<"END\n\n";

	 //comparrison
	cout<<"\n\n   7. Testing comparison operators:\nTEST1 \n";
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	if (s2 < s3) 	cout << "\t" << s2 << " <  " << s3 << " is TRUE\n";
	else			cout << "\t" << s2 << " <  " << s3 << " is FALSE\n";
	if (s2 > s3) 	cout << "\t" << s2 << " >  " << s3 << " is TRUE\n";
	else			cout << "\t" << s2 << " >  " << s3 << " is FALSE\n";
	if (s2 >= s3) 	cout << "\t" << s2 << " >=  " << s3 << " is TRUE\n";
	else			cout << "\t" << s2 << " >  " << s3 << " is FALSE\n";
	if (s2 <= s3) 	cout << "\t" << s2 << " <=  " << s3 << " is TRUE\n";
	else			cout << "\t" << s2 << " <=  " << s3 << " is FALSE\n";
	if (s2 == s3) 	cout << "\t" << s2 << " ==  " << s3 << " is TRUE\n";
	else			cout << "\t" << s2 << " ==  " << s3 << " is FALSE\n";
	if (s2 != s3) 	cout << "\t" << s2 << " !=  " << s3 << " is TRUE\n";
	else			cout << "\t" << s2 << " !=  " << s3 << " is FALSE\n";
	cout << "TEST2\n";
	cout << "s4: " << s4 << endl;
	cout << "s3: " << s3 << endl;
	if (s4 < s3) 	cout << "\t" << s4 << " <  " << s3 << " is TRUE\n";
	else			cout << "\t" << s4 << " <  " << s3 << " is FALSE\n";
	if (s4 > s3) 	cout << "\t" << s4 << " >  " << s3 << " is TRUE\n";
	else			cout << "\t" << s4 << " >  " << s3 << " is FALSE\n";
	if (s4 >= s3) 	cout << "\t" << s4 << " >=  " << s3 << " is TRUE\n";
	else			cout << "\t" << s4 << " >  " << s3 << " is FALSE\n";
	if (s4 <= s3) 	cout << "\t" << s4 << " <=  " << s3 << " is TRUE\n";
	else			cout << "\t" << s4 << " <=  " << s3 << " is FALSE\n";
	if (s4 == s3) 	cout << "\t" << s4 << " ==  " << s3 << " is TRUE\n";
	else			cout << "\t" << s4 << " ==  " << s3 << " is FALSE\n";
	if (s4 != s3) 	cout << "\t" << s4 << " !=  " << s3 << " is TRUE\n";
	else			cout << "\t" << s4 << " !=  " << s3 << " is FALSE\n";
	cout<<"END\n\n";

	// Testing extraction operator
	cout<<"\n\n   8. Testing extraction operator:\n";
	cout<< "\nType a string for s5: ";
	cin >> s5;
	cout << "\t Expected: " << s5 << endl;
	cout<<"END";

	// Testing Tokenization
	cout<<"\n\n   9. Testing Tokenization:\n";
	MyString s9 = "Big, Dog";
	int i =5;
	s9.Tokenize(','); 
	cout << s9.NextToken(i);
	cout<<"\nEND";

	// Testing Accessors
	cout<<"\n\n   10. Testing Accessors:\n";
	cout << "s3\n";
	cout<<"\tExpected Cstring:\t Joes\n";
	cout<<"\tExpected Length:\t 4";
	cout<<"\n\tActual Cstring:\t\t "<< s3.cstring();// print cstring of MyString
	cout<<"\n\tActual Length:\t\t "<< s3.GetLength() <<"\n";// print length of MyString	
	cout<<"END";

	cout << endl;
	return 0;
}