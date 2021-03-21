#pragma once
#ifndef HEADER_H
#define HEADER_H
struct Stack //������� �����
{
	char surname[16];
	Stack* next = nullptr;
};
struct Queue//������� �������
{
	Stack* st;
	int number_of_students;
	Stack* start = nullptr;
	Queue* next = nullptr;
};
void add_to_queue(Queue** start, Queue** finish);//���������� � �������
void output(Queue* start, Queue* finish);//�����
void free(Queue* start, Queue* finish);//������� ������
void del(Queue*, Queue*);
#endif // !HEADER_H
