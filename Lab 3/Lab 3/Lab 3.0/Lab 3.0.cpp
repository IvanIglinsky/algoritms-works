#include <stdio.h>
#include <Windows.h>
#include <math.h>
double FACTORIAL(int a)
{
	return((a == 0) || (a == 1) ? 1 : a * FACTORIAL(a - 1));
}

int main()
{

	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int n = 1;
	double res = 0;
	printf("Лабораторна робота №3\nЗавдання 1:\nТабулювання функції f(n)=n:\n\n\n");
	while (n <= 50)
	{
		res = n;
		printf("|f(%d) = %.f |\t\t", n, res);
		n++;
	}
	n = 1;
	printf("\n\n\nТабулювання функції f(n)=log(n):\n\n\n");
	while (n <= 50)
	{
		res = log(n);
		printf("|f(%d) = %.2f |\t\t", n, res);
		n++;
	}
	n = 1;
	printf("\n\n\nТабулювання функції f(n)=n*log(n)\n\n\n");
	while (n <= 50)
	{
		res = n * log(n);
		printf("|f(%d) = %.f |\t\t", n, res);
		n++;

	}
	n = 1;
	printf("\n\n\nТабулювання функції f(n)= n^2\n\n\n");
	while (n <= 50)
	{
		res = n * n;
		printf("|f(%d) = %.f |\t\t", n, res);
		n++;
	}
	n = 1;
	printf("\n\n\nТабулювання функції f(n)= 2^n\n\n\n");
	while (n <= 50)
	{
		res = pow(2, n);
		printf("\n|f(%d) = %.f |\t", n, res);
		n++;

	}
	n = 1;
	printf("\n\n\nТабулювання функції f(n)= n!\n\n\n");
	while (n <= 50)
	{
		res = FACTORIAL(n);
		printf("\n|f(%d) = %.f |\t", n, res);
		n++;
	}
}