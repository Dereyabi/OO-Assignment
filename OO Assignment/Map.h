#pragma once

const unsigned int mMaxLength = 696969;

template <typename TypeKey, typename TypeValue>
class CMap
{
public:

	CMap::CMap() 
	{
		mLength = 0;
		Key = new TypeKey[mMaxLength];
		Value = new TypeValue[mMaxLength];
		mStart = &Key[0];
	}

	void Clear();				//clears all elements 
	void Insert(TypeKey, TypeValue);		//insert a new element 
	void Erase(TypeKey, TypeValue);		//erase a specific element 

	bool Empty();		//returns a boolean for if the map is empty
	unsigned int Size();				//returns the size of the array
	unsigned int MaxSize();				//returns the max size the array can be 

	int Count();					//return number of elements matching specific key. this is useless, 1 key to 1 value
	TypeValue Find(TypeKey, TypeValue);			//looks up a certain element and returns where it is on the array
	void LookUp(TypeKey);

	void Contains();			//looks up which elements contain whatever is passed through the function 
	//pass over a typevalue, returns array of typekeys that contain original typevalue

	TypeValue get(TypeKey) {return TypeValue};

private:

	unsigned int mLength;

	int mCount;

	TypeKey* Key;
	TypeValue* Value;

	TypeKey* mStart;
	TypeKey* mEnd;

};

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Clear()
{
	//need iterator through the array to delete everything in it, return the length of the array to 0
	for (int i = 0; i < mLength; i++)
	{
		//delete whats in the key array and the value array

	}
	//set the length of the array to 0 as everything has been deleted
	mLength = 0;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Insert(TypeKey k, TypeValue v)
{
	//takes a key and a value, inserts key into key array and value into value array 
	Key[mLength] = k;
	Value[mLength] = v;
	mLength++;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Erase(TypeKey k, TypeValue v)
{
	//takes a key, erase the key and the value, reduce length by 1
	for (int i = 0; i < mLength; i++)
	{
		if (Key[i] == k)
		{
			//erase key and value associated with position, make length 1 less, move everything ahead to being 1 position less on the array
		}
	}
	mLength--;
}

template <typename TypeKey, typename TypeValue>
bool CMap<TypeKey, TypeValue>::Empty()
{
	//checks if the map is empty or not

	if (mLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename TypeKey, typename TypeValue>
unsigned int CMap<TypeKey, TypeValue>::Size()
{
	//just returns what the current length of the array is 
	cout << mLength << endl;
	return mLength;
}

template <typename TypeKey, typename TypeValue>
unsigned int CMap<TypeKey, TypeValue>::MaxSize()
{
	//just returns what the overall length of the array is
	cout << mMaxLength << endl;
	return mMaxLength;
}

template <typename TypeKey, typename TypeValue>
int CMap<TypeKey, TypeValue>::Count()
{
	//useless lul
}

template <typename TypeKey, typename TypeValue>
TypeValue CMap<TypeKey, TypeValue>::Find(TypeKey k, TypeValue v)
{
	//
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Contains()
{

}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::LookUp(TypeKey k)
{
	for (int i = 0; i < mLength; i++)
	{
		if (Key[i] == k)
		{
			cout << "the key is: " << Key[i] << endl;
			cout << "the value is:" << Value[i] << endl;
		}
		else
		{
			cout << "Key not found" << endl;
		}

	}
}