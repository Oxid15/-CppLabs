#include<iostream>
using namespace std;


int main()
{
	int m;
	cout << "Write array size" << "\n"; cin >> m;
	int **a = new int *[m];
	for (int i = 0; i < m; i++)
	{
		int a[i] = new int[m];
	}

}