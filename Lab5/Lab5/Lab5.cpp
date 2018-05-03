#include <iostream>
#include <cmath>

using namespace std;


class Figur {
public:

	virtual void create() {}
	virtual void move(double dx, double dy) {}
	virtual void increase(int chocie1, double delta) {}
	virtual void decrease(int chocie1, double delta) {}
	virtual void output() {}
	virtual void rotation() {}
protected:
	int identifier;

};
class circle : public Figur
{
	double  dradius, dx, dy;
public:
	double x, y, radius, trn ;

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
	double x, y, dx, dy, sideLength, dsideLength, trn, halfDiagonal, PI = 3.1415926535;
public:
	double x1, y1, x2, y2;
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
		x1 = x - sideLength / 2;
		y1 = y + sideLength / 2;
		x2 = x + sideLength / 2;
		y2 = y - sideLength / 2;
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
	double trn, x, y, dx, dy, height, width, dheight, dwidth, dperimeter, PI = 3.1415926535, halfDiagonal, perimeter;

public:
	double  x1, x2, y1, y2;
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
		perimeter = width + height;
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
	void increase(int choice, double delta)
	{

		if (choice == 1)
		{
			height += delta;
		}
		else if (choice == 2)
		{
			width += delta;
		}
		else
		{
			perimeter += delta;
		}
	}
	void decrease(int choice, double delta)
	{
		while (1)
		{
			if (choice == 1)
			{
				if (delta > height)
					height -= delta;
				else
					break;
			}
			else if (choice == 2)
			{
				if (delta > height)
					width -= delta;
				else
					break;
			}
			else
			{
				if (delta > height)
					perimeter -= delta;
				else
					break;

			}
		}
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
		trn = 0;
	}
};

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
	int x, y, radius, sideLength, dx, dy, height, width;
	while (1)
	{
		flag1 = false;
		while (!flag1)
		{
			int menu;
			cout << "Выбeрете тип фигуры" << endl;
			cout << "1) Круг" << endl << "2) Квадрат" << endl << "3) Прямоугольник" << endl;
			cin >> menu;
			switch (menu)
			{

			case 1:
				next++;
				cir = c;
				F[next] = cir;
				cout << "Введите координат центра" << endl;
				cout << "По оси X: ";
				cin >> x;
				cout << "По оси Y: ";
				cin >> y;
				cout << "Введите значение радиуса" << endl;
				cout << "Размер: ";
				cin >> radius;
				circle(x, y, radius);
				cout << "Координаты центра: " << x << " " << y << " " << "Радиус: " << radius << endl;
				
				flag1 = true;
				break;
			case 2:
				next++;
				sq = s;
				F[next] = sq;
				cout << "Введите координат центра" << endl;
				cout << "По оси X: ";
				cin >> x;
				cout << "По оси Y: ";
				cin >> y;
				cout << "Введите значение стороны" << endl;
				cout << "Размер: ";
				cin >> sideLength;
				square(x, y, sideLength);
				cout << "Координаты центра: " << x << " " << y << " " << "Сторона: " << sideLength << endl;
				cout << "Координата левого верхнего угла: " << s->x1 << ", " << s->y1 << endl;
				cout << "Координата правого нижнего угла: " << s->x2 << ", " << s->y2 << endl;
				flag1 = true;
				break;
			case 3:
				next++;
				rect = r;
				F[next] = rect;
				cout << "Введите координат центра" << endl;
				cout << "По оси X: ";
				cin >> x;
				cout << "По оси Y: ";
				cin >> y;
				cout << "Введите значение высоты" << endl;
				cout << "Размер: ";
				cin >> height;
				cout << "Введите значение ширины" << endl;
				cout << "Размер: ";
				cin >> width;
				rectangle(x, y, width, height);
				cout << "Координаты центра: " << x << " " << y << " " << "Высота: " << height<< ' ' << "Ширина: " << width << endl;
				cout << "Координата левого верхнего угла: " << r->x1 << ", " << r->y1 << endl;
				cout << "Координата правого нижнего угла: " << r->x2 << ", " << r->y2 << endl;
				flag1 = true;
				break;
			default:
				cout << "Неверный ввод. Попробуйте снова" << endl;
				break;

			}
		}

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
				cout << "Значение по X : ";
				cin >> dx;
				cout << "Занчение по Y : ";
				cin >> dy;
				F[next]->move(dx, dy);
				cout << x << ", " << y << endl;
				break;
			case 2:
				int choice;
				cout << "Уменьшить или увеличить размер?" << endl;
				cout << "1) Увеличить" << endl;
				cout << "2) Уменьшить" << endl;
				cin >> choice;
				cout << "Увеличить высоту или ширину?" << endl;
				cout << "1)Высоту" << endl << "2)Ширину" << endl << "3)Высоту и ширину" << endl;
				int chocie1;
				cin >> chocie1;

				if (choice == 1)
				{
					cout << "Ведите величену увеличения " << endl;
					double delta;
					cin >> delta;
					F[next]->increase(chocie1, delta);
					cout << "Высота: " << height<<' '<< "Ширина: " << width <<' '<< "Пириметр: " << endl;
				}
				else
				{
					cout << "Ведите величену уменьшения " << endl;
					double delta;
					cin >> delta;
					F[next]->decrease(chocie1, delta);
					cout << "Высота: " << height << ' ' << "Ширина: " << width << ' ' << "Пириметр: " << endl;
				}
				break;
				/*	case 3:
						cout << "Введите значение угла поворота в градусах " << endl;
						cin >> F[next]->trn;
						F[next]->turn();
						F[next]->output();
						break;*/
			case 4:
				flag = true;
				break;
			default:
				cout << "Неверный ввод. Попробуйте снова" << endl;
				break;
			}
		}
	}

	return 0;
}