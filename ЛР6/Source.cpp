#include<iostream>
#include<cstring>

using namespace std;

class ComplexNumber
{
private:
	//float x, y;
public:
	float x, y;
	void numberInput()
	{
		bool isRight = false;
		//while (!isRight)
		//{
			float inputX, inputY;
			cout << "Write x and y through the gap or press Enter after first number" << "\n";
			cin >> inputX >> inputY;
			x = inputX;
			y = inputY;
			//isRight = true;
			system("pause");
			system("cls");
		//}
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

void main()
{
	ComplexNumber a, b, c;
	a.x = 4;
	a.y = 3;
	b.x = 1;
	b.y = 2;
	c = a + b;
	cout << c.x << " " << c.y << "\n";;
	c = a - b;
	cout << c.x << " " << c.y << "\n";;
	c = a * b;
	cout << c.x << " " << c.y << "\n";;
	c = a / b;
	cout << c.x << " " << c.y << "\n";;
	system("pause");
}