#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	double e,s = 0, sum = 0;
	cout << "Write e" << "\n"; cin >> e;
	for (int  i = 1; s<e; i++)
	{
		s = (pow((-1), (1 + i))) / (i*(i + 1)*(i + 2));
		sum += s;
		cout << "mid sum=" << sum << "\n";
	}
	cout << "Final Sum=" << sum;
	system("pause");
}