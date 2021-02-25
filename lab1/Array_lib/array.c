#include "array.h"

void checkError (const Array *array)
{
    if (array->arr == NULL)
        Throw(NULL_POINTER);
    if (array->elementSize <= 0)
        Throw(WRONG_ELEMENT_SIZE);
    if (array->dimension <= 0)
        Throw(WRONG_DIMENSION);
}       //пока с регестрицией ошибок не работаю

void sort (Array *array)
{
    checkError(array);
    if (array->compare == NULL)
        Throw(NO_COMPARATOR);

    qsort(array->arr,
          array->dimension,
          array->elementSize,
          array->compare);
}

Array map (void (*func) (void *element), const Array *array)
{
    checkError(array);

    Array result = {malloc(array->elementSize * array->dimension),
                    array->dimension,
                    array->elementSize};

    if (array->compare != NULL)
        result.compare = array->compare;

    memcpy(result.arr,
           array->arr,
           array->dimension * array->elementSize);

    for (size_t i = 0; i < array->dimension; i++)
        func(result.arr + i * array->elementSize);

    return result;
}

void *reduce (void *(*func) (const void *first, const void *second),
              const Array *array,
              const void *start_element)
{
    checkError(array);

    void *res = func(array->arr, start_element);

    for (size_t i = 1; i < array->dimension; i++)
        res = func(array->arr + i * array->elementSize, res);

    return res;
}

Array where (bool (*func) (const void *element), const Array *array)
{
    checkError(array);

    Array result = {malloc(array->elementSize * array->dimension),
                    array->dimension,
                    array->elementSize};

    if (array->compare != NULL)
        result.compare = array->compare;

    size_t newDimension = 0;
    for (size_t i = 0; i < array->dimension; i++) {

        bool isConditionOk = func(array->arr + i * array->elementSize);
        if (isConditionOk) {
            memcpy(result.arr + newDimension * result.elementSize,
                   array->arr + i * array->elementSize,
                   array->elementSize);

            newDimension++;
        }

    }
    result.dimension = newDimension;

    return result;
}

Array concatenat (const Array *arr1, const Array *arr2)
{
    checkError(arr1);
    checkError(arr2);

    if (arr1->compare == NULL)
        Throw(NO_COMPARATOR);
    if (arr1->elementSize == arr2->elementSize)
        Throw(DIFFERENT_ELEMENT_SIZE);
    if (arr1->compare == arr2->compare)
        Throw(DIFFERENT_COMPARATOR);

    Array result = {malloc((arr1->dimension + arr2->dimension) * arr1->elementSize),
                    arr1->dimension + arr2->dimension,
                    arr1->elementSize,
                    arr1->compare};

    memcpy(result.arr,
           arr1->arr,
           arr1->dimension * arr1->elementSize);

    memcpy(result.arr + arr1->dimension * arr1->elementSize,
           arr2->arr,
           arr2->dimension * arr2->elementSize);

    return result;
}


void printIntArray (const Array *array)
{
    for (size_t i = 0; i < array->dimension; i++)
        printf("%d ", *((int *) (array->arr + i * array->elementSize)));
    printf("\n");
}
int compareIntElements (const int *left, const int *right)
{
    return *left - *right;
}
Array constructIntArray ()
{
    printf("Enter the number of elements\n");
    int dist;
    scanf("%d", &dist);
    while (dist <= 0) {
        printf("Error, invalid length, try again!\n");
        scanf("%d", &dist);
    }
    printf("Enter array elements\n");
    int *arr = malloc(sizeof(int) * dist);
    for (int i = 0; i < dist; i++)
        scanf("%d", &arr[i]);
    getchar();
    Array array = {arr, dist, sizeof(int), compareIntElements};
    return array;
}
void destructIntArray (Array *array){
    free(array->arr);
}

void handlerError (CEXCEPTION_T EXPT)
{
    switch (EXPT) {
        case NULL_POINTER:
            printf("Array points to a null pointer!");
            break;

        case WRONG_ELEMENT_SIZE:
            printf("Element length less than or equal to 0!");
            break;

        case WRONG_DIMENSION:
            printf("Array length is less than or equal to 0!");
            break;

        case NO_COMPARATOR:
            printf("No comparison function!");
            break;

        case DIFFERENT_ELEMENT_SIZE:
            printf("Different element length!");
            break;

        case DIFFERENT_COMPARATOR:
            printf("Different comparison functions!");
            break;

        default:
            printf(
                    "Unknown error %d",
                    EXPT);
            break;
    }
}               //не используется
