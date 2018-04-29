#include<iostream>

using namespace std;

int getInteger()
{
	int input;
	cout << "Enter the integer\n";
	cin >> input;
	return input;
}

float getFloat()
{
	float input;
	cout << "Enter the number with floating point\n";
	cin >> input;
	return input;
}

bool getBoolean()
{
	bool input;
	cout << "Enter the boolean\n";
	cin >> input;
	return input;
}

int getCNumber()
{
	cout << "Type the number of structure";
	int number;
	cin >> number;
	return number;
}

void bufferOutput(char* buf, int length)
{
	for (int i = 0; i < length + 1; i++)
	{
		cout << buf[i];
	}
}

class BaseClass
{
public:
	virtual bool equals(BaseClass* curr) { return false; };
	virtual char* toString(char *buffer, int i) { return buffer; };
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
	/*Data dataElem;*/							
public:
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

	Data getData()
	{
		return dataElem;
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
		cout << "Enter the type of data:\n 1- integer\n 2- with floating point\n 3- boolean\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			newElem->dataElem.intData = getInteger();
			array[j] = (BaseClass*)newElem;
			break;
		case 2:
			newElem->dataElem.floatData = getFloat();
			array[j] = (BaseClass*)newElem;
			break;
		case 3:
			newElem->dataElem.boolData = getBoolean();
			array[j] = (BaseClass*)newElem;
			break;
		}
		j++;
	}

	bool equals(BaseClass* inst) 
	{
		if (this->getType() != inst->getType())
		return false;

	}

	char* toString(char *&buffer, int i)
	{
		buffer[i] = '[';
		//cout << "[";
		i++;
		for (i; i < j; i++)
		{
			if (this->array[i]->getType())
			{
				Element* newElement = (Element*)getArray()[i];
				buffer[i] = newElement->getData().intData;
				//cout << newElement->getData().intData;		   
			}
			else
			{
				Container* tmp = (Container*)array[i];
				tmp->toString(*&buffer, i);
			}
		}
		//cout << "]";
		buffer[i] = ']';
		i++;
		return buffer;
	}								  

	void moveDown(Container* &current)
	{
		BaseClass* temp = (BaseClass*)current;
		temp = current->array[getCNumber() - 1];
	}

	void moveUp(Container* &current)
	{
		if (current->parent != nullptr)
			current = current->parent;
		else
			return;
	}

	BaseClass** getArray()
	{
		return this->array;
	}

	int getNum()
	{
		return j;
	}
};

BaseClass* chooseStruct(Container* &current)
{
	BaseClass * newCurrent = (BaseClass*)current;
	while (1)
	{ 
		int choice = 0;
		cout << " 3- toString\n 5- moveDown\n 6- moveUp\n 9- [CHOOSE]";
		cin >> choice;
		switch (choice)
		{
		case 3:
		{
			char* buf = new char[255];
			static int i = 0;
			current->toString(buf, i);
		}
		case 5:
			current->moveDown(current);
		case 6:
			current->moveUp(current);							  
		case 9:
			newCurrent = current->getArray()[getCNumber()];
		}
	}
	return newCurrent;
}

void main()
{
	Container root;
	Container* current = new Container;
	current = &root;
	while (1)
	{
		int choice;
		cout << " 1- addContainer\n 2- addElement\n 3- toString\n 4- equals\n 5- moveDown\n 6- moveUp\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			current->addContainer();
			break;
		case 2:
			current->addElement();
			break;
		case 3:
		{
			char* buf = new char[32];
			static int i = 0;
			current->toString(buf, i);
			bufferOutput(buf, current->getNum());
			break;
		}
		case 4:
			if (current->equals(chooseStruct(current)))
				cout << "Structures is equal";
			else
				cout << "Structures isn't equal";
			break;
		case 5:
			current->moveDown(current);
			break;
		case 6:
			current->moveUp(current);
			break;
		}
		system("pause");
	}
}