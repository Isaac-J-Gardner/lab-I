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

    //insertion sort 
    //for element in array, is the element before it bigger?
    //yes - swap them, check again
    //no - its in the correct spot, move to next element
    //if they're equal, swap them anyway and they will sit next to each other after.

    double temp; //to swap 2 elements in an array, a temporary variable needs to hold one of them
    int j; //this will start at the location of each element, then work backwards, comparing each element
    for(int c = 0; c < M; c++){
        for(int i = 1; i < N; i++){
        j = i;
        for(; j > 0; j--){ //working backwards
            if(data[j][c] <= data[j-1][c]){
                temp = data[j-1][c];
                data[j-1][c] = data[j][c];
                data[j][c] = temp;
            }
            else{
                break;
            }
        }
    }
    }
    
    printf("%.2f,", data[100][0]);
    printf("%.2f,", data[100][1]);
    printf("%.2f", data[100][2]);

    return EXIT_SUCCESS;
}