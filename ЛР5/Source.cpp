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

}

 bool isHead = true;

 void push(coordinates crd, list* head)
{
	 
	 if (isHead)
	 {
		 isHead = false;
		 node = new list;
	     node->next = nullptr;
	     node->head = node;
	 }
	 head->c.x = crd.x;
	 head->c.y = crd.y;
}

  void pop()
{

}

  void peek(list* head)
{
	cout << head->c.x << "," << head->c.y ;
}
};


int main()
{
	Stack stack1;
	coordinates c0, c1;
	c0.x = 5;
	c0.y = 9;
	stack1.push(c0,stack1.node->head);
	stack1.peek(stack1.node->head);
	system("pause");
	return 0;
}