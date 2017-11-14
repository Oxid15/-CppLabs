#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	struct student
	{
		char* full_name = new char[256]; 
		int group_num;
		int grades[5];
	};
	student a[10];
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter full name" << "\n"; cin >> a[i].full_name;
		cout << "Enter number of group" << "\n"; cin >> a[i].group_num;
		for (int j = 0; j < 5; j++)
		{
			cout << "Enter grade" << "\n";
			cin >> a[i].grades[j];
		}
		int k;
			cout << "Enter 0 if you need to stop writing, or any positive number if you don't";
			cin >> k;
			count = ++count;
			if (!k)
				break;
	}

	for (int i = 0; i < count; i++)
	{
		cout << "Full name:" << a[i].full_name << "\n";
		cout << "Group number:" << a[i].group_num << "\n";

		for (int j = 0; j < 5; j++)
		{
			cout << i << " grade:" ;
			cout << a[i].grades[j] << "\n";
		}
	}
	system("pause");
}