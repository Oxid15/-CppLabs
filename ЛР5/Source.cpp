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
		 head->c.x = c.x;
		 head->c.y = c.y;
	 }
	 else
	 {
		 list *prev = new list;
		 list* newNode = new list;
		 prev = head;
		 head = newNode;
		 head->c.x = c.x;
		 head->c.y = c.y;
		 prev->next = head;
		 head->next = nullptr;
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
	coordinates c0, c1, c2;
	c0.x = 5;
	c0.y = 9;
	c1.x = 5;
	c1.y = 8;
	c2.x = 5;
	c2.y = 7;
	Stack1.push(c0, Stack1.head);
	Stack1.peek(Stack1.head);

	Stack1.push(c1, Stack1.head);
	Stack1.peek(Stack1.head);

	Stack1.push(c2, Stack1.head);
	Stack1.peek(Stack1.head);

	//Stack1.pop();
	//Stack1.peek(Stack1.head);

	system("pause");
	return 0;
}