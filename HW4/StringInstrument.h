#pragma once
#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

class StringInstrument : public Instrument {
private:
	int numStrings, numFrets;
	bool isBowed;
public:
	int GetNumOfStrings();

	int GetNumOfFrets();

	bool GetIsBowed();

	void SetNumOfStrings(int numOfStrings);

	void SetNumOfFrets(int numOfFrets);

	void SetIsBowed(bool bowed);

	// TODO: Declare private data members: numStrings, numFrets, isBowed


	// TODO: Declare mutator functions - 
	//      SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()


	// TODO: Declare accessor functions -
	//      GetNumOfStrings(), GetNumOfFrets(), GetIsBowed()


};

#endif
