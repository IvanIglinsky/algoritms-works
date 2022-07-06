#include <stdio.h>
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);SetConsoleOutputCP(1251);
	struct Operation
	{
		signed char five = 5;
		signed char twentyseven = 127;
		signed char two = 2;
		signed char three = 3;
		signed char onehundredtwo = 120;
		signed char threefour = 34;
		signed char fivesix = 56;
		signed char treeeight = 38;
	};
	Operation O;
	printf("а)5+127=%d\n", O.five + O.twentyseven);
	printf("0000 0101 + 0111 1111 = 1000 0100 - Результат виконання неправильним  виникає переповнення типу даних char!\nВ результаті 0000 0101 + 0111 1111 = 1000 0011\n");
	printf("б)2-3=%d\n", O.two - O.three);
	printf("0010-0011=1110-Результат правильний\n");
	printf("в)-120-34=%d\n", -O.onehundredtwo - O.threefour);
	printf("1000 0111 - 0010 0010 = 0110 0101 - Результат є неправильним так як виникає переповнення типу даних char!\nВ результаті 1000 0111 - 0010 0010 = 0110 0110\n");
	printf("г)(unsigned char)(- 5)=%d\n", unsigned char(-O.five));
	printf("Проходить перетворення типів числа -5 в 5 але перетворення не відбудеться \n");
	printf("д)56 & 38 =%d\n", O.fivesix& O.treeeight);
	printf("0011 1000 & 0010 0100=0010 0000-Результат є правильним\n");
	printf("е)56 | 38 =%d\n", O.fivesix | O.treeeight);
	printf("0011 1000 | 0010 0100=0011 1110-Результат є правильним\n");
	return 0;
}