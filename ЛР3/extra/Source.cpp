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

	//...

	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}

	ofile.close();
}