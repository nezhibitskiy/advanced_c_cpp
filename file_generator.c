//
// Created by cross on 29.10.2021.
//

#define _CRT_RAND_S

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t original_max_len = 0;
    FILE* file = fopen("../text.txt", "w");
    if (file == NULL)
        return -1;

    unsigned int randValue = 0;

    for (unsigned int i = 0; i < 2000000; i++) {
        errno_t err;
        err = rand_s(&randValue);
        if (err != 0) {
            printf("The rand_s function failed!\n");
        }
        unsigned int word_length = (unsigned int)((double)randValue/((double) UINT_MAX + 1 ) * 105.0) + 1;
        if (word_length > original_max_len)
            original_max_len = word_length;
        for (unsigned int j = 0; j < word_length; j++) {
            err = rand_s(&randValue);
            if (err != 0) {
                printf("The rand_s function failed!\n");
            }
            unsigned int letter_number = (unsigned int) ((double) randValue / ((double) UINT_MAX + 1) * 52.0) + 1;
            if (letter_number > 26)
                letter_number += 6;
            letter_number += 64;

            fprintf(file, "%c", (char)letter_number);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}