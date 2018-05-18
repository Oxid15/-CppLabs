#include <iostream>
#include<fstream>

using namespace std;

template <class TKey, class TValue>
class Collection
{
	struct CollectionElement
	{
		TKey key;
		TValue value;
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

	friend istream& operator >>(istream& in, Collection<TKey,TValue>& inst)
	{
		TValue val;
		in >> val;
		inst.value = val;
		return in;
	}

	TValue getValue()
	{
		return CollectionElement.value;
	}

	TKey getKey()
	{
		return CollectionElement.key;
	}

	void setValue(TValue val)
	{
		value = val;
	}

	void setKey(TKey k)
	{
		key = k;
	}

	void add(TKey newKey, TValue newValue)
	{
		// Check if numOfElem > length -> expansion or not
		// Check key if it's unique -> adding or not
		for (int i = 0; i < numOfElem; i++)
		{
			if(array[i]->)
		}
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
	//system("pause");
}