/*Дан массив размерности n (четное). В случае если элементы массива упорядочены
по возрастанию, удалить элементы массива через один, начиная с первого, иначе -
вставить в середину массива элемент, равный первому, «нарушающему» условие
возрастания. Дополнительный массив использовать нельзя.(неверно)*/

#include <iostream>

using namespace std;
 
bool del( int &kol; int nm; int *ar)
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
 
bool ser(int &kol; int x; int *ar)
{  
	int t;
	for (int x = 0; x < kol ; x++)
	{
		if (ar[x] > ar[x + 1])
			t = x;
			break;
	}
	kol++;
	for (int x = kol; x != kol/2 ; x--)
	{
		ar[x] = ar[x + 1];
	}
	ar[kol / 2] = ar[t];
 }

 
int main()
{ 
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int k=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1])
			k++;
		{
			if (k == n)
				del(i; n; a);
			else
				ser(n; i; a);
		}
	}
	return 0;
}
