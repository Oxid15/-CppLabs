#include<iostream>
#include<cstring>

using namespace std;

bool check(char* string)// to check if entered string isn't correct
{
	for (int i = 0; i < strlen(string); i++)
	{
		cout << string[i] << "\n";
	}
	return (0);
}

class ComplexNumber
{
private:
	//float x, y;
public:
	float x, y;	// temporary
	void numberInput()
	{
			cout << "Write x and y through the gap \n";
			char* inputStr = new char;
			cin.getline(inputStr, 128);
			check(inputStr);
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
		result.y = (y * second.x - x * second.y) / (second.x * second.x + second.y * second.y);
		return (result);
	}
};

void menu()
{

}

void main()
{
	ComplexNumber a, b, c;
	a.numberInput();
	//a.x = 4;
	//a.y = 3;
	//b.x = 1;
	//b.y = 2;
	//c = a + b;
	//cout << c.x << " " << c.y << "\n";
	//c = a - b;
	//cout << c.x << " " << c.y << "\n";
	//c = a * b;
	//cout << c.x << " " << c.y << "\n";
	//c = a / b;
	//cout << c.x << " " << c.y << "\n";        //also temporary until I will done with the menu() function 
	system("pause");
}