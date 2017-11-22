#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	char* i = new char();
	ifstream ifile("Input.txt");
	if (!ifile)
	{
		cout << "Input file error";
	}

	int p = 0, cnt = 0;
	int* a = new int[256];
	int k = 0;
	int *b = new int[256];
	for (int j = 0; j < 256; j++)
		b[j] = 0;
	while (!ifile.eof())
	{
		int z = ifile.get();
		if (z != (int)'\n')
		{
			a[p] = z - 48;
		}
		else
		{
			a[p] = -16;
		}
		cnt++;
		p++;
	}

	for (int j = 0; j < cnt - 1; j++)
	{
		if (a[j] != -16 && a[j] != (int)'\n')
		{
			b[k] = b[k] * 10 + a[j];
		}
		else
		{
			k++;
		}
	}
	k++;
	for (int j = 0; j < k; j++)
	{
		cout << "b[" << j << "]=" << b[j] << "\n";
	}

	ifile.close();
	int el, elpas;
	cout << "Write array element" << "\n"; cin >> el;
	cout << "Write array element to paste in output file" << "\n"; cin >> elpas;
	int* c = new int[k];
	for (int j = 0, l = 0; j < k; l++, j++)
	{
		if (c[j] == el)
		{
			c[j] = b[l];
			c[j + 1] = elpas;
			j++;
		}
		for (int j = 0; j < k; j++)
		{
			cout << "c[" << j << "]=" << c[j] << "\n";
		}
	}
	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}
	ofile.close();
	system("pause");
}