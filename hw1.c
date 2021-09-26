#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH___STRING 11
#define MAX_LENGTH___INT 32

int main() {
    char c = 0;            
    char m1[MAX_LENGTH___STRING] = { 0 };           // массив, в который записываются числа введённые пользователем с клавиатуры
    char tmp[MAX_LENGTH___STRING] = { 0 };          // массив, для сохранения промежуточного значения переменной dec, он используется проверки не выходит ли число, введённое пользователем, за заданный диапазаон
    int m2[MAX_LENGTH___INT] = { 0 };               // массив, в котором находится двоичная запись введённого числа(в десятичной форме)
    int count_m1 = 0;                               // счётчик/кол-во символов в массива m1
    int dec = 0;                                    // число в десятичной форме
    int count_m2 = 0;                               // счётчик/кол-во символов в массиве m2
    int length_m2 = 0;
    int flag_null = 0;                              // флаг для определения незначащих нулей/ флаг для определения введённого нуля

    while (((c = getchar()) != '\n') && (count_m1 < 11)) {

        if (!isdigit(c)) {                                        // проверка на то, является ли символ - числом
            printf("403\n");
            return 403;
        }

        if ((flag_null) && (c != '0'))                                                                  
            flag_null = 0;
        if ((flag_null) && (c == '0'))
            continue;
        if ( (c == '0') && (count_m1 == 0) ) {                    // поднятие флага для не допуск в массив незначащих нулей
            flag_null = 1;
            continue;
        }

        m1[count_m1++] = c; 
    }

    if (flag_null) {
        printf("0\n");
        return 0;
    }

    if (count_m1 == 0) {                                          // проверка на то, ввёл ли пользователь число
        printf("404\n");
        return 404;
    }

    if (count_m1 > 10) {                                          // проверка на переполнение массива m1
        printf("404\n");
        return 404;
    }

    dec = atoi(m1);
    sprintf(tmp, "%d", dec);

        for (int j = 0; j < 10; j++) {                            // проверка, поместится ли введённое число в заданный диапазон
            if (m1[j] != tmp[j]) {
                printf("405\n");
                return 405;
            }
        }

    while (dec > 1) {                                             // перевод числа в десятичной форме в двоичную 
        m2[count_m2++] = dec % 2;
        dec /= 2;
    }
    m2[count_m2++] = dec;

    for (int j = count_m2 - 1; j >= 0; j--)
        printf("%d", m2[j]);

    printf("\n");

    return 0;
}
