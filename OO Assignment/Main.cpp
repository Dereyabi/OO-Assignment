#include "Map.h"
#include <iostream>
using namespace std;

void main()
{

	int TestData[]{10, 51, 123, 38, 22, 19, 18, 31, 17, 200};
	float TestData2[]{10.2f, 37.1f, 19.4f, 81.2f, 1.9f, 8.8f, 9.1f, 30.3f, 78.9f, 40.8f};

	CMap<int, float>* map = new CMap<int, float>;

	for (int i = 0; i < 10; i++)
	{
		map->Insert(TestData[i], TestData2[i]);
	}

	

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
	
	for (int i = 0; i < 10; i++)
	{
		map->LookUp(51);
	}
	
	system("pause");
	
	map->Clear();

	system("pause");
}