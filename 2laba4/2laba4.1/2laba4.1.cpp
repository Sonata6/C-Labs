#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "io.h"

void add(FILE *);
void del(FILE*, int);
void print(FILE*);
void swap(FILE*, struct str,struct str, fpos_t*, fpos_t*);
void sort(FILE*, int);

struct data                                        // структура с ФИО
{
	const char *mn[16] = {"Aleksandr", "Danila", "Alexey", "Kirill", "Sergey", "Nikita", "Andrey", "Artem", "Dmitriy", "Mihail", "Petr", "Pavel", "Egor", "Ilya", "Matvey"};
	const char* ms[16] = { "Ivanov", "Smirnov", "Kuznecov", "Popov", "Vasiliev", "Petrov", "Sokolov", "Mihailov", "Novikov", "Fedorov", "Morozov", "Volkov", "Alexeev", "Lebedev", "Semenov", "Egorov"};
	const char* mp[16] = { "Aleksandrovich", "Danilovich", "Alexeyevich", "Kirillovich", "Sergeyevich", "Nikitich", "Andreyevich", "Artemovich", "Dmitriyevich", "Mihailovich", "Petrovich", "Pavlovich", "Egorovich", "Ilyich", "Matveyevich" };
	const char* wn[16] = { "Elena", "Anastasiya", "Anna", "Kseniya", "Nataliya", "Mariya", "Olga", "Alexandra", "Svetlana", "Sofiya", "Juliya", "Darya", "Mariya", "Polina", "Irina", "Elizaveta"};
	const char* ws[16] = { "Ivanova", "Smirnova", "Kuznecova", "Popova", "Vasilieva", "Petrova", "Sokolova", "Mihailova", "Novikova", "Fedorova", "Morozova", "Volkova", "Alexeeva", "Lebedeva", "Semenova", "Egorova" };
	const char* wp[16] = { "Aleksandrovna", "Danilovna", "Alexeyevna", "Kirillovna", "Sergeyevna", "Nikitichna", "Andreyevna", "Artemovna", "Dmitriyevna", "Mihailovna", "Petrovna", "Pavlovna", "Egorovna", "Ilyichna", "Matveyevna" };
	
};
struct str                                         // структура с информацией о каждом человеке
{
	 char name[15], surname[15], patronymic[15];
	 int sq, kl;
};
int main()
{
	setlocale(LC_ALL, "Russian");
	int i, k=0, count=0;
	FILE* f;
	fopen_s(&f, "t.bin", "wb");                  
	fclose(f);
	fopen_s(&f, "t.bin", "r+b");                        //открытие файла
	if (!f)                                             //проверка на открытие
	{
		puts(" ошибка  открытия файла");
		return 0;
	}
	printf("введите количество человек: ");
	do                                                 //умный ввод начального количества человек
	{
		rewind(stdin);
	}while(!scanf_s("%d", &i) || i<0);
	while (count < i)                                  //вызов функции для добавления начального количества человек
	{
		add(f);
		count++;
	}
	rewind(stdin);
	while (1)                                         //цикл выбора основных функций программы
	{
		printf("\n1- add \n2-del \n3-sort \n4-print \n5-end\n выберите режим работы: \n\n");
		scanf_s("%d", &k);
 		switch (k)
		{
		case 1: add(f); count++; break;
		case 2: --count; del(f, count); break;
		case 3: sort(f,count); break;
		case 4: print(f); break;
		case 5: return 0;
		}
	}
	fclose(f);
	return 0;
}

