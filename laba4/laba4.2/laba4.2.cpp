#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

void vvod(int** mt, int n);
void vivod(int** mt, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	system("CLS");
	int** mt, n, i, j, k;
	printf("введите количество столбцов/строк\n");
	do                                                  //цикл ввода количества столбцов\строк квадратной матрицы
	{
		rewind(stdin);
	} while (!scanf_s("%d", &n) || n<0 );
	mt = (int**)malloc(n * sizeof(int*));               //создание динамического массива указателей
	vvod(mt, n);                                        //заполнение матрицы рандомными значениями
	vivod(mt, n);                                       //вывод исходной матрицы
	printf("\n\n\n");
	for (i = 0; i < n; i++)                             //цикл транспонирования матрицы относительно главной диагонали
		for (j = i + 1; j < n; j++)
		{
			k = mt[i][j];
			mt[i][j] = mt[j][i];
			mt[j][i] = k;
		}
	vivod(mt, n);                                       //вывод транспонированной матрицы
	printf("\n\n\n");
	for (int i = 0; i < n; i++)                         //очистка памяти
		free(mt[i]);
	free(mt);
	system("pause");
	return 0;
}

void vvod(int** mt, int n)                              //функция ввода матрицы
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		mt[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
			mt[i][j] = rand() % 100;
	}
}

void vivod(int** mt, int n)                             //функция вывода матрицы
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%3d", mt[j][i]);
	}
}