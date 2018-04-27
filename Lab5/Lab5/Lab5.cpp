#include <iostream>
#include <cmath>

using namespace std;


class Figur {
public:

	virtual void create() {}
	virtual void move(double dx, double dy) {}
	virtual void size() {}
	virtual void output() {}
	virtual void rotation() {}
protected:
	int identifier;

};
class circle : public Figur
{
	double x, y, radius, trn, dradius, dx, dy;
public:


	circle(double x, double y, double radius)
	{
		this->x = x;
		this->y = y;
		this->radius = radius;

		identifier = 1;
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
	}
	void size(int choice, double dradius)
	{
		bool flag = false;
		if (choice == 1)
		{
			radius += dradius;
		}
		else
		{
			while (!flag)
			{
				if (dradius > radius)

					flag = false;
		
				else
				{
					radius -= dradius;
					flag = true;
				}
			}
		}
		
		
	}
	void rotation(double trn)
	{
		this->trn = trn;
	}

	~circle() {}

};
class square : public Figur
{
	double x, y, dx, dy, sideLength, dsideLength, trn, x1, x2, y1, y2, halfDiagonal, PI = 3.1415926535;
public:

	square(double x, double y, double sideLength)
	{
		this->x = x;
		this->y = y;
		this->sideLength = sideLength;
		halfDiagonal = sqrt((sideLength / 2)*(sideLength / 2) * 2);
		x1 = x - sideLength / 2;
		y1 = y + sideLength / 2;
		x2 = x + sideLength / 2;
		y2 = y - sideLength / 2;
		identifier = 2;
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
	}
	void size(int chocie, double dsideLength)
	{
		bool flag = false;
		if (chocie == 1)
		{
			sideLength += dsideLength;
		}
		else
		{
			while (!flag)
			{
				if (dsideLength > sideLength)

					flag = false;

				else
				{
					sideLength -= dsideLength;
					flag = true;
				}
			}
		}
		
	}
	void rotation(double trn)
	{
		this->trn = trn;
		trn = PI * trn / 180;
		x1 = x + (x1 - x) * cos(trn) - (y1 - y) * sin(trn);
		y1 = y + (y1 - y) * cos(trn) + (x1 - x) * sin(trn);
		x2 = x + (x2 - x) * cos(trn) - (y2 - y) * sin(trn);
		y2 = y + (y2 - y) * cos(trn) + (x2 - x) * sin(trn);

		trn = 0;
	}

};
class rectangle : public Figur
{
	double trn, x, y, dx, dy, height, width, dheight, dwidth, dperimeter, x1, x2, y1, y2, PI = 3.1415926535, halfDiagonal;

public:
	rectangle(double x, double y, double width, double height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		x1 = x - width / 2;
		x2 = x + width / 2;
		y1 = y + height / 2;
		y2 = y - height / 2;
		halfDiagonal = sqrt(pow(width / 2, 2) + pow(height / 2, 2));
		identifier = 3;
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
		x1 += dx;
		x2 += dx;
		y1 += dy;
		y2 += dy;
	}
	void size()
	{

		/*int choice;
		cout << "Уменьшить или увеличить размер?" << endl;
		cout << "1) Увеличить" << endl;
		cout << "2) Уменьшить" << endl;
		cin >> choice;
		bool flag = false;
		switch (choice)
		{
		case 1:
			cout << "Увеличить высоту или ширину?" << endl;
			cout << "1)Высоту" << endl << "2)Ширину" << endl << "3)Высоту и ширину" << endl;
			int chocie1;
			cin >> chocie1;

			while (!flag)
			{
				switch (chocie1)
				{
				case 1:
					cout << "На сколько вы хотите увеличить?" << endl;
					cout << "Величена увеличения: ";
					cin >> dheight;
					height += dheight;
					flag = true;
					break;

				case 2:
					cout << "На сколько вы хотите увеличить?" << endl;
					cout << "Величена увеличения: ";
					cin >> dwidth;
					width += dwidth;
					flag = true;
					break;
				case 3:
					cout << "На сколько вы хотите увеличить?" << endl;
					cout << "Величена увеличения высоты: ";
					cin >> dperimeter;
					height += dperimeter;
					width += dperimeter;
					flag = true;
					break;
				default:
					cout << "Неверно выбран пункт меню. Попробуйте снова" << endl;
					break;
				}
			}
			break;
		case 2:
			cout << "Уменьшить высоту или ширину?" << endl;
			cout << "1)Высоту" << endl << "2)Ширину" << endl << "3)Высоту и ширину" << endl;
			int chocie;
			cin >> chocie;
			while (!flag)
			{
				bool flag1 = false;
				switch (chocie)
				{
				case 1:
					cout << "На сколько вы хотите уменьшить?" << endl;
					while (!flag1)
					{
						cout << "Величена уменьшения: ";
						cin >> dheight;
						if (dheight > height)
						{
							cout << "Значение уменьшения слишком большое. Введите повторно" << endl;

						}
						else
						{
							height -= dheight;
							flag1 = true;
							flag = true;
						}
					}
					break;
				case 2:
				overwriting2:
					cout << "На сколько вы хотите уменьшенить?" << endl;
					while (!flag1)
					{
						cout << "Величена уменьшения: ";
						cin >> dwidth;
						if (dwidth > width)
						{
							cout << "Значение уменьшения слишком большое. Введите повторно" << endl;

						}
						else
						{
							width -= dwidth;
							flag1 = true;
							flag = true;
						}
					}
					break;
				case 3:
					cout << "На сколько вы хотите уменьшить?" << endl;
					while (!flag1)
					{
						cout << "Величена уменьшения: ";
						cin >> dperimeter;
						if (dperimeter > width || dperimeter >height)
						{
							cout << "Значение уменьшения слишком большое. Введите повторно" << endl;

						}
						else
						{
							height -= dperimeter;
							width -= dperimeter;
							flag1 = true;
							flag = true;
						}
					}
					break;
				default:
					cout << "Неверно выбран пункт меню. Попробуйте снова" << endl;
					break;
				}
			}
			break;
		default:
			cout << "Неверно выбран пункт меню. Попробуйте снова" << endl;
			size();
			break;
		}*/
	}
	void rotation()
	{

		cout.precision(5);

		cin >> trn;

		double x_1 = x1, y_1 = y1, x_2 = x2, y_2 = y2;

		while (1)
		{
			if ((int)trn % 180 == 0)
			{
				trn = PI * trn / 180;
				x1 = x + (x_1 - x) * cos(trn);
				y1 = y + (y_1 - y) * cos(trn);
				x2 = x + (x_2 - x) * cos(trn);
				y2 = y + (y_2 - y) * cos(trn);
				break;
			}

			else if ((int)trn % 90 == 0)
			{
				trn = PI * trn / 180;
				x1 = x - (y_1 - y) * sin(trn);
				y1 = y + (x_1 - x) * sin(trn);
				x2 = x - (y_2 - y) * sin(trn);
				y2 = y + (x_2 - x) * sin(trn);
				break;
			}

			else
			{
				trn = PI * trn / 180;
				x1 = x + (x_1 - x) * cos(trn) - (y_1 - y) * sin(trn);
				y1 = y + (y_1 - y) * cos(trn) + (x_1 - x) * sin(trn);

				x2 = x + (x_2 - x) * cos(trn) - (y_2 - y) * sin(trn);
				y2 = y + (y_2 - y) * cos(trn) + (x_2 - x) * sin(trn);
				break;
			}
		}
		x_1 = x1;
		x_2 = x2;
		y_1 = y1;
		x_2 = x2;
		cout << trn << endl;
		cout << cos(trn) << ", " << sin(PI) << endl;

		cout << "Координаты левого верхнего угла: " << x1 << ", " << y1 << endl;
		cout << "Координаты правого нижнего угла: " << x2 << ", " << y2 << endl;

		trn = 0;
	}
	void intersection()
	{

	}
	void output()
	{
		cout << "Координаты центра: " << x << " " << y << " " << "Высота: " << height << " " << "Ширина: " << width << endl;
	}
};

