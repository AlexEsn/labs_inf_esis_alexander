#include "vector.h"
#include "string.h"
#include <stdlib.h>

struct Vector3 sum3(struct Vector3 v1, struct Vector3 v2)
{
    struct Vector3 v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    return v3;
}

struct VectorFloatN* sumFloatN(struct VectorFloatN *v1, struct VectorFloatN *v2)
{
    if (v1->dimension != v2->dimension) // = (*v1).dimension
        ;// throw an exception
    struct VectorFloatN *v3 = malloc(sizeof(struct VectorFloatN)); // sizeof(struct VectorN) = 8 (!)
    v3->dimension = v1->dimension;
    v3->coordinates = (float*)malloc(sizeof(float) * v3->dimension);
    for (int i = 0; i < v3->dimension; ++i)
        *(v3->coordinates + i) = *(v1->coordinates + i) + *(v2->coordinates + i);// v2->coordinates[i]
    return v3;
}



////////////////////////////////////////////////////////later
struct VectorN
{
    size_t dimension;
    size_t elementSize;
    void* coordinates;

    void* zero;
    void* one;
    void* (*minus)(void*);
    void* (*inv)(void*);

    void* (*sum)(void*, void*);
    void* (*mult)(void*, void*);
};


struct VectorN* Create0(size_t size, void* zero, size_t elementSize, void* coord, ..., void* (*sum)(void*, void*))
{
    struct VectorN *v = malloc(sizeof(struct VectorN));
    v->dimension = size;
    v->zero = zero;
    v->elementSize = elementSize;
    v->coordinates = malloc(elementSize * size);
    //...
    for (size_t i = 0; i < size; i++)
    {
        int8_t* position = (int8_t*)v->coordinates + i*v->elementSize;
        memcpy(position, v->zero, v->elementSize);
    }
    return v;
}

struct VectorN* sumN(struct VectorN *v1, struct VectorN *v2)
{
    if (v1->dimension == v2->dimension)
    {
        if (v1->elementSize == v2->elementSize)
        {
            struct VectorN* v3 = Copy(v1); // Create0(...)
            for (size_t i = 0; i < v3->dimension; i++)
            {
                void* coord1 = GetN(i, v1);
                void* coord2 = GetN(i, v2);
                void* coord3 = v3->sum(coord1, coord2);
                SetN(i, coord3, v3);
            }
        }
        else {

        }
    }
    else {

    }
    return v3;
}
// ...



////////////////////vector_float.c
struct VectorN* Create0Float(size_t size)
{
    if (!f_zero)
    {
        f_zero = malloc(sizeof(float));
        *(float*)f_zero = 0.0f;
        f_one = malloc(sizeof(float));
        *(float*)f_one = 1.0f;
    }
    return Create0(size, f_zero, sum_float, ...); // or &sum_float; and other implementations
}


void* sum_float(void* x, void* y)
{
    float* a = (float*)x;
    float* b = (float*)y;
    float* c = malloc(sizeof(float));
    *c = *a + *b;
    return (void*)c;
}
// ...
