#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int hour, min, sec, day, month, year;
}Time_And_Days;


int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    bool fl = true;
    Time_And_Days Time;
    printf("Введіть поточний час: ");
    do
    {
        scanf("%d %d %d", &Time.hour, &Time.min, &Time.sec);
        if (Time.hour > 24  || Time.min > 60 ||  Time.sec > 60)
        {
            printf("Час введений не корректно!\nВведіть ще раз: ");
            fl = true;
        }
        else fl = false;
    } while (fl);
    printf("Введіть поточну дату: ");
    do {
        scanf("%d %d %d", &Time.day, &Time.month, &Time.year);
        if (Time.day > 31 || Time.month > 12 || Time.year > 2022)
        {
            printf("Час введений не корректно!\nВведіть ще раз: ");
            fl = true;
        }
        else fl = false;
    } while (fl);
    printf("-------------------------------\n");
    printf("Поточий час: %02d:%02d:%02d\nПоточна дата: %02d.%02d.%d\n", Time.hour, Time.min, Time.sec, Time.day, Time.month, Time.year);
    printf("-------------------------------\n");
    printf("Обсяг пам'яті=%d", sizeof(Time));
    printf("\n-----------------------------\n");
    printf("Виведення за допомогою Time.h\n");
    const time_t timer = time(NULL);
    printf("%s", ctime(&timer));
    printf("-------------------------------\n");
    printf("Обсяг пам'яті=%d", sizeof(timer));
    return 0;
}