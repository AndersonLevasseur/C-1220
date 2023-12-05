/*
* Author:    Anderson Levassur
* Purpose: Reverse a section of string between the given indices
* Date:       26 Jan 2023
*/


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int zymain(int, char**);
void reverse(char*, char*);

int main(int argc, char** argv) {

	return zymain(argc, argv);
}

int zymain(int argc, char** argv) {

	int frontIndex;
	int rearIndex;

	char* front;
	char* rear;


	// verifies : 
	//   * that only 4 arguments entered in the command line
	if (argc != 4)
	{
		cout << "Standard Error : wrong number of arguments";
		return 1;
	}

	// verifies :
	//   * that frontIndex and rearIndex are integers
	try
	{
		frontIndex = stoi(argv[2]);
		rearIndex = stoi(argv[3]);
	}
	catch (const invalid_argument& ia)
	{
		cout << "ERROR : " << ia.what() << endl;
		cout << "third or fourth agrument not a number";

		return 2;
	}

	// verifies :
	//   * that frontIndex, third argument, is greater than 0
	//   * that it is smaller than the rerIndex, fourth argument
	if (frontIndex < 0)
	{
		cout << "Third argument less than zero";
		return 3;
	}
	else if (frontIndex > rearIndex)
	{
		cout << "Fourth argument less than first argument";
		return 3;
	}

	// verifies :
	//   * that rearIndax, fourth argument, will point to a valid index in the string
	//      * It isn't too large 
	if (rearIndex >= strlen(argv[1]))
	{
		cout << "Rear index larger than string index";
		return 4;
	}

	//Initial print, done here because argv[1] gets changed in thhe for loop
	cout << "Reversing " << argv[1] << " from index " << frontIndex << " to index " << rearIndex << endl;

	//swapping the characters between and including frontIndex and rearIndex
	for (int i = 0; i < (rearIndex - frontIndex + 1) / 2; i++)
	{
		front = &argv[1][frontIndex + i];
		rear = &argv[1][rearIndex - i];
		reverse(front, rear);
	}

	//print of changed string
	cout << " yields   ";
	cout << '"' << argv[1] << '"' << endl;

	return 0;
}

void reverse(char* front, char* rear) {
	// swaps the two characters given
	char temp = *front;
	*front = *rear;
	*rear = temp;


}