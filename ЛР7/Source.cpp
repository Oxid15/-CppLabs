#include<iostream>

using namespace std;

class BaseClass
{
	virtual bool equals(BaseClass &inst)
	{
		return false;
	}

	virtual void toString(char *buffer)			 //?
	{}
};

class Container : BaseClass
{
	BaseClass** array = new BaseClass*;
	Container* next = nullptr;
	Container* prev = nullptr;					  //?
	int j = 0;
public:
	void addFirstContainer(int &i, BaseClass** &baseArr)
	{
		Container firstContainer;
		baseArr[i] = &firstContainer;
		i++;
	}

	void addContainer()
	{
		Container newContainer;
		array[j] = &newContainer;
		j++;
		next = &newContainer;
		//prev = & ?
	}

	void addElement()
	{

	}
};

union Data
{
	int intData;
	float floatData;
	bool boolData;
};

class Element : BaseClass
{
	Data dataElem;
};

void main()
{
	int i = 0;
	BaseClass** baseArr = new BaseClass*[8]; //?
	Container* current;
	Container c;
	current = &c;
	c.addFirstContainer(i,baseArr);
	c.addContainer();
}