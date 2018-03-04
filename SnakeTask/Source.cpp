#include<iostream>
#include<conio.h>
#include<windows.h>
#include <fstream>

using namespace std;

bool gameover, menu;

const int width = 30, height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100], nTail;
enum direction {STOP, LEFT, RIGHT, UP, DOWN};
direction dir;

void Pause()
{
	system("cls");
	cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";
	cout << "                         P A U S E" << "\n";
	cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";
	system("pause");
}

void ShowScores()
{

}

void SaveScores()
{			   
	system("cls");
	char* name = new char[256];
	cout << "Enter your name: ";
	cin >> name;
	
	ofstream ofile("scores.txt",ios::app);
	ofile << "\n";
	ofile << score << "\n";
	for (int i = 0; i < (strlen(name) + 1); i++)
	{
		ofile << name[i];
	}
	ofile.close();
	delete name;
}

void Run()
{
	menu = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width - 1;
	fruitY = rand() % height - 1;
	score = 1;
	nTail = 0;
}

void Draw()
{
	system ("cls");
	cout << "        Snake: The Game" << "\n";
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
					}
					if (!print)
					cout << " ";
				}

		}
		cout << "\n";
	}
	for (int i = 0; i < width; i++)
	{
		cout << "/";
	}
	cout << "\n" << "Score: " << score << "\n";
	cout << "Press '7' to pause" << "\n";
	cout << "Press '9' to save and quit" << "\n";
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
		case'7':
			Pause();
			break;
		case'9':
			gameover = true;
			SaveScores();
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int	prevY = tailY[0];
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

	for (int i = 0; i < nTail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameover = true;
			SaveScores();
		}
	}

	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
	Sleep(100);
}

void Game()
{
	Run();
	while (!gameover)
	{
		Draw();
		Input();
		Logic();
	}
}

void Menu()
{
	int* chs = new int;
	while (!menu)
	{
		system("cls");
		cout << "............... Snake The Game ..............." << "\n";
		cout << ".................... Menu: ..................." << "\n";
		cout << "\n" << "\n" << "\n";
		cout << "1 - Start the Game" << "\n";
		cout << "2 - Scores" << "\n";
		cout << "9 - Exit the Game" << "\n";
		cin >> *chs;

		switch (*chs)
		{
		case(1):
			gameover = false;
			menu = true;
			Game();
			break;
		case(2):
			break;
		case(9):
			menu = true;
			gameover = true;
			break;
		}
	}
	delete chs;
}

void main()
{
	Menu();
}