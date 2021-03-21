#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

struct stack
{
	char Data;
	stack* Next;
};
void push(stack**, char);
void pop(stack**);
void show(stack*);

int main()
{
	setlocale(LC_ALL, "Russian");
	stack* s = nullptr;
	char l, inf;
	int kol, f = 0, k=0;
	printf("Введите размер стека: \n");
	do
	{
		rewind(stdin);
	}while(!scanf_s("%d", &kol) ||kol<1);
	while (1)
	{
		puts("\nвыберите операцию:\n  1-добавить элементы в стек\n  2-удалить элемень из стека\n  3-просмотреть содержимое стека\n  4-окончить работу программы");
		rewind(stdin);
		l = getchar();     //выбор операции
		switch (l)
		{
		case '1':
			printf("\n\n");
				if (f == kol) {
					printf("Стек полон.\n");
					break;
				}
				while (f < kol)
				{
					if (k == 5)         //удаление пятого элемента
					{
						rewind(stdin);
						pop(&s); f--;
						printf("Пятый элемент %c удалён\n", inf);
					}
					do           //проверка на ввод информации
					{
						rewind(stdin);
					} while (!scanf_s("%c", &inf));
					push(&s, inf); f++; k++;
				} k--;
						break;
		case '2': if (s)
		{
			if (s)
			{
				pop(&s);
				printf("Элемент удален.\n");
				f--; k--;
			}
			else printf("Стек пустой.\n");
			break;
		}
				  else puts("стек пуст");
			break;
		case '3': show(s); break; 
		case '4': return 0;
		default: printf("Ошибка, повторите \n");
		}
	}
	free(s);          //очистка памяти
	return 0;
}

// функция cоздания/добавления в стек
void push(stack** head, char x) //функция создания ячейки в стеке
{
	stack* n = (stack*)malloc(sizeof(stack)); //выделяем память под ячейку
	n->Data = x; //сохраняем символ
	if (*head == NULL) //если голова нулл, то присваиваем голове ячейку
	{
		n->Next = NULL; //в нулл указатель
		*head = n;
	}
	else //иначе кладем сверху стека ячейку
	{
		n->Next = *head;
		*head = n;
	}
}
// функция просмотра элементов стека
void show(stack* s)
{
	printf("\nсодержимое стека:\n");
	if (!s)
	{
		puts("Стек пуст");
		return;
	}
	do
	{
		printf("%c\n", s->Data);
		s = s->Next;
	} while (s);
	system("pause");
}

// функция удаления последнего элемента стека
// (с вершины стека)
void pop(stack** s)
{
	stack* s1, ss;
	s1 = *s;       // указатель на вершину стека      
	*s = (*s)->Next;  // указатель передвигаем "вниз" по стеку
	free(s1);    // удаляем с вершины стека
}
