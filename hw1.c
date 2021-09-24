#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH___STRING 12
#define MAX_LENGTH___INT 32

int main() {
    char c = 0;            
    char m1[MAX_LENGTH___STRING] = { 0 };           // массив, в который записываются числа введённые пользователем с клавиатуры
    char tmp[MAX_LENGTH___STRING] = { 0 };          // массив, для сохранения промежуточного значения переменной dec, он используется проверки не выходит ли число, введённое пользователем, за заданный диапазаон
    int m2[MAX_LENGTH___INT] = { 0 };               // массив, в котором находится двоичная запись введённого числа(в десятичной форме)
    int count_m1 = 0;                               // счётчик/кол-во символов в массива m1
    long int dec = 0;                               // число в десятичной форме
    int count_m2 = 0;                               // счётчик/кол-во символов в массиве m2
    int length_m2 = 0;
    int flag_sign = 0;                              // показывает знак(+/-) введённого числа
    int flag_null = 0;                              // флаг для определения незначащих нулей/ флаг для определения введённого нуля

    for (; ((c = getchar()) != '\n') && (count_m1 < 12);) {                                             // ввод числа с клавиатуры

        if ((!isdigit(c)) && !((count_m1 == 0) && (c == '-'))) {                                        // проверка на то, является ли символ - числом
            printf("403\n");
            return 403;
        }

        if ((flag_null) && (c != '0'))                                                                  
            flag_null = 0;
        if ((flag_null) && (c == '0'))
            continue;
        if ( (c == '0') && ((count_m1 == 0) || ((count_m1 == 1) && (m1[0] == '-'))) ) {                 // поднятие флага для не допуск в массив незначащих нулей
            flag_null = 1;
            continue;
        }


        m1[count_m1++] = c; 
    }

    if (flag_null) {
        printf("0 0\n");
        return 0;
    }

    if ((count_m1 == 0) || ((count_m1 == 1) && (m1[count_m1 - 1] == '-')) ) {                           // проверка на то, ввёл ли пользователь число
        printf("404\n");
        return 404;
    }

    if (count_m1 > 11) {                                                                                // проверка на переполнение массива m1
        printf("404\n");
        return 404;
    }

    dec = atoi(m1);
    sprintf(tmp, "%ld", dec);

    if (m1[0] == '-') {                                                                                 // определяем знак введённого числа
        flag_sign = 1;

        for (int j = 0; j < 11; j++) {                                                                  // проверка, поместится ли введённое число в заданный диапазон
            if (m1[j] != tmp[j]) {
                printf("405\n");
                return 405;
            }
        }
    }
    else {
        if (count_m1 > 10) {
            printf("405\n");
            return 405;
        }
        for (int j = 0; j < 10; j++) {
            if (m1[j] != tmp[j]) {
                printf("405\n");
                return 405;
            }
        }
    }

    if ((flag_sign) && (dec != 0)) {                                  // учёт знака числа в двоичной форме записи 
        printf("1 ");
    }    
    else
        printf("0 ");

    if (dec < 0) {                                                    // модуль числа dec
        dec = -dec;
    }

    while (dec >= pow(2, count_m2)) {                                 // определение ближайшей степени двойки, при условии 2^(count_m2) >= dec
        count_m2++;
    }
    length_m2 = count_m2;

    while (dec > 1) {                                                 // перевод числа в десятичной форме в двоичную 
        m2[--count_m2] = dec % 2;
        dec /= 2;
    }
    m2[--count_m2] = dec;

    for (int j = 0; j < length_m2; j++)
        printf("%d", m2[j]);

    printf("\n");

    return 0;
}
