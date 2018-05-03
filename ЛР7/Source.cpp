#include<iostream>
#include<fstream>

using namespace std;

int getChoice()
{
	while (true)
	{
		char* choice = new char[256];
		cin >> choice;
		bool error = false;
		for (int i = 0; i < strlen(choice); i++)
		{
			if (!(choice[i] >= 48 && choice[i] <= 57) || choice[i] == '-')
			{
				error = true;
				break;
			}
		}
		if (!error)
			return atoi(choice);
	}
}

bool checkInt(char* input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (!(input[i] >= 48 && input[i] <= 57) || input[i] == '-')
		{
			return false;
		}
	}
	return true;
}

bool checkFloat(char* input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (!(input[i] >= 48 && input[i] <= 57 || input[i] == '.' || input[i] == '-'))
		{
			return false;
		}
	}
	return true;
}

int getInteger()
{
	while (true)
	{
		char* input = new char[256];
		cout << "Enter the integer\n";
		cin >> input;

		if (checkInt(input))
			return atoi(input);
		else
			cout << "Try again\n";
		//delete[] input;										//?
		//delete input;
	}
}

float getFloat()
{
	while (true)
	{
		char* input = new char[256];
		cout << "Enter the number with floating point\n";
		cin >> input;

		if (checkFloat(input))
		{
			return atof(input);
		}
		else
			cout << "Try again\n";
		//delete[] input;
		//delete input;
	}
}

bool getBoolean()
{
	while (true)
	{
		char* input = new char[256];
		cout << "Enter the boolean\n";
		cin >> input;

		if (checkInt(input))
		{
			int output = atoi(input);
			if (output != 0)
				return true;
			else
				return false;
		}
		else
			cout << "Try again\n";
		//delete[] input;
		//delete input;
	}
}

int getCNumber()
{
	char* input = new char[255];
	cout << "Enter the number of structure\n";
	cin >> input;

	if (checkInt(input))
		return atoi(input);
	else
		cout << "Try again\n";
	//delete[] input;
	//delete input;
}

void bufferOutput(char* buf, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << buf[i];
	}
}

void fileOutput(char* buffer, int length)
{
	ofstream ofile("result.txt");
	ofile << "\n";
	for (int i = 0; i < (length); i++)
	{
		ofile << buffer[i];
	}
	ofile.close();
}

class BaseClass
{
public:
	virtual bool equals(BaseClass* current) { return false; };
	virtual char* toString(char *buffer, int i) { return buffer; };
	virtual int getType() { return -1; };
};

union Data
{
	int intData;
	float floatData;
	bool boolData;
};

struct ElementData
{
	Data unionData;
	short flag;
};

class Element : BaseClass
{																								  //!
	/*Data dataElem;*/							
public:
	ElementData elemData;

	bool equals(BaseClass* inst) 
	{
		if (this->getType() != inst->getType())
			return false;
		else
		{
			Element* newInst = new Element;
			newInst = (Element*)inst;
			if (newInst->elemData.unionData.intData == this->elemData.unionData.intData)
			{
				return true;
			}
			else
				return false;
		}
	}

	char* toString(char *&buffer, int &i) 
	{
		switch (this->elemData.flag)
		{
		case 1:
		{
			char* tempBuf = new char[256];
			_itoa_s(this->elemData.unionData.intData, tempBuf, 256, 10);
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
			sprintf_s(tempBuf, 256, "%f", this->elemData.unionData.floatData);

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
			delete[] tempBuf;
		}
		break;

		case 3:
		{
			if (this->elemData.unionData.boolData)
			{
				    buffer[i] = 't';
				buffer[i + 1] = 'r';
				buffer[i + 2] = 'u';
				buffer[i + 3] = 'e';
				i += 4;
			}
			else
			{
				    buffer[i] = 'f';
				buffer[i + 1] = 'a';
				buffer[i + 2] = 'l';
				buffer[i + 3] = 's';
				buffer[i + 4] = 'e';
				i += 5;
			}
		}
		}
		return buffer;
	}

	int getType()
	{
		return 1;
	}

	ElementData getData()
	{
		return elemData;
	}
};

class Container : BaseClass
{
	int j;
	int length;
	BaseClass** array = new BaseClass*[length];
	Container* parent = nullptr;					  
public:
	Container()
	{
		j = 0;
		length = 8;
		parent = nullptr;
	}
	
	int getType()
	{
		return 0;
	}

