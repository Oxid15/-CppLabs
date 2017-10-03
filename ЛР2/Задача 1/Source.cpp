#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int sum=0,n;
	cout << "Write array size"<<"\n"; cin >> n;
	int *m = new int[n];
	srand(time(NULL));
	for (int a = 0; a != n; a++)
	{
		m[a] = rand();
		cout << "m[" << a << "]=" << m[a] << "\n";
	}
	int a = 3;
	bool b = true;
	while (a <= n)
	{
		if (m[a] > m[a - 2])
			b *= 1;
		else
		{
			b = 0;
			break;
		}
		a += 2;
	}
	int c = 0;
	if (b = 1)
	{
		while (c <= n)
		{
			sum = sum + m[c];
			c += 2;
		}
		cout << "sum=" << sum;
	}
	delete m;
	system("pause");
}