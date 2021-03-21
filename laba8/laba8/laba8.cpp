#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>
int fun(int , int );
int main()
{
	setlocale(LC_ALL, "Russian");
	system("CLS");
	int a, b;
	printf("Введите промежуток значений, необходимых для вывода на экран: \n");
	do
	{
		rewind(stdin);
	} while (!scanf_s("%d %d", &a, &b));
	fun(a, b);
	return 0;
}

int fun(int a, int b)
{
	if (a > b)
	{
		printf("%3d", a);
		a--;
		fun(a, b);
	}
	else if (a < b)
	{
		printf("%3d", a);
			a++;
			fun(a, b);
	}
	else if (a == b)
	{
		printf("%3d", a);
		return 0;
	}
}