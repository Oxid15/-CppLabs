#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int n;
	cout << "Write array size:" << "\n"; cin >> n;
	int *m = new int[n];
	srand(time(NULL));
	for (int a = 0; a != n; a++)
	{
		m[a] = rand();
		cout << "m[" << a << "]=" << m[a] << "\n";
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m[j] < m[j + 1])
			{
				int a = 0;
				a = m[j];
				m[j] = m[j+1];
				m[j+1] = a;
			}
		}	
	}
	for (int i = 0; i < n; i++)
	{
		cout << "m1[" << i << "]=" << m[i] << "\n";
	}

	system("pause");
	delete[]m;
}