// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a;
	cin >> a;
	float n = 0;
	float s = 0;
	while (s <= a)
	{	
		++n;
		s += 1 / n;				
	}
	cout << n-1 << endl;
	system("pause");
	return 0;
	
}