void add(FILE *f)                        // функция добавления человека
{	
	rewind(f);                           // сброс ошибки, если дошли до конца
	fseek(f, 0, 2);                      // установка УТПФ в конец файла
	int r;
	str* s;
	data d;
	if ((s = (str*)calloc(1, sizeof(str))) == NULL)          // проверка на выделение памяти под структуру
	{
		puts("ошибка при выделении памяти");
		fclose(f);
		return;
	}
	r = rand() % 2;                                // выбор пола и заполнение полей структуры
	if (!r)
	{
		r = rand() % 16;
		strcpy_s(s->name, d.mn[r]);
		r = rand() % 16;
		strcpy_s(s->surname, d.ms[r]);
		r = rand() % 16;
		strcpy_s(s->patronymic, d.mp[r]);
	}
	else
	{
		r = rand() % 16;
		strcpy_s(s->name, d.wn[r]);
		r = rand() % 16;
		strcpy_s(s->surname, d.ws[r]);
		r = rand() % 16;
		strcpy_s(s->patronymic, d.wp[r]);
	}
	s->kl = rand() % 10 + 1;
	s->sq = rand() % 450 + 51;
		fwrite(s, sizeof(str), 1, f);   // дозапись структуры в конец файла
}

void del(FILE*f, int count)                 // функция удаления человека
{
	rewind(f);
	str st, stt;
	setlocale(LC_ALL, "Russian");
	long l, i;
	printf("введите номер структуры, который хотите удалить");
	do
	{
		rewind(stdin);
	} while (!scanf_s("%d", &i) || i < 0);
	fseek(f, i * sizeof(str), 0);
			do
			{
				fread(&stt, sizeof(str), 1, f);          // чтение следующей стр-ры
				if (feof(f)) break;                      // проверка на ввод
				l = ftell(f);                            // запоминаем позицию за считанной
				fseek(f, l - (long)(2 * sizeof(str)), 0);// на 2 стр-ры назад к началу файла
				fwrite(&stt, sizeof(str), 1, f);         // и запись считанной ст-ры
				fseek(f, l, 0);                          // возврат к позиции L
			} while (!feof(f));
	rewind(f);                                           // перемещение УТПФ в начало и сброс ошибок
	fseek(f, sizeof(str), 2);
	_chsize(_fileno(f), (count * sizeof(str)));          // перевыделение памяти в файле(на 1 человека меньше)


}

void print(FILE* f)                       // функция вывода на экран
{
	rewind(f);
	str st;
	rewind(f);
	puts("         Фамилия           Имя          Отчество          площадь       количество человек");
	do
	{
		fread(&st, sizeof(str), 1, f);                            //считывание структуры
		if (feof(f)) break;
		printf("\n%16s%16s%16s%15d%15d", st.surname, st.name, st.patronymic, st.sq, st.kl);           // вывод информации структуры
	} while (!feof(f));
}

void sort(FILE* f, int count)             // функция сортировке по площади
{
	rewind(f);
	str st1, st2;
	fpos_t n1, n2;
	int i=0;
	while(i<count)
	{
		rewind(f);
		fseek(f, 0, 0);                             // установка УТПФ в начало файла
		if (feof(f)) break;
		while(1)
		{
			fgetpos(f, &n1);                        // получение позиции первой структуры
			fread(&st1, sizeof(str), 1, f);         // считывание первой структуры
			if (feof(f)) break;
			fgetpos(f, &n2);                        // получение позиции второй структуры
			fread(&st2, sizeof(str), 1, f);         // считывание второй структуры
			if (feof(f)) break;
			if((st1.sq/st1.kl)>(st2.sq / st2.kl))   // если площадь человека из первой структуры больше площади человека из второй структуры
			swap(f, st1, st2, &n1, &n2);            // замена
			n1 +=sizeof(str);                       // перемещение объекта, указывающего на позицию первой структуры в файле
			fsetpos(f, &n1);                        // установка позиции
		} 
		i++;
	}
}

void swap(FILE* f, struct str s1, struct str s2, fpos_t* l1, fpos_t* l2)      //функция замены двух структур
{
	if (!f) return;
	fsetpos(f, l1);
	fwrite(&s2, sizeof(str), 1, f);    // вторая стр-ра по первому адресу
	fsetpos(f, l2);
	fwrite(&s1, sizeof(str), 1, f);    // первая стр-ра по второму адресу
}