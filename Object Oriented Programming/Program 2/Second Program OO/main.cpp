#include <iostream>
#include "date.h"

using namespace std;

int main()
{
   Date d1;				// should default to 1/1/2000
   Date d2(4,10,1992);  // should init to 4/10/1992
   Date d3(13,30,1990); // invalid month, initializes to Jan 1, 2000 instead. 
   Date d4(2,29,2000); // invalid month, initializes to Jan 1, 2000 instead.
   
   // display dates to the screen
   cout << "\nDate d1 is: "; d1.Show();
   cout << "1/1/2000";
   d1.Set(5,5,5);
	    cout << "\nDate d1 is: "; d1.Show();
   
   cout << "\nDate d2 is: "; d2.Show();
   cout << "4/10/1992";
   cout << "\nDate d3 is: "; d3.Show();
   cout << "1/1/2000";
   cout << "\nDate d4 is: "; d4.Show();
   cout << "2/29/2000";

   // Allow user to enter a date for d1
   d1.Input();					
   cout << "\nDate d1 is: "; d1.Show();			
   

   d1.SetFormat('L');			// change format of d1 to "Long" format
   cout << "\nDate d1 is: ";
   d1.Show();					// print d1 -- should show now in long format
   d1.SetFormat('T');
   cout << "\nDate d1 is: "; d1.Show();
	
   d1.Increment();
   cout << "\nDate d1 is incremented 1: "; d1.Show();
   d1.Increment(5);
   cout << "\nDate d1 is incremented 5: "; d1.Show();
   d1.Compare(d2);
   cout << "\nDate d1 is compared to d2: ";
   cout << d1.Compare(d2) << endl;

      
}