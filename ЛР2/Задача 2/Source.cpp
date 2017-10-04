#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int n;
	cout << "Write array size" << "\n"; cin >> n;
	int *m = new int [n];
	srand(time(NULL));
	for (int a = 0; a != n; a++)
	{
		m[a] = rand();
		cout << "m[" << a << "]=" << m[a] << "\n";
	}
	int *max;
	for (int i = 1;i<=n;i++)
	{
		if (m[i] > m[i - 1])
			*max & m[i];
	}
	system("pause");
}