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

	bool equals(BaseClass &inst) { return false; }
	void toString(char *buffer) 
	{ }
	int getType()
	{
		return 1;
	}
};

class Container : BaseClass
{
	int len = 8;
	BaseClass** array = new BaseClass*[len];      
	Container* parent = nullptr;					  
	int j = 0;
public:
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
		return false; 
	}

	void toString(char *buffer) 
	{
		for (int i = 0; i < len; i++)
		{

		}
	}
};

void main()
{
	int i = 0;
	Container* current;
	Container c;
	current = &c;
	c.addContainer();
	char* buff = new char[8];
	c.toString(buff);
	for (int i = 0; i < strlen(buff); i++)
	{
		cout << buff[i] << " ";
	}
	system("pause");
}