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
	int* a = new int[];
	for (int i = 0; i < n; i++)
	{
			if (i = 0)
				a[0] = b[0][0];
			else
			{

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
	system("pause");
	
	for (int i = 0; i < n; i++)
	{
			delete[]b[i];
	}
	delete[]b;
}