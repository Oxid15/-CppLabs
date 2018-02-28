#include<iostream>

using namespace std;

bool gameover;
const int width = 20, height = 20;
int x, y, fruitX, fruitY, score;
enum direction {STOP, LEFT, RIGHT, UP, DOWN};
direction dir;
void Setup()
{
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}


void Draw()
{
	system ("cls");
	for (int i = 0; i < width + 1; i++)
	{
		cout << "#";
	}
	cout << "\n";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < width + 1; i++)
	{
		cout << "#";
	}
}

void Input()
{

}

void Logic()
{

}

void main()
{
	Setup();
	while (!gameover)
	{
		Draw();
		Input();
		Logic();
	}
}




