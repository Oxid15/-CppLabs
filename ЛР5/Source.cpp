#include <iostream>

using namespace std;

int labyrinth[9][9] =
{
{ 1,1,1,1,1,4,1,1,1 },
{ 1,1,1,1,1,0,1,1,1 },
{ 1,1,1,1,1,0,0,0,1 },
{ 1,1,1,1,1,1,1,0,1 },
{ 1,1,1,1,0,1,1,0,1 },
{ 1,1,1,1,0,1,1,0,1 },
{ 1,1,1,1,0,0,0,0,1 },
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
	cout << "\n";
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

  coordinates peek(list* head)
{
//  cout << head->c.x << "," << head->c.y << "\n";
	return (head->c);
}
};

int check(coordinates curr)
{
	if (labyrinth[curr.y][curr.x] == 4)
		return(0);
	if (labyrinth[curr.y - 1][curr.x] == 0 || labyrinth[curr.y - 1][curr.x] == 4)
		return(1);
	if (labyrinth[curr.y][curr.x - 1] == 0 || labyrinth[curr.y][curr.x - 1] == 4)
		return(2);
	if (labyrinth[curr.y][curr.x + 1] == 0 || labyrinth[curr.y][curr.x + 1] == 4)
		return(3);
	if (labyrinth[curr.y + 1][curr.x] == 0 || labyrinth[curr.y + 1][curr.x] == 4)
		return(4);
}

void move(int dir, coordinates curr, Stack &stack)
{
	switch (dir)
	{
	case(1): 
		labyrinth[curr.y][curr.x] = 2;
		curr.y--;
		stack.push(curr, stack.head);
		break;
	case(2):
		labyrinth[curr.y][curr.x] = 2;
		curr.x--;
		stack.push(curr, stack.head);
		break;
	case(3):
		labyrinth[curr.y][curr.x] = 2;
		curr.x++;
		stack.push(curr, stack.head);
		break;
	case(4):
		labyrinth[curr.y][curr.x] = 2;
		curr.y++;
		stack.push(curr, stack.head);
		break;
	}
}

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
	Stack stack;
	coordinates*	curr = new coordinates;
	curr->x = 4; curr->y = 8;
	stack.push(*curr, stack.head);
	delete curr;
	while (check( stack.peek(stack.head) ))
	{
		returnLabyrinth();
		move(check( stack.peek(stack.head) ), stack.peek(stack.head), stack );
		system("pause");
	}
}