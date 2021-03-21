#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>
void fun(int** , int );
int fun1(int** , int );

int main()
{
	setlocale(LC_ALL, "Russian");
	system("CLS");
	int i=0, j=0, n, ** a;
	printf("введите количество строк/столбцов матрицы\n");
	do
	{
		rewind(stdin);
	} while (!scanf_s("%d", &n) || n < 1);
	a=(int**)malloc(n*sizeof(int*));
	fun(a,n);
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%3d", a[i][j]);
	}
	i = fun1(a,n);
	printf("\n%d", i);
	for (i = 0; i < n; i++)
		free(a[i]);
	free(a);
	return 0;
}

void fun(int** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
			a[i][j] = rand() % 100;
	}
}
int fun1(int** a, int n)
{
	int i = 0,sum=0,j=n-1,k;
	printf("\nвведите 1,если нужна сумма элементов главной диагонали\nвведите 2,если нужна сумма элементов побочной диагонали\n");
	do
	{
		rewind(stdin);
	} while (!scanf_s("%d", &k) || k < 0 || k>2);
	switch (k)
	{
	case 1:
		while (i < n)
		{

			sum += a[i][i];
			++i;
		};
		break;
	case 2:
		
		while (i < n || j>0)
		{
			sum += a[i][j];
			++i;
			--j;

		};
		break;
	}
	return sum;
}