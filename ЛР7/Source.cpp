#include<iostream>

using namespace std;

class BaseClass
{
public:
	virtual bool equals(BaseClass &inst) { return false; };
	virtual char* toString(char *buffer) {};
	virtual int getType() { return -1; };
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
		if (this->getType() != inst.getType())
			return false;
	}

	char* toString(char *buffer) 
	{
		return buffer;
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
		parent = nullptr;
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
		if (this->getType() != inst.getType())
		return false;
	}

	char* toString(char *buffer)
	{
		for (int i = 0; i < len; i++)
		{
			//...
		}
		return buffer;
	}

	void moveDown(Container* &current)
	{
		BaseClass* temp = (BaseClass*)current;
		temp = current->array[getCNumber()];
	}

	void moveUp(Container* &current)
	{
		if (current->parent != nullptr)
			current = current->parent;
		else
			return;
	}
};

int getCNumber()
{
	cout << "Type the number of container";
	int number;
	cin >> number;
}

void main()
{
	Container root;
	Container* current = new Container;
	current = &root;
	while (1)
	{
		int choice;
		cout << " 1- addContainer\n 2- addElement\n 3- toString\n 4- moveDown\n 5- moveUp\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			current->addContainer();
		case 2:
			current->addElement();
		case 3:
		{
			char* buf = new char[255];
			current->toString(buf);
		}

		/*
		   case 4:
			  current->equals(current);
		*/
		case 5:

			current->moveDown(current);
		case 6:
			current->moveUp(current);

		}
		system("pause");
	}
}