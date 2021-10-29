//
// Created by cross on 29.10.2021.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("../text.txt", "rt");
    fseek(file, 0L, SEEK_END);
    size_t sz = ftell(file);
    rewind(file);
    printf("Size of file is %llu\n", sz);

    char *data = malloc(sizeof(char) * sz);

    if (!data)
        return -1;

    size_t index = 0;
    for (; index < sz; index++) {
        data[index] = (char)fgetc(file);
    }

    printf("Storaged data length is %llu\n", index);
    fclose(file);
    scanf("%llu", &index);
    free(data);
    scanf("%llu", &index);
    return 0;

//    size_t size = 1;
//    char *str;
//    int ch;
//    size_t len = 0;
//    str = realloc(NULL, sizeof(*str)*size);//size is start size
//    if(!str)return -1;
//    while(EOF!=(ch=fgetc(file)) && ch != '\n'){
//        str[len++] = (char)ch;
//        if(len==size){
//            str = realloc(str, sizeof(*str)*(size+=16));
//            if(!str) return -1;
//        }
//    }
//    realloc(str, sizeof(*str)*len);
//
//    printf("%s length: %llu", str, len);


}