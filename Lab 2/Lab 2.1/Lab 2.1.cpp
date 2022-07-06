#include <stdio.h>
#include <Windows.h>
#include <math.h>
unsigned char period(unsigned int array[], int a);
int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	unsigned long long a = 22695477, c = 1, m = pow(2, 32),k=40000;
	unsigned int* array;
	unsigned int* array2;
	array = (unsigned int*)malloc(sizeof(unsigned int) * k);
	array2=(unsigned int*)malloc(sizeof(unsigned int) * k);
	unsigned arrays[250];
	float arrays2[250], S = 0, bm = 0;
	for (int i = 0; i < k - 1; i++)
	{
		array[i + 1] = (a * array[i] - c) % m;
	}
	for (int i = 0; i < k; i++)
	{
		array2[i] = array[i] % 250;
		printf("%d\t", array2[i]);
	}
	printf("\n--------------------------------------------------------------\n");
	printf("Частота інтервалів появи випадкових величин\n");
	for (int i = 0; i < 250; i++)
	{
		arrays[i] = period(array2, i);
		printf("%d - %d\n", i, arrays[i]);
	}
	printf("\n--------------------------------------------------------------\n");
	printf("Статистична імовірність появи випадкових величин\n");
	for (int i = 0; i < 250; i++)
	{
		arrays2[i] = (float)arrays[i] / k;
		printf("%d - %.4f\n", i, arrays2[i]);
	}
	printf("\n--------------------------------------------------------------\n");
	for (int i = 0; i < 250; i++)
		S += i * arrays2[i];
	printf("Математичне сподівання випадкових величин:%f",S);
	for (int i = 0; i < 250; i++)
		bm += pow((i - S), 2) * arrays2[i];
	printf("\n");
	printf("Дисперсія випадкових величин:%f\n", bm);
	printf("Cередньоквадратичне відхилення випадкових величин:%f\n",sqrt(bm));
	return 0;
}	
unsigned char period(unsigned int array[], int a)
{
	int d = 0;
	for (int i = 0; i < 40000; i++)
	{
		if (array[i] == a)
			d++;
	}
	return d;
}