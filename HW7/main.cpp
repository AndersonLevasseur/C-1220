#include <string>
#include <iostream>

using namespace std;

int main() {
	string inputName;
	int age;
	// Set exception mask for cin stream
	cin.exceptions(ios::failbit);

	cin >> inputName;
	while (inputName != "-1") {
		try
		{
			cin >> age;
		}
		catch (ios_base::failure)
		{
			// Clear failbit to be able to use cin again
			cin.clear();
			// Throw away the rest of the failed input line from cin buffer
			string garbage;
			getline(cin, garbage);
			age = -1;
		}
		cout << inputName << " " << (age + 1) << endl;


		cin >> inputName;
	}

	return 0;
}