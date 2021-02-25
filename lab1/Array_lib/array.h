#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <string.h>

#include "../CException_lib/CException.h"     //lib для обработки исключений методом Try Catch

typedef struct Array
{

    void *arr;                  //указатель на первый элемент
    size_t dimension;           //длина всего массива
    size_t elementSize;         //длина одного элемента

    int (*compare)(const void *left, const void *right);       //функция сравнения

} Array;

//конструкторы
Array   constructIntArray();

//деструкторы
void   destructIntArray     (Array* array);

// функции сравнения
int     compareIntElements  (const int *left,const int *right);

//функции вывода
void    printIntArray       (const Array *array);
//правильно ли я понял, что эти 3 функции нужно написать для каждого типа?



// множество для работы с исключениями
enum ERRORCODE_T
{
    NULL_POINTER,               //массив указывает на пустой указатель
    WRONG_ELEMENT_SIZE,         //длина элемента меньше или равна 0
    WRONG_DIMENSION,            //длина массива меньше или равна 0
    NO_COMPARATOR,              //отсутствует функция сравнения
    DIFFERENT_ELEMENT_SIZE,     //разная длина элемента
    DIFFERENT_COMPARATOR        //разные функции сравнения
};

//функция для обработки ошибок
void    handlerError        (CEXCEPTION_T EXPT);



//основные функции
void    sort            (Array *array);                                //требуется массив, в котором обязательно присутствует функция сравнения

Array   map             (void (*func)(void *element),
                         const Array *array);

void    *reduce         (void *(*func)(const void *first, const void *second),
                         const Array *array,
                         const void *start_element);

Array   where           (bool (*func)(const void *element),
                         const Array *array);

Array   concatenat      (const Array *arr1,                             //конкатенация
                         const Array *arr2);                            //требуются массивы с одинаковым типом данных

#endif //ARRAY_H