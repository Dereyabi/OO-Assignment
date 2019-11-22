#pragma once

template <typename TypeKey, typename TypeValue>
class map
{
public:

	void clear(TypeKey, TypeValue);		//clears all elements 
	void insert(TypeKey, TypeValue);	//insert a new element 
	void erase(TypeKey, TypeValue);		//erase a specific element 

	bool empty(TypeKey, TypeValue);		//returns a boolean for if the cell is empty
	int size();							//returns the size of the array
	int maxSize();						//returns the max size the array can be 

	int count();						
	TypeValue find();					//looks up a certain element and returns where it is on the array
	void contains()						//looks up which elements contain whatever is passed through the function 


	TypeValue get(TypeKey, TypeValue) {return TypeValue};


private:

};
