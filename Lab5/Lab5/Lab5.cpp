#include <iostream>
#include <cmath>

using namespace std;

class Output
{
public:

};

class Figure
{
public:
	virtual void move(double dx, double dy) {}
	virtual bool resize(double delta1, double delta2) { return false; }
	virtual void rotation(double trn) {}
	virtual int identification(){	return identifier;	}
	virtual bool intersection(Figure* f){	return false;	}
protected:
	int identifier;

};
class circle : public Figure
{
	double x, y, radius;
public:

	circle(double x, double y, double radius)
	{
		this->x = x;
		this->y = y;
		this->radius = radius;

		identifier = 1;
	}
	double get_x() { return x; }
	double get_y() { return y; }
	double get_radius() { return radius; }
	circle(const Figure& f)
	{
		circle c = circle(f);
	}

	int identification()
	{
		return this->identifier;
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
	}
	bool resize(double dradius, double delta2)
	{

		double radius1 = radius;
		radius += dradius;
		if (radius <= 0)
		{
			radius = radius1;
			return false;
		}
		else
		{
			return true;
		}
	}


	bool intersection(Figure f)
	{
		circle c = (circle)f;
		double d = sqrt(pow((c.x - this->x), 2) + pow((c.y - this->y), 2));

		if (this->radius + c.radius > d)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	const char* outPut(char* strocka)
	{
		return strocka;
	}


};
class square : public Figure
{
	double x, y, dx, dy, sideLength, dsideLength, trn, halfDiagonal, PI = 3.1415926535;
	double x1, y1, x2, y2;
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
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		identifier = 2;
	}
	double get_x() { return x; }
	double get_y() { return y; }
	double get_sideLength() { return sideLength; }
	double get_x1() { return x1; }
	double get_y1() { return y1; }
	double get_x2() { return x2; }
	double get_y2() { return y2; }
	int identification(int identifier)
	{
		this->identifier = identifier;
		return identifier;
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
	bool resize(double dsideLength)
	{

		double sideLength1 = sideLength;
		sideLength += dsideLength;
		if (sideLength <= 0)
		{
			sideLength = sideLength1;
			return false;
		}
		else
		{
			return true;
		}
	}
	void rotation(double trn)
	{
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
class rectangle : public Figure
{
	double trn, x, y, dx, dy, height, width, dheight, dwidth, dperimeter, PI = 3.1415926535, halfDiagonal, perimeter;
	double  x1, x2, y1, y2;
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
		perimeter = (width + height) * 2;
		identifier = 3;
	}
	double get_x() { return x; }
	double get_y() { return y; }
	double get_height() { return height; }
	double get_width() { return width; }
	double get_x1() { return x1; }
	double get_y1() { return y1; }
	double get_x2() { return x2; }
	double get_y2() { return y2; }
	int identification(int identifier)
	{
		this->identifier = identifier;
		return identifier;
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
	bool resize(double delta1, double delta2)
	{
		double height1 = height;
		double width1 = width;
		height += delta1;
		width += delta2;
		if (height <= 0 || width <= 0)
		{
			height = height1;
			width = width1;
			return false;
		}
		else
		{
			return true;
		}
	}
	void rotation(double trn)
	{
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
	Figure **F = new Figure*[100];
	bool flag1 = false;
	int next = -1;
	circle *c = new circle(0, 0, 0);
	Figure *cir = c;
	square *s = new square(0, 0, 0);
	Figure *sq = s;
	rectangle *r = new rectangle(0, 0, 0, 0);
	Figure *rect = r;
	int x, y, radius, sideLength, dx, dy, height, width, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Output out;

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
				cout << "Введите координат центра" << endl;
				cout << "По оси X: ";
				cin >> x;
				cout << "По оси Y: ";
				cin >> y;
				cout << "Введите значение радиуса" << endl;
				cout << "Размер: ";
				cin >> radius;
				cout << "=============================" << endl;
				*c = circle(x, y, radius);
				cir = c;
				F[next] = cir;
				cout << "Координаты центра: " << c->get_x() << ", " << c->get_y() << endl << "Радиус: " << c->get_radius() << endl;
				flag1 = true;
				break;
			case 2:
				next++;
				cout << "Введите координат центра" << endl;
				cout << "По оси X: ";
				cin >> x;
				cout << "По оси Y: ";
				cin >> y;
				cout << "Введите значение стороны" << endl;
				cout << "Размер: ";
				cin >> sideLength;
				cout << "=============================" << endl;
				*s = square(x, y, sideLength);
				sq = s;
				F[next] = sq;
				cout << "Координаты центра: " << s->get_x() << ", " << s->get_y() << endl << "Сторона: " << s->get_sideLength() << endl;
				cout << "Координата левого верхнего угла: " << s->get_x1() << ", " << s->get_y1() << endl;
				cout << "Координата правого нижнего угла: " << s->get_x2() << ", " << s->get_y2() << endl;
				flag1 = true;
				break;
			case 3:
				next++;
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
				*r = rectangle(x, y, width, height);
				rect = r;
				cout << "Координаты центра: " << r->get_x() << " " << r->get_y() << " " << "Высота: " << r->get_height() << ' ' << "Ширина: " << r->get_width() << endl;
				cout << "Координата левого верхнего угла: " << r->get_x1() << ", " << r->get_y1() << endl;
				cout << "Координата правого нижнего угла: " << r->get_x2() << ", " << r->get_x2() << endl;
				F[next] = rect;
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
				if (F[next]->identification() == 1)
				{
					cout << c->get_x() << ", " << c->get_y() << endl;
				}
				if (F[next]->identification() == 2)
				{
					cout << s->get_x() << ", " << s->get_y() << endl;
				}
				if (F[next]->identification() == 3)
				{
					cout << r->get_x() << ", " << r->get_y() << endl;
				}
				break;
			case 2:
				if (F[next]->identification() == 1)
				{
					cout << "Ведите парамтр изменения размера (радиус)" << endl;
					double delta1;
					bool flag = false;
					while (!flag)
					{
						cin >> delta1;

						if (!F[next]->resize(delta1, 0))
						{
							cout << "Радиус должен быть больше нуля" << endl;
							cout << "Чтобы оставить старые значения введите 0 " << endl;
						}
						else
						{
							cout << "Радиус: " << c->get_radius() << endl;
							flag = true;
						}

					}
				}
				if (F[next]->identification() == 2)
				{
					cout << "Ведите парамтр изменения размера (сторона)" << endl;
					double delta1;
					bool flag = false;
					while (!flag)
					{
						cin >> delta1;

						if (F[next]->resize(delta1, 0))
						{
							cout << "Сторона должна быть больше нуля" << endl;
							cout << "Чтобы оставить старые значения введите 0 " << endl;
						}
						else
						{
							cout << "Сторона: " << s->get_sideLength() << endl;
							flag = true;
						}

					}
				}
				if (F[next]->identification() == 3)
				{

					cout << "Ведите парамтры изменения размера (высота ширина)" << endl;
					double delta1, delta2;
					bool flag = false;
					while (!flag)
					{
						cin >> delta1;
						cin >> delta2;
						if (F[next]->resize(delta1, delta2))
						{
							cout << "Высота и ширина должны быть больше нуля" << endl;
							cout << "Чтобы оставить старые значения введите 0 0" << endl;
						}
						else
						{
							cout << "Высота: " << r->get_height() << ' ' << "Ширина: " << r->get_width() << endl;
							flag = true;
						}

					}
				}

				break;
			case 3:
				double trn;
				cout << "Введите значение угла поворота в градусах " << endl;
				cin >> trn;
				F[next]->rotation(trn);
				if (F[next]->identification() == 1)
					cout << "Совершён поворот на  " << trn << " градусов" << endl;
				if (F[next]->identification() == 2)
				{
					cout << "Координата левого верхнего угла: " << s->get_x1() << ", " << s->get_y1() << endl;
					cout << "Координата правого нижнего угла: " << s->get_x2() << ", " << s->get_y2() << endl;
				}
				if (F[next]->identification() == 3)
				{
					cout << "Координата левого верхнего угла: " << r->get_x1() << ", " << r->get_y1() << endl;
					cout << "Координата правого нижнего угла: " << r->get_x2() << ", " << r->get_x2() << endl;
				}
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

	return 0;
}
