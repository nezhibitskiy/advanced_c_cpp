//
// Created by ilyas on 10.10.2021.
//

#include <gtest/gtest.h>

#define ARRAY_DATA 3

extern "C"
{
    #include "pad_array_vectors.h"
};

// Функция добавления элемента в вектор
int *testAddElementToVector(int value) {
    int *element = new int;
    *element = value;
    return element;
}

// Функция создания вектора и его элементов
int **createVector(size_t sizeOfArr) {
    if (sizeOfArr > 0)
    {
        int **arr = new int*[sizeOfArr];
        for (size_t j = 0; j < (sizeOfArr - 1); j++) {
            arr[j] = testAddElementToVector(ARRAY_DATA);
        }
        arr[sizeOfArr - 1] = nullptr;
        return arr;
    }
    else
        return nullptr;
}

void testingFunction(const size_t sizeOfArr, const size_t* arrSizes)
{
    size_t biggestElement = 0;
    for (size_t i = 0; i < sizeOfArr; i++) {
        if (arrSizes[i] > biggestElement)
            biggestElement = arrSizes[i];
    }
    int ***arr = new int**[sizeOfArr];
    for (size_t i = 0; i < sizeOfArr; i++)
        arr[i] = createVector(arrSizes[i]);

    int ***returnArr = update_matrix(arr, sizeOfArr);

    for (size_t i = 0; i < sizeOfArr; i++) {
        if (arrSizes[i] > 1){
            for (size_t j = 0; j < (arrSizes[i] - 1); j++)
                delete arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    EXPECT_FALSE( returnArr == nullptr);
    for (size_t j = 0; j < sizeOfArr; j++) {
        size_t i = 0;
        if (arrSizes[j] != 0) {
            for (; i < (arrSizes[j] - 1); i++)
                EXPECT_EQ(*returnArr[j][i],  ARRAY_DATA);
        }
        for (; i < (biggestElement - 2); i++)
            EXPECT_EQ(*returnArr[j][i],  0);
        if (i != (biggestElement - 1))
            EXPECT_TRUE(returnArr[j][i+1] == nullptr);
        else
            EXPECT_TRUE(returnArr[j][i] == nullptr);
    }

    for (size_t i = 0; i < sizeOfArr; i++) {
        for (size_t j = 0; j < (biggestElement - 1); j++)
            free(returnArr[i][j]);
        free(returnArr[i]);
    }
    free(returnArr);
}


TEST(HW_TEST, Assert_1) {
    const size_t sizeOfArr = 10;
    const size_t arrSizes[sizeOfArr] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    testingFunction(sizeOfArr, arrSizes);
}

TEST(HW_TEST, Assert_2) {
    const size_t sizeOfArr = 3;
    const size_t arrSizes[sizeOfArr] = {5, 1, 10};
    testingFunction(sizeOfArr, arrSizes);
}

TEST(HW_TEST, Assert_3) {
    const size_t sizeOfArr = 15;
    const size_t arrSizes[sizeOfArr] = {5, 1, 10,48, 35, 110, 11, 2, 35, 41, 47, 13, 41, 48, 56};
    testingFunction(sizeOfArr, arrSizes);
}
TEST(HW_TEST, Assert_4) {
    const size_t sizeOfArr = 25;
    const size_t arrSizes[sizeOfArr] = {12, 15, 4, 15, 0, 4, 12, 41, 41, 1, 5, 1, 10, 48, 35, 110, 11, 2, 35, 41, 47, 13, 41, 48, 56};
    testingFunction(sizeOfArr, arrSizes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}