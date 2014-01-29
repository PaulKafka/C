/* File: MyString.cpp
   Author: Paul Kafka
   Description: Implementation for custom class that is used for storing and 
   manipulating strings.*/

#include "MyString.h" /* MyString class declaration*/
#include <string.h>   /* strcpy, strlen, etc.*/
#include <cstdio> // added after submitted

using namespace std;
                                     
MyString::MyString(const char* init_str) 
/* Initializes calling MyString object to represent c-string 'init_str'. 
   Tokenization and substring generation state are initialized to be invalid. */
{	
	str_length = strlen(init_str);			// Take str_length
	str_ptr = new char[strlen(init_str) +1];// leave room for '\0'
	strcpy(str_ptr, init_str);				// string copy

	int token_index =-1;	// Invalid
	char token_delim = ',';	// Delim set to comma
	int substring_size = -1;// Invalid
	int substring_pos = -1; // Invalid
}    

MyString::~MyString() 
//Deallocates memory resources associated with calling object.
{
	if (str_ptr != NULL)
		delete[] str_ptr;
}

void MyString::Resize(int new_length) 
/* Resize the calling object's internal string representation to allow a string 
   of length 'new_length', meaning an allocation of 'new_length' + 1. Previous 
   string content should be preserved as much as possible (shrinking may 
   truncate content).  Tokenization and substring generation state should be 
   invalidated by a call to this function.*/
{
	token_index =-1;		// Invalidated
	substring_size = -1;	// Invalidated
	substring_pos = -1;		// Invalidated

	// If new_length is uninitialized... set to 0
	if ((new_length < 0) || (new_length >999))
		new_length=0;
	
	char * temp_str_ptr= new char[new_length+1];	// Allocate a new array.
    strncpy(temp_str_ptr, str_ptr, new_length);		// copy old string to temp
	str_length = new_length;						// set length 
	
	delete [] str_ptr;			// Remove the old array contents
	str_ptr = temp_str_ptr;		// Point old array to temp array
}

char& MyString::operator[](int pos) 
/* Returns reference of calling object's char in c-string representation at 
   'pos'. If 'pos' is invalid, an error message should be printed to std::cerr 
   (including file name, function, error case) and the program should immediately
   exit with status 1.*/
{
	if ((pos <= str_length) && (pos >= 0))		// Valid
		return this->str_ptr[pos]; 
	else										// Invalid
	{	// Error Message
		std::cerr << "Error: MyString.cpp, char& operator[](int), Position referenced is not Valid";
		exit (1);
	}
}  

char MyString::operator[] (int pos) const 
/* Same as overload above (This version allows []'s to be used for const 
   objects).*/
{
	if ((pos <= str_length) && (pos >= 0))		// Valid
		return this->str_ptr[pos]; 
	else										// Invalid
	{	// Error Message
		std::cerr << "Error: MyString.cpp, char operator[] (int) const, Position referenced is not Valid";
		exit (1);
	}
}      

MyString operator+(const MyString& my_str1, const MyString& my_str2) 
/* Returns Mystring object that represents the concatination of MyString objects
   'my_str1' and 'my_str2'.  Tokenization and substring generation state are 
   invalid in returned object.                                                 */
{
	MyString ret;		

	// Allocate enough space
	ret.Resize(my_str1.str_length + my_str2.str_length);

	for(int i = 0; i < my_str1.str_length; i++)		// put str1 in
		ret.str_ptr[i] = my_str1.str_ptr[i];
	ret.str_ptr[my_str1.str_length] = NULL;			// add null

	strcat(ret.str_ptr, my_str2.str_ptr);			// put str2 in
	ret.str_ptr[ret.str_length] = NULL;				// add null

	ret.token_index =-1;		// Invalidated
	ret.substring_size = -1;	// Invalidated
	ret.substring_pos = -1;		// Invalidated
	
	return ret;
}

