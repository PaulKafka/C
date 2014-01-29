//--------------- Date.H ---------------
// By: Paul Kafka

class Date
{
public:
	Date(int m = 1, int d = 1, int y = 2000);	// constructor with parameters
												// default 1/1/2000
   // standard input/output routines
   void Input();								// Prompts user for input
   void Show();									// Outputs data to screen
  
   // accessors
   int GetMonth();								// returns month
   int GetDay();								// returns day
   int GetYear();								// returns year

   // mutator
   bool Set(int m, int d, int y);				// sets date to specified values
   bool SetFormat(char f);						// allows caller to change the format setting
   void Increment(int numDays=1);				// move date forward by # in argument. deault 1
   int Compare(const Date& d);					// compare two date objects

private:
	int month;			// store month
	int day;			// store day
	int year;			// store year
	char format;		// store format
};