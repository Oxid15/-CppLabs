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

	system("pause");
	delete[]m;
}