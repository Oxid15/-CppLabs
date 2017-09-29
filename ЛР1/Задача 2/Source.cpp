#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	float a1, b1, c1, a2, b2, c2;
	cout << "Write a1 \n"; cin >> a1;
	cout << "Write b1 \n"; cin >> b1;
	cout << "Write c1 \n"; cin >> c1;
	cout << "Write a2 \n"; cin >> a2;
	cout << "Write b2 \n"; cin >> b2;
	cout << "Write c2 \n"; cin >> c2;

	if ((abs(a1*b2 - a2*b1))>=0.0001)
	
	{
		float x = (b2*c1 - b1*c2) / (b1*a2 - b2*a1);
		float y = ((a1*c1 - a1*c2) / (a2*b1 / a1*b2));
		cout << "x= " << x << "\n";
		cout << "y= " << y << "\n";
	}
	system("pause");
}