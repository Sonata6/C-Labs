#include"Header.h"
#include<iostream>
#include<locale.h>
void add_to_stack(Stack** start, char* surname);//добавление в стек
void stack_output(Stack* start);//вывод
void free_stack(Stack* start);//освобождение пам€ти стека
void stack_add(Stack* , Stack* );
void add_to_queue(Queue** start, Queue** finish)//добавление элемента в очередь
{
	int r;
	const char* sur[16] = { "Ivanov", "Smirnov", "Kuznecov", "Popov", "Vasiliev", "Petrov", "Sokolov",
		"Mihailov", "Novikov", "Fedorov", "Morozov", "Volkov", "Alexeev", "Lebedev", "Semenov", "Egorov" };
	Queue* pointer = new Queue[1];//выдел€ю пам€ть под новый элемент
	setlocale(LC_ALL, "RU");
	pointer->number_of_students=rand()%25+5;//ввод данных
	for (int i = 0; i < pointer->number_of_students; i++)
	{
		r = rand() % 16;
		char surname[16];
		strcpy_s(surname,sur[r]);
		add_to_stack(&pointer->start, surname);//функци€ добавлени€ в стек
	}
	if (*start == nullptr)//если до этого очередь пуста€ то создаю 1 элемент
	{
		*start = pointer;
		*finish = pointer;
		(*start)->next = *start;
	}
	else
	{
		(*finish)->next = pointer; //если очередь не пуста€ то добавл€ю новый элемент в конец
		*finish = pointer;
		(*finish)->next = *start;
	}
}

void add_to_stack(Stack** start, char* s)
{
	Stack* pointer = new Stack[1];//выдел€ю пам€ть под элемент стека
	strcpy_s(pointer->surname,s);
	if ((*start) == nullptr)//если первый элемент то старт указывает на него
	{
		*start = pointer;
	}
	else
	{
		pointer->next = *start; //если нет то соедин€ю с предыдущим и старт указывает на вершину
		*start = pointer;
	}
}

void output(Queue* start, Queue* finish)//вывод информации
{
	Queue* memory = start;
	int flag = 0;
	printf("----------------------------------------------------------\n");
	while (start != memory || flag == 0)
	{
		flag = 1;
		printf("%d\n", start->number_of_students);
		stack_output(start->start);
		start = start->next;
		printf("\n");
	}
	printf("----------------------------------------------------------\n");
}

void stack_output(Stack* start)//вывод стека
{
	while (start != nullptr)
	{
		printf("%s\n", start->surname);
		start = start->next;
	}
}

void free(Queue* start, Queue* finish) //очистка пам€ти дл€ очереди
{
	Queue* pointer;
	while (start != finish)//пока не дошел до последнего элемента
	{
		pointer = start->next; //запоминаю следующий
		free_stack(start->start);//освобождаю стек
		delete(start);//удал€ю элемент
		start = pointer;//перехожу к следующему
	}
	free_stack(start->start);//после вайла осталс€ 1 элемент который тоже удал€ю
	delete(start);
}
void free_stack(Stack* start) //очистка стека
{
	Stack* pointer;
	while (start != nullptr)
	{
		pointer = start->next;//запоминаю следующий
		delete(start);//удал€ю
		start = pointer;//перехожу к следующему
	}
}

void del(Queue* start, Queue* finish)     //удаление элемента с минимальным стеком в очереди 
{
	int num=start->number_of_students;
	Queue* memory = start, *tmp;
	int flag = 0;
	while (start != memory || flag == 0)            //поиск элемента с минимальным стеком
	{
		if (start->number_of_students < num)
			num = start->number_of_students;
		flag = 1;
		start = start->next;
	}
	start = start->next;
	flag = 0;
	while (start != memory || flag == 0)         // перенос стека 
	{
		if (start->number_of_students == num)
		{
			start->next->number_of_students += start->number_of_students;
			while (start->start != NULL) {
				add_to_stack(&start->next->start, start->start->surname);
				start->start = start->start->next;
			}
			while (start->next->number_of_students != num)
				start = start->next;
			tmp = start->next->next;
			free(start->next);                  //очистка элемента
			start->next = tmp;
			break;
		}
			
		flag = 1;
		start = start->next;
	}
}

