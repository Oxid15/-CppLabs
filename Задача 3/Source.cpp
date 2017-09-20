#include<iostream>
using namespace std;


int main()
{
	int sum = 0;
	for (int i = 19; i < 100; i++)
	{
		if ((i % 3 == 0) && ((i % 10 == 2) || (i % 10 == 4) || (i % 10 == 8)))
		{
			sum += i;
			cout << i <<"\n";
		}
	}
	cout << "Sum = " << sum;
	system("pause");
}