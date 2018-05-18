#include <iostream>
#include<fstream>

using namespace std;

template <class TKey, class TValue>
struct CollectionElement
{
	TKey key;
	TValue value;
};

template <class TKey, class TValue>
class Collection
{
public:											 //test!

	CollectionElement** arr;
	int numOfElem;
	int length;

	void arrayExpansion()
	{
		int newLength = length * 2;
		CollectionElement** newArray = new CollectionElement[newLength];
		for (int i = 0; i < length; i++)
		{
			newArray[i] = arr[i];
		}
		arr = newArray;
		length = newLength;
	}

public:

	Collection()
	{
		length = 8;
		numOfElem = 0;
		arr = new CollectionElement*[length];
	}

	friend ostream& operator <<(ostream& out, const Collection& inst)
	{
		out << inst.value;
		return out;
	}

	friend istream& operator >>(istream& in, Collection<TKey, TValue>& inst)
	{
		TValue val;
		in >> val;
		inst.value = val;
		return in;
	}

	TValue getValue()
	{
		return CollectionElement->value;
	}

	TKey getKey()
	{
		return CollectionElement->key;
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
		// Check unique key
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

template <class TKey, class TValue>
bool uniqueCheck(TKey key, CollectionElement** arr)
{
	
	return false;
}

class Bus 
{
	int num;
	char* nameOfDriver;
	int routeNum;
};

class BusPark
{
public:												//test!
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
	Bus* b = new Bus;
	park.inPark.add(1, *b);
	while (1)
	{
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			park.inPark.add(10,*b);
		case 2:
			//deleting
		case 3:
			//busOut
		case 4:
			//busIn
		case 5:
			//return
		case 0:
			return;
		}
	}
	system("pause");
}