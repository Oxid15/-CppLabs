#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	cout << (int) ';'; // 59
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
		int buff = ifile.get();
		if (buff != (int)'\n')
		{
			a[p] = buff - 48;
		}
		else
		{
			a[p] = -16;
		}
		cnt++;
		p++;
		cout << "b[" << p << "]= " << b[p] << "\n";
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
	for (int i = 0; i < k; i++)
	{
		cout << "b[" << i << "]= " << b[i] << "\n";
	}

	ifile.close();

	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}

	ofile.close();
	system("pause");
}