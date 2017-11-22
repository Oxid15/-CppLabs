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
	delete[] a;

	ifile.close();
	int el, elpas;
	cout << "Write array element" << "\n"; cin >> el;
	cout << "Write array element to paste in output file" << "\n"; cin >> elpas;
	int* c = new int[2*k];
	int count = 0;
	for (int j = 0, l = 0; j < 2*k; l++, j++)
	{
		if (b[l] == el)
		{
			c[j] = b[l];
			c[j + 1] = elpas;
			j++;
			count++;
		}
		else
		c[j] = b[l];
	}
	delete[] b;
	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}
	for (int j = 0; j < k + count; j++)
	{
		ofile << c[j] << " ";
	}
	ofile.close();
	delete[] c;
	system("pause");
}