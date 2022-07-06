#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <time.h>
#include <chrono>
#include <stdbool.h>
#include <stdlib.h>
#include "ConsoleApplication1.h"
#define _CLIST_H
#include <malloc.h>

typedef int elemtype;
struct elem {
	elemtype value;
	struct elem* next;
	struct elem* prev;
};
struct myList {
	struct elem* head;
	struct elem* tail;
	int size;
};

typedef struct elem cNode;
typedef struct myList cList;

cList* createList(void) {
	cList* list = (cList*)malloc(sizeof(cList));
	if (list) {
		list->size = 0;
		list->head = list->tail = NULL;
	}
	return list;
}
bool isEmptyList(cList* list) {
	return ((list->head == NULL) || (list->tail == NULL));
}
void deleteList(cList* list) {
	cNode* head = list->head;
	cNode* next = NULL;
	while (head) {
		next = head->next;
		free(head);
		head = NULL;
		head = next;
	}
	free(list);
	list = NULL;
}
int pushBack(cList* list, elemtype data) {
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
int popBack(cList* list, elemtype data) {
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
void printList(cList* list, void (*func)(elemtype)) {
	cNode* node = list->head;
	if (isEmptyList(list)) {
		return;
	}
	while (node) {
		func(node->value);
		node = node->next;
	}
}
//------------------------------------------------------------------------------
typedef int elemtype2;
struct elem2 {
	elemtype2* value2;
	struct elem2* next2;
	struct elem2* prev2;
};
struct myList2 {
	struct elem2* head2;
	struct elem2* tail2;
	int size2;
};

typedef struct elem2 cNode2;
typedef struct myList2 cList2;

cList2* createList2(void) {
	cList2* list2 = (cList2*)malloc(sizeof(cList2));
	if (list2) {
		list2->size2 = 0;
		list2->head2 = list2->tail2 = NULL;
	}
	return list2;
}
bool isEmptyList2(cList2* list2) {
	return ((list2->head2 == NULL) || (list2->tail2 == NULL));
}
void deleteList2(cList2* list2) {
	cNode2* head = list2->head2;
	cNode2* next = NULL;
	while (head) {
		next = head->next2;
		free(head);
		head = next;
	}
	free(list2);
	list2 = NULL;
}
int pushBack2(cList2* list2, elemtype2* data) {
	cNode2* node = (cNode2*)malloc(sizeof(cNode2));
	if (!node) {
		return(-3);
	}
	node->value2 = data;
	node->next2 = NULL;
	node->prev2 = list2->tail2;
	if (!isEmptyList2(list2)) {
		list2->tail2->next2 = node;
	}
	else {
		list2->head2 = node;
	}
	list2->tail2 = node;
	list2->size2++;
	return(0);
}
int popBack2(cList2* list2, elemtype2* data) {
	cNode2* node = NULL;
	if (isEmptyList2(list2)) {
		return(-4);
	}
	node = list2->tail2;
	list2->tail2 = list2->tail2->prev2;
	if (!isEmptyList2(list2)) {
		list2->tail2->next2 = NULL;
	}
	else {
		list2->head2 = NULL;
	}
	data = node->value2;
	list2->size2--;
	free(node);
	return(0);
}
void printList2(cList2* list2, void (*func)(elemtype2*)) {
	cNode2* node = list2->head2;

	if (isEmptyList2(list2)) {
		return;
	}

	while (node) {
		func(node->value2);
		node = node->next2;
	}
}

void printMenu()
{
	system("cls");
	printf("Виберіть метод сортування:\n");
	printf("1-Сортування вибором(структура даних – двусвязний список)\n");
	printf("2-Сортування вставками (структура даних – масив)\n");
	printf("3-Сортування вставками(структура даних – двусвязний список)\n");
	printf("4-Вихід\n");

}
void printNode(elemtype value)
{
	printf("%d ", value);
}
void printNode2(elemtype2* value2)
{
	printf("%d ", *((int*)value2));
}
int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int arr[100000], n, num, tmp;
	printf("Оберіть кількість елементів в масиві для сортування: ");
	scanf_s("%d", &n);
	do {
		printMenu();
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
		{
			cList* list = createList();
			for (int i = 0; i < n; i++)
			{
				tmp = 100 + rand() % (-100 - 100 + 1);
				pushBack(list, tmp);
			}
			printf("До сортування:{ ");
			printList(list, printNode);
			printf("}");
			cNode* min;
			cNode* builder;
			cNode* checker;
			builder = list->head;
			min = builder->next;
			checker = min->next;
			cNode* temp = (cNode*)malloc(sizeof(cNode));
			auto begin = std::chrono::steady_clock::now();
			for (int i = 1; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (min->value>checker->value) //шукаємо менший елемент
					{
						min = checker;//пересуваємо вказівник до меншого елемента
						checker = checker->next;//Змінну пошуку відправляєм далі
					}
					else checker = checker->next;//Якщо не знайшли менший, то змінну пошуку відправляєм далі
				}
				if (min->value < builder->value)//Тут перевіряєм, чи знайдений нами елемент менше першого
				{
					temp->value = builder->value;//значення більшого елемента запам'ятовуємо
					builder->value = min->value;//на його місце ставимо той,що знайшли
					min->value = temp->value;//присвоюємо змінній значення,за рахунок якого будем шукати наступний елемент
				}
				if (i < n - 1)//здвигаємо значення на 1 вперед
				{
					builder = builder->next;
					min = builder->next;
					checker = min->next;
				}
			}
			auto end = std::chrono::steady_clock::now();
			auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
			printf("\n\nПісля сортування: { ");
			printList(list, printNode);
			printf("} \nЧас виконання сортування :%lld nanoS \n", result.count());
			deleteList(list);
			break;
		}
		case 2:
		{
			for (int i = 0; i < n; i++)
				arr[i] = 100 + rand() % (-100 - 100 + 1);
			printf("До сортування: { ");
			for (int i = 0; i < n; i++)
				printf("%2d   ", arr[i]);
			printf(" }\n");
			auto begin2 = std::chrono::steady_clock::now();
			for (int i = 1; i < n; i++)
			{
				tmp = arr[i];//Беремо перший елемент масиву
				for (int j = i - 1; j >= 0 && arr[j] > tmp; j--)//проходимо по елементам які стояли пред ним та перевіряємо, що цей елемент ще не менший ніж той, з яким порівнюємо
				{
					arr[j + 1] = arr[j];//Тут преставляємо елемент tmp назад
					arr[j] = tmp;//Переносимо елемент який ми переставили на місце того,що був менше його
				}
			}
			auto end2 = std::chrono::steady_clock::now();
			auto result2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
			printf("\n\nПісля сортування: { ");
			for (int i = 0; i < n; i++)
				printf("%2d   ", arr[i]);
			printf(" }\n\n");
			printf("Час виконання сортування:%lld nanoS\n", result2.count());
		}
		break;
		case 3:
		{
			cList2* list2 = createList2();
			int arrlist[100000];
			for (int i = 0; i < n; i++)
			{
				arrlist[i]= 100 + rand() % (-100 - 100 + 1);
				pushBack2(list2, &arrlist[i]);
			}
			printf("До сортування: { ");
			printList2(list2, printNode2);
			printf(" }\n");
			auto begin3 = std::chrono::steady_clock::now();
			for (int i = 1; i < n; i++)
			{
				tmp = arrlist[i];//Беремо перший елемент масиву
				for (int j = i - 1; j >= 0 && arrlist[j] > tmp; j--)//проходим по елементам які стояли до цього
				{
					arrlist[j + 1] = arrlist[j];//тут преставляємо елемент tmp
					arrlist[j] = tmp;//Переносимо елемент який ми поставили на місце того,що був менше
				}
			}
			auto end3 = std::chrono::steady_clock::now();
			auto result3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);
			printf("\n\nПісля сортування: { ");
			printList2(list2, printNode2);
			printf(" }\n\n");
			printf("Час виконання сортування:%lld nanoS\n", result3.count());
			deleteList2(list2);
		}
		break;
		case 4:
			break;
		default:{
			printf("Помилка при введенні пунката меню\n");
		}
			   break;
		}
		if (num != 4)
			system("pause");
	} while (num != 4);
	return 0;
}
