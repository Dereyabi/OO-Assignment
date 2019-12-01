#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Map.h"
#include <iostream>
using namespace std;

const int arraySizes = 10;

template <typename TypeKey>
class MyClass
{
public:
	MyClass() {};
	~MyClass() {};

	TypeKey index;
	MyClass(TypeKey a) : index(a) {}
	friend ostream& operator << (ostream& out, const MyClass& c)
	{
		out << c.index;
		return out;
	}

	bool operator ==(const MyClass<TypeKey>& itPtr)
	{
		//overload == so user defined data can be compared
		return index == itPtr.index;
	}

private:

};

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

	cout << endl;

	cout << "Outputting data" << endl;

	//outputting all elements of array
	map->OutputData();

	cout << endl;

	cout << "erasing first element of the array" << endl;

	map->Erase(keyArray[0]);

	cout << endl;

	map->OutputData();

	cout << endl;

	cout << "Finding 6th element of the Array" << endl;

	//testing find function
	map->Find(keyArray[5]);

	cout << endl;

	map->Size();
	map->MaxSize();

	CMap<TypeKey, TypeValue>::Iterator MyIterator;
	for (MyIterator = map->mStart(); MyIterator != map->mEnd(); ++MyIterator)
	{

	}

	map->Empty();

	cout << endl;

	cout << "Clearing Map" << endl;
	//testing clear function
	map->Clear();

	cout << endl;

	map->Size();

	map->Empty();

	map->OutputData();

	system("pause");

	system("CLS");

	delete map;
}

struct MyData
{
public:
	//lists of test data
	int TestDataInt[arraySizes]{ 10, 51, 123, 38, 22, 19, 18, 31, 17, 200 };
	bool TestDataBool[arraySizes]{ true, true, true, true, true, false, false, false, false, false};
	float TestDataFloat[arraySizes]{ 10.2f, 37.1f, 19.4f, 81.2f, 1.9f, 8.8f, 9.1f, 30.3f, 78.9f, 40.8f };
	double TestDataDouble[arraySizes]{ 10.1, 23.4, 1.1, 12.5, 74.1, 98.9, 7.7, 12.4, 98.9, 0.2 };
	char TestDataChar[arraySizes]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	string TestDataString[arraySizes]{ "ayy", "bee", "see", "dee", "eee", "eff", "gee", "aych", "eye", "jay" };
	MyClass<int> TestDataUDC[arraySizes]{ 69, 420, 82, 921, 421, 666, 32, 32, 21, 21 };
};

void main()
{
	//Primitive data types are: int, float, string, double, chars, user defined classes 

	//int Test Cases
	cout << "this is for int" << endl << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataInt);
	}

	cout << "this is for bool" << endl << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataBool);
	}

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataFloat);
	}

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataDouble);
	}

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataChar);
	}

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataString);
	}

	cout << "this is for a UDC" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataInt, Data.TestDataUDC);
	}

	cout << "Start of test for Floats" << endl;
	
	//float Test Cases
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataInt);
	}

	cout << "this is for bool" << endl << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataBool);
	}

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataFloat);
	}

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataDouble);
	}

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataChar);
	}

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataString);
	}
	
	cout << "this is for a UDC" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataFloat, Data.TestDataUDC);
	}

	//double Test Cases
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataInt);
	}

	cout << "this is for bool" << endl << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataBool);
	}

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataFloat);
	}

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataDouble);
	}

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataChar);
	}

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataString);
	}

	cout << "this is for a UDC" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataDouble, Data.TestDataUDC);
	}

	//char Test Cases
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataInt);
	}

	cout << "this is for bool" << endl << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataBool);
	}

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataFloat);
	}

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataDouble);
	}

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataChar);
	}

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataString);
	}

	cout << "this is for a UDC" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataChar, Data.TestDataUDC);
	}

	//string Test Cases
	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataInt);
	}

	cout << "this is for bool" << endl << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataBool);
	}

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataFloat);
	}

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataDouble);
	}

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataChar);
	}

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataString);
	}

	cout << "this is for a UDC" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataString, Data.TestDataUDC);
	}

	//UDC Test Cases

	cout << "this is for int" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataUDC, Data.TestDataInt);
	}

	cout << "this is for bool" << endl << endl;
	{
		MyData Data;
		TestCases(Data.TestDataUDC, Data.TestDataBool);
	}

	cout << "this is for float" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataUDC, Data.TestDataFloat);
	}

	cout << "this is for double" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataUDC, Data.TestDataDouble);
	}

	cout << "this is for chars" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataUDC, Data.TestDataChar);
	}

	cout << "this is for strings" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataUDC, Data.TestDataString);
	}

	cout << "this is for a UDC" << endl;
	{
		MyData Data;
		TestCases(Data.TestDataUDC, Data.TestDataUDC);
	}
	//checking for memory leaks
	_CrtDumpMemoryLeaks();
	system("pause");
}
