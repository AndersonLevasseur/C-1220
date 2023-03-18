#include "OfferedCourse.h"

// TODO: Define mutator functions -
//      SetInstructorName(), SetLocation(), SetClassTime()
void OfferedCourse::SetInstructorName(string iName) {
	instructorName = iName;
}
	 
void OfferedCourse::SetLocation(string loc) {
	location = loc;
}
	 
void OfferedCourse::SetClassTime(string time) {
	classTime = time;
}

string OfferedCourse::GetInstructorName() {
	return instructorName;
}

string OfferedCourse::GetLocation() {
	return location;
}

string OfferedCourse::GetClassTime() {
	return classTime;
}

// TODO: Define accessor functions -
//      GetInstructorName(), GetLocation(), GetClassTime()