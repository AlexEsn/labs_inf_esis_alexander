#include <stdio.h>
#include "array.h"
#include "integer.h"


int main(int argc, char **argv) {
    CEXCEPTION_T EXCEPTION;
    
    int arr1[] = {2, 5, 1, 4, 7, 9, 3, 6, 10};
    Array integer1 = {arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), intCompare};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array integer2 = {arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), intCompare};
    Array integer3 = concatenat(&integer1, &integer2);
    for (int i = 0; i < integer3.dimension; i++)
        printf("%d ", *((int *) integer3.first_element + i));

    return 0;
}


