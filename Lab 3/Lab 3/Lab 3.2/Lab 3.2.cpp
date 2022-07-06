#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    string s;
    int x = 0;
    int i;
    int m;
    int a;
    clock_t start, finish;
    cout << "Уведіть число:";
    cin >> s;
    start=clock();
    for (m = 1, i = s.length(); i > 0; --i, m *= 10)
    {
        x += m * (((int)s[i - 1]) - ((int)'0'));
    }
    a = x;
    cout << "Число в двійковій:";
    do
    {
        cout << (a % 2);
        a /= 2;
    } while (a != 0);
    finish = clock();
    float dd = (float)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nЧас виконання в секундах" << dd;
}