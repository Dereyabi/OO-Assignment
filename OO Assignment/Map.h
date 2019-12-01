#pragma once
#include <iostream>
#include <iterator>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>




template <typename TypeKey, typename TypeValue>
class CDataPairs
{
public:

	TypeKey keyPair;		//stores key of any type
	TypeValue valuePair;	//stores value of any type

};



template <typename TypeKey, typename TypeValue>
class CMap
{
private:

	int mMaxLength = 9;		//sets the length of the array to this when initialised 

	template <typename TypeKey, typename TypeValue>
	struct iteratorStruct
	{
	public: 
		iteratorStruct() {}  //constructor for iterator class
		~iteratorStruct() { it = NULL;  delete it; } //stops memory leaks with pointer to the data pairs
		iteratorStruct(CDataPairs< typename TypeKey, typename TypeValue>* ptr) : it(ptr) {}	//allows iterator pointer to point towards data pairs
		bool operator ==(const iteratorStruct<TypeKey, TypeValue>& itPtr) 
		{ 
			//overload == so user defined data can be compared, same with !=
			return it == itPtr.it; 
		}	
		bool operator !=(const iteratorStruct<TypeKey, TypeValue>& itPtr) 
		{ 
			return it != itPtr.it; 
		}	
		iteratorStruct<TypeKey, TypeValue>& operator ++() 
		{ 
			//overload to allow pointer arithmetic to cycle through array using pointer 
			it++; 
			index++;
			return *this; 
		}	
		iteratorStruct<TypeKey, TypeValue>& operator --() 
		{ 
			//same but backwards
			it--;
			index--;
			return *this; 
		}	 
		CDataPairs<TypeKey, TypeValue>* operator ->() 
		{ 
			return *it 
		}	//allows access to keypair and value pair using pointer 

		int index = 0;

	private:
		CDataPairs<TypeKey, TypeValue>* it; //pointer that cycles through the array
	};

	int mLength;	//the current length of the array

public:


