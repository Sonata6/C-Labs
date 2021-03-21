#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

void vvod(int** mt, int n, int m);
void vivod(int** mt, int n, int m);

int main()
{
	setlocale(LC_ALL, "Russian");
	system("CLS");
	int** mt, * ms, n, m, i, k, k1;
	printf("введите количество столбцов и строк\n");
	do                                                  //цикл ввода количества столбцов\строк квадратной матрицы
	{
		rewind(stdin);
	} while ((scanf_s("%d%d", &n, &m) != 2) || n < 0 || m < 0);
	mt = (int**)malloc(n * sizeof(int*));                    //создание динамического массива указателей
	ms = (int*)malloc(m * sizeof(int));
	system("CLS");
	vvod(mt, n, m);                                        //заполнение матрицы рандомными значениями
	vivod(mt, n, m);                                      //вывод исходной матрицы
	printf("\n\n\n");
	printf("выберите номер строки k и k1 от 1 до %d\n", n);
	i = 0;
	do                                                  //цикл ввода количества столбцов\строк квадратной матрицы
	{
		printf("\nk: ");
		rewind(stdin);
	} while (!(scanf_s("%d", &k)) || n <= k || k <= 1 );
	do                                                  //цикл ввода количества столбцов\строк квадратной матрицы
	{
		printf("\nk1: ");
		rewind(stdin);
	} while (!(scanf_s("%d", &k1)) || n <= k1 || k1 <= 1 || k == k1);
	for (i = 0; i < m; i++)
	{
		ms[i] = mt[k1][i];
		printf("ms[%d]:", ms[i]);
	}
	printf("\n");



	for (int i = 0; i < n; i++)                         //очистка памяти
		free(mt[i]);
	free(mt);
	free(ms);
	system("pause");
	return 0;
}


void vvod(int** mt, int n, int m)                              //функция ввода матрицы
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		mt[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++)
			mt[i][j] = rand() % 100;
	}
}

void vivod(int** mt, int n, int m)                             //функция вывода матрицы
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%3d", mt[i][j]);
	}
}