#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers
void PrintVector(vector<Plant*> plant)
{
	for (int i = 0; i < plant.size(); i++)
	{
		cout << "Plant " << i+1 << " Information:\n";
		plant.at(i)->PrintInfo();
		cout << endl;
	}
}

int main() {
	// TODO: Declare a vector called myGarden that can hold object of type plant pointer
	vector<Plant*> myGarden;
	// TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
	//       colorOfFlowers, isAnnual
	string plantName, flowerName, colorOfFlowers;
	int plantCost, flowerCost;
	bool isAnnual;

	string input;

	cin >> input;

	int i = 0;
	bool flower = false;
	bool plant = false;
	int p = 0;
	int f = 0;

	Flower* inputFlower = new Flower;
	Plant* inputPlant = new Plant;

	while (input != "-1") {
		// TODO: Check if input is a plant or flower
		//       Store as a plant object or flower object
		//       Add to the vector myGarden


		if (input == "flower")
		{
			inputFlower = new Flower;
			flower = true;
			plant = false;
			i = 0;
			f++;
		}
		else if (input == "plant")
		{
			inputPlant = new Plant;
			plant = true;
			flower = false;
			i = 0;
			p++;
		}
		else
		{
			if (plant)
			{

				switch (i % 3)
				{
				case 1:
					inputPlant->SetPlantName(input);
					break;
				case 2:
					inputPlant->SetPlantCost(stoi(input));
					myGarden.push_back(inputPlant);
					break;
				default:
					throw "Plant switch case error";
					break;
				}
			}
			else if (flower)
			{
				switch (i % 5)
				{
				case 1:
					inputFlower->SetPlantName(input);
					break;
				case 2:
					inputFlower->SetPlantCost(stoi(input));
					break;
				case 3:
					if (input == "false")
					{
						inputFlower->SetPlantType(false);
					}
					else if (input == "true")
					{
						inputFlower->SetPlantType(true);
					}
					else
					{
						throw "case 3 not true or false";
					}
					break;
				case 4:
					inputFlower->SetColorOfFlowers(input);
					myGarden.push_back(inputFlower);
					break;
				default:
					throw "Flower switch case error";
					break;
				}
			}
			else
			{
				throw "Not a flower or a plant";
			}
		}
		i++;
		cin >> input;
	}

	// TODO: Call the method PrintVector to print myGarden
	PrintVector(myGarden);

	for (size_t i = 0; i < myGarden.size(); ++i) {
		delete myGarden.at(i);
	}

	return 0;
}