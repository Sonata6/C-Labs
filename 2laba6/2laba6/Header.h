#pragma once
#ifndef HEADER_H
#define HEADER_H
struct Stack //элемент стека
{
	char surname[16];
	Stack* next = nullptr;
};
struct Queue//элемент очереди
{
	Stack* st;
	int number_of_students;
	Stack* start = nullptr;
	Queue* next = nullptr;
};
void add_to_queue(Queue** start, Queue** finish);//добавление в очередь
void output(Queue* start, Queue* finish);//вывод
void free(Queue* start, Queue* finish);//очистка памяти
void del(Queue*, Queue*);
#endif // !HEADER_H
