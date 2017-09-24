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
		if ((xc < xp)&&(xc!=0))
		{
			vv = false;
			cout << "nonincr"<<"\n";
		}
		else
		{
			vv = true;
			cout << "incr"<< "\n";
		}
	}
	vv = vv*vv;
	if (vv == 1)
	{
		cout << "the sequence is increasing" << "\n";
	}
	else
	{
		cout << "the sequence is nonincreasing" << "\n";
	}
	cout << vv;
	system("pause");
}