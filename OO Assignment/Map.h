#pragma once
#include <iostream>

const unsigned int mMaxLength = 696969;

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
public:

	CMap::CMap() 
	{
		mLength = 0;
		keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength] {};

	}

	void Clear();							//clears all elements 
	void Insert(TypeKey, TypeValue);		//insert a new element 
	void Erase(TypeKey);					//erase a specific element 

	bool Empty();							//returns a boolean for if the map is empty
	unsigned int Size();					//returns the size of the array
	unsigned int MaxSize();					//returns the max size the array can be 

	int Count();							//return number of elements matching specific key. this is useless, 1 key to 1 value
	TypeValue Find(TypeKey);				//looks up a certain element and returns where it is on the array
	void LookUp();

	void Contains();						//looks up which elements contain whatever is passed through the function 
											//pass over a typevalue, returns array of typekeys that contain original typevalue

	TypeValue get(TypeKey) {return TypeValue};

private:

	unsigned int mLength;


	CDataPairs<TypeKey, TypeValue>* keyValueArray;

	//TypeKey* mStart;
	//TypeKey* mEnd;

};

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Clear()
{

	//need iterator through the array to delete everything in it, return the length of the array to 0
	delete[] keyValueArray;

	keyValueArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength];
	//set the length of the array to 0 as everything has been deleted
	mLength = 0;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Insert(TypeKey k, TypeValue v)
{
	//takes a key and a value, inserts key into key array and value into value array 
	keyValueArray[mLength].keyPair = k;
	keyValueArray[mLength].valuePair = v;
	mLength++;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Erase(TypeKey k)
{

	CDataPairs<TypeKey, TypeValue>* tempArray;
	tempArray = new CDataPairs<TypeKey, TypeValue>[mMaxLength];
	int removeAtPoint;

	CDataPairs<TypeKey, TypeValue> tempPair;

	for (int i = 0; i < mLength; i++)
	{
		if (keyValueArray[i].keyPair == k)
		{
			removeAtPoint = i;
			tempPair = keyValueArray[i];
			break;
		}
	}

	if (mLength == 1)
	{
		Clear();
	}

	for (unsigned int i = removeAtPoint; i < mLength - 1; i++)
	{
		keyValueArray[i] = keyValueArray[i + 1];
	}

	keyValueArray[mLength -1].keyPair = NULL;
	keyValueArray[mLength -1].valuePair = NULL;

	//i spent too long on this to get rid of it, im actually an idiot tho
	//takes a key, erase the key and the value, reduce length by 1
	//for (int i = 0; i < mLength; i++)
	//{
	//	if (i != removeAtPoint)
	//	{
	//		//erase key and value associated with position, make length 1 less, move everything ahead to being 1 position less on the array
	//		tempArray[i] = keyValueArray[i];
	//		
	//	}
	//	else
	//	{
	//		tempArray[i].keyPair = NULL;
	//		tempArray[i].valuePair = NULL;
	//		//cout << "why is this: " << tempArray[i].keyPair << "   aaaahhhh  " << tempArray[i].valuePair << endl;
	//		//tempArray[i] = keyValueArray[i];
	//		
	//	}
	//}

	//for (int i = 0; i < mLength; i++)
	//{
	//	if (tempArray[i].keyPair == 0)
	//	{
	//
	//	}
	//}
	//
	//for (int i = 0; i < mLength; i++)
	//{
	//	keyValueArray[i] = tempArray[i];
	//}
	mLength--;
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
unsigned int CMap<TypeKey, TypeValue>::Size()
{
	//just returns what the current length of the array is 
	cout << "The length is: " << mLength << endl;
	return mLength;
}

template <typename TypeKey, typename TypeValue>
unsigned int CMap<TypeKey, TypeValue>::MaxSize()
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
	for (int i = 0; i < mLength; i++)
	{
		if (keyValueArray[i].keyPair == k)
		{
			cout << "key is: " << keyValueArray[i].keyPair << "  value is: " << keyValueArray[i].valuePair << endl;
			return keyValueArray[i].valuePair;
		}
	}
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Contains()
{

}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::LookUp()
{
	if (mLength != 0)
	{
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

