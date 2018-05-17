#include <iostream>

using namespace std;

template <class Tkey, class Tvalue>
class Collection
{
//public:
	Tkey key;
	Tvalue value;

public:

	friend ostream& operator <<(ostream& out, const Collection& inst)
	{
		out << inst.value;
		return out;
	}

	friend ostream& operator >>(ostream& in, const Collection& inst)
	{
		in >> inst.value;
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

	void setValue(Tvalue val)
	{
		value = val;
	}

	void setKey(Tkey k)
	{
		key = k;
	}

};

template <class T>
T getT()
{
	T smpl;
	cin << smpl;
	return smpl;
}

void main()
{
	float key = 1, value = 0;
	Collection<float, float> a;
	cin >> value;
	a.setValue(value);
	cout << a;
}