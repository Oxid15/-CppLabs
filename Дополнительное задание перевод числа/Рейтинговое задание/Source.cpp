#include<iostream>

using namespace std;


int main()
{
	int num, mask = 1, count = 0, bin[8*sizeof(int)];
	cout << "Write a number" << "\n"; cin >> num;
	{
		for (int i = 0; i < 8*sizeof(int); i++)
		{
			bin[i] = num & mask;
			num = num >> 1;
		}
		cout << "\n" << "\n";
		for (int i = (8*sizeof(int)-1); i >= 0; i--)
		{
			cout << bin[i];
		}
		system("pause");
	}
}