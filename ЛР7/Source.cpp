#include<iostream>

using namespace std;

class BaseClass
{
	virtual bool equals()
	{

	}

	virtual void toString(char *buffer)
	{

	}
};

class Container : BaseClass
{
	BaseClass** array = new BaseClass*;
};

class Element : BaseClass
{
	int n;
	union Data
	{
		int intData;
		float floatData;
		bool boolData;
	};
	Data* vector = new Data[n];
};

void main()
{

}