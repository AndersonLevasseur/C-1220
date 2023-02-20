#pragma once
// Author:  Keith A. Shomper
// Date:    Jan 7, 2020
// Purpose: Starter code for HW#2

#include <iostream>

using namespace std;

class ComplexNumber {
public:
	// constructors (copy constructor not necessary, included for illustration)
	ComplexNumber(float real = 0.0, float imag = 0.0);
	ComplexNumber(const ComplexNumber& rhs);
	// add new construtor here ...
	ComplexNumber(const char* str);
	// assignment operator (not necessary, included for illustration)
	ComplexNumber& operator=(const ComplexNumber& rhs);

	// the multiplication operation is a member function
	// add new mult op here ...
	ComplexNumber operator*(ComplexNumber rhs);

	// equality operator needed for unit test in HW2
	bool operator==(const ComplexNumber& rhs) const;

	// friend operator functions
	friend ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
	friend ComplexNumber operator-(const ComplexNumber&, const ComplexNumber&);
	friend ostream& operator<<(ostream&, const ComplexNumber&);
	// add new input operator here ...
	friend istream& operator>>(istream&, ComplexNumber&);

	// data members
private:
	float r;
	float i;
};
