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

	//for (int j = 0; j < cnt - 1; j++)
	//{
	//	if (a[j] != -16 && a[j] != (int)'\n')
	//	{
	//		b[k] = b[k] * 10 + a[j];
	//		cout << "b[" << k << "]= " << b[k] << "\n";
	//	}
	//	else
	//	{
	//		k++;
	//	}
	//}
	//k++;

	ifile.close();

	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}

	ofile.close();
	system("pause");
}