#include<iostream>
#include<cstring>

using namespace std;

bool check()
{

}

class ComplexNumber
{
private:
	//float x, y;
public:
	float x, y;	// temporary
	void numberInput()
	{
			float inputX, inputY;
			cout << "Write x and y through the gap \n";
			x = inputX;
			y = inputY;
	}
	
	const ComplexNumber operator+(const ComplexNumber second) const
	{
		ComplexNumber result;
		result.x = x + second.x;
		result.y = y + second.y;
		return (result);
	}

	const ComplexNumber operator-(const ComplexNumber second) const
	{
		ComplexNumber result;
		result.x = x - second.x;
		result.y = y - second.y;
		return (result);
	}

	const ComplexNumber operator*(const ComplexNumber second) const
	{
		ComplexNumber result;
		result.x = x * second.x - y * second.y;
		result.y = y * second.x + x * second.y;
		return (result);
	}

	const ComplexNumber operator/(const ComplexNumber second) const
	{
		ComplexNumber result;
		result.x = (x * second.x - y * second.y) / (second.x * second.x + second.y * second.y);
		result.y = (y * second.x - x * second.y) / (second.x * second.x + second.y * second.y);;
		return (result);
	}
};

void menu()
{

}

void main()
{
	ComplexNumber a, b, c;
	menu();
	//a.x = 4;
	//a.y = 3;
	//b.x = 1;
	//b.y = 2;
	//c = a + b;
	//cout << c.x << " " << c.y << "\n";;
	//c = a - b;
	//cout << c.x << " " << c.y << "\n";;
	//c = a * b;
	//cout << c.x << " " << c.y << "\n";;
	//c = a / b;
	//cout << c.x << " " << c.y << "\n";;
	system("pause");
}