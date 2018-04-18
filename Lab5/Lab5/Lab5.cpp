#include <iostream>
#include <cmath>

using namespace std;

class Figur {
public:
	virtual void create() {}
	virtual void move() {}
	virtual void size() {}
	virtual void output() {}
	virtual void turn() {}

//protected:
//	double x, y, radius, dx, dy, dradius;
};
class circle : public Figur
{
	double x, y, radius, dx, dy, dradius, trn;
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
		cin >> dx;
		cin >> dy;
		x += dx;
		y += dy;
	}
	void size()
	{
		bool flag = false;
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
		
			while (!flag)
			{
				cout << "Величена уменьшения: ";
				cin >> dradius;
				if (dradius > radius)

					cout << "Значение уменьшения слишком большое. Введите повторно" << endl;
				
				else
				{
					radius -= dradius;
					flag = true;
				}
			}
			break;
		default:
			cout << "Неверно выбран пункт меню. Попробуйте снова" << endl;
			size();
			break;
		}
	}
	void turn() 
	{
		cin >> trn;
		cout << "Фигура повёрнута на " << trn << " градусов" << endl;
	}
	void output()
	{
		cout << "Координаты центра: " << x << " " << y << " " << "Радиус: " << radius << endl;
	}
};
class square : public Figur
{
	double x, y, dx, dy, sideLength, dsideLength, trn, x1, x2, y1, y2, halfDiagonal, PI= 3.1415926535;
public:
	void create()
	{
		cout << "Введите координат центра" << endl;
		cout << "По оси X: ";
		cin >> x;
		cout << "По оси Y: ";
		cin >> y;
		cout << "Введите значение стороны" << endl;
		cout << "Размер: ";
		cin >> sideLength;
		halfDiagonal = sqrt((sideLength / 2)*(sideLength / 2) * 2);
		x1 = x - sideLength / 2;
		y1 = y + sideLength / 2;
		x2 = x + sideLength / 2;
		y2 = y - sideLength / 2;
		cout.precision(3);
		cout << "Координаты левого верхнего угла: " << x1  << ", " << y1 << endl;
		cout << "Координаты правого нижнего угла: " << x2  << ", " << y2 << endl;
	}
	void move()
	{
		cin >> dx;
		cin >> dy;
		x += dx;
		y += dy;
	}
	void size()
	{
		int choice;
		bool flag = false;
		cout << "Уменьшить или увеличить размер?" << endl;
		cout << "1) Увеличить" << endl;
		cout << "2) Уменьшить" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "На сколько вы хотите увеличить?" << endl;
			cout << "Величена увеличения: ";
			cin >> dsideLength;
			sideLength += dsideLength;
			break;
		case 2:
			cout << "На сколько вы хотите уменьшить?" << endl;
			while (!flag)
			{
				cout << "Величена уменьшения: ";
				cin >> dsideLength;
				if (dsideLength > sideLength)

					cout << "Значение уменьшения слишком большое. Введите повторно" << endl;

				else
				{
					sideLength -= dsideLength;
					flag = true;
				}
			}
			
			break;
		default:
			cout << "Неверно выбран пункт меню. Попробуйте снова" << endl;
			size();
			break;
		}
	}
	void turn()
	{
		cin >> trn;
		trn = PI*trn/180;
		cout << trn << endl;
		x1 = x + (x1 - x) * cos(trn) - (y1 - y) * sin(trn);
		y1 = y + (y1 - y) * cos(trn) + (x1 - x) * sin(trn);
		x2 = x + (x2 - x) * cos(trn) - (y2 - y) * sin(trn);
		y2 = y + (y2 - y) * cos(trn) + (x2 - x) * sin(trn);

		
		cout << "Координаты левого верхнего угла: " << floor(x1 + 0.55555) << ", " << floor(y1 + 0.55555) << endl;
		cout << "Координаты правого нижнего угла: " << floor(x2 + 0.55555) << ", " << floor(y2 + 0.55555) << endl;
		trn = 0;
	}
	void output()
	{
		cout << "Координаты центра: " << x << " " << y << " " << "Сторона: " << sideLength << endl;

	}
};
class rectangle : public Figur
{
	double x, y, dx, dy, height, width, dheight, dwidth, dperimeter, x1, x2, y1, y2, PI = 3.1415926535, trn, halfDiagonal;
public:
	void create()
	{
		cout << "Введите координат центра" << endl;
		cout << "По оси X: ";
		cin >> x;
		cout << "По оси Y: ";
		cin >> y;
		cout << "Введите ширину" << endl;
		cout << "Ширина: ";
		cin >> width;
		cout << "Введите высоту" << endl;
		cout << "Высота: ";
		cin >> height;
		x1 = x - width / 2;
		x2 = x + width / 2;
		y1 = y + height / 2;
		y2 = y - height / 2;
		halfDiagonal = sqrt(pow(width / 2, 2) + pow(height / 2, 2));
		cout << "Координаты левого верхнего угла: " << x1 << ", " << y1 << endl;
		cout << "Координаты правого нижнего угла: " << x2 << ", " << y2 << endl;
	}
	void move()
	{
		cin >> dx;
		cin >> dy;
		x += dx;
		y += dy;
		x1 += dx;
		x2 += dx;
		y1 += dy;
		y2 += dy;
	}
	void size()
	{
		int choice;
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
		}
	}
	void turn()
	{
		
		/*cout.precision(3);*/

		cin >> trn;
		trn = PI * trn / 180;
		cout << trn << endl;
		/*x1 = x + (x1 - x) * cos(trn) - (y1 - y) * sin(trn);
		y1 = y + (y1 - y) * cos(trn) + (x1 - x) * sin(trn);
		x2 = x + (x2 - x) * cos(trn) - (y2 - y) * sin(trn);
		y2 = y + (y2 - y) * cos(trn) + (x2 - x) * sin(trn);
															*/
		x1 = (x - cos((width / 2) / halfDiagonal - trn) * halfDiagonal);
		y1 = (y - sin((width / 2) / halfDiagonal - trn) * halfDiagonal);
		x2 = (x - cos(cos((width / 2) / halfDiagonal) - trn) * halfDiagonal);
		y2 = (y - sin(cos((width / 2) / halfDiagonal) - trn) * halfDiagonal);

		cout << "Координаты левого верхнего угла: " << floor(x1 + 0.55555) << ", " << floor(y1 + 0.55555) << endl;
		cout << "Координаты правого нижнего угла: " << floor(x2 + 0.55555) << ", " << floor(y2 + 0.55555) << endl;
		trn = 0;
	}
	void output()
	{
		cout << "Координаты центра: " << x << " " << y << " " << "Высота: " << height << " " << "Ширина: " << width << endl;
	}
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
		bool flag = false;
		
		while (!flag)
		{
			cout << "Выберите функцию" << endl << "1)Перемещение" << endl << "2)Изменение размера" << endl << "3)Поворот" << endl << "4)Закончить" << endl;
			cin >> postmenu;
			switch (postmenu)
			{
			case 1:
				cout << "Введите значение координат вектора, на который хотите сдвинуть" << endl;
				cout << "Значение по X и по Y: ";
				F[next]->move();
				F[next]->output();
				break;
			case 2:
				F[next]->size();
				F[next]->output();
				break;
			case 3:
				cout << "Введите значение угла поворота в градусах " << endl;
				F[next]->turn();
				break;
			case 4:
				flag = true;
				break;
			default:
				cout << "Неверный ввод. Попробуйте снова" << endl;
				break;
			}
		}
	}


	system("pause");
	return 0;
}