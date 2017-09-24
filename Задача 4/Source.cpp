#include<iostream>
using namespace std;


int main()
{
	cout << "Write sequence that ends by 0 character-by-character: " << "\n";
	int xc=1, xp=1;
	bool vv;
	while (xc != 0)
	{
		xp = xc;
		cin >> xc;
		if (xc < xp)
		{
			vv = false;
			cout << "nonincr=" << vv <<"\n";
		}
		else
		{
			vv = true;
			cout << "incr=" << vv << "\n";
		}
	}
	system("pause");
}