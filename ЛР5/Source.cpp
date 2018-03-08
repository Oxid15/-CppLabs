#include <iostream>

using namespace std;

int labyrinth[9][9] =
{
{ 1,1,1,1,1,0,1,1,1 },
{ 1,1,1,1,1,0,1,1,1 },
{ 1,1,0,0,0,0,1,1,1 },
{ 1,1,0,1,1,1,1,1,1 },
{ 1,1,0,1,1,1,1,1,1 },
{ 1,1,0,1,1,1,1,1,1 },
{ 1,1,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,1,1,1,1 },
{ 1,1,1,1,0,1,1,1,1 }
};


void returnLabyrinth ()
{
	for (int i = 0; i < 9; i++)
	{
		cout << "\n";
		for (int j = 0; j < 9; j++)
		{
			cout << labyrinth[i][j];
	    }
    }
	system("pause");
}

struct coordinates
{
	int x;
	int y;
};

struct list
{
	coordinates c;
	list* next;
	list* prev;
};

class Stack
{
public:	list* node;
		list* head;
 Stack()
{
	 node = new list;
	 head = node;
}

 bool isFirst = true;

 void push(coordinates c, list* &head)
{
	 
	 if (isFirst)
	 {
		 isFirst = false;
	     node->next = nullptr;
		 node->prev = nullptr;
		 head->c.x = c.x;
		 head->c.y = c.y;
	 }
	 else
	 {
		 list* newNode = new list;
		 newNode->prev = head;
		 head = newNode;
		 head->c.x = c.x;
		 head->c.y = c.y;
		 newNode->prev->next = head;
		 head->next = nullptr;
	 }
}

  void pop(list* &head)
{
	 head = head->prev;
	 delete (head->next);
	 head->next = nullptr;
}

  void peek(list* head)
{
	cout << head->c.x << "," << head->c.y << "\n";
}
};

void menu()
{
	bool menuOff = false;
	while (!menuOff)
	{
		int choice;
		cout << "1 - to see labyrinth" << "\n";
		cout << "0 - to exit" << "\n";
		cin >> choice;

		switch (choice)
		{
		case (1):
			returnLabyrinth();
			system("cls");
			break;
		case (0):
			menuOff = true;
			break;
		}
	}
}

void main()
{
	menu();
}