#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
struct tail {
	char tailX, tailY;
	struct tail* ptr;
	struct tail* ptr;
};

enum Сontrol
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
Сontrol cont;

class Snake {
public:

};

class Game {
public:
	int x, y, bonusX, bonusY;
	bool gameOver;
	int score, height = 10, width = 10;
	int size, delay;
	int gotoXY(int _x, int _y)
	{
		COORD coord;
		coord.X = _x;
		coord.Y = _y;
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);
		return _x, _y;
	}
	
	void start()
	{
		srand(time(0));
		gameOver = false;
		score = 0;
		
		cout << "Select a card size: " << endl;
		cout << "1: 20x20" << endl;
		cout << "2: 30x30" << endl;
		cout << "3: 40x40" << endl;
		cin >> size;

		cout << "Choose the difficulty of the game: " << endl;
		cout << "1: Easy" << endl;
		cout << "2: Medium" << endl;
		cout << "3: Hard" << endl;
		cin >> delay;

		switch (size)
		{
		case 1:
			width = 20;
			height = 20;
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

		switch (delay)
		{
		case 1:
			delay = 150;
			break;
		case 2:
			delay = 100;
			break;
		case 3:
			delay = 80;
			break;
		}
	
	}
	void drawField(char** field)
	{
		system("cls");

		x = width / 2 - 1;
		y = height / 2 - 1;
		bonusX = 1 + rand() % (width - 1);
		bonusY = 1 + rand() % (height - 1);

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
			   gotoXY(0, height);
				break;
			}
		}
	}

	void move()
	{
		
		Sleep(delay);
		switch (cont)
		{
		case LEFT:

			gotoXY(x, y);
			cout << ' ';
			x--;
			gotoXY(x, y);
			cout << '0';
			break;
		case RIGHT:

			gotoXY(x, y);
			cout << ' ';
			x++;
			gotoXY(x, y);
			cout << '0';
			break;
		case UP:

			gotoXY(x, y);
			cout << ' ';
			y--;
			gotoXY(x, y);
			cout << '0';
			break;
		case DOWN:

			gotoXY(x, y);
			cout << ' ';
			y++;
			gotoXY(x, y);
			cout << '0';
			break;

		}
		if (x >= width - 2 || x <= 1 || y >= height - 2 || y <= 1)
		{
			gameOver = true;
			gotoXY(0, height);
		}
	}
};

int main()
{
	Game* game = new Game();
	
	game->start();

	char** field = new char*[game->height];
	for (int i = 0; i < game->height; i++)
	{
		field[i] = new char[game->width];
	}

	game->drawField(field);

	while (!game->gameOver)
	{
		game->buttons();
		game->move();
	}
	system("pause");
	return 0;
}