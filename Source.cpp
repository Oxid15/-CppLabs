#include <iostream> 
#include <math.h>
using namespace std;

int x, y, z;
int main()
{
	std::cout << "Write x -"; std::cin >> x;
	std::cout << "Write y -"; std::cin >> y;
	std::cout << "Write z -"; std::cin >> z;

	int a = log(abs((y - sqrt(abs(x))))*(x - (y / (z + x*x / 4))));
	int b = (x - x*x /6)+(x*x*x*x*x/120);
		std::cout <<"Variable a =" << a;
		std::cout << "Variable b =" << b;
}