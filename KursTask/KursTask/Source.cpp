#include <iostream>
#include<fstream>

using namespace std;


template <class T>
T get()
{
	T data;
	cout << "Enter the data\n";
	cin >> data;
	return data;
}

template <class TKey, class TValue>  
class Collection{};

template<class TValue>
class Collection<int, TValue>					 //partial template specialization
{
private:
	struct CollectionElement
	{
		int key;
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

	void setKey(int newKey, int idx)
	{
		arr[idx]->key = newKey;
	}

	void setValue(TValue newValue, int idx)
	{
		arr[idx]->value = newValue;
	}

	bool inputCheck(char* str)
	{
		bool isCommaFlag = false;
		bool isSpacesFlag = false;

		for (int i = 0; i < strlen(str); i++)
		{
			if (isCommaFlag || isSpacesFlag)
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

	int getKey(int num)
	{
		return arr[num]->key;
	}

	TValue getValue(int num)
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
			out << inst.getKey(i) << ',' << inst.getValue(i) << '\n';
		}
		return out;
	}

	friend istream &operator >> (istream & in, Collection &inst)
	{
		char* strBuf = new char[1024];
		in.getline(strBuf, 1024);

		if (inst.inputCheck(strBuf))
		{
			int len = strlen(strBuf);
			int numberOfPairs = 0;
			for (int i = 0; i < len; i++)
			{
				if (strBuf[i] == ',')
					numberOfPairs++;
			}

			int keyCnt = 0;
			int* keyArr = new int[numberOfPairs];
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
				int newBuf = (int)buf;
				keyArr[keyCnt] = (int)newBuf;
				keyCnt++;
			}

			delete[] strBuf;
			delete strBuf;

			return in;
		}
		else
			return in;
	}

	void add(int newKey, TValue newValue)
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
		numOfElem--;
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
	//cout << "Type the key:\n";
	//int newKey = get<int>();
	//cout << "Type the value:\n";
	//int newValue = get<int>(); 
	//a.add(newKey,newValue);

	//cout << "Type the key:\n";
	//newKey = get<int>();
	//cout << "Type the value:\n";
	//newValue = get<int>(); 
	//a.add(newKey, newValue);

	cin >> a;
	cout << a;
};

//1,2 3,4 5,6