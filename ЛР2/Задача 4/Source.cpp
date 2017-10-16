#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int n = 0;
	cout << "Write matrix size:"; cin >> n;
	int* *b = new int*[n];
	if (n > 4)
	{
		{
			srand(time(NULL));
			for (int i = 0; i != n; i++)
			{
				b[i] = new int[n];
				for (int j = 0; j < n; j++)
				{
					b[i][j] = rand();
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			b[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				cout << "Write b[" << i << "]" << "[" << j << "]" << "/n";
				cin >> b[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "b[" << i << "]" << "[" << j << "]=" << b[i][j] << "  ";
		}
		cout << "\n";
	}

	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			a[i] = b[i][i];
		}
		else
		{
			break;
		}
		cout << "a[" << i << "]=" << a[i] << "\n";
	}
	/*
	int x = 0;

	while (int i = 0 >= x)
	{
		a[i] = b[i][i - x] + b[i - x][i];
		i += 1;
		for (int i = 0; i < n; i++)
		{
			cout << "a[" << i << "]=" << a[i] << "\n";
		}
	}
	*/

	system("pause");
	for (int i = 0; i < n; i++)
	{
			delete[]b[i];
	}
	delete[]b;
	delete[]a;
}