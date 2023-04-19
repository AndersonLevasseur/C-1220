#pragma once
#ifndef STATEPAIR
#define STATEPAIR

using namespace std;

template<typename T1, typename T2>
class StatePair {
public:
	// TODO: Define constructors
	StatePair() 
	{
		key;
		value;
	}

	StatePair(T1 userKey, T2 userValue)
	{
		key = userKey; 
		value = userValue;
	}

	// TODO: Define mutators, and accessors for StatePair
	void SetKey(T1 newKey)     { key = newKey; }
	void SetValue(T2 newValue) { value = newValue; }
	T1 GetKey()           { return key; }
	T2 GetValue()         { return value; }

	// TODO: Define PrintInfo() method
	void PrintInfo()
	{
		cout << key << ": " << value << endl;
	}
private:
	T1 key;
	T2 value;
};
#endif