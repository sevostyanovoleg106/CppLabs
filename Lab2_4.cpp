/*Дана матрица размерности nxm.Получить одномерный массив a[m], хранящий
сумму элементов соответствующих столбцов матрицы, являющихся простыми
числами.*/
 #include <iostream> 

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int** Mas = new int *[n];
	for (int i = 0; i < n; ++i)
		Mas[i] = new int[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Mas[i][j];
		}
	}

	int s[] = {0};
	
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			s[j] += Mas[i][j];
		}
	
	}
	for (int j = 0; j < m; j++)
	{
		cout << s[j] << endl;
	}

 
	return(0);
}
