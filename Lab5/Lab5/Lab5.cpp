#include <iostream>

using namespace std;

class Figur {
public:
	virtual void create()
	{

	}
	virtual void move()
	{

	}
	virtual void size()
	{

	}
	virtual void output()
	{

	}

protected:
	int x, y, radius, dx, dy, dradius;
};
class circle : public Figur
{
public:
	void create()
	{
		cout << "Введите координат центра" << endl;
		cout << "По оси X: ";
		cin >> x;
		cout << "По оси Y: ";
		cin >> y;
		cout << "Введите радиус" << endl;
		cout << "Радиус: ";
		cin >> radius;
	}
	void move()
	{
		
		cout << "Введите значение координат вектора, на который хотите сдвинуть" << endl;
		cout << "Значение по X: ";
		cin >> dx;
		cout << "Значение по Y: ";
		cin >> dy;
		x += dx;
		y += dy;
	}
	void size()
	{
		int choice;
		cout << "Уменьшить или увеличить размер?" << endl;
		cout << "1) Увеличить" << endl;
		cout << "2) Уменьшить" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "На сколько вы хотите увеличить?" << endl;
			cout << "Величена увеличения: ";
			cin >> dradius;
			radius += dradius;
			break;
		case 2:
			cout << "На сколько вы хотите уменьшить?" << endl;
			cout << "Величена уменьшения: ";
			cin >> dradius;
			if (dradius > radius)
			{
				cout << "Значение уменьшения слишком большое. Введите повторно" << endl;
				cout << "Величена уменьшения: ";
				cin >> dradius;
			}
			else
				radius -= dradius;
			break;
		default:
			cout << "Неверно выбран пункт меню. Попробуйте снова" << endl;
			size();
			break;
		}
	}
	void output()
	{
		cout << "Координаты центра: " << x << " " << y << " " << "Радиус: " << radius << endl;
	}
};
class square : public Figur
{
public:
};
class rectangle : public Figur
{
public:
};
int main()
{
	setlocale(0, "");
	Figur **F = new Figur*[100];
	bool flag1 = false;
	int next = -1;
	circle * c = new circle;
	Figur *cir = c;
	square * s = new square;
	Figur *sq = s;
	rectangle * r = new rectangle;
	Figur *rect = r;
	while (1)
	{
		flag1 = false;
		while (!flag1)
		{
			int menu;
			cout << "Выбeрете тип фигуры" << endl;
			cout << "1) Круг" << endl << "2)Квадрат" << endl << "3)Прямоугольник" << endl;
			cin >> menu;
			switch (menu)
			{

			case 1:
				next++;
				cir = c;
				F[next] = cir;
				flag1 = true;
				break;
			case 2:
				next++;
				sq = s;
				F[next] = sq;
				flag1 = true;
				break;
			case 3:
				next++;
				rect = r;
				F[next] = rect;
				flag1 = true;
				break;
			default:
				cout << "Неверный ввод. Попробуйте снова" << endl;
				break;
			}
		}

		F[next]->create();
		int postmenu;
		cout << "Выберите функцию" << endl << "1)Перемещение" << endl << "2)Изменение размера" <<endl<<"3)Закончить"<< endl;
		
		bool flag = false;
		while (!flag)
		{
			cin >> postmenu;
			switch (postmenu)
			{
			case 1:
				F[next]->move();
				F[next]->output();
				cout << "Выберите функцию" << endl << "1)Перемещение" << endl << "2)Изменение размера" << endl << "3)Закончить" << endl;
				break;
			case 2:
				F[next]->size();
				F[next]->output();
				cout << "Выберите функцию" << endl << "1)Перемещение" << endl << "2)Изменение размера" << endl << "3)Закончить" << endl;
				break;
			case 3:
				flag = true;
				break;
			default:
				cout << "Неверный ввод. Попробуйте снова" << endl;
				cout << "Выберите функцию" << endl << "1)Перемещение" << endl << "2)Изменение размера" << endl << "3)Закончить" << endl;
				break;
			}
		}
	}


	system("pause");
	return 0;
}