	void addContainer()
	{
		Container* newContainer = new Container;
		if (j < length)
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

	void addElement()
	{
		Element* newElem = new Element;
		BaseClass* newInst = (BaseClass*)newElem;
		cout << "\nEnter the type of data:\n 1- integer\n 2- with floating point\n 3- boolean\n";
		switch (getChoice())
		{
		case 1:
			newElem->elemData.unionData.intData = getInteger();
			newElem->elemData.flag = 1;
			arrayAdd(newInst);
			break;
		case 2:
			newElem->elemData.unionData.floatData = getFloat();
			newElem->elemData.flag = 2;
			arrayAdd(newInst);
			break;
		case 3:
			newElem->elemData.unionData.boolData = getBoolean();
			newElem->elemData.flag = 3;
			arrayAdd(newInst);
			break;
		}
	}

	int search(Container* container, BaseClass* inst)
	{
		int sum = 0;
		int t = container->getContNum();
		for (int i = 0; i < t; i++)
		{
			if (container->getArray()[i]->getType() != inst->getType())			 //if we see the different types
				continue;
			else
			{
				if (!inst->getType())											 //if we see two Containers
				{
					Container* newInst = new Container, *secInst = new Container;
					newInst = (Container*)inst;
					secInst = (Container*)container->getArray()[i];
					if (newInst != secInst)											//if Container isn't the same
					{
						if (newInst->getContNum() == 0)									 //if Container is empty
						{
							(secInst->getContNum() == 0) ? sum++ : sum = sum;
						}
						else														 //if it contains something
						{
							if (newInst->getContNum() == secInst->getContNum()) //if number of instances isn't equal
							{
								int tempSum = 0;
								for (int k = 0; k < newInst->getContNum(); k++)
								{
									tempSum += search(secInst, newInst->getArray()[k]);
								}
								if (tempSum == newInst->getContNum())
									sum++;
							}
							else
								continue;
						}
					}
				}
				else															 //if we see two Elements
				{
					Element* newInst = new Element, *secInst = new Element;
					newInst = (Element*)inst;
					secInst = (Element*)container->getArray()[i];
					if (newInst->elemData.unionData.intData == secInst->elemData.unionData.intData
						&& newInst != secInst)	  //Elements is equal if																									  
					{						      //int blocks in them is equal								  //?
						sum++;					  //even if there's no integer in blocks
					}
					else
						continue;
					delete newInst, secInst;
				}
			}
		}
		return sum;
	}

	bool equals(BaseClass* inst) 
	{
		if (this->getType() != inst->getType())
		return false;
		else
		{
				Container* newInst = new Container, *secInst = new Container;
				newInst = (Container*)inst;
				secInst = (Container*)this;
				if (newInst->getContNum() == secInst->getContNum())
				{
					int tempSum = 0;
					for (int i = 0; i < newInst->getContNum(); i++)
					{
						tempSum += search(secInst, newInst->getArray()[i]);
					}

					if (tempSum == newInst->getContNum() || newInst == secInst)
						return true;
					else
						return false;
				}
				else
					return false;
				delete newInst, secInst;
		}
	}

	char* toString(char *&buffer, int &i)
	{
		buffer[i] = '[';
		i++;
		for (int k = 0; k < j; k++)														  
		{
			if (k != 0)
			{
				buffer[i] = ',';
				i++;
			}
			if (this->array[k]->getType())
			{
				Element* newInst = (Element*)this->array[k];
				newInst->toString(buffer, i);
			}
			else
			{
				Container* newInst = (Container*)array[k];
				newInst->toString(*&buffer, i);
			}
		}
		buffer[i] = ']';
		i++;
		return buffer;
	}								  

	void moveDown(Container* &current)
	{
		int i = getCNumber() - 1;
		if (i < j)
		{
			if (!array[i]->getType())
			{
				current = (Container*)array[i];
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
		length *= 2;
		BaseClass** tempArray = new BaseClass*[length];
		for (int i = 0; i < length / 2; i++)
		{
			tempArray[i] = array[i];
		}
		array = tempArray;
		delete[] tempArray;
		delete tempArray;
	}

	BaseClass** getArray()
	{
		return this->array;
	}

	int getContNum()
	{
		return j;
	}

	void arrayAdd(BaseClass* newInst)
	{
		if (!search(this, newInst))
		{
			if (j < length)
				array[j] = (BaseClass*)newInst;
			else
			{
				arrayExpansion();
				array[j] = (BaseClass*)newInst;
			}
			j++;
		}
		else
		{
			cout << "\nThis Element is already exist\n";
		}
	}
};

BaseClass* chooseStruct(Container* &current)
{
	BaseClass * newCurrent = (BaseClass*)current;
	while (true)
	{ 
		cout << " 3- toString\n 5- moveDown\n 6- moveUp\n 9- [CHOOSE]\n";
		switch (getChoice())
		{
		case 3:
		{
			char* buf = new char[255];
			int i = 0;
			current->toString(buf, i);
			bufferOutput(buf, i);
			break;
		}
		case 5:
			current->moveDown(current);
			break;
		case 6:
			current->moveUp(current);
			break;
		case 9:
		{
			short choice2;
			cout << "Enter """ << "0" << """ to choose current structure or any other digit if you need to choose\n";
			cin >> choice2;
			if (choice2)
			{
				newCurrent = current->getArray()[getCNumber() - 1];
				return newCurrent;
			}
			else
			{
				return (BaseClass*)current;
			}		
		}
		}
	}
}

void main()
{
	Container root;
	Container* current = new Container;
	current = &root;
	while (1)
	{
		cout << "\n 1- addContainer\n 2- addElement\n 3- toString\n 4- equals\n 5- moveDown\n 6- moveUp\n 0- exit\n";
		switch (getChoice())
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
			fileOutput(buf, i);
			break;
		}
		case 4:
		{
			BaseClass * fstInst = chooseStruct(current);
			Element* newFstInstE = new Element;
			Container* newFstInstC = new Container;

			if (fstInst->getType())
			{
				newFstInstE = (Element*)fstInst;
				if (newFstInstE->equals(chooseStruct(current)))
					cout << "\nStructures is equal\n";
				else
					cout << "\nStructures isn't equal\n";
				delete newFstInstC;
			}
			else
			{
				newFstInstC = (Container*)fstInst;
				if (newFstInstC->equals(chooseStruct(current)))
					cout << "\nStructures is equal\n";
				else
					cout << "\nStructures isn't equal\n";
				delete newFstInstE;
			}
		}
		break;
		case 5:
			current->moveDown(current);
			break;
		case 6:
			current->moveUp(current);
			break;
		case 0:
			return;
		}
	}
}

//test
//1 5 1 2 3 1 6 2 2 3.4 1 1 2 1 1234 3