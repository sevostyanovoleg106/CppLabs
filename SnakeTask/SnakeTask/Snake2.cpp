//#include<iostream>
//#include <conio.h>
//#include <iomanip>
//#include <vector>
//using namespace std;
//bool gameOver;
//int width = 20;
//int height = 20;
//int x, y, bonusX, bonusY, score;
//int kolTail, n,m;
//int *tailX = new int[n];
//int *tailY = new int[n];
//enum Ñontrol
//{STOP = 0, LEFT, RIGHT, UP, DOWN};
//Ñontrol cont;
//
//
//
//void start()
//{
//	gameOver = false;
//	x = width / 2 - 1;
//	y = height / 2 - 1;
//	bonusX = rand() % width;
//	bonusY = rand() % height;
//	score = 0;
//	int size;
//	cout << "Select a card size: " << endl;
//	cout << "1: 20x20" << endl;
//	cout << "2: 30x30" << endl;
//	cout << "3: 40x40" << endl;
//	cin >> size;
//
//	switch (size)
//	{
//	case 1:
//		n = width * height;
//		break;
//	case 2:
//		width = 30;
//		height = 30;
//		n = width * height;
//		break;
//	case 3:
//		width = 40;
//		height = 40;
//		n = width * height;
//		break;
//	}
//	
//}
//
//void buttons()
//{
//	if (_kbhit)
//		switch (_getch())
//		{
//		case 'a':
//			cont = LEFT;
//			break;
//		case 's':
//			cont = DOWN;
//			break;
//		case 'd':
//			cont = RIGHT;
//			break;
//		case 'w':
//			cont = UP;
//			break;
//		case 'r':
//			gameOver = true;
//			break;
//		}
//}
//
//void drawField()
//{
//	system("cls");
//	char** field = new char*[height];
//	for (int i = 0; i < height; i++)
//	{
//		field[i] = new char[width];
//	}
//	for (int j = 0; j < height; j++)
//	{
//		for (int f = 0; f < width; f++)
//		{
//
//			for (int k = 1; k < height - 1; k++)
//			{
//				if (f == 0 || f == width - 1)
//
//					field[j][f] = '#';
//				else
//					field[j][f] = ' ';
//			}
//			if (j == height - 1 || j == 0)
//				field[j][f] = '#';
//
//			if (j == y && f == x)
//				field[j][f] = '0';
//			if (j == bonusY && f == bonusX)
//				field[j][f] = 'B';
//		
//		}
//						
//	}	
//			for (int i = 0; i < height; i++)
//			{
//				for (int j = 0; j < height; j++)
//				{
//					cout << field[i][j];
//				}
//				cout << endl;
//			}
//
//
//}
//
//
//
//int main()
//{
//	start();
//	drawField();
//	
//	system("pause");
//	
//	return 0;
//}