#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int n;
	cout << "Write array size:" << "\n"; cin >> n;
	int *m = new int[n];
	if (n >= 10) 
	{
		srand(time(NULL));
		for (int a = 0; a != n; a++)
		{
			m[a] = rand();
			cout << "m[" << a << "]=" << m[a] << "\n";
		}
	}
	else
	{
		for (int a = 0; a != n; a++)
		{
			cout << "Write m[" << a << "]" << "\n";
			cin >> m[a];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
		{
			if (m[i] < m[i + 1])
				swap(m[i],m[i+1]);
		}
	}
	int* *b = new int*[n];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((m[i] == m[i + 1])||(m[i] == m[i-1]))
		{
			b[i] = &m[i];
			count += 1;
		}
		else
			break;
	}
	int sum_min = 0;
	for (int i = n; i > 0; i--)
	{
		if ((m[i] == m[i - 1]) || (m[i] == m[i + 1]))
		{
			sum_min += m[i];
		}
	}
	cout << "sum_min=" << sum_min << "\n";
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (&m[i] == b[count / 2])
		{
			m[i] = sum_min;
		}
		else
			a[i] = m[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << "a[" <<i<<"]=" << a[i] << "\n";
	}
	delete[]m;
	delete[]a;
	system("pause");
}