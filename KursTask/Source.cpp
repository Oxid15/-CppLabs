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
	CollectionElement<TKey, TValue>** arr;
	int numOfElem;
	int length;

	void arrayExpansion()
	{
		int newLength = length * 2;
		CollectionElement<TKey, TValue>** newArray = new CollectionElement<TKey, TValue>[newLength];
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
		arr = new CollectionElement<TKey, TValue>*[length];
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

	//TValue getValue()
	//{
	//}

	//TKey getKey()
	//{
	//}

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
	Collection<int,int> c;
	
	system("pause");
}