#pragma once

template <typename TypeKey, typename TypeValue>
class CMap
{
public:

	CMap::CMap() 
	{

	}

	~CMap::CMap() 
	{

	}

	void Clear();				//clears all elements 
	void Insert(TypeKey, TypeValue);		//insert a new element 
	void Erase(TypeKey, TypeValue);		//erase a specific element 

	bool Empty(TypeKey, TypeValue);		//returns a boolean for if the cell is empty
	unsigned int Size();				//returns the size of the array
	unsigned int MaxSize();				//returns the max size the array can be 

	int Count();					//return number of elements matching specific key, list of 	
	TypeValue Find(TypeKey, TypeValue);			//looks up a certain element and returns where it is on the array

	void Contains();			//looks up which elements contain whatever is passed through the function 
	//pass over a typevalue, returns array of typekeys that contain original typevalue

	TypeValue get(TypeKey) {return TypeValue};

private:

	const int maxLengthTemp = 696969;
	unsigned int mLength;
	unsigned int mMaxLength;
	int mCount;

	TypeKey* mStart;
	TypeKey* mEnd;

};

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Clear()
{

	mLength = 0;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Insert(TypeKey, TypeValue)
{
	
	mLength++;
}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Erase(TypeKey, TypeValue)
{

	mLength--;
}

template <typename TypeKey, typename TypeValue>
bool CMap<TypeKey, TypeValue>::Empty(TypeKey, TypeValue)
{
	if (TypeValue == NULL)
	{
		return false
	}
}

template <typename TypeKey, typename TypeValue>
unsigned int CMap<TypeKey, TypeValue>::Size()
{
	return mLength;
}

template <typename TypeKey, typename TypeValue>
unsigned int CMap<TypeKey, TypeValue>::MaxSize()
{
	return mMaxLength;
}

template <typename TypeKey, typename TypeValue>
int CMap<TypeKey, TypeValue>::Count()
{

}

template <typename TypeKey, typename TypeValue>
TypeValue CMap<TypeKey, TypeValue>::Find(TypeKey, TypeValue)
{

}

template <typename TypeKey, typename TypeValue>
void CMap<TypeKey, TypeValue>::Contains()
{

}