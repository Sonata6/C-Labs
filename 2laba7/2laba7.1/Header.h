#pragma once
#ifndef HEADER_H
#define HEADER_H
struct tree
{
	int n;           
	int kl;             // число встреч инф. поля в бинарном дереве
	tree* L, * R;       // указатель на левое и правое поддерево
};
int* getms(tree*, int);
void show(tree*);
tree* creat1(tree*, int);
void Sort(int*, int);

#endif // !HEADER_H