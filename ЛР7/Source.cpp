#include<iostream>
#include <stdlib.h>

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
	cout << "Type the number of structure\n";
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

union uData
{
	int intData;
	float floatData;
	bool boolData;
};

struct Data
{
	uData unionData;
	int flag;
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
		cout << "\nEnter the type of data:\n 1- integer\n 2- with floating point\n 3- boolean\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			newElem->dataElem.unionData.intData = getInteger();
			newElem->dataElem.flag = 1;
			//if(!search((BaseClass*)newElem))
			//{
			if (j < len)
				array[j] = (BaseClass*)newElem;
			else
			{
				arrayExpansion();
				array[j] = (BaseClass*)newElem;
			}
			//break;
			//}
			//else
			break;
		case 2:
			newElem->dataElem.unionData.floatData = getFloat();
			newElem->dataElem.flag = 2;
			// if(!search((BaseClass*)newElem))
			//{
			if (j < len)
				array[j] = (BaseClass*)newElem;
			else
			{
				arrayExpansion();
				array[j] = (BaseClass*)newElem;
			}
			//break;
			//}
			//else
			break;
		case 3:
			newElem->dataElem.unionData.boolData = getBoolean();
			newElem->dataElem.flag = 3;
			// if(!search((BaseClass*)newElem))
			//{
			if (j < len)
				array[j] = (BaseClass*)newElem;
			else
			{
				arrayExpansion();
				array[j] = (BaseClass*)newElem;
			}
			//break;
			//}
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
				switch (newElement->dataElem.flag)
				{
				case 1:
				{
					char* tempBuf = new char[256];
					_itoa_s(newElement->dataElem.unionData.intData, tempBuf, 256, 10);
					for (int l = 0; l < strlen(tempBuf); l++)
					{
						buffer[i] = tempBuf[l];
						i++;
					}
				}
				break;

				case 2: 							
				{
					
					char* tempBuf = new char[256];
					sprintf_s(tempBuf,256, "%f", newElement->dataElem.unionData.floatData);

					int newStrlen = strlen(tempBuf), y = strlen(tempBuf) - 1;
					for (y; y > 0; y--)
					{
						if (tempBuf[y] == '0')
						{
							newStrlen--;
						}
						else
						{
							break;
						}
					}
						for (int l = 0; l < newStrlen; l++)
					{
						buffer[i] = tempBuf[l];
						i++;
					}
				}
				break;

				case 3:
				{
					if (newElement->dataElem.unionData.boolData)
					{
						    buffer[i] = 't';
						buffer[i + 1] = 'r';
						buffer[i + 2] = 'u';
						buffer[i + 3] = 'e';
						i+= 4;
					}
					else
					{
						    buffer[i] = 'f';
						buffer[i + 1] = 'a';
						buffer[i + 2] = 'l';
						buffer[i + 3] = 's';
						buffer[i + 4] = 'e';
						i +=5;
					}
				}
				}
				buffer[i] = ',';
				i++;
			}
			else
			{
				Container* tmp = (Container*)array[k];
				tmp->toString(*&buffer, i);
			}
		}
		i--;
		buffer[i] = ']';
		i++;
		return buffer;
	}								  

	void moveDown(Container* &current)
	{
		int index = getCNumber() - 1;
		if (index <= j)
		{
			if (!array[index]->getType())			                                           //!
			{
				current = (Container*)array[index];
			}
			else
			{
				cout << "This is not Container\n";
			}
		}
		else
		{
			cout << "The number is too big\n";
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
			char* buf = new char[255];
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