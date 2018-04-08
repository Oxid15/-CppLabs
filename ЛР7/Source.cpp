#include<iostream>

using namespace std;

class BaseClass
{													
	virtual bool equals(BaseClass &inst) = 0;
	virtual void toString(char *buffer) = 0;
	virtual int getType() = 0;
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

	bool equals(BaseClass &inst) 
	{
		if (this->getType != inst.getType)
			return false;
	}

	void toString(char *buffer) 
	{

	}
	int getType()
	{
		return 1;
	}
};

class Container : BaseClass
{
	int j;
	int len;
	BaseClass** array = new BaseClass*[len];      
	Container* parent = nullptr;					  
public:
	Container()
	{
		j = 0;
		len = 8;
	}

	int getType()
	{
		return 0;
	}

	void addContainer()
	{
		Container* newContainer = new Container;
		array[j] = (BaseClass*) newContainer;
		j++;
		newContainer->parent = this;								       
	}

	void addElement()
	{
		Element* newElem = new Element;
		array[j] = (BaseClass*) newElem;						        
		j++;
	}

	bool equals(BaseClass &inst) 
	{
		if (this->getType != inst.getType)
		return false;
		
		//...
	}

	void toString(char *buffer) 
	{
		for (int i = 0; i < len; i++)
		{
			//...
		}
	}
};

void main()
{
	system("pause");
}