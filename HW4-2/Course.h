#pragma once
#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course {
	// TODO: Declare private data members
private:
	string courseName, courseNumber;
public:
	void SetCourseNumber(string cNum);

	void SetCourseTitle(string cTitle);

	string GetCourseNumber();

	string GetCourseTitle();

	void PrintInfo();

	// TODO: Declare mutator functions 
	//       SetCourseNumber(), SetCourseTitle()


	// TODO: Declare accessor functions - 
	//       GetCourseNumber(), GetCourseTitle()


	// TODO: Declare PrintInfo()

};

#endif
