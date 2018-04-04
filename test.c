#include "csv.h"


int main(void){
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int arrlen;
    char d = ';';
    stream = fopen("test.csv", "r");
    while((read = getline(&line, &len, stream)) != -1){
        char **arr = printRow(line, d, &arrlen);
        int i;
        for(i = 0; i < arrlen; i++)
            printf("%s, ", *(arr+(i*MAXLEN)));
        printf("\n");
    
        free(arr);
    }
    free(line);
    fclose(stream);
    return 0;
}
