#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;


enum Сontrol
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
Сontrol cont;


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

class Snake
{
public:

	Snake()
	{
		head = nullptr;
	}
	void add_back(int x, int y)
	{
		if (head == nullptr)
			head = new Tail(x, y);
		else
		{
			Tail *current = this->head;
			while (current->ptrnext != nullptr)
			{
				current = current->ptrnext;
			}
			current->ptrnext = new Tail(x, y);
		}
	}

	class Tail
	{
	public:
		int x;
		int y;
		Tail *ptrnext;
		Tail(int  x, int  y, Tail *ptrnext = nullptr)
		{
			this->x = x;
			this->y = y;
			this->ptrnext = ptrnext;
		}
	};
	Tail *head;
};

class Game {
private:

	int size, delay = 150;
	int score;
	int nTail = 0;
public:
	int height = 20, width = 20;
	bool gameOver;
	int x, y, bonusX, bonusY;

	Snake snk;

	void start()
	{
		system("mode con cols=90 lines=50");
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
		bonusX = 1 + rand() % (width - 2);
		bonusY = 1 + rand() % (height - 2);

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
				{
					field[j][f] = '0';
					snk.add_back(x, y);
					nTail++;
				}
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
		gotoXY(0, height);
		cout << "score: " << endl;
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
			case 'e':
				gameOver = true;
				gotoXY(0, height + 1);
				break;
			}
		}
	}
	int prf_x, prf_y;
	int move()
	{
		Sleep(delay);
		switch (cont)
		{
		case LEFT:
			gotoXY(x, y);
			cout << ' ';
			prf_x = x;
			x--;
			gotoXY(x, y);
			cout << '0';
			break;
		case RIGHT:
			gotoXY(x, y);
			cout << ' ';
			prf_x = x;
			x++;
			gotoXY(x, y);
			cout << '0';
			break;
		case UP:
			gotoXY(x, y);
			cout << ' ';
			prf_y = y;
			y--;
			gotoXY(x, y);
			cout << '0';
			break;
		case DOWN:
			gotoXY(x, y);
			cout << ' ';
			prf_y = y;
			y++;
			gotoXY(x, y);
			cout << '0';
			break;
		}
		if (x >= width - 1 || x <= 0 || y >= height - 1 || y <= 0)
		{
			gameOver = true;
			gotoXY(0, height + 1);
		}
		if (x == bonusX && y == bonusY)
		{
			snk.add_back(x, y);
			nTail++;
			score += 5;
			Beep(500, 50);
			gotoXY(7, height);
			cout << score;
			bonusX = 1 + rand() % (width - 2);
			bonusY = 1 + rand() % (height - 2);
			gotoXY(bonusX, bonusY);
			cout << 'B';

		}
		gotoXY(0, height + 1);
		cout << nTail;
		return x, y;
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