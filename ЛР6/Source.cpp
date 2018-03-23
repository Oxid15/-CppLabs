#include<iostream>
#include<cstring>

using namespace std;

bool check(char* string) // to check if entered string isn't correct
{
	bool digits = false, gap = false;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == ' ' || string[i] == '.' || (int)string[i] - 48 >= 1 && (int)string[i] - 48 <= 9)
		{
			if (string[i] == ' ')
				gap = true;
			if ((int)string[i] - 48 >= 1 && (int)string[i] - 48 <= 9)
				digits = true;
			continue;
		}
		else
			return(true);
	}
	if (digits && gap)
		return (false);
	else
		return(true);
}

void convert(char* string, float &x, float &y)
{
	for (int i = 0; i < strlen(string); i++)
	{

	}
}

class ComplexNumber
{
private:
	//float x, y;
public:
	float x, y;	// temporary
	void numberInput()
	{
		char* inputStr = new char;
		while(true)
		{
			cout << "Write x and y through the gap \n";
			cin.getline(inputStr, 128);

			if (!check(inputStr))
			{
				break;
			}
			cout << "Try again";
			system("pause");
			system("cls");
		}
		float inputX, inputY;
		convert(inputStr, x, y);
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