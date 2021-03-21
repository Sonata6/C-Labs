#include <iostream>
#include"Header.h"
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RU");
	Queue* start = nullptr, * finish = nullptr;
	int choice;
	do //добавление элемента в очередь со всеми проверками
	{
		do
		{
			rewind(stdin);
			printf("Хотите добавить элемент в очередь?\n1-ДА 2-НЕТ\n");
			scanf_s("%d", &choice);
			if (choice > 2 || choice < 1)
			{
				printf("Ошибка при вводе!Попробуйте еще раз");
			}
		} while (choice > 2 || choice < 1);
		if (choice == 2)
			break;
		add_to_queue(&start, &finish);//функция добавления в очередь
	} while (true);
	do//диалоговое окно со всеми функциями
	{
		do {
			rewind(stdin);
			printf("1-Добавить элемент\n2-удаление элемента с минимальным стеком\n3-Вывод\n0-Выход\n");
			scanf_s("%d", &choice);
			if (choice < 0 || choice>4)
			{
				printf("Ошибка при вводе попробуйте еще раз!\n");
			}
		} while (choice < 0 || choice>4);
		switch (choice)
		{
		case 1: add_to_queue(&start, &finish); break; //добавление в кольцо
		case 2: del(start, finish); break;//удаоение
		case 3: output(start, finish);//вывод
		}
	} while (choice);
	free(start, finish);//очистка памяти
}