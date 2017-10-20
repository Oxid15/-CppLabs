#include <iostream>
#include <fstream>

using namespace std;


int main()
{

	ofstream file;
	file.open("Output.txt");
	if (!file) 
	{
		cout << "File error";
	}
	for (int i = 0; i<10; i++) file << i << "/n";
	file.close();
}