#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <math.h>

void HeapSort(float* HeapArr, int n, int i)
{
	float tmp;
	int larg = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<n && HeapArr[left]>HeapArr[larg])//якщо лівий нащадок > корінь
		larg = left;
	if (right<n && HeapArr[right]>HeapArr[larg])//якщо правий нащадок > корінь
		larg = right;
	if (larg != i)//Якщо найбільший елемент не є коренем
	{
		tmp = HeapArr[i];
		HeapArr[i] = HeapArr[larg];
		HeapArr[larg] = tmp;
		HeapSort(HeapArr, n, larg);//Рекурсивно перетворюємо в кучу піддерево з нащадків найбільшого елемента
	}
}
void ShellSort(int n, int Shellarr[])
{
	
	int s = 1;
	int step = pow(2,s)-1, tmp = 0;
	//Переставляєм елементи на кожні n/2, n/4, n/8, ... інтервали
	while (step > 0)
	{
		for (int i = 0; i < (n - step); i++)
		{
			int j = i;
			while (j >= 0 && Shellarr[j] > Shellarr[j + step])
			{
				float tmp = Shellarr[j];
				Shellarr[j] = Shellarr[j + step];
				Shellarr[j + step] = tmp;
				j--;
			}
		}
		s++;
		step /= 2;
	}
}
void CountSort(short CountArr[], int size) {
	short output[10004]{};
	// Знайти найбільший елемент масиву
	short max = CountArr[0];
	short min = CountArr[0];
	for (int i = 1; i < size; i++) {
		if (CountArr[i] > max)
			max = CountArr[i];
	}
	for (int i = 1; i < size; i++) {
		if (CountArr[i] < min)
			min = CountArr[i];
	}
	// Розмір підрахунку має бути принаймні (max+1), але
	// ми не можемо оголосити це як int count(max+1) у C як
	// він не підтримує динамічний розподіл пам'яті.
	// Отже, його розмір надається статично.
	short count[10001]{};
	// Ініціалізація масиву лічильників усіма нулями.
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}
	// Зберігає кількість кожного елемента
	for (int i = 0; i < size; i++) {
		count[CountArr[i]-min]++;
	}
	// Зберігає кумулятивну кількість кожного масиву
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}
	// Знайти індекс кожного елемента вихідного масиву в масиві count, і
	// розмістити елементи у вихідному масиві
	for (int i = size-1 ; i >= 0; i--) {
		output[count[CountArr[i] - min] -1] = CountArr[i];
		count[CountArr[i]-min]--;
	}
	// Копіювати відсортовані елементи в оригінальний масив
	for (int i = 0; i < size; i++) {
		CountArr[i] = output[i];
	}

}

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	srand(time(0));
	int n;
	float i=0,  x=0, tmp, HeapArr[10001];
	printf("Введіть розмірність масиву: ");
	scanf_s("%d", &n);
	//HeapSort
	printf("Сортування масиву методом (Heap Sort)\n");
	printf("\nМасив до сортування:{ ");
	for (int i = 0; i < n; i++)
	{
		HeapArr[i] =0.01*(rand()%11000-10000);
		printf("%.2f  ", HeapArr[i]);
	}
	printf(" }\n");
	auto start = std::chrono::steady_clock::now();
	for (int i = n / 2 - 1; i >= 0; i--)
		HeapSort(HeapArr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		tmp = HeapArr[0];
		HeapArr[0] = HeapArr[i];
		HeapArr[i] = tmp;
		HeapSort(HeapArr, i, 0);
	}
	auto end = std::chrono::steady_clock::now();
	auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	printf("\nМасив після сортування:{ ");
	
	for (int i = 0; i < n; i++)
	{
		printf("%.2f  ", HeapArr[i]);
	}
	printf(" }");
	printf("\nЧас витрачений на сортування:%lld nanoS\n", res.count());
	printf("\n---------------------------------------------\n");
	//ShellSort

	int Shellarr[10001];
	printf("Сортування масиву методом (Shell Sort)\n");
	printf("\nМасив до сортування:{ ");
	for (int i = 0; i < n; i++)
	{
		Shellarr[i] =   rand() % 401;
		printf("%d  ", Shellarr[i]);
	}
	printf(" }\n");
	auto start1 = std::chrono::steady_clock::now();
	for(int i=0;i<n;i++)
		ShellSort(n, Shellarr);
	auto end1 = std::chrono::steady_clock::now();
	auto res1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
	printf("\nМасив після сортування:{ ");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", Shellarr[i]);
	}
	printf(" }");
	printf("\nЧас витрачений на сортування:%lld nanoS", res1.count());
	printf("\n---------------------------------------------\n");

	//CountSort
	
	short CountArr[10004];
	printf("Сортування масиву методом (Count Sort)\n");
	printf("\nМасив до сортування:{ ");
	for (int i = 0; i < n; i++)
	{
		CountArr[i] = rand() % 111-10;
		printf("%d  ", CountArr[i]);
	}
	printf(" }\n");
	auto start2 = std::chrono::steady_clock::now();
	for (int i = 0; i < n; i++)
		CountSort(CountArr,n);
	auto end2 = std::chrono::steady_clock::now();
	auto res2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
	printf("\nМасив після сортування:{ ");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", CountArr[i]);
	}
	printf(" }");
	printf("\nЧас витрачений на сортування:%lld nanoS", res2.count());
	printf("\n---------------------------------------------\n");
	return 0;
}