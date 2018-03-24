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
		x = atof(strX);
		y = atof(strY);
	}

	void getNumber()
	{
		cout << x << "+" << y << (char)251 << "-1  \n";
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

void showMethod(ComplexNumber a, ComplexNumber b, ComplexNumber c)
{
	system("cls");
	cout << "a= ";
	a.getNumber();
	cout << "b= ";
	b.getNumber();
	cout << "\n" << "c= ";
	c.getNumber();
	system("pause");
	system("cls");
}

void menu()
{
	cout << "\n\n" << " This program works with complex numbers \n \n";
	bool menuIsActive = true;
	while (menuIsActive)
	{
			cout << "Enter x and y of complex number with '+' \n" << "Example: 3.4+5 \n";
			ComplexNumber a, b, c;
			a.numberInput();
			cout << "Enter x and y of complex number again \n";
			b.numberInput();

			bool testing = true;
			while (testing)
			{
				cout << "Choose what to keep:\n";
				int choose = 0;
				cout << "1 - c = a + b" << "\n";
				cout << "2 - c = a - b" << "\n";
				cout << "3 - c = a * b" << "\n";
				cout << "4 - c = a / b" << "\n";
				cout << "0 - Nothing" << "\n";
				cin >> choose;

				switch (choose)
				{
				case 1:
					c = a + b;
					showMethod(a,b,c);
					break;
				case 2:
					c = a - b;
					showMethod(a, b, c);
					break;
				case 3:
					c = a * b;
					showMethod(a, b, c);
					break;
				case 4:
					c = a / b;
					showMethod(a, b, c);
					break;
				case 0:
					testing = false;
					system("cls");
					break;
			    }
			}
	}
}

void main()
{
	menu();
}