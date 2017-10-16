#include<iostream>
using namespace std;


int main()
{
	int n = 0;
	cout << "Write matrix size:"; cin >> n;
	int* *b = new int*[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "Write b[" << i << "]" << "[" << j << "]" << "/n";
			cin >> b[i][j];
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
}