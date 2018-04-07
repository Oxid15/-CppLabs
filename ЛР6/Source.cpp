#include<iostream>
#include<cstring>

using namespace std;

bool isInt(int i, char* string)
{
	if ((int)string[i] - 48 >= 0 && (int)string[i] - 48 <= 9)
		return true;
	else
		return false;
}

bool check(char* string) // to check if entered string isn't correct
{
	bool digits = false, gap = false;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '+' || string[i] == '*' || string[i] == '.' || string[i] == '^' || string[i] == '-' 
			|| isInt(i,string))
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

void linearInput(char* string, double &x, double &y) // dividing string to get two strings with numbers before and after "+"
{													 // and then interpret them to float
	char* strX = new char[strlen(string)];
	char* strY = new char[strlen(string)];
	int i = 0;
	for (i; i < strlen(string); i++)
	{
		if (string[i] != '+')
			strX[i] = string[i];
		else
			break;
	}

	int j;
	for (++i, j = 0; i <= strlen(string); j++, i++)
	{
		strY[j] = string[i];
	}														
	x = atof(strX);
	y = atof(strY);
}

void expInput(char* string, double &x, double &y)  //same as linear but more complicated
{
	char* strX = new char[strlen(string)];
	char* strY = new char[strlen(string)];
	int i = 0;
	for (i; i < strlen(string); i++)
	{
		if (string[i] == '*')
			break;
		else
			strX[i] = string[i];
	}											   //getting coefficient...
	char* charPowX = new char[strlen(string)];
	int j = 0;
	i += 3;
	for (i,j; i < strlen(string); i++)
	{
			charPowX[j] = string[i];
			j++;
	}
												   //and exponent of the value x
	for (++i; i < strlen(string); i++)
	{
		if (string[i] == '*')
			break;
		else
			strY[i] = string[i];
	}
	char* charPowY = new char[strlen(string)];
	int k = 0;
	i += 3;
	for (i, k; i < strlen(string); i++)
	{
		charPowY[k] = string[i];
		k++;
	}
												   //the same for y
	x = atof(strX)*pow(10, atoi(charPowX));
	y = atof(strY)*pow(10, atoi(charPowY));
}												   
												  
bool choose(char* string)						   //chooses what input function to use
{
	for (int i = 0; i < strlen(string)-1; i++)
	{
		if (string[i] == '*' || string[i] == '^')
			return false;
	}
	return true;
}

class ComplexNumber
{
private:
	double x, y;
public:

	void numberInput()
	{
		char* bufStr = new char[256];
		while(true)
		{
			cin >> bufStr;
			if (!check(bufStr))
			{
				break;
			}
			cout << "Try again \n";
		}
		char* inputStr = new char[strlen(bufStr)];
		for (int i = 0; i < strlen(bufStr); i++)
		{
			inputStr[i] = bufStr[i];
		}

		if (choose(inputStr))
			linearInput(inputStr, x, y);
		else
			expInput(inputStr, x, y);
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
			cout << "Enter x and y of complex number with '+' like: \n" << "x + y \n" 
				<< "OR \n" 
				<< "You can enter in scientific notation like: \n" << "x * 10^n + y * 10^m without gaps \n";
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
				cout << "0 - Back" << "\n";
				cout << "\n9 - Exit" << "\n";
				cin >> choose;

				switch (choose)
				{
				case 1:
					c = a + b;
					showMethod(a, b, c);
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
				case 9:
					return;
			    }
			}
	}
}

void main()
{
	menu();
}