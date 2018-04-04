#include "csv.h"


char **printRow(char *c, char delimiter, int *arrlen){
    char* ptr = c;
    int i = 0;
    int count = 0;
    while (*(ptr+i) != '\0'){
        if (*(ptr+i) == delimiter)
            count++;
        i++;
    }
    count;
    i = 0;
    int size = 0;    
    int y = 0;
    char buf[MAXLEN];
    char **arr = malloc(sizeof(char)*MAXLEN);
    ptr = c;
    while (*(ptr+i) != '\0'){
        buf[y] = *(ptr+i);
        i++;
        y++;
        if(*(ptr+i) == delimiter && size < count ||
            size == count && *(ptr+i) == '\0') {
            if (buf[y-1] == '\n')
                buf[y-1] = '\0';
            else
                buf[y] = '\0';
            arr[MAXLEN*size] = malloc(strlen(buf));
            memcpy(arr[MAXLEN*size], buf, y);
            size++; 
            y = 0;
            i++;
        }
    }
    *arrlen = count +1;
    return arr;
}


