#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	char* i = new char[256];

	ifstream ifile("Input.txt");
	if (!ifile) 
	{
		cout << "File error";
	}
		while (!ifile.eof())
		{
				ifile.getline(i,256*sizeof(char));
				cout << i << "\n";
		}

		ifile.close();
	ofstream ofile("Output.txt");
	if (!ifile)
	{
		cout << "File error";
	}
		// File output...
		ofile.close();
	system("pause");
}