#include<iostream>
using namespace std;

int cnt=1;
int main()
{
	int p,p1,x;
	cout << "Write sequence that ends by 0: " << "\n"; cin >> p;
	p1 = p;
	while (p!=0)
	{
		p /= 10;
		if (p != 0)
		{
			cnt = cnt * 10;
			cout << " counter: ";
		}
		cout << cnt << "  " << p << "\n";
	}
	int x2;
	while (cnt!=1)
	{
		x = p1 / cnt;
		p1 = p1%cnt;
		cnt /= 10;
		cout << "x= " << x<< "\n";
	}
	system("pause");
}