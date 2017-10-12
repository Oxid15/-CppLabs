#include<iostream>
using namespace std;


int main()
{
	int n = 0, k = 0;
	int* m = new int[n];

	cout << "Write array size" << "\n"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Write m[" << i << "]" << "\n"; cin >> m[i];
	}
	cout << "Write k" << "\n"; cin >> k;

	int* a;
	for (int j = 0; j < n; j++)
	{
		if (m[j] == k)
		{
			a = & m[j];
			cout <<"a=" << a << "\n" <<"*a=" <<*a << "\n";
			cout << "k=" << k << "\n";
			cout << "m[j]=" << m[j] << "\n";
		}
	}

	system("pause");
}