#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

union Znaks
{
	signed short num;
	 struct
	{
		signed short  number;
		signed short znak;
	}VizZnak;
};
int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	Znaks Search;
	printf("Уведіть число в форматі signed short (-32768...32767)\n");
	scanf("%hd", &Search);
	printf("Перший спосіб  за допомогою структури даних та об'єднання\n");

	if (Search.VizZnak.number < 0)
	{
		Search.VizZnak.znak = '-';
	}
	else
		Search.VizZnak.znak = '+';
	if (Search.VizZnak.number == 0)
	{
		Search.VizZnak.znak = ' ';
	}
	if (Search.VizZnak.znak == 0)
		printf("Знак=число нейтральне\n");
	printf("Знак=%c\n", Search.VizZnak.znak);
	printf("Число=%d\n", Search.VizZnak.number);
	printf("Другий спосіб за допомогою побітові логічні операції\n");
	printf("Уведіть число в форматі signed short (-32768...32767)\n");
	printf("Уведіть число: "); scanf_s("%hd", &Search.num);
	signed short u = Search.num >> 16;
	if (Search.num == 0)
	{
		printf("Знак= \nЧисло=%d\n",Search.num);

	}
	else
	{
		if (u)
		{
			printf("Знак = -\nЧисло = %d\n", Search.num);

		}
		else
			printf("Знак = +\nЧисло = %d\n", Search.num);
	}
	return 0;
}