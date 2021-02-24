#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

struct Vector3
{
    float x;
    float y;
    float z;
};

struct Vector3 sum3(struct Vector3 v1, struct Vector3 v2);


struct VectorFloatN
{
    int dimension;
    float *coordinates;
};

struct VectorFloatN* sumFloatN(struct VectorFloatN *v1, struct VectorFloatN *v2);



////////////////////////////////////////later
struct VectorN;

// Создание объекта
struct VectorN* Create0(size_t size, void* zero, size_t elementSize, void* coords, ..., void* (*sum)(void*, void*));
struct VectorN* Create1(size_t, void* one, ...);
struct VectorN* CreateFromValues(size_t, ...);

struct VectorN* Copy(struct VectorN* v);

// Декомпозиция
void* GetN(size_t coord, struct VectorN * v);
void SetN(size_t coord, void* value, struct VectorN* v);
//struct VectorN* SetN(size_t coord, void* value, struct VectorN* v);

// Операции
struct VectorN* sumN(struct VectorN *v1, struct VectorN *v2);
struct VectorN* multN(struct VectorN *v1, struct VectorN *v2);
// ...



////////////////////////////////////////////// vector_float.h
void* f_zero; // = 0
void* f_one; // = 0

void* sum_float(void*, void*);
// ...

#endif // VECTOR_H
