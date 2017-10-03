#include<iostream>
using namespace std;


int main()
{
	int sum,n;
	cout << "Write array size"<<"\n"; cin >> n;
	int *m = new int[n];
	for (int a = 0; a != n; a++)
	{
		m[a] = rand();
		cout << "m[" << a << "]=" << m[a] << "\n";
	}
	for (int a = 1; a != n; a + 2) 
	{
		if ((m[a] > m[a-1]))
		{
			sum =+ m[a];
			cout << sum << "\n";
		}
	}
	delete m;
	system("pause");
}