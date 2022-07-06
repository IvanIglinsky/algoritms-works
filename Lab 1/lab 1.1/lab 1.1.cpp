#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    unsigned short hour : 5;
    unsigned short min : 6;
    unsigned short sec : 6;
    unsigned short day : 5;
    unsigned short month : 4;
    unsigned short year : 11;
   
}Time_And_Days;

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    Time_And_Days Time;
    unsigned short tmp;
    printf("Введіть поточний час:\n");
    
        printf("Годин:\n");
        scanf_s("%hu", &tmp);
        Time.hour = tmp;  
        printf("Хвилин:\n");
        scanf_s("%hu", &tmp);
        Time.min = tmp;    
        printf("Секунд:\n");
        scanf_s("%hu", &tmp);
        Time.sec = tmp;
        printf("День:\n");
        scanf_s("%hu", &tmp);
        Time.day = tmp;
        printf("Місяць:\n");
        scanf_s("%hu", &tmp);
        Time.month = tmp;
        printf("Рік:\n");
        scanf_s("%hu", &tmp);
        Time.year = tmp;
    printf("-------------------------------\n");
    printf("Поточий час: %02d:%02d:%02d\nПоточна дата: %02d.%02d.%d\n", Time.hour, Time.min, Time.sec, Time.day, Time.month, Time.year);
    printf("-------------------------------\n");
    printf("Обсяг пам'яті=%d байтів", sizeof(Time));
    printf("\n-----------------------------\n");
    printf("Виведення за допомогою Time.h\n");
    const time_t timer = time(NULL);
    printf("%s", ctime(&timer));
    printf("-------------------------------\n");
    printf("Обсяг пам'яті=%d байтів", sizeof(tm));
    return 0;
}