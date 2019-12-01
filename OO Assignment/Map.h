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

	TypeKey keyPair;
	TypeValue valuePair;

};



template <typename TypeKey, typename TypeValue>
class CMap
{
private:

	unsigned int mMaxLength = 9;

	template <typename TypeKey, typename TypeValue>
	struct iteratorStruct
	{
	public: 
		iteratorStruct() {}  //constructor for iterator class
		~iteratorStruct() { it = NULL;  delete it; }
		iteratorStruct(CDataPairs< typename TypeKey, typename TypeValue>* ptr) : it(ptr) {}	//allows iterator pointer to point towards
		bool operator ==(const iteratorStruct<TypeKey, TypeValue>& itPtr) 
		{ 
			//overload == so user defined data can be compared
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
		CDataPairs<TypeKey, TypeValue>* it;
	};

	unsigned int mLength;

public:


	CMap::CMap<typename TypeKey, typename TypeValue>()
	{
		mLength = 0;

		keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};
	}

	CMap::~CMap<typename TypeKey, typename TypeValue>() { delete[] keyValueArray; }

	void Insert(TypeKey, TypeValue);		//insert a new element 
	void OutputData();
	void Clear();							//clears all elements 
	void Erase(TypeKey);					//erase a specific element 

	bool Empty();							//returns a boolean for if the map is empty
	int Size();					//returns the size of the array
	int MaxSize();					//returns the max size the array can be 

	int Count();							//return number of elements matching specific key. this is useless, 1 key to 1 value
	TypeValue Find(TypeKey);				//looks up a certain element and returns where it is on the array


	void Contains();						//looks up which elements contain whatever is passed through the function 
											//pass over a typevalue, returns array of typekeys that contain original typevalue

	TypeValue get(TypeKey) {return TypeValue};

	using Iterator = iteratorStruct<TypeKey, TypeValue>;
	iteratorStruct<TypeKey, TypeValue> mStart() { return &keyValueArray[0]; };
	iteratorStruct<TypeKey, TypeValue> mEnd() { return &keyValueArray[mLength]; };
	
	CDataPairs<TypeKey, TypeValue>* keyValueArray;

	

};

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Clear()
{
	//need iterator through the array to delete everything in it, return the length of the array to 0
	delete[] keyValueArray;

	keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};
	//set the length of the array to 0 as everything has been deleted
	mLength = 0;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Insert(TypeKey k, TypeValue v)
{
	CDataPairs<TypeKey, TypeValue>* tempArray;

	if (mLength >= mMaxLength)
	{
		mMaxLength = mMaxLength * 2;

		tempArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};

		CMap<TypeKey, TypeValue>::Iterator MyIterator;
		for (int i = 0; i < mLength; i++)
		{
			tempArray[i] = keyValueArray[i];
		}

		delete[] keyValueArray;

		keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};

		for (int i = 0; i < mLength; i++)
		{
			keyValueArray[i] = tempArray[i];
		}

		cout << "this is the max array length: " <<mMaxLength << endl;
	}

	//takes a key and a value, inserts key into key array and value into value array 
	keyValueArray[mLength].keyPair = k;
	keyValueArray[mLength].valuePair = v;
	mLength++;

	tempArray = NULL;
	delete tempArray;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Erase(TypeKey k)
{

	CDataPairs<TypeKey, TypeValue>* tempArray;
	tempArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength];
	int removeAtPoint;

	CDataPairs<TypeKey, TypeValue> tempPair;

	if (mLength == 1){Clear();}
	//this should be an iterator
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

	//for (int i = 0; i < mLength; i++)
	//{
	//	
	//}



	//for (unsigned int i = removeAtPoint; i < mLength - 1; i++)
	//{
	//	keyValueArray[i] = keyValueArray[i + 1];
	//}
	//
	//keyValueArray[mLength -1].keyPair = NULL;
	//keyValueArray[mLength -1].valuePair = NULL;

	//i spent too long on this to get rid of it, im actually an idiot tho
	//takes a key, erase the key and the value, reduce length by 1
	//this should be an iterator
	for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
	{
		if (MyIterator.index != removeAtPoint)
		{
			//erase key and value associated with position, make length 1 less, move everything ahead to being 1 position less on the array
			tempArray[MyIterator.index] = keyValueArray[MyIterator.index];
		}
	}
	delete[] keyValueArray;

	keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};
	//this should be an iterator
	for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
	{
		if (MyIterator.index != removeAtPoint)
		{
			keyValueArray[MyIterator.index] = tempArray[MyIterator.index];
		}
	}

	//insertionSort(keyValueArray, mLength);
	//mEnd--;
	mLength--;

	tempArray = NULL;

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
int CMap<TypeKey, TypeValue>::Count()
{
	//useless lul
}

template <typename TypeKey, typename TypeValue>
TypeValue CMap<TypeKey, TypeValue>::Find(TypeKey k)
{
	//this should be an iterator
	CMap<TypeKey, TypeValue>::Iterator MyIterator;
	for (MyIterator = mStart(); MyIterator != mEnd(); ++MyIterator)
	{
		if (keyValueArray[MyIterator.index].keyPair == k)
		{
			cout << "key is: " << keyValueArray[MyIterator.index].keyPair << "  value is: " << keyValueArray[MyIterator.index].valuePair << endl;
			return keyValueArray[MyIterator.index].valuePair;
		}
	}
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Contains()
{

}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::OutputData()
{
	if (mLength != 0)
	{
		//this should be an iterator
		for (int i = 0; i < mLength; i++)
		{
			cout << "the Key is:" << keyValueArray[i].keyPair << " the Value is:" << keyValueArray[i].valuePair << endl;
		}
	}
	else
	{
		cout << "nothing on the array" << endl;
	}

}

//this is the proper sort

//template <typename TypeKey, typename TypeValue>
//void insertionSort(CDataPairs<TypeKey, TypeValue> arr[], int length)
//{
//	CDataPairs<TypeKey, TypeValue> key;
//	int i, j;
//	for (i = 1; i < length; i++)
//	{
//
//		key.keyPair = arr[i].keyPair;
//		key.valuePair = arr[i].valuePair;
//
//		j = i - 1;
//
//		while (j >= 0 && arr[j].keyPair > key.keyPair)
//		{
//			if (arr[i].keyPair == 0)
//			{
//				for (unsigned int j = i; j < mLength - 1; i++)
//				{
//					keyValueArray[i] = keyValueArray[i + 1];
//				}
//			}
//
//			arr[j + 1] = arr[j];
//			j--;
//
//			for (unsigned int i = removeAtPoint; i < mLength - 1; i++)
//			{
//				keyValueArray[i] = keyValueArray[i + 1];
//			}
//
//
//		}
//		arr[j + 1] = key;
//
//	}
//}

//void insertionSort(CDataPairs<TypeKey, TypeValue> arr[], int length)
//{
//	TypeKey tempKey;
//	TypeValue tempValue;
//
//	int i, j, min;
//
//	for (i = 1; i < length; i++)
//	{
//		tempKey = arr[i].key
//			j = i - 1;
//		while (j >= 0 && arr[i].key > tempKey)
//		{
//			arr[j + 1] = arr[j];
//			j = j - 1
//		}
//
//	}
//}