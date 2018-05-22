#include <iostream>
#include<fstream>

using namespace std;

template <class TKey, class TValue> class Collection
{
	struct CollectionElement
	{
		TKey key;
		TValue value;
	};
	CollectionElement **arr;
	int numOfElem;
	int length;

	void arrayExpansion()
	{
		int newLength = length * 2;
		CollectionElement **newArray = new CollectionElement*[newLength];
		for (int i = 0; i < length; i++)
		{
			newArray[i] = arr[i];
		}
		arr = newArray;
		length = newLength;
	}
	
	void setKey(TKey newKey, int num)
	{
		arr[num]->key = newKey;
	}

	void setValue(TValue newValue, int num)
	{
		arr[num]->value = newValue;
	}

public:
	Collection()
	{
		length = 8;
		numOfElem = 0;
		arr = new CollectionElement*[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = new CollectionElement;
		}
	}

	TKey returnKey(int num)
	{
		return arr[num]->key;
	}

	TValue returnValue(int num)
	{
		return arr[num]->value;
	}

	int returnNumOfElem()
	{
		return numOfElem;
	}
		 
	friend ostream & operator << (ostream & out, const Collection inst)
	{
		for (int i = 0; i < inst.returnNumOfElem(); i++)
		{
			out << inst.returnKey(i) << ',' << inst.returnValue(i) << '\n';
		}
	}

	friend istream & operator >> (istream & in, Collection &inst)
	{
			
	}

	void add(TKey newKey, TValue newValue)
	{

	}

};

//
//class Bus
//{
//	int num;
//	char *nameOfDriver;
//	int routeNum;
//};
//
//class BusPark
//{
//	Collection < int, Bus > onRoad;
//	Collection < int, Bus > inPark;
//
//	void fileOut(char *list, int size)
//	{
//		ofstream ofile("result.txt");
//		for (int i = 0; i < size; i++)
//		{
//			ofile << list[i];
//		}
//		ofile.close();
//	}
//
//public:
//
//	BusPark()
//	{
//
//	}
//
//	void busOut()
//	{
//
//	}
//
//	void busIn()
//	{
//
//	}
//
//	char *returnList(Collection < int, Bus > coll, char *buf)
//	{
//		int j = 0;
//
//	}
//};

void main()
{
	Collection<int, int> a;

};