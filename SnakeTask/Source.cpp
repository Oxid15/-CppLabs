#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool gameover;
const int width = 40, height = 20;
int x, y, fruitX, fruitY, score, nTail;
int tailX[100], tailY[100];
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
				{
					bool print = false;
					for (int k = 0; k < nTail; k++)
					{
						if (tailX[k] == j && tailY[k] == i)
						{
							print = true;
							cout << "o";
						}
						if (!print)
							cout << " ";
					}
					cout << " ";
				}

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
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
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
		nTail++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameover = true;
	}

	Sleep(20);
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




