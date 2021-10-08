#include <stdio.h>
#include "vector.h"

size_t searchLength(int ***arr, size_t arrRowsCount)
{
    size_t size = 0;
    size_t tmpSize = 0;
    for (size_t i = 0; i < arrRowsCount; i++)
    {
        while(arr[i][tmpSize] != NULL)
        {
            tmpSize++;
        }
        if (tmpSize > size)
            size = tmpSize;
    }
    return size;
}

void updateMatrix(int ***arr, size_t arrRowsCount)
{
    size_t maxLength = searchLength(arr, arrRowsCount);
    for(size_t i = 0; i < arrRowsCount; i++)
    {
        size_t tmpSize = 0;
        while (arr[i][tmpSize] != NULL)
        {
            tmpSize++;
        }
        if (tmpSize < maxLength)
        {
          //  int **items = realloc(arr[i], sizeof(int*) * 16);
//            if (items)
//            {
//                arr[i] = items;
//            }
            int *zeros = malloc(sizeof(int) * (maxLength - tmpSize));
            for (size_t j = 0; j < (maxLength - tmpSize); j++)
            {
                zeros[j] = 0;
            }
            size_t index = 0;
            for (; tmpSize < maxLength; tmpSize++)
            {
                arr[i][tmpSize] = &(zeros[index++]);
            }
            arr[i][tmpSize + 1] = NULL;
        }

    }
}

int main()
{
    Vector_t *arr = malloc(sizeof(Vector_t) * 5);
    for (size_t i = 0; i < 5; i++)
    {
        vectorInit(&arr[i]);
    }

    vectorPushBack(&arr[0], 1);
    vectorPushBack(&arr[0], 2);
    vectorPushBack(&arr[0], 3);

    vectorPushBack(&arr[1], 1);
    vectorPushBack(&arr[1], 2);
    vectorPushBack(&arr[1], 3);
    vectorPushBack(&arr[1], 4);
    vectorPushBack(&arr[1], 5);
    vectorPushBack(&arr[1], 6);

    vectorPushBack(&arr[2], 1);
    vectorPushBack(&arr[2], 2);
    vectorPushBack(&arr[2], 3);
    vectorPushBack(&arr[2], 4);
    vectorPushBack(&arr[2], 5);
    vectorPushBack(&arr[2], 6);
    vectorPushBack(&arr[2], 7);
    vectorPushBack(&arr[2], 8);
    vectorPushBack(&arr[2], 9);
    vectorPushBack(&arr[2], 10);


    vectorPushBack(&arr[3], 1);
    vectorPushBack(&arr[3], 2);
    vectorPushBack(&arr[3], 3);
    vectorPushBack(&arr[3], 4);
    vectorPushBack(&arr[3], 5);


    vectorPushBack(&arr[4], 1);
    vectorPushBack(&arr[4], 2);
    vectorPushBack(&arr[4], 3);

    int ***data = malloc(sizeof(int **) * 5);
    for (size_t i = 0; i < 5; i++)
    {
        data[i] = arr[i].data;
    }

    updateMatrix(data, 5);

    for (size_t j = 0; j < 5; j++)
    {
        size_t i = 0;
        while((arr[j].data[i]) != NULL)
        {
            printf("%d ", (*(arr[j].data[i])));
            i++;
        }
        printf("Capacity: %ld\n", i);
    }


    for (size_t i = 0; i < 5; i++)
    {

            free(data[i]);

//        vectorFree(&arr[i]);
    }
    free(data);
    return 0;
}