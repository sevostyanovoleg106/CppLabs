/*ƒан массив размерности n (четное). ¬ случае если элементы массива упор€дочены
по возрастанию, удалить элементы массива через один, начина€ с первого, иначе -
вставить в середину массива элемент, равный первому, Ђнарушающемуї условие
возрастани€. ƒополнительный массив использовать нельз€.*/

#include <iostream>

using namespace std;
 
bool del(int *ar; int &kol; int nm)
{
	for (int nm = 1; nm < kol - 1; nm + 2)
	{
		if (nm > kol || nm < 1)
		{
			cout << "Error" << endl;
			return false;
		}
		for (int x = nm - 1; x < kol - 1; x++)
		{
			ar[x] = ar[x + 1];
		}
		kol--;
		return true;
	}
}

 bool ser()
 
int main()
{ 
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int k=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1])
			k++;
		if (k==n) 
			
	}
	return 0;
}