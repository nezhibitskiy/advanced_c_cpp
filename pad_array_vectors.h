//
// Created by ilyas on 10.10.2021.
//

#ifndef ADVANCED_C_C___HOMEWORKS_PADARRAYVECTORS_H
#define ADVANCED_C_C___HOMEWORKS_PADARRAYVECTORS_H

#include <stdlib.h>
#include <string.h>

// Функция поиска наибольшей длины вектора в серии
size_t search_length(int ***arr, size_t arr_rows_count);
// Функция добавления элемента в вектор
int *addElementToVector(int value);
// Функция дополнения векторов принимаемого массива
int ***update_matrix(int ***input_arr, size_t arr_rows_count);



#endif //ADVANCED_C_C___HOMEWORKS_PADARRAYVECTORS_H
