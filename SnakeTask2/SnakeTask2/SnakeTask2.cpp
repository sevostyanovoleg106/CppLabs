#include<iostream>
#include<conio.h>
#include<windows.h>
#include <fstream>

using namespace std;

class SnakeGame
{
public:
	const int width = 30, height = 20;
	bool gameover, menu;
	int fruitX, fruitY, score;

	SnakeGame()
	{
		menu = false;
		fruitX = rand() % (width - 2);
		fruitY = rand() % height;
		score = 1;
	}
	void ShowScores()
	{
		system("cls");
		ifstream ifile("scores.txt");
		while (!ifile.eof())
		{
			char* buff = new char;
			*buff = ifile.get();
			cout << *buff;
		}
		cout << "\n";
		system("pause");
	}

	void SaveScores()
	{
		system("cls");
		char* name = new char[256];
		cout << "Enter your name: ";
		cin >> name;

		ofstream ofile("scores.txt", ios::app);
		ofile << "\n";
		ofile << score << " ";
		for (int i = 0; i < (strlen(name) + 1); i++)
		{
			ofile << name[i];
		}
		ofile.close();
		delete name;
	}


	void Menu(SnakeGame &game)
	{
		int* chs = new int;
		while (!game.menu)
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
				game.gameover = false;
				game.menu = true;
				break;
			case(2):
				game.ShowScores();
				break;
			case(9):
				game.menu = true;
				game.gameover = true;
				break;
			}
		}
		delete chs;
	}

};


class Snake
{
public:
	Snake()
	{
		dir = STOP;
		nTail = 0;
	}

	int x, y;
	int tailX[100], tailY[100], nTail;
	enum direction { STOP, LEFT, RIGHT, UP, DOWN };
	direction dir;

	void Input(SnakeGame &game)
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
			case'e':
				game.gameover = true;
				game.SaveScores();
				break;
			}
		}
	}

	void Logic(SnakeGame &game, Snake &snake)
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
				game.gameover = true;
				game.SaveScores();
			}
		}

		if (x == game.fruitX && y == game.fruitY)
		{
			game.score++;
			game.fruitX = rand() % (game.width - 2);
			game.fruitY = rand() % game.height;
			nTail++;
		}
		Sleep(100);
	}
	void Draw(SnakeGame &game, Snake &snake)
	{
		system("cls");
		cout << "        Snake: The Game" << "\n";
		for (int i = 0; i < game.width; i++)
		{
			cout << "#";
		}
		cout << "\n";
		for (int i = 0; i < game.height; i++)
		{
			for (int j = 0; j < game.width; j++)
			{
				if (j == 0 || j == game.width - 1)
					cout << "#";
				if (i == snake.y && j == snake.x)
					cout << "0";
				else
					if (i == game.fruitY && j == game.fruitX)
						cout << "F";
					else
					{
						bool print = false;
						for (int k = 0; k < snake.nTail; k++)
						{
							if (snake.tailX[k] == j && snake.tailY[k] == i)
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
		for (int i = 0; i < game.width; i++)
		{
			cout << "#";
		}
		cout << "\n" << "Score: " << game.score << "\n";
		cout << "Press 'e' to save and quit" << "\n";
	}
};



void main()
{
	SnakeGame game;
	Snake snake;
	game.Menu(game);
	snake.x = game.width / 2 - 1;
	snake.y = game.height / 2 - 1;
	while (!game.gameover)
	{
		snake.Draw(game, snake);
		snake.Input(game);
		snake.Logic(game, snake);
	}
}