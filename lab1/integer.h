#ifndef INTEGER_H
#define INTEGER_H

#include <stdlib.h>
#include <stdbool.h>

// функция сравнения
int intCompare(const int *left, const int *right);

// примеры функции для работы с map, reduce, where
void intFuncMap(int *element);
int *intFuncReduce(const int *first, const int *second);
bool intFuncWhere(const int* element);

#endif // INTEGER_H