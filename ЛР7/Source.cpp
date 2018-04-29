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
	for (int i = 0; i < length; i++)
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
		if (j < len)
		{
			array[j] = (BaseClass*)newContainer;
			j++;
			newContainer->parent = this;
		}
		else
		{
			arrayExpansion();
			array[j] = (BaseClass*)newContainer;
			j++;
			newContainer->parent = this;
		}
	}

	//bool search(BaseClass* inst)
	//{
	//
	//}

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
			//if(!search((BaseClass*)newElem))
			if (j < len)
				array[j] = (BaseClass*)newElem;
			else
			{
				arrayExpansion();
				array[j] = (BaseClass*)newElem;
			}
			//break;
			//else
			break;
		case 2:
			newElem->dataElem.floatData = getFloat();
			// if(!search((BaseClass*)newElem))
			if (j < len)
				array[j] = (BaseClass*)newElem;
			else
			{
				arrayExpansion();
				array[j] = (BaseClass*)newElem;
			}
			//break;
			//else
			break;
		case 3:
			newElem->dataElem.boolData = getBoolean();
			// if(!search((BaseClass*)newElem))
			if (j < len)
				array[j] = (BaseClass*)newElem;
			else
			{
				arrayExpansion();
				array[j] = (BaseClass*)newElem;
			}
			//break;
			//else
			break;
		}
		j++;
	}

	bool equals(BaseClass* inst) 
	{
		if (this->getType() != inst->getType())
		return false;

	}

	char* toString(char *&buffer, int &i)
	{
		buffer[i] = '[';
		i++;
		for (int k = 0; k < j; k++)
		{
			if (this->array[k]->getType())
			{
				Element* newElement = (Element*)getArray()[k];
				buffer[i] = (newElement->getData().intData);
				i++;
			}
			else
			{
				Container* tmp = (Container*)array[k];
				tmp->toString(*&buffer, i);
			}
		}
		buffer[i] = ']';
		i++;
		return buffer;
	}								  

	void moveDown(Container* &current)
	{
		int index = getCNumber() - 1;
		if (!array[index]->getType())			                                           //!
		{
			current = (Container*)array[index];
		}
		else
		{
			cout << "This is not Container";
		}
	}

	void moveUp(Container* &current)
	{
		if (current->parent != nullptr)
			current = current->parent;
		else
		{
			return;
		}
	}

	void arrayExpansion()
	{
		len = len * 2;
		BaseClass** tempArray = new BaseClass*[len];
		for (int i = 0; i < len / 2; i++)
		{
			tempArray[i] = array[i];
		}
		array = tempArray;
	}

	BaseClass** getArray()
	{
		return this->array;
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
			break;
		}
		case 5:
			current->moveDown(current);
			break;
		case 6:
			current->moveUp(current);
			break;
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
		cout << "\n 1- addContainer\n 2- addElement\n 3- toString\n 4- equals\n 5- moveDown\n 6- moveUp\n";
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
			int i = 0;
			current->toString(buf, i);
			bufferOutput(buf, i);
			break;
		}
		case 4:
			if (current->equals(chooseStruct(current)))										   //!
				cout << "Structures is equal\n";
			else
				cout << "Structures isn't equal\n";
			break;
		case 5:
			current->moveDown(current);
			break;
		case 6:
			current->moveUp(current);
		}
	}
}