#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int n;
	double sum=0;
	cout << "Write n"; cin >> n;
	for (n;n!=2;n--)
	{
		sum = sqrt(sum + 3*n);
	}
	cout << "sum= " << sum << "\n";
	system("pause");
}