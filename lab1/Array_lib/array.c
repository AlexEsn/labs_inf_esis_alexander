#include "array.h"

void check_err(const Array *array) {
    if (array->arr == NULL) Throw(NULL_POINTER);
    if (array->elementSize <= 0) Throw(WRONG_ELEMENT_SIZE);
    if (array->dimension <= 0) Throw(WRONG_DIMENSION);
}

void intPrint(const Array *array){
    for (size_t i = 0; i < array->dimension; i++)
        printf("%d ", *((int*)(array->arr + i*array->elementSize)));
}

void sort(Array *array) {
    check_err(array);
    if (array->compare == NULL) Throw(NO_COMPARATOR);
    qsort(array->arr, array->dimension, array->elementSize, array->compare);
}

Array map(void (*func)(void *element), const Array *array) {
    check_err(array);
    Array result = {calloc(array->elementSize, array->dimension), array->dimension, array->elementSize};
    if (array->compare != NULL) result.compare = array->compare;
    memcpy(result.arr, array->arr, array->dimension * array->elementSize);
    for (size_t i = 0; i < array->dimension; i++) func(result.arr + i * array->elementSize);
    return result;
}

void *reduce(void *(*func)(const void *first, const void *second), const Array *array, const void *start_element) {
    check_err(array);
    void *res = func(array->arr, start_element);
    for (size_t i = 1; i < array->dimension; i++) res = func(array->arr + i * array->elementSize, res);
    return res;
}

Array where(bool (*func)(const void *element), const Array *array) {
    check_err(array);
    Array result = {calloc(array->elementSize, array->dimension), array->dimension, array->elementSize};
    if (array->compare != NULL) result.compare = array->compare;
    for (size_t i = 0, j = 0; i < array->dimension; i++) {
        if (func(array->arr + i * array->elementSize)) {
            memcpy(result.arr + j * result.elementSize,
                   array->arr + i * array->elementSize,
                   array->elementSize);
            result.dimension = j + 1;
            j++;
        }
    }
    return result;
}

Array concatenat(const Array *arr1, const Array *arr2) {
    check_err(arr1);
    check_err(arr2);
    if (arr1->compare == NULL) Throw(NO_COMPARATOR);
    if (arr1->elementSize == arr2->elementSize) Throw(DIFFERENT_ELEMENT_SIZE);
    if (arr1->compare == arr2->compare) Throw(DIFFERENT_COMPARATOR);
    Array result = {calloc(arr1->dimension + arr2->dimension, arr1->elementSize),
                    arr1->dimension + arr2->dimension, arr1->elementSize, arr1->compare};
    memcpy(result.arr, arr1->arr, arr1->dimension * arr1->elementSize);
    memcpy(result.arr + arr1->dimension * arr1->elementSize,
           arr2->arr, arr2->dimension * arr2->elementSize);
    return result;
}

int intCompare(const int *left, const int *right) {
    return *left - *right;
}
