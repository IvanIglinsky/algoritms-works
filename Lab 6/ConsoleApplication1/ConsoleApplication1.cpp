#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <math.h>
private static void HeapSort(float[] array)
{
	int n = array.Length;

	//Побудова кучі (перегрупування масиву)
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify(array, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		float temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		Heapify(array, i, 0);
	}
}

//Сортування Шелла
private static void ShellSort(double[] arrayShell)
{
	int n = arrayShell.Length;
	int s = 0;

	while ((double)Math.Pow(2, s) + 1 <= n)//шукаємо найбільше s, яке задовільнить умову формули приросту
		s++;
	int step = (int)Math.Pow(2, s) + 1;//формула приросту стане кроком
	double c;
	while (s >= -1)//цикл сортування, який працюватиме поки s буде >= за -1
	{
		for (int i = 0; i < (n - step); i++) // створюємо групу елементів
		{
			int j = i;
			while (j >= 0 && arrayShell[j] > arrayShell[j + step]) //сортуємо простими вставками
			{
				c = arrayShell[j];
				arrayShell[j] = arrayShell[j + step];
				arrayShell[j + step] = c; // міняємо значення місцями
				j -= step; // переходимо до іншого елемента
			}
		}
		s--; //s зменшується на одиницю для того, щоб пройти по новоій групі
		step = (int)Math.Pow(2, s) + 1; // Перераховуємо step з новим s, щоб в майбутньому дійти до 1
	}
}

//Сортування підрахунком
private static void CountingSort(short[] array)
{
	short max = array.Max();  //Максимальний елемент масиву
	short min = array.Min(); //Мінімальний елемент масиву

	short[] counts = new short[max - min + 1]; //Масив частот 
	short[] output = new short[array.Length];

	for (int i = 0; i < array.Length; i++)
	{
		//Частота появи кожного числа
		counts[array[i] - min]++;
	}
	for (int i = 1; i < counts.Length; i++)
	{
		counts[i] += counts[i - 1];
	}
	for (int i = array.Length - 1; i >= 0; i--)
	{
		output[counts[array[i] - min] - 1] = array[i];
		counts[array[i] - min]--;
	}

	//Повертаємо у вихідний масив відсортований вхідний
	for (int i = 0; i < array.Length; i++)
	{
		array[i] = output[i];
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