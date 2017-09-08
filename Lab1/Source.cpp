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
		std::cout << a;
}