#include <iostream>
#include <conio.h>
#include <fstream> 
#include <string>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, bonusX, bonusY, score;
int kolTail, n;
int *tailX = new int[n];
int *tailY = new int[n];
enum Сontrol
{STOP = 0, LEFT, RIGHT, UP, DOWN};
Сontrol cont;
void start() 
{

	gameOver = false;
	cont = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	bonusX = rand() % width;
	bonusY = rand() % height;
	score = 0;
	
	
}
void drawField()
{ 
	system("cls");
	for (int i = 0; i < width + 1; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == bonusY && j == bonusX)
				cout << "F";
			else
			{ 
				bool print = false;
				for (int f = 0; f < kolTail; f++)
				{
					if (tailX[f] == j && tailY[f] == i)
					{
						print = true;
						cout << "o";
					}
				}
				if(!print)
				cout << " ";

			}
		}
		cout << endl;
	}
	for (int i = 0; i < width+1; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "SCORE: " << score;

}
void buttons()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			cont = LEFT;
			break;
		case 's':
			cont = DOWN;
			break;
		case 'w':
			cont = UP;
			break;
		case 'd':
			cont = RIGHT;
			break;
		case 'r':
			gameOver = true;
			break;
		}
	}
}
void game()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < kolTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (cont)
	{

	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	
	}
	if (x > width || x<0 || y>height || y < 0)
	{
		gameOver = true;
		for (int i = 0; i < kolTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
				gameOver = true;
		}
	}
	if (x == bonusX && y == bonusY)
	{
		score += 5;
		bonusX = rand() % width;
		bonusY = rand() % height;
		kolTail++;
	}
}

int main()
{ 
	char*  a = new char[10];
	start();
	cout << "Enter your name: ";
	cin >> a;
	char buff[50];
	while (!gameOver)
	{
		drawField();
		buttons();
		game();
	}
	ofstream fin("INPUT.txt");
	fin << "Name: " << a <<" "<< "Score: " << score << endl;
	return 0;
}