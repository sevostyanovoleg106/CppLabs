#include <iostream>

using namespace std;

void output(double x, double y)
{
	if (y < 0)
		cout << "z = " << x << y << (char)251 << "-1" << endl;
	else
		cout << "z = " << x << "+" << y << (char)251 << "-1" << endl;
}

class ComplexNumber
{
	double x, y;
public:
	ComplexNumber() {}
	ComplexNumber(const ComplexNumber& copyCN)
	{
		x = copyCN.x;
		y = copyCN.y;
	}
	void inputNumber(char* stroka)
	{
		char* strX = new char[strlen(stroka)];
		char* strY = new char[strlen(stroka)];
		int i = 0;
		bool sign = false;
		for (i; i < strlen(stroka); i++)
		{

			if (stroka[i] == '-' && sign == false)
			{
				strX[i] = '-';
				i++;
				sign = true;
			}
			if (stroka[i] == '+' || stroka[i] == '-')
				break;
			else
				strX[i] = stroka[i];
		}
		int f = 0;
		for (++i; f < strlen(stroka); f++, i++)
		{
			if (stroka[i - 1] == '-')
			{
				strY[f] = '-';
				f++;
			}

			strY[f] = stroka[i];
		}
		x = atof(strX);
		y = atof(strY);
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	const ComplexNumber operator+(const ComplexNumber sum) const
	{
		ComplexNumber result;
		result.x = x + sum.x;
		result.y = y + sum.y;
		return (result);
	}

	const ComplexNumber operator-(const ComplexNumber diff) const
	{
		ComplexNumber result;
		result.x = x - diff.x;
		result.y = y - diff.y;
		return (result);
	}

	const ComplexNumber operator*(const ComplexNumber composition) const
	{
		ComplexNumber result;
		result.x = x * composition.x;
		result.y = y * composition.x;
		return (result);
	}

};
int main()
{
	ComplexNumber z1, z2, zr;

	int menu;
	char* stroka1 = new char[256];
	
	while (1)
	{
		bool flag = false;
		cout << "Enter a complex number in the form x +/- y" << endl;
		char* stroka = new char[256];
		cin >> stroka;
		z1.inputNumber(stroka);
		while (!flag)
		{


			cout << "Select an operation" << endl;
			cout << "1) Addition of complex numbers " << endl << "2) Subtraction of complex numbers " << endl << "3) Multiplication by a number "<<endl<<"4) Back" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1:
				cout << "Enter the number you want to add to" << endl;
				cin >> stroka1;
				z2.inputNumber(stroka1);
				zr = z1 + z2;
				output(zr.get_x(), zr.get_y());
				break;
			case 2:
				cout << "Enter the number you want to take away from" << endl;
				cin >> stroka1;
				z2.inputNumber(stroka1);
				zr = z1 - z2;
				output(zr.get_x(), zr.get_y());
				break;
			case 3:
				cout << "Enter the number you want to take away from" << endl;
				cin >> stroka1;
				z2.inputNumber(stroka1);
				zr = z1 * z2;
				output(zr.get_x(), zr.get_y());
				break;
			case 4:
				flag = true;
				break;
			default:
				cout << "Try again" << endl;
				break;
			}
		}
	}
	return 0;
}
