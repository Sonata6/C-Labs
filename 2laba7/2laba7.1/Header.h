#pragma once
#ifndef HEADER_H
#define HEADER_H
struct tree
{
	int n;           
	int kl;             // ����� ������ ���. ���� � �������� ������
	tree* L, * R;       // ��������� �� ����� � ������ ���������
};
int* getms(tree*, int);
void show(tree*);
tree* creat1(tree*, int);
void Sort(int*, int);

#endif // !HEADER_H