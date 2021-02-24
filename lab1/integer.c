#include "integer.h"

// функция сравнения
int intCompare(const int *left, const int *right) {
    return *left - *right;
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