#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
bool gameOver;
int x, y, bonusX, bonusY, score, width = 20, height = 20;
char **feild [1000][1000];
enum Ñontrol
{STOP = 0, LEFT, RIGHT, UP, DOWN};
Ñontrol cont; 
 void start()
{
	 srand(time(0));
	gameOver = false;
	x = width / 2 - 1;
	y = height / 2 - 1;
	bonusX = 1 + rand() % (width - 1);
	bonusY = 1 + rand() % (height - 1);
	score = 0;
	int size;
		cout << "Select a card size: " << endl;
		cout << "1: 20x20" << endl;
		cout << "2: 30x30" << endl;
		cout << "3: 40x40" << endl;
		cin >> size;
	
		switch (size)
		{
		case 1:
			break;
		case 2:
			width = 30;
			height = 30;
			break;
		case 3:
			width = 40;
			height = 40;
			break;
		}
	
}


 void drawSnake(char** field)
 {
	 for (int j = 0; j < height; j++)
	 {
		 for (int f = 0; f < width; f++)
		 {

			 if (j == y && f == x)
				 field[j][f] = '0';
			 if (j == bonusY && f == bonusX)
				 field[j][f] = 'B';
			 
		 }
	 }
	
 }

 void drawField(char** field)
 {
 	system("cls");
 	
 	for (int j = 0; j < height; j++)
 	{
 		for (int f = 0; f < width; f++)
 		{
 
 			for (int k = 1; k < height - 1; k++)
 			{
 				if (f == 0 || f == width - 1)
 
 					field[j][f] = '#';
 				else
 					field[j][f] = ' ';
 			}
 			if (j == height - 1 || j == 0)
 				field[j][f] = '#';
 
 			if (j == y && f == x)
 				field[j][f] = '0';
 			if (j == bonusY && f == bonusX)
 				field[j][f] = 'B';
 		
 		}
 						
 	}	
 			for (int i = 0; i < height; i++)
 			{
 				for (int j = 0; j < height; j++)
 				{
 					cout << field[i][j];
 				}
 				cout << endl;
 			}
 
 
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
 void gotoXY(int column, int line)
 {
	 COORD coord;
	 coord.X = column;
	 coord.Y = line;
	 SetConsoleCursorPosition(
		 GetStdHandle(STD_OUTPUT_HANDLE),
		 coord
	 );
 }
 void moveSnake(int j, int i)
 {
	 gotoXY(j, i);
	 switch (cont)
		 	{
		 	case LEFT:
				putch(' ');
				gotoXY(j + 1, i);
				putch('0');
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
 }
 void game()
 {

 }
 
int main()
{
	char** field = new char*[height];
	for (int i = 0; i < height; i++)
	{
		field[i] = new char[width];
	}
	start();
	drawField(field);
	moveSnake();
	system("pause");
	return 0;
}