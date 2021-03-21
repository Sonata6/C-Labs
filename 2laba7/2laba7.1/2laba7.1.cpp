#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <locale.h>
#include"Header.h"
int main()
{
	int r=250,i,j=2, *a;
	tree* dr = nullptr;        // адрес корня бинарного дерева
	tree* drk = nullptr;
	setlocale(LC_ALL, "Russian");
	while (1)
	{
		puts("\nвид операции: 1-создать дерево ");
		puts("              2-вывод содержимого дерева");
		puts("              3-создание и вывод содержимого дерево по количеству обращений");
		puts("              4-выход");
		rewind(stdin);
		switch (getchar())
		{
		case '1':
			puts("Введите количество элементов в дереве(от нуля до 500)\n");
			do
			{
				rewind(stdin);
			}while(scanf_s("%d", &i) && i>500 && i<1);
			while (j<i+2)
			{
				 dr = creat1(dr, r+j);
				 dr = creat1(dr, r-j);
				 j += 2;
			}
			break;
		
		case '2': show(dr); getchar(); break;
		case '3': 
			j=0;
			a = getms(dr, i);
			j = i;
			while (j >0)
			{
				drk = creat1(drk, a[j-1]);
				j--;
			}
			show(drk);
			break;
		case '4': return 0;
		default: puts("ошибка в выборе варианта");
		}
	}
	puts("\n");
	return 0;
}

