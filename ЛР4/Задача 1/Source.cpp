#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	struct student
	{
		char* first_name = new char[256];
		char* last_name = new char[256];
		char* patronymic_name = new char[256];
		int group_num;
		int grade[5];
	};
	student a[10];
	ofstream ofile("lib.txt");

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter first name" << "\n"; 
		cin >> a[i].first_name; 
		ofile << a[i].first_name;
		cout << "Enter last name" << "\n";
		cin >> a[i].last_name;
		ofile << a[i].last_name;
		cout << "Enter patronymic name" << "\n";
		cin >> a[i].patronymic_name;
		ofile << a[i].patronymic_name;
		cout << "Enter number of group" << "\n"; 
		cin >> a[i].group_num;
		ofile << a[i].group_num;
		for (int j = 0; j < 5; j++)
		{
			cout << "Enter grade" << "\n";
			cin >> a[i].grade[j];
			ofile << a[i].grade[j];
		}
		ofile << "\n";
		int k;
			cout << "Enter 0 if you need to stop writing, or any positive number if you don't" << "\n";
			cin >> k;
			if (!k)
				break;
			else
				cout << "Continue..." << "\n";
	}
}