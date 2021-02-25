#include <stdio.h>
#include <time.h>
#include "Array_lib/array.h"

const char *MENU1[] = {"0. Exit", "1. We working with integer numbers", "2. We working with real numbers"};
const int MENU1_SIZE = sizeof(MENU1) / sizeof(MENU1[0]);
const char *MENU2[] = {"0. Back", "1. Sort", "2. Map", "3. Reduce", "4. Where", "5. Concatenation"};
const int MENU2_SIZE = sizeof(MENU2) / sizeof(MENU2[0]);

// функция задержки для меню
void delay (int milli_seconds)
{
    int nano_seconds = 1000 * milli_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + nano_seconds);
}

// функция для работы меню
int dialog (const char *msgs[], int n)
{
    int choice;
    do {
        for (int i = 0; i < n; ++i)
            puts(msgs[i]);
        printf(">");

        choice = getchar() - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

        delay(500);
        printf("\033[0d\033[2J");

    } while (choice < 0 || choice >= n);

    return choice;
}

// примеры функции для работы с map, reduce, where
// позже добавлю ещё вариантов
void intFuncMap (int *element)
{
    *((int *) element) = *((int *) element) + 2;
}                              // просто к каждому элементу прибавляем 2
int *intFuncReduce (const int *first, const int *second)
{
    int *result = malloc(sizeof(int));
    *result = (*((int *) first)) * 2 + (*((int *) second)) * 3;
    return result;
}    // x1*2+x2*3
bool intFuncWhere (const int *element)
{
    return !(*element % 2);
}                      // берём четные



int main (int argc, char **argv)
{
    CEXCEPTION_T EXCEPTION;

    int menu1;
    do {
        menu1 = dialog(MENU1, MENU1_SIZE);
        switch (menu1) {
            case 1: {
                int menu2;
                Array array1 = constructIntArray();
                do {
                    menu2 = dialog(MENU2, MENU2_SIZE);
                    switch (menu2) {
                        case 1: {
                            sort(&array1);
                            printIntArray(&array1);
                        }
                            break;

                        case 2: {
                            Array array2 = map(intFuncMap, &array1);
                            printIntArray(&array2);
                            destructIntArray(&array2);
                            break;
                        }


                        case 3: {
                            int start_element = 4;
                            printf("%d", *((int *) reduce(intFuncReduce, &array1, &start_element)));
                            printf("\n");
                            break;
                        }


                        case 4: {
                            Array array2 = where(intFuncWhere, &array1);
                            printIntArray(&array2);
                            destructIntArray(&array2);
                            break;
                        }

                        case 5: {
                            Array array2 = constructIntArray();
                            Array array3 = concatenat(&array1, &array2);
                            printIntArray(&array3);
                            destructIntArray(&array3);
                            destructIntArray(&array2);
                            break;
                        }

                        default:
                            break;

                    }
                } while (menu2 != 0);
                free(array1.arr);
                break;
            }
            case 2:
                printf("Still in development\n");
                break;

            default:
                break;
        }
    } while (menu1 != 0);

    return 0;
}