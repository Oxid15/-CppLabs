#include <iostream>

using namespace std;

struct student
{
	char* first_name = new char[256]; // ! // char* buf = new char[255]; cin >> buf; student.first_name = new char[strlen(buf)//(+1)//(?)];
	char* last_name = new char[256];
	char* patronymic_name = new char[256];
	int group_num;
	short grade[5];
	double avg;
};
struct linlist
{
	student a;
	student* next_ptr = new student;
};

 int add(student* head, linlist el_n)
{
	 student st;
	 if (head == nullptr)
	 {
		 head = &st;
	 }
	 else
	 {

	 }
	 return 0;
}

void arr()
{
	student a[10];
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter first name" << "\n";
		cin >> a[i].first_name;
		cout << "Enter last name" << "\n";
		cin >> a[i].last_name;
		cout << "Enter patronymic name" << "\n";
		cin >> a[i].patronymic_name;
		cout << "Enter number of group" << "\n";
		cin >> a[i].group_num;
		double sum = 0;
		for (int j = 0; j < 5; j++)
		{
			cout << "Enter grade" << "\n";
			cin >> a[i].grade[j];
			sum = sum + a[i].grade[j];
			cout << "sum=" << sum << "\n";
		}
		a[i].avg = sum / 5;
		cout << "avg=" << a[i].avg << "\n";
		count = ++count;
		double k;
		cout << "Enter 0 if you need to stop writing, or any positive number if you don't" << "\n";
		cin >> k;
		if (!k)
			break;
		else
			cout << "Continue..." << "\n";
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (a[j].avg < a[j + 1].avg)
				swap(a[j], a[j + 1]);
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << a[i].first_name << "\n";
		cout << a[i].last_name << "\n";
		cout << a[i].patronymic_name << "\n";
		cout << a[i].group_num << "\n";
		cout << a[i].avg << "\n";
	}
	system ("pause");
}

void list()

{
	student* head = nullptr;
	for (int i = 0; i < 10; i++)
	{
		linlist el_1;
		add(head, el_1);
	}
}

int main()
{
	cout << "This program works with data structures." << "\n";
	int prog = 1;
	while (prog)
	{
		int choose = 0;
		cout<< "Choose what to keep:" << "\n"
			<< "1 - Use array as data structure" << "\n"
			<< "2 - Use linked list as data structure" << "\n"
			<< "9 - Exit if you want" << "\n"
			<< "0 - Nothing" << "\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			system("cls");
			arr();
		}
		case 2:
		{
			system("cls");
			list();
		}
		case 0:
		{
			system("cls");
			cout << "You need to keep something" << "\n" << "\n";
			break;
		}
		case 9: 
		{
			system("cls");
			prog = 0;
			break;
		}
		system("cls");
		default: cout << "Please, write 1, 2 or 9, there's no choice" << "\n";
			break;
		}
	}
}