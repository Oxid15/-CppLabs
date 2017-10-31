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
	cout << "count=" << count << "\n";
		ifile.close();
	int el, elpas;
	cout << "Write array element" << "\n"; cin >> el;
	cout << "Write array element to paste in output file" << "\n"; cin >> elpas;
	int* idx = new int[count];
	int l = 0;
	for (int j = 0; j < count; j++)
	{
		if (a[j] == el)
		{
			idx[l] = j;
			cout << "idx[" << l << "]=" << idx[l] << "\n";
			l = ++l;
		}
	}
	//Creating an array of indices
	ofstream ofile("Output.txt");
	if (!ofile)
	{
		cout << "Output file error";
	}
		//...
		ofile.close();
	system("pause");
}