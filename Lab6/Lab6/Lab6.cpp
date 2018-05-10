#include <iostream>

using namespace std;


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
	void inputNumber(char* stroka, double& x, double& y)
	{
		char* strX = new char[strlen(stroka)];
		char* strY = new char[strlen(stroka)];
		int i = 0;
		for ( i; i < strlen(stroka); i++)
		{
			if (stroka[i] == '+' || stroka[i] == '-')
				break;
			else
				strX[i] = stroka[i];
				

		}
		int f = 0;
		for (++i; f < strlen(stroka); f++,i++)
		{
			strY[f] = stroka[i];
		}
		x = atof(strX);
		y = atof(strY);
	}
	void outputNumber(char* stroka, double& x, double& y)
	{
		bool sign;
		for (int i = 0; i < strlen(stroka); i++)
		{
			if (stroka[i] == '+')
			{
				sign = true;
				break;
			}
			else
				sign = false;
		}
		if (sign == true)
			cout << "z = " << x << '+' << y << '!' << "-1" << endl;
		else
			cout << "z = " << x << '-' << y << '!' << "-1" << endl;
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
		result.y = y * composition.y;
		return (result);
	}

};
int main()
{
	setlocale(0, "");
	ComplexNumber z1,z2,zr;
	cout << "Введите комплексное число" << endl;
	char* stroka = new char[256];
	cin >> stroka;
	double x, y;
	z1.inputNumber(stroka,x,y);
	int menu;
	char* stroka1 = new char[256];
	while (1)
	{
		cout << "Выберите операцию" << endl;
		cout << "1) Сложение комплексных чисел " << endl << "2) Вычитание комплексных чисел " << endl << "3) Умножение на число " << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Введите число, с которым хотите сложить" << endl;
			cin >> stroka1;
			z2.inputNumber(stroka1, x, y);
			zr = z1 + z2;
			zr.outputNumber(stroka1, x, y);
			break;
		case 2:
			zr = z1 - z2;
			z1.outputNumber(stroka, x, y);
			break;
		case 3:
			zr = z1 + z2;
			z1.outputNumber(stroka, x, y);
			break;
		default:
			break;
		}
	}
	return 0;
}
