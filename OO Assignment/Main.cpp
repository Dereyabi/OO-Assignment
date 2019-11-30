#include "Map.h"
#include <iostream>
using namespace std;

const int arraySizes = 10;

template <typename TypeKey, typename TypeValue>
void TestCases(TypeKey keyArray[], TypeValue valueArray[])
{
	CMap<TypeKey, TypeValue>* map = new CMap<TypeKey, TypeValue>;

	cout << "inserting data" << endl;

	//testing insert function
	for (int i = 0; i < arraySizes; i++)
	{
		map->Insert(keyArray[i], valueArray[i]);
	}

	cout << "Outputting data" << endl;

	//outputting all elements of array
	map->OutputData();

	cout << "erasing first element of the array" << endl;

	map->Erase(keyArray[0]);

	map->OutputData();

	cout << "Finding 6th element of the Array" << endl;

	//testing find function
	map->Find(keyArray[5]);

	system("pause");

	map->Size();
	map->MaxSize();


	map->Empty();

	//testing clear function
	map->Clear();

	map->Size();

	map->Empty();

	map->OutputData();

	cout << "******************************************************************************" << endl;
}

void main()
{
	//Primitive data types are: int, float, string, double, chars, user defined classes 

	//int Test Cases
	
	int TestDataInt[arraySizes]{10, 51, 123, 38, 22, 19, 18, 31, 17, 200};
	float TestDataFloat[arraySizes]{10.2f, 37.1f, 19.4f, 81.2f, 1.9f, 8.8f, 9.1f, 30.3f, 78.9f, 40.8f};
	double TestDataDouble[arraySizes]{ 10.1, 23.4, 1.1, 12.5, 74.1, 98.9, 7.7, 12.4, 98.9, 0.2};
	char TestDataChar[arraySizes]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	string TestDataString[arraySizes]{"ayy", "bee", "see", "dee", "eee", "eff", "gee", "aych", "eye", "jay"};

	//Int Test
	cout << "this is for int" << endl;
	TestCases(TestDataInt, TestDataInt);
	cout << "this is for float" << endl;
	TestCases(TestDataInt, TestDataFloat);
	cout << "this is for double" << endl;
	TestCases(TestDataInt, TestDataDouble);
	cout << "this is for chars" << endl;
	TestCases(TestDataInt, TestDataChar);
	cout << "this is for strings" << endl;
	TestCases(TestDataInt, TestDataString);

	cout << "Start of test for Floats" << endl;

	//Float Test
	cout << "this is for int" << endl;
	TestCases(TestDataFloat, TestDataInt);
	cout << "this is for float" << endl;
	TestCases(TestDataFloat, TestDataFloat);
	cout << "this is for double" << endl;
	TestCases(TestDataFloat, TestDataDouble);
	cout << "this is for chars" << endl;
	TestCases(TestDataFloat, TestDataChar);
	cout << "this is for strings" << endl;
	TestCases(TestDataFloat, TestDataString);

	//Double Test
	cout << "this is for int" << endl;
	TestCases(TestDataDouble, TestDataInt);
	cout << "this is for float" << endl;
	TestCases(TestDataDouble, TestDataFloat);
	cout << "this is for double" << endl;
	TestCases(TestDataDouble, TestDataDouble);
	cout << "this is for chars" << endl;
	TestCases(TestDataDouble, TestDataChar);
	cout << "this is for strings" << endl;
	TestCases(TestDataDouble, TestDataString);

	//Char Test
	cout << "this is for int" << endl;
	TestCases(TestDataChar, TestDataInt);
	cout << "this is for float" << endl;
	TestCases(TestDataChar, TestDataFloat);
	cout << "this is for double" << endl;
	TestCases(TestDataChar, TestDataDouble);
	cout << "this is for chars" << endl;
	TestCases(TestDataChar, TestDataChar);
	cout << "this is for strings" << endl;
	TestCases(TestDataChar, TestDataString);

	//String Test
	cout << "this is for int" << endl;
	TestCases(TestDataString, TestDataInt);
	cout << "this is for float" << endl;
	TestCases(TestDataString, TestDataFloat);
	cout << "this is for double" << endl;
	TestCases(TestDataString, TestDataDouble);
	cout << "this is for chars" << endl;
	TestCases(TestDataString, TestDataChar);
	cout << "this is for strings" << endl;
	TestCases(TestDataString, TestDataString);

	system("pause");
}
