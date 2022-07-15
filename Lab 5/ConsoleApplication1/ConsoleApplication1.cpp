#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>
#include <chrono>
#include <stdbool.h>
#define MAX_N 100000
typedef int elemtype;
struct elem {
	elemtype* value;   // Значення змінної
	struct elem* next; // Ссилка на наступний елемент
	struct elem* prev; // Ссилка на попередній елемент списку
};
struct myList {
	struct elem* head;    // Перший елемент списку
	struct elem* tail;   // Останнній елемент списку
	size_t size; 		// Кількість елементів в списку
};
typedef struct elem cNode;
typedef struct myList cList;
// Створення пустого списку
cList* createList(void) {
	cList* list = (cList*)malloc(sizeof(cList));
	if (list) {
		list->size = 0;
		list->head = list->tail = NULL;
	}
	return list;
}
// Видалення списку
void deleteList(cList* list) {
	cNode* head = list->head;
	cNode* next = NULL;
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
	free(list);
	list = NULL;
}
// Перевірка списку на пустоту
bool isEmptyList(cList* list) {
	return ((list->head == NULL) || (list->tail == NULL));
}
// Додавання нового вузла в кінець списку
int pushBack(cList* list, elemtype* data) {
	cNode* node = (cNode*)malloc(sizeof(cNode));
	if (!node) {
		return(-3);
	}
	node->value = data;
	node->next = NULL;
	node->prev = list->tail;
	if (!isEmptyList(list)) {
		list->tail->next = node;
	}
	else {
		list->head = node;
	}
	list->tail = node;
	list->size++;
	return(0);
}
// Видалення вузла з кінця списку
int popBack(cList* list, elemtype* data) {
	cNode* node = NULL;
	if (isEmptyList(list)) {
		return(-4);
	}
	node = list->tail;
	list->tail = list->tail->prev;
	if (!isEmptyList(list)) {
		list->tail->next = NULL;
	}
	else {
		list->head = NULL;
	}
	data = node->value;
	list->size--;
	free(node);
	return(0);
}
// Вивід списку в консоль
void printList(cList* list, void (*func)(elemtype*)) {
	cNode* node = list->head;
	if (isEmptyList(list)) {
		return;
	}
	while (node) {
		func(node->value);
		node = node->next;
	}
}
cList* createList(void);
void deleteList(cList* list);
bool isEmptyList(cList* list);
int pushBack(cList* list, elemtype* data);
void printList(cList* list, void (*fun)(elemtype*));
void printNode(elemtype* value) {
	printf("%d ", *((int*)value));
}
void menu()
{
	system("cls");
	printf("1. Сортування вибором (двусвязний список)\n");
	printf("2. Сортування вставками (масив)\n");
	printf("3. Сортування вставками (двусвязний список)\n");
	printf("4. Вихід\n");
	printf("Введіть пункт меню: ");
}
int get_variant(int count) {
	int variant;
	scanf_s("%d", &variant);
	return variant;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cList* mylist = createList();
	cList* mylist2 = createList();
	int list[MAX_N], arr[MAX_N], a, b, n, c, min;
	int variant, k;
	srand(time(0));
	printf("Введіть діапазон чисел: [a;b];\na="); scanf_s("%d", &a);
	printf("b="); scanf_s("%d", &b);
	printf("Кількість елементів:"); scanf_s("%d", &n);
	do {
		menu();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		variant = get_variant(5);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		switch (variant)
		{
		case 1:
		{
			auto begin = std::chrono::steady_clock::now();
			for (int i = 0; i < n; i++) {
				list[i] = a + rand() % (b - a + 1);
				pushBack(mylist, &list[i]);
			}
			printList(mylist, printNode);
			for (int i = 0; i < n - 1; i++)
			{
				min = i;    //позначаємо елемент як мінімальний
					for (int j = i + 1; j < n; j++)
						if (list[j] < list[min])
							//порівнюємо мінімальний елемент з наступним, якщо наступний менший, то позначаємо його як мінімальний
							min = j;
				//проходимося по всім елементам, знаходимо найменший
				c = list[i];
				list[i] = list[min];
				list[min] = c;
			}
			printf("\n\n---------- Відсортований зв'язний список ----------\n\n");
			printList(mylist, printNode);
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			printf("\nЧас сортування: %lld ms\n", elapsed_ms.count());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		break;
		case 2:
		{
			auto begin = std::chrono::steady_clock::now();
			for (int i = 0; i < n; i++)
				arr[i] = a + rand() % (b - a + 1);
			for (int i = 0; i < n; i++)
				printf("%4d", arr[i]);
			for (int i = 1; i < n; i++)
			{
				c = arr[i];
				for (int j = i - 1; j >= 0 && arr[j] > c; j--)
				{
					arr[j + 1] = arr[j];//перебираємо масив і ставимо  елементи в правильному положенні  серед масиву
					arr[j] = c;
				}
			}
			printf("\n\n---------- Відсортований масив ----------\n\n");
			for (int i = 0; i < n; i++)
				printf("%4d", arr[i]);
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			printf("\nЧас сортування: %lld ms\n", elapsed_ms.count());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		break;
		case 3:
		{
			auto begin = std::chrono::steady_clock::now();
			for (int i = 0; i < n; i++) {
				list[i] = a + rand() % (b - a + 1);
				pushBack(mylist2, &list[i]);
			}
			printList(mylist2, printNode);
			for (int i = 1; i < n; i++)
			{
				c = list[i];
				for (int j = i - 1; j >= 0 && list[j] > c; j--)
				{
					list[j + 1] = list[j];//перебираємо список і ставимо  елементи в правильному положенні  серед списку

					list[j] = c;
				}
			}
			printf("\n\n---------- Відсортований зв'язний список ----------\n\n");
			printList(mylist2, printNode);
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			printf("\nЧас сортування: %lld ms\n", elapsed_ms.count());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		break;
		case 4:
			break;
		}
		if (variant != 10)
			system("pause");

	} while (variant != 4);
}
