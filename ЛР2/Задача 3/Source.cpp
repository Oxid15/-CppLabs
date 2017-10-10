#include<iostream>
using namespace std;


int main()
{
	int n = 0;
	int *m = new int[3*n];
	cout << "Write array size" << "\n"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Write m[" << i << "]" << "\n"; cin >> m[i];
	}

	system("pause");
}