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
	int count = 0, a[256];
	for (int j = 0; j < 256; j++)
	{
		ifile.get(i,2);
		if (ifile.eof())
			break;
		a[j] = atoi(i);
		cout << "a[" << j << "]=" << a[j] << "\n";
		count = ++count;
	}
	cout << "count=" << count;
		ifile.close();

	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}
		// File output...
		ofile.close();
	system("pause");
}