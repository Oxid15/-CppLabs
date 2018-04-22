#include <iostream>
#include<windows.h>
using namespace std;

int labyrinth[20][20] =
{
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1 },
{ 1,0,1,1,1,0,1,1,0,0,1,0,0,0,1,1,0,1,1,1 },
{ 1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,1,0,1,1,1 },
{ 1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,1,0,1,1,1 },
{ 1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1 },
{ 1,0,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1 },
{ 1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1 },
{ 1,1,0,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,1 },
{ 1,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1 },
{ 1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1 },
{ 1,1,1,0,1,0,1,0,1,0,1,1,0,0,0,1,0,1,1,1 },
{ 1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1 },
{ 1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,0,1,1,1 },
{ 1,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,1 },
{ 1,1,0,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1 },
{ 1,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,1,1 },
{ 1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1 },
{ 1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1 },
{ 1,1,1,0,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 }
};

void returnLabyrinth ()
{
	for (int i = 0; i < 20; i++)
	{
		cout << "\n";
		for (int j = 0; j < 20; j++)
		{
			if (labyrinth[i][j] == 1)
				cout << (char)219;
			else
				if (labyrinth[i][j] == 2)
					cout << ".";
				else
					if ((labyrinth[i][j] == 3))
						cout << (char)176;
					else
					cout << " ";
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
  cout << head->c.x << "," << head->c.y << "\n";
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

	if (labyrinth[curr.y - 1][curr.x] == 2)
		return(5);
	if (labyrinth[curr.y][curr.x - 1] == 2)
		return(6);
	if (labyrinth[curr.y][curr.x + 1] == 2)
		return(7);
	if (labyrinth[curr.y + 1][curr.x] == 2)
		return(8);
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


	case(5):
		labyrinth[curr.y][curr.x] = 3;
		stack.pop(stack.head);
		break;
	case(6):
		labyrinth[curr.y][curr.x] = 3;
		stack.pop(stack.head);
		break;
	case(7):
		labyrinth[curr.y][curr.x] = 3;
		stack.pop(stack.head);
		break;
	case(8):
		labyrinth[curr.y][curr.x] = 3;
		stack.pop(stack.head);
		break;
	}
}

void main()
{
	//for (int i = -256; i < 256; i++)
	//{
	//	cout <<  i << "-" << (char)i << "\n";
	//}
	system("pause");
	Stack stack;
	coordinates* curr = new coordinates;
	curr->x = 12; curr->y = 19;
	stack.push(*curr, stack.head);
	delete curr;

	while (check( stack.peek(stack.head) ))
	{
		returnLabyrinth();
		move(check( stack.peek(stack.head) ), stack.peek(stack.head), stack );
		/*system("pause");*/
		system("cls");
		Sleep(10);
	}
	returnLabyrinth();
	cout << "\n";
	while (!(stack.head->prev == nullptr))
	{
		stack.peek(stack.head);
		stack.pop(stack.head);
	}
	system("pause");
}