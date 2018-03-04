#include <iostream>
#include <conio.h>
 
using namespace std;
bool gameOver;
int x, y, bonusX, bonusY, score, width = 20, height = 20;
char **feild [1000][1000];
int prevXY = feild[0][0];
 void start()
{
	gameOver = false;
	x = width / 2 - 1;
	y = height / 2 - 1;
	bonusX = rand() % width;
	bonusY = rand() % height;
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
	system("pause");
	return 0;
}