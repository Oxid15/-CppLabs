#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int sum,n;
	cout << "Write array size"<<"\n"; cin >> n;
	int *m = new int[n];
	srand(time(NULL));
	for (int a = 0; a != n; a++)
	{
		m[a] = rand();
		cout << "m[" << a << "]=" << m[a] << "\n";
	}
	while (int a = 0 <= n)
	{
		a += 2;
		if ((m[a] > m[a - 1]) && (a != 1))
		{
			cout << "a=" << a << "\n";
			sum = +m[a];
			cout << "sum=" << sum << "\n";
			system("pause");
		}
	}
	delete m;
	system("pause");
}