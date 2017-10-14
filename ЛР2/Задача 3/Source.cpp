#include<iostream>
using namespace std;


int main()
{
	int n = 0;
	int* m = new int[n];

	cout << "Write array size" << "\n"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Write m[" << i << "]" << "\n"; cin >> m[i];
	}
	int k = 0;
	cout << "Write k" << "\n"; cin >> k;

	int p, count = 0;
	for (int i = 0; i < n; i++)
	{
		if (m[i] == k)
		{
			count = count++;
		}
	}
	p = count * 2;
	int* a = new int[n+p];
	for (int j = 0, i = 0; j < (n + p); i++, j++)
	{
		if (m[j] == k)
		{
			a[j] = 0;
			a[j + 1] = k;
			a[j + 2] = 0;
			j = j + 2;
		}
		else
		{
			a[j] = m[i];
		}
	}
	for (int i = 0; i < (n + p); i++)
	{
		cout << "a[" << i << "]" << a[i] << "\n";
	}
	int* u = new int;
	for (int i = 0; i < (n + p); i++)
	{
		if ((a[i] % 2 == 0) && (a[i + 1] % 2 == 1) && (a[i + 2] % 2 == 0))
		{
			u = &a[i + 1];
			break;
		}		
	}
	int* a1 = new int[n + p - 1];
	for (int i = 0, j = 0; i < (n + p); j++, i++)
	{
		if (a[i] == *u)
		{
			i += 1;
		}
		a1[j] = a[i];
	}
	for (int i = 0; i < (n + p-1); i++)
	{
		cout << "a1[" << i << "]" << a1[i] << "\n";
	}
	system("pause");
	delete[]a;
	delete[]a1;
	delete[]m;
}