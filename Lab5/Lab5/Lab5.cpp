#include <iostream>
#include <cmath>

using namespace std;

struct  Output
{
	const double *x, *y, *radius, *trn, *sideLength, *height, *width, *x1, *y1, *x2, *y2;
	
};

class Figur
{
public:

	virtual void create() {}
	virtual void move(double dx, double dy) {}
	virtual bool resize(double delta1, double delta2) { return false; }
	virtual void rotation(double trn) {}
	virtual int identification()
	{
		return identifier;
	}
protected:
	int identifier;

};
class circle : public Figur
{
	double x, y, radius, trn;
public:
	double retRad()
	{
		return this->radius;
	}

	circle(double x, double y, double radius)
	{
		this->x = x;
		this->y = y;
		this->radius = radius;

		identifier = 1;
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
		if (radius <= 0 )
		{
			radius = radius1;
			return false;
		}
		else
		{
			return true;
		}
	}
	void rotation(double trn)
	{
		this->trn = trn;
	}

	Output output()
	{
		Output o;
		o.x = &(this->x);
		o.y = &(this->y);
		o.radius = &(this->radius);
		o.trn = &(this->trn);
		return o;
	}

};
class square : public Figur
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
		identifier = 2;
	}
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
	Output output()
	{
		Output o;
		o.x = &(this->x);
		o.y = &(this->y);
		o.sideLength = &(this->sideLength);
		o.x1 = &(this->x1);
		o.y1 = &(this->y1);
		o.x2 = &(this->x2);
		o.y2 = &(this->y2);
		o.trn = &(this->trn);
		return o;
	}

};
class rectangle : public Figur
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
		perimeter = (width + height)*2;
		identifier = 3;
	}
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
	Output output()
	{
		Output o;
		o.x = &(this->x);
		o.y = &(this->y);
		o.width = &(this->width);
		o.height = &(this->height);
		o.x1 = &(this->x1);
		o.y1 = &(this->y1);
		o.x2 = &(this->x2);
		o.y2 = &(this->y2);
		o.trn = &(this->trn);
		return o;
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
		rectangle *r = new rectangle(0, 0, 0, 0);
		Figur *rect = r;
		int x, y,radius, sideLength, dx, dy, height, width;
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
					*c = circle(x, y, radius);
					cir = c;
					out = c->output();
					cout << "Координаты центра: " << *(out.x) << " " << *(out.y) << " " << "Радиус: " << *(out.radius) << endl;
					F[next] = cir;
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
					*s = square(x, y, sideLength);
					sq = s;
					out = s->output();
					cout << "Координаты центра: " << *(out.x) << " " << *(out.y) << " " << "Сторона: " << *(out.sideLength) << endl;
					cout << "Координата левого верхнего угла: " << *(out.x1) << ", " << *(out.y1) << endl;
					cout << "Координата правого нижнего угла: " << *(out.x2) << ", " << *(out.y2) << endl;
					F[next] = sq;
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
					out = r->output();
					cout << "Координаты центра: " << *(out.x) << " " << *(out.y) << " " << "Высота: " << *(out.height)<< ' ' << "Ширина: " << *(out.width) << endl;
					cout << "Координата левого верхнего угла: " << *(out.x1) << ", " << *(out.y1) << endl;
					cout << "Координата правого нижнего угла: " << *(out.x2) << ", " << *(out.y2) << endl;
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
					cout << *(out.x) << ", " << *(out.y) << endl;
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
								cout << "Радиус: " << *(out.radius)<< endl;
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
								cout << "Сторона: " << *(out.sideLength) << endl;
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
									cout << "Высота: " << *(out.height) << ' ' << "Ширина: " << *(out.width) << endl;
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
								cout << "Совершён поворот на  " << *(out.trn) << " градусов" << endl;
							if (F[next]->identification() == 2 || F[next]->identification() == 3)
							{
								cout << "Координата левого верхнего угла: " << *(out.x1) << ", " << *(out.y1) << endl;
								cout << "Координата правого нижнего угла: " << *(out.x2) << ", " << *(out.y2) << endl;
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
