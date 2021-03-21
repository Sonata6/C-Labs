#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	system("CLS");
	int p,j=0, i = 0, k = 0,n=0,d=0;
	unsigned char* a;
	int* b;
	a = (unsigned char*)malloc(1);
	b = (int*)malloc(1 * sizeof(int));    //массив расположения пробелов
	printf("Введите строку:");
	while ((a[i] = getchar()) != '\n')                  //цикл ввода строки и запоминания пробелов
	{
		if ((int)a[i] > 64 && (int)a[i] < 91 || (int)a[i]>96 && (int)a[i] < 123 || (int)a[i] == 32 || (int)a[i]>191 && (int)a[i] < 224 || (int)a[i]>223 && (int)a[i] < 256)
		{
			if ((int)a[i] == 32)
			{
				b[d] = i;
				d++;
				b = (int*)realloc(b, (d + 1) * sizeof(int));
			}
			i++;
			a = (unsigned char*)realloc(a, i + 1);
		}
	}
	a[i] = '\0';
	printf("введите n\n");
	do
	{ 
	}while(!scanf_s("%d", &p));              //ввод значения сдвига букв
	while (p > 26)
		p -= 26;
	while (p < 0)
		p += 26;
	for (j = 0; j < i; j++)
	{
		if (a[j] == '\0')
			break;
		if (a[j] == ' ')            //удаление пробелов в строке
		{
			for (k=j; k < i; k++) 
				a[k] = a[k + 1];
			--i;
			a[i] = '\0';
		}
		if ((int)a[j] < 91)           //шифровка текста
		{
			a[j] += p;
				if ((int)a[j] > 90)
					a[j] -= 26;
		}
		else if((int)a[j] < 123)
		{
			a[j] +=p;
				if ((int)a[j] > 122)
					a[j] -= 26;
		}
		else if ((int)a[j] < 224)
		{
			a[j] += p;
			if ((int)a[j] > 223)
				a[j] -= 33;
		}
		else if ((int)a[j] < 257)
		{
			a[j] +=p;
			if ((int)a[j] > 256)
				a[j] -= 33;

		}
	}
	for (j = 0; j < i; j++)          //вставка пробелов после каждого пятого символа
	{
		++n;
		if (n % 5 == 0)
		{
			if (n == 5)
				j++;
			a = (unsigned char*)realloc(a, ++i);
			for (k = i; k > j; k--)
				a[k] = a[k - 1];
			a[k] = ' ';
			j++;
		}
	}
	a[i]='\0';
	printf("зашифрованный текст:\n");          // вывод зашифрованного текста(xxxxx xxxxx xxxxx)
	//puts(a);
	for (j = 0; j < i; j++)
		printf("%c", a[j]);
	printf("\n");
	for (j = 0; j < i; j++)
	{
		if (a[j] == '\0')
			break;
		if (a[j] == ' ')                        //удаление пробелов (для расшифровки)
		{
			for (k = j; k < i; k++)
			{
				a[k] = a[k + 1];
			}
			--i;
			a[i] = '\0';
		}
		if ((int)a[j] < 91)                //расшифровка текста
		{
			a[j] -= p;
			if ((int)a[j] < 65)
				a[j] += 26;
		}
		else if ((int)a[j] < 123)
		{
			a[j] -= p;
			if ((int)a[j] < 97)
				a[j] += 26;
		}
		else if ((int)a[j] < 223)
		{
			a[j] -= p;
			if ((int)a[j] < 191)
				a[j] += 33;
		}
		else if ((int)a[j] < 256)
		{
			a[j] -= p;
			if ((int)a[j] < 223)
				a[j] += 33;

		}
	}
	
	i += d;
	a = (unsigned char*)realloc(a, i);
	d = 0;
	for (j = 0; j < i; j++)        
	{
		
		if (j == b[d])
		{
			
			for (k = i; k > j; k--)
				a[k] = a[k - 1];
			a[k] = ' ';
			j++;
			d++;
		}
	}
	a[i] = '\0';
	printf("расшифрованный текст:\n");
	for (j = 0; j < i; j++)
		printf("%c", a[j]);
	//puts(a);
	free(b);

	return 0;
}