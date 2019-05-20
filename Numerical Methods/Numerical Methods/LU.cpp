#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

void show(double **A, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2.3f\t", A[i][j]);
		}
		cout << endl;
	}
}
void LU(double **A, double **&L,	double **&U, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			U[i][j] = A[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			L[j][i] = 0;
		}

	}
	for (int k = 1; k < n; k++)
	{
		for (int i = k - 1; i < n; i++)
			for (int j = i; j < n; j++)
				L[j][i] = U[j][i] / U[i][i];

		for (int i = k; i < n; i++)
			for (int j = k - 1; j < n; j++)
				U[i][j] -= L[i][k - 1] * U[k - 1][j];
	}
	
}

void proisv(double **A, double **B,	double **R, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			R[j][i] = 0;
		}

	}
	for ( i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for ( k = 0; k < n; k++)
			{
				R[i][j] += A[i][k] * B[k][j];
			}
				
}

int main()
{
	double **A, **L, **U, **R;
	int  i, j, n;
	scanf("%d", &n);
	A = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
		A[i] = (double*)malloc((n + 1) * sizeof(double));
	L = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
		L[i] = (double*)malloc((n + 1) * sizeof(double));
	U = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
		U[i] = (double*)malloc((n + 1) * sizeof(double));
	R = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
		R[i] = (double*)malloc((n + 1) * sizeof(double));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%lf", &A[i][j]);
		}
	}
	//show(A, n);
	LU(A, L, U, n);
	cout << "Fisrt matrix" << endl;
	show(A, n);
	cout << "U matrix" << endl;
	show(U, n);
	cout << "L matrix" << endl;
	show(L, n);
	proisv(L, U, R, n);
	cout << "L*U matrix" << endl;
	show(R, n);
	getch();
	return 0;
}
/*
4
6 3 -1.5 1
-2 -8 3 -2.5
1.5 -2 -8 2.5
-3 -3 1.5 9.5
11.5
-19
-16.5
33.5
*/