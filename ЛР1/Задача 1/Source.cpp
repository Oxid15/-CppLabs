//variant 5
#include <iostream> 
#include <math.h>
using namespace std;

int x, y, z;
int main()
{
	cout << "Write x -"; cin >> x;
	cout << "Write y -"; cin >> y;
	cout << "Write z -"; cin >> z;

	int a = log(abs((y - sqrt(abs(x))))*(x - (y / (z + x*x / 4))));
	int b = (x - x*x /6)+(x*x*x*x*x/120);
		cout <<"Variable a =" << a;
		cout << "Variable b =" << b;
}