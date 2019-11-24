#include "Map.h"
#include <iostream>
using namespace std;

void main()
{

	int TestData[]{10, 51, 123, 38, 22, 19, 18, 31, 17, 200};
	float TestData2[]{10.2f, 37.1f, 19.4f, 81.2f, 1.9f, 8.8f, 9.1f, 30.3f, 78.9f, 40.8f};

	CMap<int, float>* map = new CMap<int, float>;
	//testing insert function
	for (int i = 0; i < 10; i++)
	{
		map->Insert(TestData[i], TestData2[i]);
	}

	//outputting all elements of array
	map->LookUp();
	
	system("pause");

	map->Erase(10);

	map->LookUp();

	//testing find function
	map->Find(51);


	system("pause");

	map->Size();
	map->MaxSize();

	map->Empty();

	//testing clear function
	map->Clear();

	map->Size();

	map->Empty();

	//inserting and finding works after clear
	map->Insert(10, 10.2f);

	map->Find(10);

	map->LookUp();




	system("pause");
}