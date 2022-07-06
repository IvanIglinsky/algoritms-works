#include <stdio.h>
#ifndef _CLIST_H_
#define _CLIST_H_
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

typedef int elemtype;       

struct elem {
    elemtype* value;        
    struct elem* next;      
    struct elem* prev;      
};

struct myList {
    struct elem* head;      
    struct elem* tail;      
    size_t size;         
};

typedef struct elem cNode;
typedef struct myList cList;

cList* createList(void);
void deleteList(cList* list);
bool isEmptyList(cList* list);
int pushFront(cList* list, elemtype* data);
int popFront(cList* list, elemtype* data);
int pushBack(cList* list, elemtype* data);
int popBack(cList* list, elemtype* data);
cNode* getNode(cList* list, int index);
void printList(cList* list, void (*fun)(elemtype*));

#endif  //_CLIST_H_

// Створення нового списку
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

// Перевірка на пустоту
bool isEmptyList(cList* list) {
    return ((list->head == NULL) || (list->tail == NULL));
}

// Додавання нового вузла на початок списку
int pushFront(cList* list, elemtype* data) {
    cNode* node = (cNode*)malloc(sizeof(cNode));
    if (!node) {
        return(-1);
    }
    node->value = data;
    node->next = list->head;
    node->prev = NULL;

    if (!isEmptyList(list)) {
        list->head->prev = node;
    }
    else {
        list->tail = node;
    }
    list->head = node;

    list->size++;
    return(0);
}

// Вилучення вузла з початку списку
int popFront(cList* list, elemtype* data) {
    cNode* node;

    if (isEmptyList(list)) {
        return(-2);
    }

    node = list->head;
    list->head = list->head->next;

    if (!isEmptyList(list)) {
        list->head->prev = NULL;
    }
    else {
        list->tail = NULL;
    }

    data = node->value;
    list->size--;
    free(node);

    return(0);
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

// Вилучення вузла з кінця списку
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

// Читання вузла списка
cNode* getNode(cList* list, int index) {
    cNode* node = NULL;
    int i;

    if (index >= list->size) {
        return (NULL);
    }

    if (index < list->size / 2) {
        i = 0;
        node = list->head;
        while (node && i < index) {
            node = node->next;
            i++;
        }
    }
    else {
        i = list->size - 1;
        node = list->tail;
        while (node && i > index) {
            node = node->prev;
            i--;
        }
    }

    return node;
}

// Вивод списка в консоль
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
void printNode(elemtype* value) {
    printf("%d\n", *((int*)value));
}

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    printf("Уведіть перший елемент:");
    elemtype a;
    scanf_s("%d", &a);

    printf("Уведіть другий елемент:");
    elemtype b;
    scanf_s("%d", &b);
    printf("Уведіть третій  елемент:");
    elemtype c;
    scanf_s("%d", &c);
    elemtype tmp;
    cList* mylist = createList();
    pushFront(mylist, &b);
    pushFront(mylist, &a);
    pushBack(mylist, &c);
    int x = 0, y = 0;
    int num;
    bool YesNo = true;

    do {
        printf("\nВиберіть пункт меню\n");
        printf("1-Додавання нового вузла на початок списку\n");
        printf("2-Вилучення вузла з початку списку\n");
        printf("3-Додавання нового вузла в кінець списку\n");
        printf("4- Вилучення вузла з кінця списку\n");
        printf("5-Видалення списку\n");
        printf("6-Виведення всього списку\n");
        scanf_s("%d", &num);
    
        switch (num)
        {
        case 1:
        {
            x = 0;
            printf("Увдіть елемент для додавання:\n");
            scanf_s("%d", &x);
            printf("---------\n");
            pushFront(mylist, &x);
            printList(mylist, printNode);
            printf("\n");
            break;
        }
        case 2:
        {
            popFront(mylist, &tmp);
            printList(mylist, printNode);
            printf("\n");
            break;
        }
        case 3:
        {
            y = 0;
            printf("Увдіть елемент для додавання:\n");
            scanf_s("%d", &y);
            printf("---------\n");
            pushBack(mylist, &y);
    
            printList(mylist, printNode);
            printf("\n");
            break;
        }
        case 4:
        {
            popBack(mylist, &tmp);
            break;
        }
        case 5:
        {
            deleteList(mylist);
            break;
        }
        case 6:
        {
            printList(mylist, printNode);
            break;
        }
        }
        printf("Бажаєте продожити?\n1-Так\n2-Ні\n");
        int xt = 0;
        scanf_s("%d", &xt);
        if (xt == 1)
            YesNo = true;
        else
        {
            YesNo = false;
        }
    } while (YesNo == true);
        system("pause");
        return 0;
}
