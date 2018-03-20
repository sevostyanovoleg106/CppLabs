//#include <iostream>
//#include <conio.h>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//bool gameOver;
//int x, y, bonusX, bonusY, score, width = 0, height = 0, delay = 0;
//unsigned char **feild [10000][10000];
//char tailXY[1000][1000];
//enum Ñontrol
//{STOP = 0, LEFT, RIGHT, UP, DOWN};
//Ñontrol cont; 
// void start()
//{
//	 srand(time(0));
//	gameOver = false;
//	score = 0;
//	int size;
//		cout << "Select a card size: " << endl;
//		cout << "1: 20x20" << endl;
//		cout << "2: 30x30" << endl;
//		cout << "3: 40x40" << endl;
//		cin >> size;
//	
//		switch (size)
//		{
//		case 1:
//			width = 20;
//			height = 20;
//			break;
//		case 2:
//			width = 30;
//			height = 30;
//			break;
//		case 3:
//			width = 40;
//			height = 40;
//			break;
//		}
//
//		x = width / 2 - 1;
//		y = height / 2 - 1;
//		bonusX = 1 + rand() % (width - 1);
//		bonusY = 1 + rand() % (height - 1);
//		cout << "Choose the difficulty of the game: " << endl;
//		cout << "1: Easy" << endl;
//		cout << "2: Medium" << endl;
//		cout << "3: Hard" << endl;
//		cin >> delay;
//
//		switch (delay)
//		{
//		case 1:
//			delay = 150;
//			break;
//		case 2:
//			delay = 100;
//			break;
//		case 3:
//			delay = 70;
//			break;
//		}
//}
//
//
// 
//
// void drawField(char** field)
// {
// 	system("cls");
// 	
// 	for (int j = 0; j < height; j++)
// 	{
// 		for (int f = 0; f < width; f++)
// 		{
//			
// 			for (int k = 1; k < height - 1; k++)
// 			{
// 				if (f == 0 || f == width - 1)
// 
// 					field[j][f] = '#';
// 				else
// 					field[j][f] = ' ';
// 			}
// 			if (j == height - 1 || j == 0)
// 				field[j][f] = '#';
// 
// 			if (j == y && f == x)
// 				field[j][f] = '0';
// 			if (j == bonusY && f == bonusX)
// 				field[j][f] = 'B';
// 		
// 		}
// 						
// 	}	
// 			for (int i = 0; i < height; i++)
// 			{
// 				for (int j = 0; j < height; j++)
// 				{
// 					cout << field[i][j];
// 				}
// 				cout << endl;
// 			}
// 
// 
// }
// void gotoXY(int column, int line)
// {
//	 COORD coord;
//	 coord.X = column;
//	 coord.Y = line;
//	 SetConsoleCursorPosition(
//		 GetStdHandle(STD_OUTPUT_HANDLE),
//		 coord
//	 );
// }
// void buttons()
// {
// 	if (_kbhit())
// 	{
// 		switch (_getch())
// 		{
// 		case 'a':
// 			cont = LEFT;
// 			break;
// 		case 's':
// 			cont = DOWN;
// 			break;
// 		case 'w':
// 			cont = UP;
// 			break;
// 		case 'd':
// 			cont = RIGHT;
// 			break;
// 		case 'r':
//			gotoXY(0, height);
// 			gameOver = true;
// 			break;
// 		}
// 	}
// }
//
// void move()
// {
//	// Sleep(delay);
//	 switch (cont)
//	 {
//	 case LEFT:
//		 
//		 gotoXY(x, y);
//		 cout << ' ';
//		 x--;
//		 gotoXY(x, y);
//		 cout << '0';
//		 break;
//	 case RIGHT:
//		
//		 gotoXY(x, y);
//		 cout << ' ';
//		 x++;
//		 gotoXY(x , y);
//		 cout << '0';
//		 break;
//	 case UP:
//		 
//		 gotoXY(x, y);
//		 cout << ' ';
//		 y--;
//		 gotoXY(x, y );
//		 cout << '0';
//		 break;
//	 case DOWN:
//		 
//		 gotoXY(x, y);
//		 cout << ' ';
//		 y++;
//		 gotoXY(x, y );
//		 cout << '0';
//		 break;
//
//	 }
//	 if (x >= width-2 || x<=1 || y>=height-2 || y <= 1)
//	 {
//		 	gameOver = true;
//			gotoXY(0, height );
//     }
// }
// 
//int main()
//{
//	start();
//	char** field = new char*[height];
//	for (int i = 0; i < height; i++)
//	{
//		field[i] = new char[width];
//	}
//	
//	drawField(field);
//	while (!gameOver)
//	{
//		buttons();
//		Sleep(delay);
//		move();
//	}
//	system("pause");
//	return 0;
//}