#include "array.h"

void check_err(const Array *array) {
    if (array->first_element == NULL) Throw(NULL_POINTER);
    if (array->elementSize <= 0) Throw(WRONG_ELEMENT_SIZE);
    if (array->dimension <= 0) Throw(WRONG_DIMENSION);
}

void sort(Array *array) {
    check_err(array);
    if (array->compare == NULL) Throw(NO_COMPARATOR);
    qsort(array->first_element, array->dimension, array->elementSize, array->compare);
}

Array map(void (*func)(void *element), const Array *array) {
    check_err(array);
    Array result = {calloc(array->elementSize, array->dimension), array->dimension, array->elementSize};
    if (array->compare != NULL) result.compare = array->compare;
    memcpy(result.first_element, array->first_element, array->dimension * array->elementSize);
    for (size_t i = 0; i < array->dimension; i++) func(result.first_element + i * array->elementSize);
    return result;
}

void *reduce(void *(*func)(const void *first, const void *second), const Array *array, const void *start_element) {
    check_err(array);
    void *res = func(array->first_element, start_element);
    for (size_t i = 1; i < array->dimension; i++) res = func(array->first_element + i * array->elementSize, res);
    return res;
}

Array where(bool (*func)(const void *element), const Array *array) {
    check_err(array);
    Array result = {calloc(array->elementSize, array->dimension), array->dimension, array->elementSize};
    if (array->compare != NULL) result.compare = array->compare;
    for (int i = 0, j = 0; i < array->dimension; i++) {
        if (func(array->first_element + i * array->elementSize)) {
            memcpy(result.first_element + j * result.elementSize,
                   array->first_element + i * array->elementSize,
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
    memcpy(result.first_element, arr1->first_element, arr1->dimension * arr1->elementSize);
    memcpy(result.first_element + arr1->dimension * arr1->elementSize,
           arr2->first_element,arr2->dimension * arr2->elementSize);
    return result;
}