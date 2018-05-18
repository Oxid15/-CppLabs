#include <iostream>
#include<fstream>

using namespace std;

template <class TKey, class TValue>
class Collection
{
	struct CollectionElement
	{
		Tkey key;
		Tvalue value;
	};

	CollectionElement** array;
	int numOfElem;
	int length;

	void arrayExpansion()
	{
		int newLength = length * 2;
		CollectionElement** newArray = new CollectionElement[newLength];
		for (int i = 0; i < length; i++)
		{
			newArray[i] = array[i];
		}
		array = newArray;
		length = newLength;
	}

public:

	Collection()
	{
		length = 8;
		numOfElem = 0;
		array = new CollectionElement*[length];
	}

	friend ostream& operator <<(ostream& out, const Collection& inst)
	{
		out << inst.value;
		return out;
	}

	friend istream& operator >>(istream& in, Collection<Tkey,Tvalue>& inst)
	{
		Tvalue val;
		in >> val;
		inst.value = val;
		return in;
	}

	Tvalue getValue()
	{
		return value;
	}

	Tkey getKey()
	{
		return key;
	}

	void setValue(TValue val)
	{
		value = val;
	}

	void setKey(TKey k)
	{
		key = k;
	}

	void add(TKey key, TValue value)
	{
		// Check key if it's unique -> adding or not
		// Check if numOfElem > length -> expansion or not
	}

	void del(TKey key)
	{

	}
};

//template <class T>
//T getT()
//{
//	T smpl;
//	cout << "Enter the data:\n";
//	cin >> smpl;
//	return smpl;
//}

/*class Test
{
public:
	char letter;

	friend ostream& operator << (ostream& out, const Test inst)
	{
		out << inst.letter;
		return out;
	}

	friend istream& operator >> (istream& in, Test& inst)
	{
		char newLet;
		in >> newLet;
		inst.letter = newLet;
		return in;
	}

};*/												

class Bus 
{
	int num;
	char* nameOfDriver;
	int routeNum;
};

class BusPark
{
	Collection<int, Bus> onRoad;
	Collection<int, Bus> inPark;

	void fileOut(char* list, int size)
	{
		ofstream ofile("result.txt");
		for (int i = 0; i < size; i++)
		{
			ofile << list[i];
		}
		ofile.close();
	}

public:

	BusPark()
	{

	}

	void busOut()
	{

	}

	void busIn()
	{

	}

	char* returnList(Collection<int, Bus> coll, char* buf)
	{
		int j = 0;

	}
};

void main()
{
	BusPark park;
	while (1)
	{
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			//adding
		case 2:
			//deleting
		case 3:
			//busOut
		case 4:
			//busIn
		case 5:
			//return
		case 0:
			break;
		}
	}
}