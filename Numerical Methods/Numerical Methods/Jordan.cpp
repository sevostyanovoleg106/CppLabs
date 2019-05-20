//#include <math.h>
//#include <stdio.h>
//#include <malloc.h>
//#include <iostream>
//#include <conio.h>
//#pragma warning(disable : 4996)
//
//using namespace std;
//
//int Slau(int n, double** a, double* b, double* x)
//{
//	double **A, tmp;
//	int i, j, k;
//
//	A = (double**)malloc(n * sizeof(double*));
//	for (i = 0; i < n; i++)
//		A[i] = (double*)malloc((n + 1) * sizeof(double));
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			A[i][j] = a[i][j];
//			A[i][n] = b[i];
//		}
//	}
//		for (int f = 0; f < n; f++)
//		{
//			for (int g = 0; g < n + 1; g++)
//			{
//				cout << A[f][g] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//		for (i = 0; i < n; i++)
//		{
//			tmp = A[i][i];
//			if (fabs(tmp) < 0.0000001)
//			{
//				for (i = 0; i < n; i++)
//					free(A[i]);
//				free(A);
//				return 0;
//			}
//		}
//			for (j =  0; j <= n + 1 ; j++)
//			{
//				A[i][j] /= tmp;
//			}
//		
//		for(int f = 0; f < n; f++)
//		{
//			for (int g = 0; g < n + 1; g++)
//			{
//				cout << A[f][g] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//		for (j = 0; j < n; j++)
//		{
//			if (i == j)
//				continue;
//			tmp = A[j][i];
//			for (k = i; k <= n; k++)
//			{
//				A[j][k] -= tmp * A[i][k];
//			}
//		}
//		for (int f = 0; f < n; f++)
//		{
//			for (int g = 0; g < n + 1; g++)
//			{
//				cout << A[f][g] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//	for (i = 0; i < n; i++)
//		x[i] = A[i][n];
//	for (i = 0; i < n; i++)
//		free(A[i]);
//	free(A);
//
//	/*for (int g = 0; g < n + 1; g++)
//	{
//		cout << x[g] << " ";
//	}
//	cout << endl;*/
//
//	return 1;
//}
//
//int main()
//{
//	double **A, *b, *x;
//	int i, j, n;
//	scanf("%d", &n);
//	A = (double**)malloc(n * sizeof(double*));
//	b = (double*)malloc(n * sizeof(double));
//	x = (double*)malloc(n * sizeof(double));
//	for (i = 0; i < n; i++)
//		A[i] = (double*)malloc((n + 1) * sizeof(double));
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			scanf("%lf", &A[i][j]);
//	for (i = 0; i < n; i++)
//		scanf("%lf", &b[i]);
//	cout << Slau(n, A, b, x) << endl;
//	if (Slau(n, A, b, x))
//	{
//		for (i = 0; i < n; i++)
//			printf("%2.2f\n", x[i]);
//	}
//	getch();
//	return 0;
//}
//
///*
//	4
//	 6 3 -1.5 1
//	-2 -8 3 -2.5
//	1.5 -2 -8 2.5
//	-3 -3 1.5 9.5
//	11.5
//	-19
//	-16.5
//	33.5
//*/
///*
//	4
//	 6 3 -1,5 1
//	12 6 -3 2
//	1,5 -2 -8 2,5
//	-3 -3 1,5 9,5
//	11,5
//	-19
//	-16,5
//	33,5
//*/
////#pragma warning(disable : 4996)
////#include <windows.h>
////#include <stdio.h>
////#include <conio.h>
////#include <math.h>
////#include <clocale>
////#include <iostream>
////#include <cstdlib>
////
////using namespace std;
////
////double* Slau(int n,  double **a, double *b, double *x)
////{
////	double v;
////	for (int k = 0, i, j, im; k < n - 1; k++)
////	{
////		im = k;
////		for (i = k + 1; i < n; i++)
////		{
////			if (fabs(a[im][k]) < fabs(a[i][k]))
////			{
////				im = i;
////			}
////		}
////		if (im != k)
////		{
////			for (j = 0; j < n; j++)
////			{
////				v = a[im][j];
////				a[im][j] = a[k][j];
////				a[k][j] = v;
////			}
////			v = b[im];
////			b[im] = b[k];
////			b[k] = v;
////		}
////		for (i = k + 1; i < n; i++)
////		{
////			v = 1.0*a[i][k] / a[k][k];
////			a[i][k] = 0;
////			b[i] = b[i] - v * b[k];
////			if (v != 0)
////				for (j = k + 1; j < n; j++)
////				{
////					a[i][j] = a[i][j] - v * a[k][j];
////				}
////		}
////		for (int f = 0; f < n; f++)
////		{
////			for (int g = 0; g < n; g++)
////			{
////				cout << a[f][g] << " ";
////			}
////			cout << endl;
////		}
////		cout << endl << endl;
////	}
////	double s = 0;
////	x[n - 1] = 1.0*b[n - 1] / a[n - 1][n - 1];
////	for (int i = n - 2, j; 0 <= i; i--)
////	{
////		s = 0;
////		for (j = i + 1; j < n; j++)
////		{
////			s = s + a[i][j] * x[j];
////		}
////		x[i] = 1.0*(b[i] - s) / a[i][i];
////	}
////	return x;
////}
////void Show(int n, double ** A, double * B)
////{
////	int i, j;
////
////	for (i = 0; i < n; i++)
////	{
////		for (j = 0; j < n + 1; j++)
////		{
////			if (j == n)
////				printf("| %2.2f ", B[i]);
////			else
////				printf(" %2.2f", A[i][j]);
////		}
////		printf("\n");
////	}
////	printf("\r\n");
////}
////
////int main()
////{
////	setlocale(LC_ALL, "Russian");
////
////	int i, j, n;
////	double **a, *b, *x;
////	scanf("%d", &n);
////	a = (double **)malloc(n * sizeof(double));
////	b = (double *)malloc(n * sizeof(double));
////	x = (double *)malloc(n * sizeof(double));
////
////	for (i = 0; i < n; i++)
////	{
////		a[i] = (double *)malloc(n * sizeof(double));
////		for (j = 0; j < n; j++)
////		{
////			scanf("%lf", &a[i][j]);
////		}
////	}
////
////	for (i = 0; i < n; i++)
////	{
////		scanf("%lf", &b[i]);
////	}
////
////	Show(n, a, b);
////
////
////	
////	Show(n, a, b);
////	printf("\n");
////
////	Slau(n, a, b, x);
////
////	printf("Переменные :\r\n");
////	for (i = 0; i < n; i++)
////	{
////		printf(" %2.2f ", x[i]);
////	}
////	printf("\n\n");
////
////	printf("Нажмите Enter для выхода\r\n");
////	free((void *)a);
////	free((void *)b);
////	free((void *)x);
////	getch();
////	return 0;
////}