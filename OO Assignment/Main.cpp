#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Map.h"
#include <iostream>
using namespace std;

const int arraySizes = 10;

class MyClass
{
public:
	MyClass() {};
	~MyClass() {};

	int ahhh = 0;
	
	//overload << so user defined data can be compared

	int operator <<(const MyClass& classPtr) {return classPtr.ahhh;}


private:

};


MyClass twat = MyClass();

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

	CMap<TypeKey, TypeValue>::Iterator MyIterator;
	for (MyIterator = map->mStart(); MyIterator != map->mEnd(); ++MyIterator)
	{

	}

	map->Empty();

	//testing clear function
	map->Clear();

	map->Size();

	map->Empty();

	map->OutputData();

	cout << "******************************************************************************" << endl;

	delete map;
}
struct MyData
{
public:

	int TestDataInt[arraySizes]{ 10, 51, 123, 38, 22, 19, 18, 31, 17, 200 };
	float TestDataFloat[arraySizes]{ 10.2f, 37.1f, 19.4f, 81.2f, 1.9f, 8.8f, 9.1f, 30.3f, 78.9f, 40.8f };
	double TestDataDouble[arraySizes]{ 10.1, 23.4, 1.1, 12.5, 74.1, 98.9, 7.7, 12.4, 98.9, 0.2 };
	char TestDataChar[arraySizes]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	string TestDataString[arraySizes]{ "ayy", "bee", "see", "dee", "eee", "eff", "gee", "aych", "eye", "jay" };
	//MyClass TestDataUDC[arraySizes]{ twat, twat, twat, twat, twat, twat, twat, twat, twat, twat };
};
void main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	//Primitive data types are: int, float, string, double, chars, user defined classes 

	//int Test Cases


	//Int Test
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataInt);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");


	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataFloat);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataDouble);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataChar);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataString);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	//cout << "this is for a UDC" << endl;
	//{
	//	MyData Data;
	//	TestCases(Data.TestDataInt, Data.TestDataUDC);
	//}
	//_CrtDumpMemoryLeaks();
	//system("Pause");

	cout << "Start of test for Floats" << endl;
	
	//Float Test
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataInt);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataFloat);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataDouble);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataChar);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataString);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	
	//Double Test
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataInt);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataFloat);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataDouble);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataChar);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataString);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	
	//Char Test
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataInt);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataFloat);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataDouble);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataChar);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataString);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");
	
	//String Test
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataInt);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataFloat);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataDouble);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataChar);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataString);
	}
	_CrtDumpMemoryLeaks();
	system("Pause");



	system("pause");
}
