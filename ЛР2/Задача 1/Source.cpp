#include<iostream>
using namespace std;


int main()
{
	int *m,n;
	cout << "Write array size"<<"\n"; cin >> n;
	int *m = new int[n];
	for (int a = 0; a != n; a + 2) 
	{
		if ((m[a] > m[a-1])&&(a!=0))
		{
			for (int b = 0; b != n; b++)
			{

			}
		}
	}
	delete m;
}