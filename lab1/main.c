#include <stdio.h>
#include <stdfix.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "integer.h"

typedef struct Array {
    void *first_element;
    unsigned int size;
    unsigned int size_type;
} Array;

Array map(void (*func)(void *element), Array *array) {
    Array result = {calloc(array->size_type, array->size), array->size, array->size_type};
    memcpy(result.first_element, array->first_element, array->size * array->size_type);
    for (int i = 0; i < array->size; i++) func(result.first_element + i * array->size_type);
    return result;
}

void funcMap(int *element) {
    *((int *) element) = *((int *) element) + 2;
}

//void reduce(void (*func)(void *first, void *second), Array *array, void *start_element) {
//    func(array->first_element, start_element);
//    for (int i = 1; i < array->size - 1; i++) func(&array->first_element[i], );
//}

void funcReduce(int *first, int *second) {
    *second = *first * 2 + *second * 3;
}

Array where(bool (*func)(void *element), Array *array) {
    Array result = {calloc(array->size_type, array->size), array->size, array->size_type};
    memcpy(result.first_element, array->first_element, array->size * array->size_type);
    for (int i = 0, j = 0; i < array->size; i++)
        if (func(array->first_element + i * array->size_type)) {
            (result.first_element + j * array->size_type) = (array->first_element + i * array->size_type);
            j++;
        }
    return result;
}

int main(int argc, char **argv) {
    int arr[] = {1, 2, 3};
    Array integer = {arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0])};
    Array integer2 = map(funcMap, &integer);
//    sort(&integer, sizeof(int), (int (*)(const void *, const void *)) intCompare);
    for (int i = 0; i < integer2.size; i++) printf("%d ", *((int *) integer2.first_element + i));
//    printf("%d", reduce(intFunc, &integer, (int*) 4));

    return 0;
}