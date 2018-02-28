#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool gameover;

const int width = 20, height = 20;
int x, y, fruitX, fruitY, score;
enum direction {STOP, LEFT, RIGHT, UP, DOWN};
direction dir;
void Setup()
{
	dir = LEFT;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system ("cls");
	cout << "              Snake: The Game" << "\n";
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
	cout << "\n" << "Score: " << score;
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
		case'0':
			gameover = true;
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
	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
	Sleep(100);
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



