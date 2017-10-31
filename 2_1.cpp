/*Дан массив действительных чисел а размерности n (n вводится с клавиатуры).
Сформировать массив b, каждый элемент которого b[i] – среднее арифметическое
элементов массива а, исключая a[i].*/
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	int n;
	cout << "Enter the number of elements in the array" << endl;
	cin >> n;
	float *a = new float[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter an item " << i << " array" << endl;
		cin >> a[i];
	}
	
	float s=0;
	for (int i = 0; i < n; i++)
	{
		s += a[i];
	}
	cout <<"Amount: " << s << endl;
	float *b = new float[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = (s-a[i]) / (n-1) ;
	}
	cout << "The resulting array" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << endl;
	}
	delete[] a;
	delete[] b;
	system("pause");
    return 0;
	
}