MyString& MyString::operator=(const MyString& ms_src) 
/* Changes calling object to a copy of 'ms_src'.  Tokenization and substring 
   generation state of calling object are invalidated.  Returns calling object 
   reference to allow casecading.*/
{
	token_index =-1;		// Invalidated
	substring_size = -1;	// Invalidated
	substring_pos = -1;		// Invalidated

	if (this !=  &ms_src)
	{
		str_length = ms_src.str_length;		// Take str length
		str_ptr = new char[str_length+1];   // Leave room for '\0'
		strcpy(str_ptr, ms_src.str_ptr);    // String copy 
	}
	return *this;
}

MyString& operator+=(MyString& ms_str1, const MyString& ms_str2) 
/* Changes 'ms_str1' to a concatination of itself with 'ms_str2'. Returns 
   MyString& to allow casecading. Tokenization and substring generation 
   state within 'ms_str1' are invalidated.*/
{
	ms_str1 = ms_str1 + ms_str2;	// token invalidated in + operator
	return ms_str1;
}

MyString::MyString(const MyString& ms_str) 
/* Initializes calling MyString object to be a copy of 'ms_str'. Tokenization  
   and substring generation state are invalidated.*/
{
	token_index =-1;		// Invalidated
	substring_size = -1;	// Invalidated
	substring_pos = -1;		// Invalidated

	str_length = ms_str.str_length;		// Copy str length
	str_ptr = new char[str_length+1];   // leave room for '\0'
	strcpy(str_ptr, ms_str.str_ptr);	// String Copy  
}

ostream& operator<<(ostream& os, const MyString& my_str) 
/* Outputs characters stored by MyString object 'my_str' to output stream 'os' */
{
	os << my_str.str_ptr;
	return os;
}
  
istream& operator>>(istream& is, MyString& my_str) 
/* Changes MyString object my_str's data to hold characters input from stream
   'is'. Input ends when a newline or EOF is encountered (the newline should
   be extracted and discarded).  There is no maximum number of characters that
   can be input and the function must not overflow any buffers or use a temporary
   buffer greater than 101 char's.  Hint: Use MyString '+=' overload for 
   concatination.       */   
{
	//for(int i = 0; ((i !=  '\n') && (i <101) && (i != '\0')); i++)
	//{		my_str.str_length++;}
	
	is.getline(my_str.str_ptr,101, '\n');
	my_str.str_length = strlen(my_str.str_ptr);
	my_str.str_ptr[my_str.str_length+1] = NULL;		// add null
	return is;
} 

MyString& operator++(MyString& ms_str) // Prefix
/* Rotates characters stored in 'ms_str' to the right by one and returns new 
   version of 'ms_str'. Tokenization and substring generation state wihtin 
   'ms_str' become invalid.*/
{
	MyString temp;

	temp.Resize(ms_str.str_length);	// Allocate space

	// Copy array into temp array
	for (int i = 0; i < ms_str.str_length; i++)
		temp.str_ptr[i]=ms_str.str_ptr[i];

	temp.str_ptr[temp.str_length] = NULL;	// add null	

	// Shift the array 1 to the right
	for (int i = 1, j=0; i < ms_str.str_length; i++, j++)
		ms_str.str_ptr[i]= temp.str_ptr[j];	// start at array[1]

	// Put the correct first value
	ms_str.str_ptr[0] = temp.str_ptr[ms_str.str_length-1];

	ms_str.token_index =-1;			// Invalidation
	ms_str.substring_size = -1;		// Invalidation
	ms_str.substring_pos = -1;		// Invalidation

	return ms_str;
}

MyString operator++(MyString& ms_str, int junk) // Postfix
/* Same as above except returns unaltered copy of 'ms_str'*/
{
	MyString temp(ms_str.str_ptr);	// Make a temp
	++ms_str;	// Use prefix

  	return temp; // Send temp
}

