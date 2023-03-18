#pragma once
#ifndef INSTRUMENTH
#define INSTRUMENTH

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Instrument {
private:
	string instrumentName;
	string instrumentManufacturer;
	int yearBuilt;
	double cost;

public:
	void SetName(string userName);

	string GetName();

	void SetManufacturer(string userManufacturer);

	string GetManufacturer();

	void SetYearBuilt(int userYearBuilt);

	int GetYearBuilt();

	void SetCost(int userCost);

	int GetCost();

	void PrintInfo();
};

#endif