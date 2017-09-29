#include<iostream>
using namespace std;


int main()
{
	cout << "Write sequence that ends by 0 character-by-character: " << "\n";
	int xc=1, xp=1,cnt=0;
	bool vv;
	while (xc != 0)
	{
		xp = xc;
		cin >> xc;
		cnt = cnt++;
		if ((xc < xp)&&(xc!=0)&&(cnt=2))
		{
			vv = false;
		}
		else
		{
			if (xc != 0)
			{
				vv = true;
			}
		}
		vv = vv*vv;
	}
	if (vv == 1)
	{
		cout << "the sequence is increasing" << "\n";
	}
	else
	{
		cout << "the sequence is nonincreasing" << "\n";
	}
	system("pause");
}