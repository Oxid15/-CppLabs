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

class Stack
{
    coordinates arr[60];
    coordinates* head = new coordinates;

public: void stackInit()
{
	head = arr;
	head--;
}

public: void push(coordinates crd)
{
	head++;
	*head = crd;
}

public: void pop()
{

}

public: void peek()
{
	cout << " ";
}
};


int main()
{
	Stack stack1;
	stack1.stackInit();
	coordinates c0, c1;
	c0.x = 5;
	c0.y = 9;
	stack1.push(c0);
	c1.x = 5;
	c1.y = 8;
	stack1.push(c1);
	system("pause");
	return 0;
}