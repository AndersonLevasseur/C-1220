#pragma once
#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

class OfferedCourse : public Course {
	// TODO: Declare private data members
private:
	string instructorName, location, classTime;
public:
	void SetInstructorName(string iName);

	void SetLocation(string loc);

	void SetClassTime(string time);

	string GetInstructorName();

	string GetLocation();

	string GetClassTime();


	// TODO: Declare mutator functions -
	//      SetInstructorName(), SetLocation(), SetClassTime()


	// TODO: Declare accessor functions -
	//      GetInstructorName(), GetLocation(), GetClassTime()


};

#endif