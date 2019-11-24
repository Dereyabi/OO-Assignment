#include "Map.h"
#include <iostream>
using namespace std;

void main()
{

	int userResponse;
	int userInputKey;
	float userInputValue;

	CMap<int, float>* map = new CMap<int, float>;


	if (!map->Empty())
	{
		cout << "map is not empty" << endl;
	}
	else
	{
		cout << "map is empty" << endl;
	}

	cin >> userInputKey;
	cin >> userInputValue;

	map->Insert(userInputKey, userInputValue);

	if (!map->Empty())
	{
		cout << "map is not empty" << endl;
	}
	else
	{
		cout << "map is empty" << endl;
	}

	map->Size();

	map->Contains();

	cin >> userResponse;

	map->LookUp(userResponse);

	system("pause");

	map->Clear();

	system("pause");
}