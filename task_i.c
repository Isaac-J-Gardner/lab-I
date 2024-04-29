#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {


    #define N 201
    #define M 3
    double data[N][M];

    #define MAXCHAR 100
    char buffer[MAXCHAR];
    int row = 0;
    int column = 0;
    char *ptr;

    char fn[] = "data.csv";
    FILE *fptr;
    fptr = fopen(fn, "r");
    while (fgets(buffer, MAXCHAR, fptr)) {
        column = 0;
        row++;
        if (row == 1) {
            continue;
        }
        char* value = strtok(buffer, ", ");
        while (value) {  
            data[row-2][column] = strtod(value,&ptr);
            value = strtok(NULL, ", ");
            column++;
        }
    }
    fclose(fptr);
    fptr = NULL;

    double total;
    for(int c = 0; c < M; c++){
        total = 0;
        for(int r = 0; r < N; r++){
            total += data[r][c];
        }
        if(c<2){
            printf("%.2f,", (total/N));
        }
        else{
            printf("%.2f", (total/N));
        }
    }


    return EXIT_SUCCESS;
}