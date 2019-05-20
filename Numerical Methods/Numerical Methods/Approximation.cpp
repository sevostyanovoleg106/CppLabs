//#include <math.h>
//#include <stdio.h>
//#include <malloc.h>
//#include <conio.h>
//#include <iostream>
//#pragma warning(disable : 4996)
//
//using namespace std;
////int Slau(int n, double** a, double* b, double* x)
////{
////	double ** A, tmp;
////	int i, j, k;
////
////	A = (double**)malloc(n * sizeof(double*));
////	for (i = 0; i < n; i++)
////		A[i] = (double*)malloc((n + 1) * sizeof(double));
////	for (i = 0; i < n; i++)
////	{
////		for (j = 0; j < n; j++)
////		{
////			A[i][j] = a[i][j];
////			A[i][n] = b[i];
////		}
////	}
////	for (int f = 0; f < n; f++)
////	{
////		for (int g = 0; g < n+1; g++)
////		{
////			cout << A[f][g] << " ";
////		}
////		cout << endl;
////	}
////	for (i = 0; i < n; i++)
////	{
////		tmp = A[i][i];
////		if (fabs(tmp) < 0.000001)
////		{
////			for (i = 0; i < n; i++)
////				free(A[i]);
////			free(A);
////			return 0;
////		}
////	}
////	for (j = i; j <= n + 1; j++)
////	{
////		A[i][j] /= tmp;
////	}
////	for (j = 0; j < n; j++)
////	{
////		if (i = j)
////			continue;
////		tmp = A[j][i];
////		for (k = i; k <= n; k++)
////		{
////			A[j][k] -= tmp * A[i][k];
////		}
////	}
////
////	for (int f = 0; f < n; f++)
////	{
////		for (int g = 0; g < n + 1; g++)
////		{
////			cout << A[f][g] << " ";
////		}
////		cout << endl;
////	}
////	for (i = 0; i < n; i++)
////		x[i] = A[i][n];
////	for (i = 0; i < n; i++)
////		free(A[i]);
////	free(A);
////	return 1;
////
////
////}
//
//int Lms(int n, int p, double* x, double* y, double* c)
//{
//	double **A;
//	int i, j, k, iret;
//	A = (double**)malloc((p + 1) * sizeof(double*));
//	for (i = 0; i <= p; i++)
//	{
//		A[i] = (double*)malloc((p + 2) * sizeof(double));
//	}
//	for (i = 0; i <= p; i++)
//	{
//		for (j = 0; j <= p; j++)
//		{
//			A[i][j] = 0;
//			for (k = 0; k < n; k++)
//			{
//				A[i][j] += pow(x[k], i + j);
//			}
//		}
//		A[i][p + 1] += y[k] * pow(x[k], i);
//	}
//	iret = Slau(p + 1, A, c, x);
//	for (i = 0; i <= p; i++)
//		free(A[i]);
//	free(A);
//	return iret;
//}
//double pol(int p, double x, double* c)
//{
//	double y;
//	int i;
//	y = c[p];
//	for (i = p; i > 0; i--)
//		y = y * x + c[i - 1];
//	return y;
//}
///*void main()
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
//			printf("%lf", x[i]);
//	}
//	getch();
//}
//*/
///*
//4
//6 3 -1.5 1
//-2 -8 3 -2.5
//1.5 -2 -8 2.5
//-3 -3 1,5 9.5
//11.5
//-19
//-16.5
//33.5
//*/