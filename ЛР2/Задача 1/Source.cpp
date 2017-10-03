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
	while ((a <= n)&&(m[a] > m[a - 2]))
	{
		a += 2;
		cout << "a=" << a << "\n";
		sum += m[a];
		cout << "sum=" << sum << "\n";
		system("pause");
	}
	delete m;
	system("pause");
}