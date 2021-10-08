
#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 16

typedef enum ActionAnswer {
    UNDEFINE    = 0, 
    SUCCESS     = 1
} ActionAnswer_t;

typedef struct Vector{
    int** data;
    size_t capacity;
    size_t current;
} Vector_t;

ActionAnswer_t vectorInit(Vector_t *vector);

ActionAnswer_t vectorPushBack(Vector_t *vector, int data);

ActionAnswer_t vectorFree(Vector_t *vector);

