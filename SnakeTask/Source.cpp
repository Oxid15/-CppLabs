#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool gameover;
const int width = 30, height = 30;
int x, y, fruitX, fruitY, score;
enum direction {STOP, LEFT, RIGHT, UP, DOWN};
direction dir;
void Setup()
{
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}


void Draw()
{
	system ("cls");
	for (int i = 0; i < width; i++)
	{
		cout << "/";
	}
	cout << "\n";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "/";
			if (i == y && j == x)
				cout << "o";
			else
			if (i == fruitY && j == fruitX)
				cout << "$";
			else
					cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < width; i++)
	{
		cout << "/";
	}
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case'a': 
			dir = LEFT;
			break;
		case'd':
			dir = RIGHT;
			break;
		case'w': 
			dir = UP;
			break;
		case's': 
			dir = DOWN;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case(LEFT):
		x--; 
		break;
	case(RIGHT):
		x++;
		break;
	case(UP):
		y--;
		break;
	case(DOWN):
		y++;
		break;
	}
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




