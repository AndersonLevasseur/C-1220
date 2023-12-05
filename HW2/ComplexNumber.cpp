// Author:  Keith A. Shomper
// Date:    Jan 7, 2020
// Purpose: Starter code for HW#2

#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(const char* str)
{
	float rIn = 0.0;
	float iIn = 0.0;
	const char* zz = strchr(str, 'i');
	stringstream ss(str);
	ss >> rIn >> iIn;
	r = rIn;
	i = iIn;
	if (zz != nullptr)
	{
		if (str[strlen(str) - 2] != '0' && iIn == 0.0) 
			//makes sure the 0i case isn't in effect
		{
			i = 1;
			if (str[strlen(str) - 2] == '-') { i = -1; }
			//checks the -i case
			else if (rIn != 0)               { i = rIn; 
			                                   r = 0;  }
		}
	}
}

ComplexNumber ComplexNumber::operator*(ComplexNumber rhs)
{
	float tempR = (r * rhs.r) - (i * rhs.i);
	rhs.i = (i * rhs.r) + (rhs.i * r);
	rhs.r = tempR;
	return rhs;
}

istream& operator>>(istream& istrm, ComplexNumber& rhs)
{
	string str;
	istrm >> str;
	ComplexNumber lhs = ComplexNumber(str.c_str());
	rhs = lhs;

	return istrm;
}

ComplexNumber::ComplexNumber(float real, float imag) {
	r = real;
	i = imag;
}

ComplexNumber::ComplexNumber(const ComplexNumber& rhs) {
	r = rhs.r;
	i = rhs.i;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& rhs) {
	r = rhs.r;
	i = rhs.i;
	return *this;
}

bool ComplexNumber::operator==(const ComplexNumber& rhs) const {
	return (r == rhs.r && i == rhs.i);
}

ComplexNumber operator+ (const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;

	return result;
}

ComplexNumber operator- (const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;

	return result;
}

ostream& operator<< (ostream& out, const ComplexNumber& b) {
	bool rPrinted = false;

	if (b.r != 0 || (b.r == 0 && b.i == 0)) {
		out << b.r;
		rPrinted = true;
	}

	if (b.i > 0) {
		if (rPrinted) {
			out << "+";
		}
		if (b.i != 1) {
			out << b.i;
		}
		out << "i";
	}
	else if (b.i < 0) {
		if (b.i == -1) {
			out << "-";
		}
		else {
			out << b.i;
		}
		out << "i";
	}

	return out;
}
