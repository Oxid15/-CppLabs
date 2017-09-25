#include <iostream>
using namespace std;


int main()
{
	int i, e;
	double sum=0;
	cout << "Write i"; cin >> i;
	cout << "Write e"; cin >> e;
	for (i;i<e;i++)
	{
		sum = sum + (((-1) ^ (1 + i))/(i*(i + 1)*(i + 2)));
	}
	cout << "Sum=" << sum;
}