MyString& operator--(MyString& ms_str)
/* Rotates characters stored in 'ms_str' to the left by one and returns new 
   version of 'ms_str'. Tokenization and substring generation state wihtin 
   'ms_str' become invalid.*/
{
	MyString temp;	// Make temp

	temp.Resize(ms_str.str_length);	// Allocate enough space

	// Copy array into temp
	for (int i = 0; i < ms_str.str_length; i++) 
		temp.str_ptr[i]=ms_str.str_ptr[i];

	temp.str_ptr[temp.str_length] = NULL;	// Add null

	// Shift original array 1 to the left
	for (int i = 0; i < ms_str.str_length-1; i++)
		ms_str.str_ptr[i]= temp.str_ptr[i+1];

	// Fix last array
	ms_str.str_ptr[ms_str.str_length-1] = temp.str_ptr[0];

	ms_str.token_index =-1;			// Invalidation
	ms_str.substring_size = -1;		// Invalidation
	ms_str.substring_pos = -1;		// Invalidation

	return ms_str;
}

MyString operator--(MyString& ms_str, int junk)
/* Rotates characters stored in 'ms_str' to the *left* by one and returns new 
   version of 'ms_str'.                                                        */
{
	MyString temp(ms_str.str_ptr);	// Make temp
	--ms_str;	// Use prefix

  	return temp;	// Return temp
}


void MyString::StrCpy(char *buffer, int len) const 
/* Accepts pointer to char buffer and it's size in bytes. Fills 'buffer' with 
   c-string from calling object.  Will stop short of overrunning buffer.*/
{
	int length = len/8;	// lengths in bytes

	char * temp_str_ptr= new char[length+1];	// Allocate a new array.

    strncpy(temp_str_ptr, str_ptr, length);	// copy array into temp
	temp_str_ptr[length] = NULL;				// Add null
	
	buffer = temp_str_ptr;					// Point buffer to temp array

	// Used for testing
	//cout << "\nStrCpy: " << buffer << endl;
}
    

void MyString::ReversedStrCpy(char *buffer, int len) const 
/* Same as above except that buffer is filled by reversed version of calling 
   object's c-string.                                                          */
{

	int length = len/8; // length in byes

	char * temp_str_ptr= new char[length+1];	// Allocate a new array.

	// fill array in reverse
	for(int i = 0; i < length+1; i++) 
	{
		temp_str_ptr[i] = str_ptr[str_length-i-1];
		buffer[i] = temp_str_ptr[i];
	}

	// Used for testing
	//cout << "\nRStrCpy: " << buffer << endl;
}

const char* MyString::cstring() const 
// Returns c-string representation of MyString object.
{
	return str_ptr; // returns the c-string to the object
}
   
int MyString::GetLength() const 
// Return length of calling object.
{
  return str_length; // returns the length of the object
}
   
/* Comparison Operators:

   Compares two MyString objects.  Comparison is case insensitive.  A comparison
   starts by comparing the first character of each string. If they are equal to 
   each other, it continues with the following pairs until the characters differ
   or until a terminating null-character is reached.  Non-alphabetical characters
   are compared using their ascii value (eg. '*' == 42 and is greater than '&' == 
   38). */

bool operator>  (const MyString& ms_str1, const MyString& ms_str2) 
{
	if (strcmp (ms_str1.str_ptr,ms_str2.str_ptr) > 0)
		return true;
	else
		return false;	
}

bool operator<  (const MyString& ms_str1, const MyString& ms_str2) {
	return(ms_str2 > ms_str1); }

bool operator<= (const MyString& ms_str1, const MyString& ms_str2) {
  return !(ms_str1 > ms_str2); 
}

bool operator>= (const MyString& ms_str1, const MyString& ms_str2) {
  return !(ms_str2 > ms_str1); 
}

bool operator== (const MyString& ms_str1, const MyString& ms_str2) {
  return ((ms_str1 >= ms_str2) && (ms_str2 >= ms_str1)); 
}

bool operator!= (const MyString& ms_str1, const MyString& ms_str2) {
  return ((ms_str1 > ms_str2) || (ms_str2 > ms_str1)); 
}

