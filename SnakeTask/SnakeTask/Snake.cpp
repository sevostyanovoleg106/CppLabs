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

class Snake {
public:
};

class Game {
public:
	bool gameOver;
	int score, height, width;
	Coord* _coord = new Coord(0, 0);
	_coord->gotoXY(width / 2 - 1, height / 2 - 1);

	Coord* coord_bonus = coord_bonus->gotoXY(1 + rand() % (width - 1), 1 + rand() % (height - 1));
	void start(int size, int delay)
	{
		srand(time(0));
		gameOver = false;
		score = 0;
		int size;

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


		cout << "Choose the difficulty of the game: " << endl;
		cout << "1: Easy" << endl;
		cout << "2: Medium" << endl;
		cout << "3: Hard" << endl;
		cin >> delay;

		switch (delay)
		{
		case 1:
			delay = 150;
			break;
		case 2:
			delay = 100;
			break;
		case 3:
			delay = 70;
			break;
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

				if (j == _coord->y && f == _coord->x)
					field[j][f] = '0';
				if (j == coord_bonus->y && f == coord_bonus->x)
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
				_coord = _coord->gotoXY(0, height);
				gameOver = true;
				break;
			}
		}
	}

	void move()
	{
		// Sleep(delay);
		switch (cont)
		{
		case LEFT:

			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << ' ';
			_coord->x--;
			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << '0';
			break;
		case RIGHT:

			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << ' ';
			_coord->x++;
			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << '0';
			break;
		case UP:

			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << ' ';
			_coord->y--;
			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << '0';
			break;
		case DOWN:

			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << ' ';
			_coord->y++;
			_coord = _coord->gotoXY(_coord->x, _coord->y);
			cout << '0';
			break;

		}
		if (_coord->x >= width - 2 || _coord->x <= 1 || _coord->y >= height - 2 || _coord->y <= 1)
		{
			gameOver = true;
			_coord->gotoXY(0, height);
		}
	}
};
class Coord {
public:
	int x;
	int y;

	Coord(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}

	void gotoXY(int _x, int _y)
	{
		COORD coord;
		coord.X = _x;
		coord.Y = _y;
		
		//Coord* c = new Coord(_x, _y);

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);

		/*return c;*/
	}	
};
int main()
{
	Game* game = new Game();
	int size, delay;
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

	game->start(size, delay);

	char** field = new char*[game->height];
	for (int i = 0; i < game->height; i++)
	{
		field[i] = new char[game->width];
	}

	game->drawField(field);

	while (!game->gameOver)
	{
		game->buttons();
		Sleep(delay);
		game->move();
	}

	return 0;
}