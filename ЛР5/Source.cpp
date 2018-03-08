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

struct coordinates
{
	int x;
	int y;
};

struct list
{
	coordinates c;
	list* next;
	list* head;
};

class Stack
{
public:	list* node;
 Stack()
{
	 node = new list;
	 node->head = node;
}

 bool isFirst = true;

 void push(coordinates c, list* head)
{
	 
	 if (isFirst)
	 {
		 isFirst = false;
	     node->next = nullptr;
		 head->c.x = c.x;
		 head->c.y = c.y;
	 }
	 else
	 {

	 }
}

  void pop()
{

}

  void peek(list* head)
{
	cout << head->c.x << "," << head->c.y << "\n";
}
};


int main()
{
	Stack Stack1;
	coordinates c0, c1;
	c0.x = 5;
	c0.y = 9;
	Stack1.push(c0, Stack1.node->head);
	Stack1.peek(Stack1.node->head);
	system("pause");
	return 0;
}