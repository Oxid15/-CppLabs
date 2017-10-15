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
		cout << "min=" << min << "\n";
	}
	for (int i = 0; i < n-1; i++)
	{
		if ((m[i] == min) && ((m[i + 1] = m[i]) || ((m[i - 1] = m[i]) && (m[i + 1] != m[i]))))
		{
			sum_min = sum_min + min;
		}
	}
	sum_min = sum_min + min;
	cout << "sum_min=" << sum_min << "\n";

	delete[]m;
	system("pause");
}