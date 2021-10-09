#include <stdio.h>
#include "vector.h"

//--- Функция поиска наибольшей длины вектора в серии -----------------------------------------------------------------
size_t searchLength(int ***arr, size_t arrRowsCount)
{
    size_t size = 0;
    size_t tmpSize = 0;
    for (size_t i = 0; i < arrRowsCount; i++)
    {
        tmpSize = 0;
        while(arr[i][tmpSize] != NULL)
        {
            tmpSize++;
        }
        if (tmpSize > size)
            size = tmpSize;
    }
    return size;
}

//--- Функция добавления элемента в вектор ----------------------------------------------------------------------------
int *addElementToVector(int value)
{
    int *element = malloc(sizeof(int));
    *element = value;
    return element;
}

//--- Основная функиця домашнего задания ------------------------------------------------------------------------------
int ***updateMatrix(int ***arr, size_t arrRowsCount)
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
            int **items = realloc(arr[i], sizeof(int*) * (maxLength + 1)); // Один дополниетльный
                                                                                // элемент предназначен
                                                                                // для ячейки с NULL
            if (items)
            {
                arr[i] = items;
            }
            for (; tmpSize < maxLength; tmpSize++)
            {
                arr[i][tmpSize] = addElementToVector(0);
            }
            arr[i][tmpSize + 1] = NULL;
        }
    }
    return arr;
}

//--- Функция создания вектора и его элементов ------------------------------------------------------------------------
int** createVector(size_t sizeOfArr)
{
    int **arr = malloc(sizeof(int*) * sizeOfArr);
    for (size_t j = 0; j < (sizeOfArr - 1); j++)
    {
        arr[j] = addElementToVector(3);
    }
    arr[sizeOfArr - 1] = NULL;
    return arr;
}

int main()
{
    size_t sizeOfBigArr = 10;
    int ***arr = malloc(sizeof(int**) * 10);

    size_t arrPoz = 0;

    arr[arrPoz] = createVector(5);
    arrPoz++;
    arr[arrPoz] = createVector(6);
    arrPoz++;
    arr[arrPoz] = createVector(7);
    arrPoz++;
    arr[arrPoz] = createVector(8);
    arrPoz++;
    arr[arrPoz] = createVector(9);
    arrPoz++;
    arr[arrPoz] = createVector(10);
    arrPoz++;
    arr[arrPoz] = createVector(11);
    arrPoz++;
    arr[arrPoz] = createVector(12);
    arrPoz++;
    arr[arrPoz] = createVector(13);
    arrPoz++;
    arr[arrPoz] = createVector(30);
    arrPoz++;

    arr = updateMatrix(arr, arrPoz);

    for (size_t j = 0; j < arrPoz; j++)
    {
        size_t i = 0;
        printf("%ld: ", j);
        while((arr[j][i]) != NULL)
        {
            printf("%d ", (*(arr[j][i])));
            i++;
        }
        printf("Capacity: %ld\n", i);
    }

    for (size_t i = 0; i < arrPoz; i++)
    {
        for(size_t j = 0; j < 30; j++)
            free(arr[i][j]);
        free(arr[i]);
    }
    free(arr);

//    Vector_t *arr = malloc(sizeof(Vector_t) * 5);
//    for (size_t i = 0; i < 5; i++)
//    {
//        vectorInit(&arr[i]);
//    }
//
//    vectorPushBack(&arr[0], 1);
//    vectorPushBack(&arr[0], 2);
//    vectorPushBack(&arr[0], 3);
//
//    vectorPushBack(&arr[1], 1);
//    vectorPushBack(&arr[1], 2);
//    vectorPushBack(&arr[1], 3);
//    vectorPushBack(&arr[1], 4);
//    vectorPushBack(&arr[1], 5);
//    vectorPushBack(&arr[1], 6);
//
//    vectorPushBack(&arr[2], 1);
//    vectorPushBack(&arr[2], 2);
//    vectorPushBack(&arr[2], 3);
//    vectorPushBack(&arr[2], 4);
//    vectorPushBack(&arr[2], 5);
//    vectorPushBack(&arr[2], 6);
//    vectorPushBack(&arr[2], 7);
//    vectorPushBack(&arr[2], 8);
//    vectorPushBack(&arr[2], 9);
//    vectorPushBack(&arr[2], 10);
//
//
//    vectorPushBack(&arr[3], 1);
//    vectorPushBack(&arr[3], 2);
//    vectorPushBack(&arr[3], 3);
//    vectorPushBack(&arr[3], 4);
//    vectorPushBack(&arr[3], 5);
//
//
//    vectorPushBack(&arr[4], 1);
//    vectorPushBack(&arr[4], 2);
//    vectorPushBack(&arr[4], 3);

//    int ***data = malloc(sizeof(int **) * 5);
//    for (size_t i = 0; i < 5; i++)
//    {
//        data[i] = arr[i].data;
//    }
//
//    updateMatrix(data, 5);
//
//    for (size_t j = 0; j < 5; j++)
//    {
//        size_t i = 0;
//        while((arr[j].data[i]) != NULL)
//        {
//            printf("%d ", (*(arr[j].data[i])));
//            i++;
//        }
//        printf("Capacity: %ld\n", i);
//    }
//
//
//    for (size_t i = 0; i < 5; i++)
//    {
//
//            free(data[i]);
//
////        vectorFree(&arr[i]);
//    }
//    free(data);
    return 0;
}