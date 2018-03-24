#include<iostream>
#include<cstring>

using namespace std;

bool check(char* string) // to check if entered string isn't correct
{
	bool digits = false, gap = false;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '+' || string[i] == '.' || (int)string[i] - 48 >= 0 && (int)string[i] - 48 <= 9)
		{
			if (string[i] == '+')
				gap = true;
			if ((int)string[i] - 48 >= 1 && (int)string[i] - 48 <= 9)
				digits = true;
			continue;
		}
		else
			return(true);
	}
	if (digits && gap && (string[strlen(string) - 1] != ' ' || string[strlen(string) - 1] != '.' || string[0] != ' '))
		return (false);
	else
		return(true);
}

class ComplexNumber
{
private:
	double x, y;
public:

	void numberInput()
	{
		char* inputStr = new char;
		while(true)
		{
			cin.getline(inputStr, 128);

			if (!check(inputStr))
			{
				break;
			}
			cout << "Try again \n";
		}

		double inputX, inputY;
		char* strX = new char;
		char* strY = new char;
		int i = 0;
		for (i; i < strlen(inputStr); i++)
		{
			if (inputStr[i] != '+')
				strX[i] = inputStr[i];
			else
				break;
		}

		short j;
		for (++i, j = 0; i <= strlen(inputStr); j++, i++)
		{
			strY[j] = inputStr[i];
		}
		//x = strtof(strX, &strX + strlen(strX) - 1);
		//y = strtof(strY, &strY + strlen(strY) - 1);
		x = atof(strX);
		y = atof(strY);
	}

	void getNumber()
	{
		cout << "\n" << x << "+" << y << (char)251 << "-1  \n";
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
	cout << "Enter x and y of complex number with '+' \n" << "Example: 3.4+5 \n";
	ComplexNumber a, b, c;
	a.numberInput();
	b.numberInput();

	c = a + b;
	c.getNumber();

	c = a - b;
	c.getNumber();

	c = a * b;
	c.getNumber();

	c = a / b;
	c.getNumber();

	system("pause");
}