/* String tokenization allows us to use a character known as a delimeter to 
   divide a string into non-empty substrings known as tokens.  Each token 
   contains the sequence of characters starting after the last token returned
   by MyString::NextToken (or from the start of the string if this is the first 
   call to MyString::NextToken after MyString::Tokenize was called) and preceding 
   the next delimeter in the string (or the end of the string).  Multiple 
   delimeter characters in a row count as 1 and a delimeter at the start or end 
   of the string are ignored (to prevent empty tokens).  

   Examples (using delimeter ','):
     String: "Hello, How,,Are ,You?" Tokens: "Hello" " How" "Are " "You?"
     String: " a"                    Tokens: " a"
     String: ",okie,dokie.,"         Tokens: "okie" "dokie." */

   
const char* MyString::NextToken(int& len)
{
  /*This function will return the tokens of the string represented by the calling
   MyString object in order following a call to MyString::Tokenize (calls to this
   function on an object that has never called MyString::Tokenize should output and
   error message and exit with status 2). Tokens are returned by a const char* to 
   the start the token within this->str_ptr and by setting the len reference parameter
   to the number of chars in the token.  After the last token in the string is returned,
   all future calls to this function will set len to 0 and return NULL, until tokenization
   state is reset.  Modifying the string represented by the calling object invalidates
   tokenization state and requires another call to MyString::Tokenize (such a scenario is 
   undefined).*/

	char * tok_ptr;		// token pointer
	int counter1=0;
	int counter2=0;
	int pos=0;		// position
	bool flag1 = false;
	bool flag2 = false;

	if(token_index == -1) 
	{	// Print Error Message
		cerr << "Never called Tokenize Function\n";
		exit(2);
	}

	while(flag2==false) 
	{
		if(pos == token_index)	// New Token
			flag1 = true;

	
		if(pos > token_index || counter2 > str_length) // position greater than token
			flag2 = true;

		if(str_ptr[counter2] == token_delim) // at the delimeter
			++pos; // increment

		if(flag1 == true)
			counter2++;
		else			// increase counters
		{	
			counter1++;
			counter2++;
		}
	}

	token_index++;	// Increment token index

	len = counter2 - counter1 - 2;	// Update len

	if(len == -2)	// No more tokens. Reset
	{
		len = 0;
		return NULL;
	}
	tok_ptr = &str_ptr[counter1];

	return tok_ptr;
}

void MyString::Tokenize(char delim) 
/* Called once on an object predceding zero or more calls to MyString::NextToken.  
   Clears any previous tokenization state of the calling object and initializes 
   it in a manner that the next call to MyString::NextToken on this object will 
   start searching from the beginning of string for tokens using delimeter 
   'delim'.                                                                    */
{
	if(token_index = -1)	// Starts from the beginning now
		token_index = 0;
	
	token_delim = delim;	// Set the Delimeter
}
 
const char *MyString::GenerateSubstring(int& len, bool reset) 
/* If 'reset' is true, initializes substring generation state, returns a
   substring of calling object after setting 'len' to the length of said 
   substring.  If 'reset' is false, returns a substring of calling object that 
   hasn't been returned since last call where 'reset' was true, if no such 
   substring exists, returns NULL and sets 'len' to 0. */
{
	 if (reset == true)		// Initializes substring generation state
	 {
		substring_size = len;
		substring_pos = 0;
		substring_pos++;

		return NULL; // returns a substring of calling object
		/*
		char * temp= new char[len*len][len+1];	// Allocate a new 2D array.
		
		for (int i= 0; i< len; i++)	// 2D array to hold all the substrings
		{
			for (int j= 0; j< len; j++)
				temp[i][j] = str_ptr[j];
		}
		*/
	 } 
  
	 else if (reset == false)
		return NULL ; // returns a substring of calling object that hasn't been 
					  //returned since last call where 'reset' was true
	else
	{
		len =0;
		return NULL;
	}
}

 
const char* MyString::LargestCommonSubstring(const MyString& ms_str, int& len) 
/* Compares all substrings of calling object against all substrings of 'ms_str'
   and returns pointer to the start of the largest common substring after 
   setting 'len' to the length of said substring.*/  
{
	GenerateSubstring(len, true);

	return NULL;
}