#include "StringInstrument.h"

// TODO: Define mutator functions - 
//      SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()


// TODO: Define accessor functions -
//      GetNumOfStrings(), GetNumOfFrets(), GetIsBowed()

int StringInstrument::GetNumOfStrings()
{
	return numStrings;
}

int StringInstrument::GetNumOfFrets()
{
	return numFrets;
}

bool StringInstrument::GetIsBowed()
{
	return isBowed;
}

void StringInstrument::SetNumOfStrings(int numOfStrings)
{
	numStrings = numOfStrings;
}

void StringInstrument::SetNumOfFrets(int numOfFrets)
{
	numFrets = numOfFrets;
}

void StringInstrument::SetIsBowed(bool bowed)
{
	isBowed = bowed;
}