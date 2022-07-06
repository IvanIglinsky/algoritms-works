#include <stdio.h>
#include <windows.h>

union Num {
    float number;
    struct Bits
    {
        unsigned int Bit1 : 1;
        unsigned int Bit2 : 1;
        unsigned int Bit3 : 1;
        unsigned int Bit4 : 1;
        unsigned int Bit5 : 1;
        unsigned int Bit6 : 1;
        unsigned int Bit7 : 1;
        unsigned int Bit8 : 1;
        unsigned int Bit9 : 1;
        unsigned int Bit10 : 1;
        unsigned int Bit11 : 1;
        unsigned int Bit12 : 1;
        unsigned int Bit13 : 1;
        unsigned int Bit14 : 1;
        unsigned int Bit15 : 1;
        unsigned int Bit16 : 1;
        unsigned int Bit17 : 1;
        unsigned int Bit18 : 1;
        unsigned int Bit19 : 1;
        unsigned int Bit20 : 1;
        unsigned int Bit21 : 1;
        unsigned int Bit22 : 1;
        unsigned int Bit23 : 1;
        unsigned int Bit24 : 1;
        unsigned int Bit25 : 1;
        unsigned int Bit26 : 1;
        unsigned int Bit27 : 1;
        unsigned int Bit28 : 1;
        unsigned int Bit29 : 1;
        unsigned int Bit30 : 1;
        unsigned int Bit31 : 1;
        unsigned int Bit32 : 1;
    }bites;
    struct
    {
        unsigned char Byte1;
        unsigned char Byte2;
        unsigned char Byte3;
        unsigned char Byte4;
    }bytes;
}num;
int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    printf("1)Введіть число: "); scanf_s("%f", &num.number);
    printf("___________________\n");
    printf("2)Побітовий вивід числа = %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n", num.bites.Bit32, num.bites.Bit31, num.bites.Bit30,
        num.bites.Bit29, num.bites.Bit28, num.bites.Bit27, num.bites.Bit26, num.bites.Bit25, num.bites.Bit24,
        num.bites.Bit23, num.bites.Bit22, num.bites.Bit21, num.bites.Bit20, num.bites.Bit19, num.bites.Bit18,
        num.bites.Bit17, num.bites.Bit16, num.bites.Bit15, num.bites.Bit14, num.bites.Bit13, num.bites.Bit12, num.bites.Bit11,
        num.bites.Bit10, num.bites.Bit9, num.bites.Bit8, num.bites.Bit7, num.bites.Bit6, num.bites.Bit5, num.bites.Bit4, num.bites.Bit3, 
        num.bites.Bit2, num.bites.Bit1);
    printf("___________________\n");
    printf("3)Побайтовий вивід числа =%X %X %X %X\n", num.bytes.Byte4, num.bytes.Byte3, num.bytes.Byte2, num.bytes.Byte1);
    printf("___________________\n");
    if (num.bites.Bit32 == 1)
        printf("4)Знак %d = (Число від'ємне)\n", num.bites.Bit32);
    else
        printf("4)Знак %d = (Число додатнє)\n", num.bites.Bit32);
    printf("___________________\n");
    printf("5)Характеристика = %d%d%d%d %d%d%d%d\n", num.bites.Bit31, num.bites.Bit30, num.bites.Bit29, num.bites.Bit28, num.bites.Bit27, num.bites.Bit26, num.bites.Bit25, num.bites.Bit24);
    printf("___________________\n");
    printf("6)Мантиса = %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n", num.bites.Bit23, num.bites.Bit22, num.bites.Bit21, num.bites.Bit20, num.bites.Bit19, num.bites.Bit18, num.bites.Bit17, num.bites.Bit16, num.bites.Bit15, num.bites.Bit14, num.bites.Bit13, num.bites.Bit12, num.bites.Bit11, num.bites.Bit10, num.bites.Bit9, num.bites.Bit8, num.bites.Bit7, num.bites.Bit6, num.bites.Bit5, num.bites.Bit4, num.bites.Bit3, num.bites.Bit2, num.bites.Bit1);
    printf("___________________\n");
    printf("7)Розмір структури = %d\n", sizeof(num));
    return 0;
}