/*void output()
{
cout << "Координаты центра: " << x << " " << y << " " << "Сторона: " << sideLength << endl;
cout << "Координаты левого верхнего угла: " << x1 << ", " << y1 << endl;
cout << "Координаты правого нижнего угла: " << x2 << ", " << y2 << endl;
}*/
int main()
{
	setlocale(0, "");
	Figur **F = new Figur*[100];
	bool flag1 = false;
	int next = -1;
	circle *c = new circle(0, 0, 0);
	Figur *cir = c;
	square *s = new square(0, 0, 0);
	Figur *sq = s;
	rectangle * r = new rectangle(0, 0, 0, 0);
	Figur *rect = r;

	//while (1)
	//{
	//	flag1 = false;
	//	while (!flag1)
	//	{
	//		int menu;
	//		cout << "Выбeрете тип фигуры" << endl;
	//		cout << "1) Круг" << endl << "2) Квадрат" << endl << "3) Прямоугольник" << endl;
	//		cin >> menu;
	//		switch (menu)
	//		{

	//		case 1:
	//			next++;
	//			cir = c;
	//			F[next] = cir;
	//			cout << "Введите координат центра" << endl;
	//			cout << "По оси X: ";
	//			cin >> c->x;
	//			cout << "По оси Y: ";
	//			cin >> c->y;
	//			cout << "Введите значение радиуса" << endl;
	//			cout << "Размер: ";
	//			cin >> c->radius;
	//			circle(c->x, c->y, c->radius);
	//			cout << "Координаты центра: " << c->x << " " << c->y << " " << "Радиус: " << c->radius << endl;
	//			flag1 = true;
	//			break;
	//		case 2:
	//			next++;
	//			sq = s;
	//			F[next] = sq;
	//			cout << "Введите координат центра" << endl;
	//			cout << "По оси X: ";
	//			cin >> s->x;
	//			cout << "По оси Y: ";
	//			cin >> s->y;
	//			cout << "Введите значение стороны" << endl;
	//			cout << "Размер: ";
	//			cin >> s->sideLength;
	//			square(s->x, s->y, s->sideLength);
	//			cout << "Координаты центра: " << s->x << " " << s->y << " " << "Сторона: " << s->sideLength << endl;
	//			cout << "Координаты левого верхнего угла: " << s->x1 << ", " << s->y1 << endl;
	//			cout << "Координаты правого нижнего угла: " << s->x2 << ", " << s->y2 << endl;
	//			flag1 = true;
	//			break;
	//		case 3:
	//			next++;
	//			rect = r;
	//			F[next] = rect;
	//			F[next]->output();
	//			flag1 = true;
	//			break;
	//		default:
	//			cout << "Неверный ввод. Попробуйте снова" << endl;
	//			break;
	//		}
	//	}

	//	int postmenu;
	//	bool flag = false;

	//	while (!flag)
	//	{
	//		cout << "Выберите функцию" << endl << "1)Перемещение" << endl << "2)Изменение размера" << endl << "3)Поворот" << endl << "4)Закончить" << endl;
	//		cin >> postmenu;
	//		switch (postmenu)
	//		{
	//		case 1:
	//			cout << "Введите значение координат вектора, на который хотите сдвинуть" << endl;
	//			cout << "Значение по X и по Y: ";

	//			cin >> F[next]->dx;
	//			cin >> F[next]->dy;
	//			F[next]->move(F[next]->dx, F[next]->dy);
	//			F[next]->output();
	//			break;
	//		case 2:
	//			F[next]->size();
	//			F[next]->output();
	//			break;
	//		case 3:
	//			cout << "Введите значение угла поворота в градусах " << endl;
	//			cin >> F[next]->trn;
	//			F[next]->turn();
	//			F[next]->output();
	//			break;
	//		case 4:
	//			flag = true;
	//			break;
	//		default:
	//			cout << "Неверный ввод. Попробуйте снова" << endl;
	//			break;
	//		}
	//	}
	//}

	//system("pause");
	return 0;
}