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
    // write your code for the main function of HW1 here
    
    int frontIndex;
    int rearIndex;

    if (argc != 4)
    {
        cout << "Standard Error : wrong number of arguments";
        return 1;
    }

    // try catch statement to check that frontIndex and rearIndex are integers
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

    if (rearIndex >= strlen(argv[1]))
    {
        cout << "Rear index larger than string index";
        return 4;
    }

    char* front;
    char* rear;

    cout << "Reversing " << argv[1] << " from index " << frontIndex << " to " << rearIndex;
    for (int i = 0; i < rearIndex / 2; i++)
    {
        front = &argv[1][frontIndex + i];
        rear = &argv[1][rearIndex - i];
        reverse(front, rear);
    }
    cout << " yields " << argv[1];
    return 0;
}

void reverse(char *front, char *rear) {
    // write your code for the reverse function here
    char temp = *front;
    *front = *rear;
    *rear = temp;


}