#pragma once

template <typename TypeKey, typename TypeValue>
class map
{
public:

	void clear(TypeKey, TypeValue);	//clears contents of selected cell of table
	void insert();	//insert 
	void erase(TypeKey, TypeValue);

	bool empty(TypeKey, TypeValue);
	int size();
	int maxSize();

	int count();
	TypeValue find();
	void contains()


	TypeValue get(TypeKey, TypeValue) {return TypeValue};


private:

};
