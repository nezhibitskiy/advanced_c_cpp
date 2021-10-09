
#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 16

typedef enum ActionAnswer {
    UNDEFINE    = 0, 
    SUCCESS     = 1
} ActionAnswer_t;

typedef struct Vector{
    int** data;         // Указатель на массив указателей
    size_t capacity;    // Размер массива указателей
    size_t current;     // Индекс текущего элемента в массиве
} Vector_t;

ActionAnswer_t vectorInit(Vector_t *vector);

ActionAnswer_t vectorPushBack(Vector_t *vector, int data);

ActionAnswer_t vectorFree(Vector_t *vector);

