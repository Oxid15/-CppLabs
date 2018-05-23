#include <iostream>
#include<fstream>

using namespace std;


template <class T>
T get()
{
	T val;
	cout << "Enter the data\n";
	cin >> val;
	return val;
}

template <class TKey, class TValue> 
class Collection
{
private:
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
	
	void setKey(TKey newKey, int idx)
	{
		arr[idx]->key = newKey;
	}

	void setValue(TValue newValue, int idx)
	{
		arr[idx]->value = newValue;
	}

	static bool inputCheck(char* str)								 // ?
	{
		bool isCommaFlag = false;
		bool isSpacesFlag = false;

		for (int i = 0; i < strlen(str); i++)
		{
			if (isCommaFlag && isSpacesFlag)
			{
				return true;
			}
			else
			{
				if (str[i] == ',')
					isCommaFlag = true;
				if (str[i] == ' ')
					isSpacesFlag = true;
			}
		}

		return false;
	}

	void decreaseNumOfElem(int number)
	{
		numOfElem = numOfElem - number;										   //?
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
		 
	friend ostream &operator << (ostream & out, Collection &inst)
	{
		for (int i = 0; i < inst.returnNumOfElem(); i++)
		{
			out << inst.returnKey(i) << ',' << inst.returnValue(i) << '\n';
		}
		return out;
	}

	friend istream &operator >> (istream & in, Collection &inst)
	{
		char* strBuf = new char[1024];
		in.getline(strBuf, 1024);											 // strBuf?

		if (inputCheck(strBuf))
		{
			int len = strlen(strBuf);
			int numberOfPairs = 0;
			for (int i = 0; i < len; i++)
			{
				if (strBuf[i] == ',')
					numberOfPairs++;
			}

			int keyCnt = 0;
			TKey* keyArr = new TKey[numberOfPairs];
			int valCnt = 0;
			TValue* valArr = new TValue[numberOfPairs];

			for (int i = 0; i < numberOfPairs; i++)
			{
				int j = 0;
				char* buf = new char[256];
				while (strBuf[j] != ',')
				{
					buf[j] = strBuf[j];
					j++;
				}
				//keyArr[keyCnt] = (TKey)buf;								 // ?
			}

			delete[] strBuf;
			delete strBuf;

			return in;
		}
		else
			return in;
	}

	void add(TKey newKey, TValue newValue)
	{
		if (numOfElem >= length)
		{
			arrayExpansion();
		}

		setKey(newKey, returnNumOfElem());
		setValue(newValue, returnNumOfElem());
		numOfElem++;
	}

	void del(int num)													
	{
		if (num > 0)
			int idx = num - 1;
		else
			return;

		for (int i = idx; i < returnNumOfElem(); i++)
		{
			arr[i] = arr[i + 1];
		}
		decreaseNumOfElem(1);
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
	cout << "Type the key:\n";
	int newKey = get<int>();
	cout << "Type the value:\n";
	int newValue = get<int>(); 
	a.add(newKey,newValue);

	cout << "Type the key:\n";
	newKey = get<int>();
	cout << "Type the value:\n";
	newValue = get<int>(); 
	a.add(newKey, newValue);

	//cin >> a;
	cout << a;
};


//1,2 3,4 5,6