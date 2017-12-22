#include <iostream>

using namespace std;

struct student
{
	char* first_name = new char[64]; // ! // char* buf = new char[255]; cin >> buf; student.first_name = new char[strlen(buf)//(+1)//(?)];
	char* last_name = new char[64];
	char* patronymic_name = new char[64];
	short group_num;
	short grade[5];
	float avg;
	bool otl;
};
struct linlist
{
	student a;
	student* next_ptr = new student;
};

 int add(linlist* head, linlist el_n)
{

	 return 0;
}

 short short_enter(short* buf)
 {
	 cin >> *buf;
	 while (*buf < 0 || *buf > 32676)
	 {
		 cout << "Invalid input, try again:" << "\n";
		 cin >> *buf;
		 if (cin.fail())
		 {
			 cin.clear();
			 while (cin.get() != '\n');
		 }
	 }
	 return *buf;
	 delete buf;
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
		short* b = new short;
		a[i].group_num = short_enter(b);
		delete b;
		float sum = 0;
		for (int j = 0; j < 5; j++)
		{
			cout << "Enter grade" << "\n";
			short* c = new short;
			a[i].grade[j] = short_enter(c);
			if (*a[i].grade < 4)
			{
				a[i].otl = false;
			}
			delete c;
			sum = sum + a[i].grade[j];
			cout << "sum=" << sum << "\n";
		}
		a[i].avg = sum / 5;
		cout << "avg=" << a[i].avg << "\n";
		count = ++count;
		double k;
		cout << "Enter 0 if you want to stop writing, or any positive number if you don't" << "\n";
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
	short* counter = new short;
	*counter = 0;
	for (int i = 0; i < count; i++)
	{
		if (a[i].otl)
		{
			cout << "Student with only 4 and 5 grades:" << "\n";
			cout << a[i].first_name << "\n";
			cout << a[i].last_name << "\n";
			cout << a[i].group_num << "\n";
			*counter++;
		}
	}
	delete counter;
	system ("pause");
}

void list()

{
	linlist* head = nullptr;
	for (int i = 0; i < 10; i++)
	{
		linlist* el = new linlist;
		add(head, *el);
	}
}
int main()
{
	cout << "                   This program works with data structures." << "\n" << "\n" << "\n";
	short prog = 1;
	while (prog)
	{
		short* choose = new short;
		cout<< "Choose what to keep:" << "\n" << "\n"
			<< "1 - Use array as data structure" << "\n"
			<< "2 - Use linked list as data structure" << "\n"
			<< "9 - Exit if you want" << "\n"
			<< "0 - Nothing" << "\n";
		*choose = short_enter(choose);
		switch (*choose)
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