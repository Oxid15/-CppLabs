#include<iostream>

using namespace std;

class BaseClass
{													
	virtual bool equals(BaseClass &inst) = 0;
	virtual void toString(char *buffer) = 0;
};

class Element : BaseClass
{
	Data dataElem[/*������*/];								//��� ������������� ���������. �����?

	bool equals(BaseClass &inst) { return false; }
	void toString(char *buffer) { }
};

class Container : BaseClass
{										
	BaseClass** array = new BaseClass*[/*������*/];          //������������ ����������?
	Container* parent = nullptr;					  
	int j = 0;
public:
	void addContainer()
	{
		Container* newContainer = new Container;
		array[j] = (BaseClass*) newContainer;
		j++;
		newContainer->parent = this;								         //��������� �� ������� ������?
	}

	void addElement()
	{
		Element* newElem = new Element;
		array[j] = (BaseClass*) newElem;						         //������
		j++;
	}

	bool equals(BaseClass &inst) { return false; }
	void toString(char *buffer) { }
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
	Container* current;
	Container c;
	current = &c;
	c.addContainer();
}