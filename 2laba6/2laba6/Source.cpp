#include"Header.h"
#include<iostream>
#include<locale.h>
void add_to_stack(Stack** start, char* surname);//���������� � ����
void stack_output(Stack* start);//�����
void free_stack(Stack* start);//������������ ������ �����
void stack_add(Stack* , Stack* );
void add_to_queue(Queue** start, Queue** finish)//���������� �������� � �������
{
	int r;
	const char* sur[16] = { "Ivanov", "Smirnov", "Kuznecov", "Popov", "Vasiliev", "Petrov", "Sokolov",
		"Mihailov", "Novikov", "Fedorov", "Morozov", "Volkov", "Alexeev", "Lebedev", "Semenov", "Egorov" };
	Queue* pointer = new Queue[1];//������� ������ ��� ����� �������
	setlocale(LC_ALL, "RU");
	pointer->number_of_students=rand()%25+5;//���� ������
	for (int i = 0; i < pointer->number_of_students; i++)
	{
		r = rand() % 16;
		char surname[16];
		strcpy_s(surname,sur[r]);
		add_to_stack(&pointer->start, surname);//������� ���������� � ����
	}
	if (*start == nullptr)//���� �� ����� ������� ������ �� ������ 1 �������
	{
		*start = pointer;
		*finish = pointer;
		(*start)->next = *start;
	}
	else
	{
		(*finish)->next = pointer; //���� ������� �� ������ �� �������� ����� ������� � �����
		*finish = pointer;
		(*finish)->next = *start;
	}
}

void add_to_stack(Stack** start, char* s)
{
	Stack* pointer = new Stack[1];//������� ������ ��� ������� �����
	strcpy_s(pointer->surname,s);
	if ((*start) == nullptr)//���� ������ ������� �� ����� ��������� �� ����
	{
		*start = pointer;
	}
	else
	{
		pointer->next = *start; //���� ��� �� �������� � ���������� � ����� ��������� �� �������
		*start = pointer;
	}
}

void output(Queue* start, Queue* finish)//����� ����������
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

void stack_output(Stack* start)//����� �����
{
	while (start != nullptr)
	{
		printf("%s\n", start->surname);
		start = start->next;
	}
}

void free(Queue* start, Queue* finish) //������� ������ ��� �������
{
	Queue* pointer;
	while (start != finish)//���� �� ����� �� ���������� ��������
	{
		pointer = start->next; //��������� ���������
		free_stack(start->start);//���������� ����
		delete(start);//������ �������
		start = pointer;//�������� � ����������
	}
	free_stack(start->start);//����� ����� ������� 1 ������� ������� ���� ������
	delete(start);
}
void free_stack(Stack* start) //������� �����
{
	Stack* pointer;
	while (start != nullptr)
	{
		pointer = start->next;//��������� ���������
		delete(start);//������
		start = pointer;//�������� � ����������
	}
}

void del(Queue* start, Queue* finish)     //�������� �������� � ����������� ������ � ������� 
{
	int num=start->number_of_students;
	Queue* memory = start, *tmp;
	int flag = 0;
	while (start != memory || flag == 0)            //����� �������� � ����������� ������
	{
		if (start->number_of_students < num)
			num = start->number_of_students;
		flag = 1;
		start = start->next;
	}
	start = start->next;
	flag = 0;
	while (start != memory || flag == 0)         // ������� ����� 
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
			free(start->next);                  //������� ��������
			start->next = tmp;
			break;
		}
			
		flag = 1;
		start = start->next;
	}
}

