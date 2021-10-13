//
// Created by ilyas on 10.10.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include "pad_array_vectors.h"
}

void errorFreeRawCPPArr(int ***arr,
                        const size_t array_size,
                        const size_t *vectors_size,
                        const size_t current_vector,
                        const size_t current_index)
{
  if ((current_vector != 0 || current_index != 0) && vectors_size != NULL) {
    for (size_t j = current_index - 1; j + 1 > 0; j--) {
      delete arr[current_vector][j];
    }
    for (size_t i = current_vector - 1; i + 1 > 0; i--)
      for (size_t j = vectors_size[i] - 1; j + 1 > 0; j--) {
        delete arr[i][j];
      }
    for (size_t i = current_vector - 1; i + 1 > 0; i--) {
      delete[] arr[i];
    }
  }
  if (array_size != 0) delete[] arr;
}

// Функция добавления элемента в вектор
int *testAddElementToVector(int value) {
  int *element = new int;
  if (element)
    *element = value;
  return element;
}

// Функция создания вектора и его элементов
int **createVector(size_t sizeOfArr, size_t *currentIndex) {
  if (sizeOfArr > 0) {
    int **arr = new int *[sizeOfArr];
    if (!arr) return nullptr;
    for (*currentIndex = 0; *currentIndex < (sizeOfArr - 1); (*currentIndex)++) {
      arr[*currentIndex] = testAddElementToVector(*currentIndex);
      if (!arr[*currentIndex]) return nullptr;
    }
    arr[sizeOfArr - 1] = nullptr;
    return arr;
  } else {
    return nullptr;
  }
}

void testingFunction(const size_t sizeOfArr, const size_t *arrSizes) {
  size_t biggestElement = 0;
  for (size_t i = 0; i < sizeOfArr; i++) {
    if (arrSizes[i] > biggestElement) biggestElement = arrSizes[i];
  }
  int ***arr = nullptr;
  if (sizeOfArr != 0) {
    arr = new int**[sizeOfArr];
    if (!arr) return;
  }
  for (size_t i = 0; i < sizeOfArr; i++) {
    size_t currentIndex = 0;
    arr[i] = createVector(arrSizes[i], &currentIndex);
    if (arrSizes[i] > 0 && !arr[i])
      errorFreeRawCPPArr(arr, sizeOfArr, arrSizes, i, currentIndex);
  }

  int ***returnArr = pad_array_vectors(arr, sizeOfArr);

  if (sizeOfArr != 0) {
    for (size_t i = 0; i < sizeOfArr; i++) {
      if (arrSizes[i] > 1) {
        for (size_t j = 0; j < (arrSizes[i] - 1); j++) delete arr[i][j];
      }
      delete[] arr[i];
    }
    delete[] arr;

    EXPECT_FALSE(returnArr == nullptr);
    for (size_t j = 0; j < sizeOfArr; j++) {
      size_t i = 0;
      if (arrSizes[j] != 0) {
        for (; i < (arrSizes[j] - 1); i++)
          EXPECT_EQ(*returnArr[j][i], i);
      }
      for (; i < (biggestElement - 2); i++) EXPECT_EQ(*returnArr[j][i], 0);
      if (i != (biggestElement - 1))
        EXPECT_TRUE(returnArr[j][i + 1] == nullptr);
      else
        EXPECT_TRUE(returnArr[j][i] == nullptr);
    }
  } else {
    EXPECT_TRUE(returnArr == nullptr);
  }


  for (size_t i = 0; i < sizeOfArr; i++) {
    for (size_t j = 0; j < (biggestElement - 1); j++) free(returnArr[i][j]);
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
  const size_t arrSizes[sizeOfArr] = {5,  1,  10, 48, 35, 110, 11, 2,
                                      35, 41, 47, 13, 41, 48,  56};
  testingFunction(sizeOfArr, arrSizes);
}
TEST(HW_TEST, Assert_4) {
  const size_t sizeOfArr = 25;
  const size_t arrSizes[sizeOfArr] = {12, 15, 4,  15, 0,  4,  12,  41, 41,
                                      1,  5,  1,  10, 48, 35, 110, 11, 2,
                                      35, 41, 47, 13, 41, 48, 56};
  testingFunction(sizeOfArr, arrSizes);
}

TEST(HW_TEST, Assert_5) {
  const size_t sizeOfArr = 0;
  const size_t arrSizes = 0;
  testingFunction(sizeOfArr, &arrSizes);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
