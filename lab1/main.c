#include <stdio.h>
#include <time.h>
#include "Array_lib/array.h"

const char *MENU1[] = {"0. Exit", "1. We working with integer numbers", "2. We working with real numbers"};
const int MENU1_SIZE = sizeof(MENU1) / sizeof(MENU1[0]);
const char *MENU2[] = {"0. Back to", "1. Sort", "2. Map", "3. Reduce", "4. Where", "5. Concatenation"};
const int MENU2_SIZE = sizeof(MENU2) / sizeof(MENU2[0]);

void delay(int milli_seconds) {
    int nano_seconds = 1000 * milli_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + nano_seconds);
}

// функция для раблты меню
int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        puts(error);
        error = "You're wrong. Try again!";
        delay(500);
        printf("\033[0d\033[2J");
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        printf(">");
        choice = getchar() - '0';
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

// примеры функции для работы с map, reduce, where
void intFuncMap(int *element) {
    *((int *) element) = *((int *) element) + 2;
}

int *intFuncReduce(const int *first, const int *second) {
    int *result = malloc(sizeof(int));
    *result = (*((int *) first)) * 2 + (*((int *) second)) * 3;
    return result;
}

bool intFuncWhere(const int *element) {
    return !(*element % 2);
}

int main(int argc, char **argv) {
    CEXCEPTION_T EXCEPTION;

    int menu1; // выбранный пункт меню
    do {
        menu1 = dialog(MENU1, MENU1_SIZE);
        int menu2;
        switch (menu1) {
            case 1: {
                printf("Enter array elements\n");
                int *arr1 = malloc(sizeof(int));
                size_t dist = 0;
                unsigned char num = getchar();
                while (num != '\n') {
                    if(num != ' ' && num != ','){
                        arr1[dist] = num - '0';
                        dist++;
                        arr1 = realloc(arr1, (dist + 1) * sizeof(int));
                    }
                    num = getchar();
                }
                Array array1 = {arr1, dist, sizeof(int), intCompare};
                do {
                    menu2 = dialog(MENU2, MENU2_SIZE);
                    switch (menu2) {
                        case 1: sort(&array1);
                        intPrint(&array1);
                    }
                } while (menu2);
                break;
            }
            case 2:
                printf("Still in development");
                break;
        }
    } while (menu1);

    int arr1[] = {2, 5, 1, 4, 7, 9, 3, 6, 10};
    Array integer1 = {arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), intCompare};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array integer2 = {arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), intCompare};
    Array integer3 = concatenat(&integer1, &integer2);
    for (int i = 0; i < integer3.dimension; i++)
        printf("%d ", *((int *) integer3.arr + i));

    return 0;
}


