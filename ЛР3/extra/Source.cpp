#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	cout << (int) ';' << "\n"; // 59
	ifstream ifile("Input.txt");
	if (!ifile)
	{
		cout << "Input file error";
	}
	int n = 0, x = 0;
	int* a = new int[256];
	while (!ifile.eof())
	{
		int buff = ifile.get() - 48;
		if (buff < 10 && buff >= 0 || buff == 11 && x > 3)
		{
			a[x] = buff;
			x++;
		}
	}
	for (int j = 0; j < x; j++)
	{
		cout << "a[" << j << "]= " << a[j] << "\n";
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