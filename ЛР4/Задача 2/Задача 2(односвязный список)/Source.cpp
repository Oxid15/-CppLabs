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
		double avg;
		int* next = new int;
	};
}