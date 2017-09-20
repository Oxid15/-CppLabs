#include<iostream>
using namespace std;


int main()
{

	for (int i = 19; i < 100; i++)
	{
		if ((i % 3 == 0) && ((i % 10 == 2) || (i % 10 == 4) || (i % 10 == 8)))
		{
			int sum;
		    sum += i;
		}
		cout << "Sum = " << sum;
	}
}