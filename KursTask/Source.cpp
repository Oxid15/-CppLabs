#include <iostream>

using namespace std;

//template<class T>
//ostream& operator << ((ostream& out, const T& inst));
//
//template<class T>
//ostream& operator >> ((ostream& out, const T& inst));

template <class Tkey, class Tvalue>
class Collection
{
public:
	Tkey key;
	Tvalue value;

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
};



void main()
{
	int key = 1, value = 0;
	Collection<int,int> a;
	a.value = value;
	cout << a;
}