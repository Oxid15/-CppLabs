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
		while (!ifile.eof())
		{
				ifile.get(i,2);
				cout << i << "\n";
		}
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