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
	cout << "count=" << count;
		ifile.close();
	int el, elpas;
	cout << "Write array element"; cin >> el;
	cout << "Write array element to paste in output file"; cin >> elpas;

	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}
		// File output...
		ofile.close();
	system("pause");
}