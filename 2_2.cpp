/*Дан массив целых чисел размерности n. Изменить этот массив так, что все
элементы, модуль которых не равен максимальному элементу массива, заменить
нулем, а равные – единицей.*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Enter the dimension of the array " << endl;
	cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "enter the element  " << i << " array" << endl;
		cin >> a[i];
	}
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (m < a[i])
			m = a[i];

	}
	cout << "maximum value: " << m << endl;
	for (int i = 0; i < n; i++)
	{
		if (m == abs(a[i]))
			a[i] = 1;
		else a[i] = 0;

	}
	for (int i=0; i < n; i++)
	{
		cout << "Modified array element " << i << endl;
		cout << a[i]<<endl;
	}
	system("pause");
	return 0;
}