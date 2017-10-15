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
	int sum_min = 0, min = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (m[i] < m[i + 1])
			min = m[i];
		else
			min = m[i + 1];
	}
	for (int i = 0; i < n-1; i++)
	{
		if ((m[i] == min) && ((m[i + 1] = m[i]) || ((m[i - 1] = m[i]) && (m[i + 1] != m[i]))))
		{
			sum_min = sum_min + min;
		}
	}
	sum_min = sum_min + min;
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (m[i] > m[i + 1])
			max = m[i];
		else
			max = m[i + 1];
	}
	int idx = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (m[i]==max)
		{
			idx += 1;
		}
	}
	int* a = new int[n];
	for (int j = 0; j < n; j++)
	{
		if (j==idx/2)
			a[j] = sum_min;
		else
			a[j] = m[j];
	}
	for (int j = 0; j < n; j++)
	{
		cout << "a[" << j << "]=" << a[j] << "\n";
	}
	delete[]m;
	delete[]a;
	system("pause");
}