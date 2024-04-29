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

    double Vin[N];
    double Vout[N];
    double Current[N];
    for(int i = 0; i < N; i++){
        Vin[i] = data[i][0];
        Vout[i] = data[i][1];
        Current[i] = data[i][2];
    }

    //insertion sort 
    //for element in array, is the element before it bigger?
    //yes - swap them, check again
    //no - its in the correct spot, move to next element
    //if they're equal, swap them anyway and they will sit next to each other after.

    double temp; //to swap 2 elements in an array, a temporary variable needs to hold one of them
    int j; //this will start at the location of each element, then work backwards, comparing each element
    for(int i = 1; i < N; i++){
        j = i;
        for(; j > 0; j--){ //working backwards
            if(Vin[j] <= Vin[j-1]){
                temp = Vin[j-1];
                Vin[j-1] = Vin[j];
                Vin[j] = temp;
            }
            else{
                break;
            }
        }
    }
    for(int i = 1; i < N; i++){
        j = i;
        for(; j > 0; j--){
            if(Vout[j] <= Vout[j-1]){
                temp = Vout[j-1];
                Vout[j-1] = Vout[j];
                Vout[j] = temp;
            }
            else{
                break;
            }
        }
    }
    for(int i = 1; i < N; i++){
        j = i;
        for(; j > 0; j--){
            if(Current[j] <= Current[j-1]){
                temp = Current[j-1];
                Current[j-1] = Current[j];
                Current[j] = temp;
            }
            else{
                break;
            }
        }
    }
    printf("%.2f,", Vin[100]);
    printf("%.2f,", Vout[100]);
    printf("%.2f", Current[100]);

    return EXIT_SUCCESS;
}