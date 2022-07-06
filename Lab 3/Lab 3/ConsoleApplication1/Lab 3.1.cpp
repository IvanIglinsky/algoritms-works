#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

long int FIBONACHI(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return FIBONACHI(n - 2) + FIBONACHI(n - 1);
}
int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int res = 0;
	unsigned int n = 2;
	clock_t start, finish;
	printf("Лабораторна робота №3\nЗавдання 2:Числа Фібоначі:\n");
	printf("Діапазон 2<=n<=40\n");
	start=clock();
	for (unsigned int i = 2; i <= 40; ++i)
		printf("fib(%u) = %ld\n", i, FIBONACHI(i));
	finish = clock();
	float dd = (float)(finish - start) / CLOCKS_PER_SEC;
	printf("Час виконання: %f с" , dd);
}
