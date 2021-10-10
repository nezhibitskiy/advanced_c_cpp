//
// Created by ilyas on 10.10.2021.
//

#include "padArrayVectors.h"

// Функция поиска наибольшей длины вектора в серии
size_t searchLength(int ***arr, size_t arrRowsCount) {
    size_t size = 0;
    size_t tmpSize = 0;
    for (size_t i = 0; i < arrRowsCount; i++) {
        if (arr[i] != NULL)
        {
            tmpSize = 0;
            while (arr[i][tmpSize] != NULL) {
                tmpSize++;
            }
            if (tmpSize > size) size = tmpSize;
        }
    }
    return size;
}

// Функция добавления элемента в вектор
int *addElementToVector(int value) {
    int *element = malloc(sizeof(int));
    *element = value;
    return element;
}

// Основная функиця домашнего задания
int ***updateMatrix(int ***arr, size_t arrRowsCount) {
    size_t maxLength = searchLength(arr, arrRowsCount);
    for (size_t i = 0; i < arrRowsCount; i++) {
        size_t tmpSize = 0;
        if (arr[i] != NULL) {
            while (arr[i][tmpSize] != NULL) {
                tmpSize++;
            }
        }
        if (tmpSize < maxLength) {
            int **items = NULL;
            if (arr[i] != NULL)
            {
                items = realloc(arr[i], sizeof(int *) * (maxLength + 1));
            } else {
                items = malloc(sizeof(int *) * (maxLength + 1));
            }
            if (items) {
                arr[i] = items;
            }
            for (; tmpSize < maxLength; tmpSize++) {
                arr[i][tmpSize] = addElementToVector(0);
            }
            arr[i][tmpSize + 1] = NULL;
        }
    }
    return arr;
}
