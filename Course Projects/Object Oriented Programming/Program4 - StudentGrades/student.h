/* File: student.h
Author: Paul Kafka
Description: This is the declaration for the student class. It makes
a heterogeneous list of students. 
*/

class Student	// Base Class
{
public:
			 Student(char* fn, char* ln, char* c, int s);	// Constructor
			 virtual double FinalAvg()=0;					// Base Final Average Function
			 virtual void Summary()=0;				// Base Summary function
			 char Get_course() const;				// Returns Course[0] value
			 void DisplayTitle();					// Prints Title for output
			 void SubDisplayTitle(int c);			// Prints SubTitle for output
			 
protected:
			char firstName[20];		// Stores students first name for all students
			char lastName[20];		// Stores students last name for all students
			char course[8];			// Stores course for all students
			int numStudents;		// Stores number of students 
			double finalAvg;		// Stores final average for all students
			
};

/////////////////ENGLISH////////////////////////////////
class English_Students : public Student
// derived from Student
{
public:
		English_Students(char* fn, char* ln, char* c, int s,   // firstname,lastname,course,size,
						double a, double p, double m, int f);  // attendance,project,midterm,final
			double FinalAvg();				// Returns Final Average
			void Summary();					// Prints Summary
			int Get_finalExamGrade() const;	// returns final exam grade
			
private: 
			double attendanceGrade;		// Stores attendance grade for enlish students
			double projectGrade;		// Stores project grade	for enlish students
		    double midtermGrade;		// Stores midterm grade for enlish students
			int finalExamGrade;			// Stores final exam grade for enlish students
};
///////////////////HISTORY/////////////////////////////
class History_Students : public Student
// derived from Student
{
public:
			History_Students(char* fn, char* ln, char* c, int s,
							 double tp, double m, int f);  
			double FinalAvg();					// Returns Final Average
			void Summary();						// Prints Summary
			int Get_finalExamGrade() const;		// Returns final exam grade
private:
			// Grades that were inputed from file
			double termPaperGrade, midtermGrade;
			int finalExamGrade; 
};
/////////////////MATH////////////////////////////////////////
class Math_Students : public Student
// derived from Student
{
public:
			Math_Students(char* fn, char* ln, char* c, int s,
							 double q1, double q2, double q3, 
							 double q4, double q5, double t1, 
							 double t2, int f); 
			double FinalAvg();					// Returns Final Average
			void Summary();						// Prints Summary
			int Get_finalExamGrade() const;		// Returns Final exam grade
private:
			// Grades that were inputed from file
			double quiz1Grade, quiz2Grade, quiz3Grade, 
				quiz4Grade, quiz5Grade, test1Grade, 
				test2Grade; 
			int finalExamGrade;
};