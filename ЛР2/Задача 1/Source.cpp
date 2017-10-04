#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int n;
	cout << "Write array size"<<"\n"; cin >> n;
	int *m = new int [n];
	srand(time(NULL));
	for (int a = 0; a != n; a++)
	{
		m[a] = rand();
		cout << "m[" << a << "]=" << m[a] << "\n";
	}
	
	int a = 3;
	bool b = true, d = false;
	while (a < n)
	{
		if (m[a] > m[a - 2])
		{
			b *= 1;
		}
		else
		{
			b = 0;
			d = 1;
			break;
		}
		a += 2;
	}
	int sum = 0, c = 0;
	if (b == 1)
	{
		int i = 0;
		while (c <= n)
		{
			sum += m[c];
			c += 2;
			i = ++i;
		}
		cout << "average=" << sum / i;
	}
		if (d == 1)
		{
			int cnt = 0, a = 0;
			while (a < n)
			{
				if (m[a] > 0)
				{
					cnt = ++cnt;
					a = ++a;
				}
			}
			cout << "positive numbers:" << cnt << "\n";
		}
	delete []m;
	system("pause");
}