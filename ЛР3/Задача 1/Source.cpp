#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	char* i = new char[256];

	ifstream ifile("Input.txt");
	if (!ifile)
	{
		cout << "Input file error";
	}
	int k = 0, count = 0, a[256];
	for (int j = 0; j < 256; j++)
	{
		ifile.get(i,2);
		if (atoi(i) != 0)
		{
			a[k] = atoi(i);
			cout << "a[" << k << "]=" << a[k] << "\n";
			count = ++count;
			k = ++k;
		}
	}
	delete[] i;
		ifile.close();
	int el, elpas;
	cout << "Write array element" << "\n"; cin >> el;
	cout << "Write array element to paste in output file" << "\n"; cin >> elpas;
	int* b = new int[2*count];
	int countb = 0;
	for (int j = 0, k = 0; j < count; k++, j++)
	{
		if (a[j] == el)
		{
			b[k] = a[j];
			b[k + 1] = elpas;
			k = k + 1;
			countb = ++countb;
		}
		else
		{
			b[k] = a[j];
		}
	}
	for (int k = 0; k < count + countb; k++)
	{
		cout << "b[" << k << "]=" << b[k] << "\n";
	}
	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}
	for (int j = 0; j < count + countb; j++)
	{
		ofile << b[j] << " ";
	}
		ofile.close();
		delete[] b;
		system("pause");
}