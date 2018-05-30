
#include <iostream>
#include<fstream>

using namespace std;

class Bus;

template <class T>
T get()
{
	T* data = new T;
	cout << "Enter the data\n";
	cin >> *data;
	return *data;
}

char* getStr(int n)
{
	char* tmp = new char[n];
	cin >> tmp;
	return tmp;
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
		int tmpLength = length * 2;
		CollectionElement **tmpArray = new CollectionElement*[tmpLength];
		for (int i = 0; i < length; i++)
		{
			tmpArray[i] = arr[i];
		}
		arr = tmpArray;
		length = tmpLength;
		for (int i = 0; i < tmpLength; i++)
		{
			delete tmpArray[i];
		}
	}

	void setKey(TKey newKey, int idx)
	{
		arr[idx]->key = newKey;
	}

	void setValue(TValue& newValue, int idx)
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

	TKey getKey(int num)
	{
		return arr[num]->key;
	}

	TValue getValue(int num)
	{
		return arr[num]->value;
	}

	int getNumOfElem()
	{
		return numOfElem;
	}

	friend ostream &operator << (ostream & out, Collection &inst)
	{
		for (int i = 0; i < inst.getNumOfElem(); i++)
		{
			out << inst.getKey(i) << ',' << inst.getValue(i) << '\n';
		}
		return out;
	}

	friend istream &operator >> (istream & in, Collection &inst)
	{
		while (in.peek() != '\n')
		{
			TKey key;
			TValue value;
			in >> key;
			in >> value;
			inst.add(key, value);
		}
			return in;
	}

	bool add(TKey newKey, TValue& newValue)
	{
		if (searchByKey(newKey) != -1)
		{
			if (numOfElem >= length)
			{
				arrayExpansion();
			}

			setKey(newKey, getNumOfElem());
			setValue(newValue, getNumOfElem());
			numOfElem++;
			return true;
		}
		return false;
	}

	bool del(TKey key)
	{
		int idx = searchByKey(key);
		if (idx != -1)
		{
			for (int i = idx; i < getNumOfElem(); i++)
			{
				arr[i] = arr[i + 1];
			}
			numOfElem--;
			return true;
		}
		else
			return false;
	}

	int searchByKey(TKey key)
	{
		for (int i = 0; i < getNumOfElem(); i++)
		{
			if (arr[i]->key == key)
				return i;
		}
		if (getNumOfElem() != 0)
			return -1;
		return 0;
	}

};


class Bus
{
char* nameOfDriver;
int routeNum;
public:
	Bus()
	{
		routeNum = 0;
		nameOfDriver = new char[3];
		nameOfDriver[0] = 'N';
		nameOfDriver[1] = 'a';
		nameOfDriver[2] = 'N';
	}

	Bus(char* name, int number)
	{
		routeNum = number;
		nameOfDriver = new char[256];
		nameOfDriver = name;
	}

	~Bus()
	{
		delete[] nameOfDriver;
	}

	char* toString()
	{
		char* buf = new char[512];
		char* num = new char[64];
		_itoa_s(getRouteNum(), num, 64, 10);
		buf[0] = '"';
		int i = 1;
		for (int j = 0; j < strlen(num); j++, i++)
		{
			buf[i] = num[j];
		}
		buf[i] = ',';
		i++;
		for (int k = 0; k < strlen(nameOfDriver); i++, k++)
		{
			buf[i] = nameOfDriver[k];
		}
		buf[i] = '"';
		return buf;
	}

	int getRouteNum()
	{
		return routeNum;
	}

	char* getNameOfDriver()
	{
		return nameOfDriver;
	}

	friend Bus &operator >> (istream& in, Bus &inst)
	{
		int num;
		char* name = new char[64];
		in >> name >> num;

		inst.nameOfDriver = name;
		inst.routeNum = num;

		return inst;
	}
};

class BusPark
{
private:

	Collection <int, Bus> onRoad;
	Collection <int, Bus> inPark;

	void fileOut(char *list, int size)
	{

	}

	char* returnList(Collection<int, Bus> inst, char *buf)
	{
		for (int i = 0; i < inst.getNumOfElem(); i++)
		{
			char* busBuf = new char[64];
			busBuf = inst.getValue(i).toString();
			buf[i] = inst.getKey(i);
			buf[i + 1] = ',';
			for (int j = 2; j < strlen(busBuf); j++, i++)
			{
				buf[i] = busBuf[j];
			}
		}
		return buf;
	}

public:

	bool busOut(int key)
	{
		int res = this->inPark.searchByKey(key);
		if (res != -1)
		{
			Bus tempVal = inPark.getValue(res);
			inPark.del(res);
			onRoad.add(key, tempVal);
			return true;
		}
		return false;
	}

	bool busIn(int key)
	{
		int res = this->onRoad.searchByKey(key);
		if (res != -1)
		{
			Bus tempVal = onRoad.getValue(res);
			onRoad.del(res);
			inPark.add(key, tempVal);
			return true;
		}
		return false;
	}

	void add()
	{
		int key = get<int>();
		int num = get<int>();
		char* name = getStr(64);
		Bus bus(name, num);

		inPark.add(key, bus);
	}
};

void main()
{
	Collection<int,Bus> a;
	cin >> a;
};				 