	CMap<typename TypeKey, typename TypeValue>::CMap()
	{
		mLength = 0;	
		keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};	//initialises array and allocates array new memory
	}

	CMap<typename TypeKey, typename TypeValue>::~CMap() { delete[] keyValueArray; }

	void Insert(TypeKey, TypeValue);		//insert a new element 
	void OutputData();						//outputs all data in the map
	void Clear();							//clears all elements 
	void Erase(TypeKey);					//erase a specific element 

	bool Empty();							//returns a boolean for if the map is empty
	int Size();								//returns the size of the array
	int MaxSize();							//returns the max size the array can be 

	TypeValue Find(TypeKey);				//looks up a certain element and returns the key and the value 

	using Iterator = iteratorStruct<TypeKey, TypeValue>;							
	iteratorStruct<TypeKey, TypeValue> mStart() { return &keyValueArray[0]; };			//returns mStart as pointer to start of map array  
	iteratorStruct<TypeKey, TypeValue> mEnd() { return &keyValueArray[mLength]; };		//returns mEnd as pointer to end of map array using mLength to find the end
	
	CDataPairs<TypeKey, TypeValue>* keyValueArray;
};

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Clear()
{
	//delete array becasue its quicker to make a new one than cycle through old array
	delete[] keyValueArray;
	keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};
	//set the length of the array to 0 as everything has been deleted
	mLength = 0;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Insert(TypeKey k, TypeValue v)
{
	CDataPairs<TypeKey, TypeValue>* tempArray;
	bool dupeKeyFound = false;	//if a duplicate key is found, output a message and stop the adding of data with dupe key

	//makes the length of the array double what it was if the data goes over what the max length allows
	//dynamic memory allocation 
	if (mLength >= mMaxLength)
	{
		mMaxLength = mLength * 2;

		//copies old array into a new array of the new size
		tempArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};

		CMap<TypeKey, TypeValue>::Iterator MyIterator;
		for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
		{
			tempArray[MyIterator.index] = keyValueArray[MyIterator.index];
		}

		delete[] keyValueArray;

		keyValueArray = tempArray;

		cout << "this is the new max array length: " <<mMaxLength << endl;
	}

	//checks whether a key is a duplicate of another key or not
	CMap<TypeKey, TypeValue>::Iterator MyIterator;
	for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
	{
		if (keyValueArray[MyIterator.index].keyPair == k)
		{
			dupeKeyFound = true;
			cout << "key is a duplicate, data not added" << endl;
		}
	}

	//takes a key and a value, inserts key into key array and value into value array 
	//will only run if the key isnt a dupe 
	if (!dupeKeyFound)
	{
		keyValueArray[mLength].keyPair = k;
		keyValueArray[mLength].valuePair = v;
		mLength++;
	}

	tempArray = NULL;
	delete tempArray;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Erase(TypeKey k)
{

	CDataPairs<TypeKey, TypeValue>* tempArray;
	tempArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength];
	int removeAtPoint;		//which index the data to remove is at 

	CDataPairs<TypeKey, TypeValue> tempPair;

	//just clears the array if there is only one value on it 
	if (mLength == 1){Clear();}
	//finds the point to remove at and points at it
	CMap<TypeKey, TypeValue>::Iterator MyIterator;
	for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
	{
		if (keyValueArray[MyIterator.index].keyPair == k)
		{
			removeAtPoint = MyIterator.index;
			tempPair = keyValueArray[MyIterator.index];
			break;
		}
	}

	//copies the array up until the point to remove at 
	for(int i = 0; i < removeAtPoint; i++)
	{
		//erase key and value associated with position, make length 1 less, move everything ahead to being 1 position less on the array
		tempArray[i] = keyValueArray[i];
	}

	//copies the rest of the array minus the data to remove to the temp array
	for (int i = removeAtPoint + 1; i < mLength; i++)
	{
		tempArray[i - 1] = keyValueArray[i];
	}

	delete[] keyValueArray;

	//copies the temp array into the main array again then make the length 1 lower 
	keyValueArray = tempArray;
	mLength--;

	tempArray = NULL;
	delete tempArray;
}

template <typename TypeKey, typename TypeValue>
bool CMap<TypeKey, TypeValue>::Empty()
{
	//checks if the map is empty or not
	if (mLength == 0)
	{
		cout << "map is empty" << endl;
		return true;
	}
	else
	{
		cout << "map isnt empty" << endl;
		return false;
	}
}

template <typename TypeKey, typename TypeValue>
int CMap<TypeKey, TypeValue>::Size()
{
	//just returns what the current length of the array is 
	cout << "The length is: " << mLength << endl;
	return mLength;
}

template <typename TypeKey, typename TypeValue>
int CMap<TypeKey, TypeValue>::MaxSize()
{
	//just returns what the overall length of the array is
	cout << "The max length is: " << mMaxLength << endl;
	return mMaxLength;
}

template <typename TypeKey, typename TypeValue>
TypeValue CMap<TypeKey, TypeValue>::Find(TypeKey k)
{
	//cycles through the array using pointers then outputs what the kay and the associated value is when it matches the key input
	CMap<TypeKey, TypeValue>::Iterator MyIterator;
	for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
	{
		if (keyValueArray[MyIterator.index].keyPair == k)
		{
			cout << "key is: " << keyValueArray[MyIterator.index].keyPair << "  value is: " << keyValueArray[MyIterator.index].valuePair << endl;
			return keyValueArray[MyIterator.index].valuePair;
		}
	}
	return 0;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::OutputData()
{
	//cycles through iterator and outputs every key and the value unless there is nothing on the array
	if (mLength != 0)
	{
		CMap<TypeKey, TypeValue>::Iterator MyIterator;
		for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
		{
			cout << "the Key is:" << keyValueArray[MyIterator.index].keyPair << " the Value is:" << keyValueArray[MyIterator.index].valuePair << endl;
		}
	}
	else
	{
		cout << "nothing on the array" << endl;
	}

}
