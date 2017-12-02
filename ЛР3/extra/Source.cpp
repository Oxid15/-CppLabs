#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	ifstream ifile("Input.txt");
	if (!ifile)
	{
		cout << "Input file error";
	}
	int x = 0, lenof = 0;
	int* a = new int[256];
	while (!ifile.eof())
	{
		int buff = ifile.get() - 48;
		if (buff < 10 && buff >= 0 || buff == 11 || buff == -38)
		{
			a[x] = buff;
			x++;
		}
		lenof++;
	}
	//for (int j = 0; j < x; j++)
	//{
	//	cout << "a[" << j << "]= " << a[j] << "\n";
	//}

	int* b = new int[x];
	int j = 0;
	for (int i = 0; i < x; i++)
	{
		if (a[i] == 11 && a[i+1] == 11 && a[i+2] == 11)
		{
			i = i + 3;
		}
		if (a[i] == -38)
		{
			b[j] = 11;
			j++;
		}
		else
		{
			b[j] = a[i];
			j++;
		}
	}
	for (int k = 0; k < j; k++)
	{
		cout << "b[" << k << "]= " << b[k] << "\n";
	}
	cout << "j =" << j << "\n";
	int* temp = new int[j];
	int temp_len = 0;
	for (int i = 0; i < j; i++)
	{
		temp[i] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < j; i++)
	{
		if (b[i] != 11)
		{
			temp[cnt] = temp[cnt]*10 + b[i];
			cout << cnt << " - " << temp[cnt] << "\n";
		}
		else
		{
			cnt++;
		}
		temp_len++;
	}
	for (int k = 0; k < cnt; k++)
	{
		cout << "temp[" << k << "]= " << temp[k] << "\n";
	}
	cout << "temp length = " << temp_len << "\n";
	int* yrs = new int[temp_len];
	for (int i = 0; i < temp_len; i = i + 2)
	{
			yrs[i] = temp[i];
	}

	for (int k = 0; k < temp_len; k++)
	{
		cout << "yrs[" << k << "]= " << yrs[k] << "\n";
	}
	//for (int k = 0; k < len; k++)
	//{
	//	cout << "mny[" << k << "]= " << mny[k] << "\n";
	//}
	system("pause");
}