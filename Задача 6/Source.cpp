#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int  i = 1;
	double e,s = 0, sum = 0;
	cout << "Write e" << "\n"; cin >> e;
	for (i; s<e; i++)
	{
		s = (pow((-1), (1 + i))) / (i*(i + 1)*(i + 2));
		sum = sum + s;
		cout << "p sum=" << sum << "\n";
	}
	cout << "FinalSum=" << sum;
	system("pause");
}