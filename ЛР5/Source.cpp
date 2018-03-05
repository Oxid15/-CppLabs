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

    public: void push(coordinates crd)
	{	
		head = arr;
	    *head = crd;
		head ++;
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
	coordinates c0;
	c0.x = 5;
	c0.y = 9;
	stack1.push(c0);

	system("pause");
	return 0;
}