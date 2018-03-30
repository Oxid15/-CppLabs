#include<iostream>

using namespace std;

class BaseClass
{
	virtual bool equals(BaseClass &inst)
	{}

	virtual void toString(char *buffer)
	{}
};

class Container : BaseClass
{
	BaseClass** array = new BaseClass*;
	bool isFirst;

	void addContainer(int &i, BaseClass* &arr)
	{

	}

	void addElement()
	{

	}
};

class Element : BaseClass
{
	Data dataElem;
};

union Data
{
	int intData;
	float floatData;
	bool boolData;
};

void main()
{
	int i = 0;
	BaseClass* baseArr = new BaseClass;
}