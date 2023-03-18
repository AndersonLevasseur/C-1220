#include "Course.h"

// TODO: Define mutator functions - 
//       SetCourseNumber(), SetCourseTitle()
void Course::SetCourseNumber(string cNum)
{
	courseNumber = cNum;
}

void Course::SetCourseTitle(string cTitle)
{
	courseName = cTitle;
}

// TODO: Define accessor functions - 
//       GetCourseNumber(), GetCourseTitle()

string Course::GetCourseNumber()
{
	return courseNumber;
}

string Course::GetCourseTitle()
{
	return courseName;
}
// TODO: Define PrintInfo()

void Course::PrintInfo() {
	cout << "Course Information:\n";
	cout << "   Course Number: " << courseNumber << endl;
	cout << "   Course Title: " << courseName << endl;
}