#include "vector.h"


ActionAnswer_t vectorInit(Vector_t *vector)
{
    ActionAnswer_t status = UNDEFINE;
    if (vector)
    {
        vector->data = malloc(sizeof(int *) * VECTOR_INIT_CAPACITY);
        if (vector->data)
        {
            vector->capacity = VECTOR_INIT_CAPACITY;
            vector->current = 0;
            status = SUCCESS;
        }
    }
    return status;
}

static ActionAnswer_t vectorResize(Vector_t *vector, int capacity)
{
    ActionAnswer_t status = UNDEFINE;
    if(vector)
    {
        int **items = realloc(vector->data, sizeof(int *) * capacity);
        if (items)
        {
            vector->data = items;
            vector->capacity = capacity;
            status = SUCCESS;
        }
    }
    return status;
}

ActionAnswer_t vectorPushBack(Vector_t *vector, int data)
{
    ActionAnswer_t status = UNDEFINE;
    if (vector)
    {
        if (vector->current == vector->capacity - 1)
        {
            status = vectorResize(vector, vector->capacity * 2);
            if (status != UNDEFINE)
            {
                int *item = malloc(sizeof(int));
                if (item)
                {
                    vector->data[vector->current++] = item;
                    *item = data;
                    vector->data[vector->current] = NULL;
                    status = SUCCESS;
                }
                else 
                {
                    status = UNDEFINE;
                }
            }
        }
        else
        {
                int *item = malloc(sizeof(int));
                if (item)
                {
                    vector->data[vector->current++] = item;
                    *item = data;
                    vector->data[vector->current] = NULL;
                    status = SUCCESS;
                }
        }
    }
    return status;
}

ActionAnswer_t vectorFree(Vector_t *vector)
{
    int  status = UNDEFINE;
    if(vector)
    {
        for (size_t i = 0; i < vector->current; i++)
        {
            free(vector->data[i]);
        }
        free(vector->data);
        vector->data = NULL;
        status = SUCCESS;
    }
    return status;
}