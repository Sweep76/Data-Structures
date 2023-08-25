#include <stdio.h>
#define MAX 5
void matrixdisplay(int matrix [MAX][MAX], int row, int column);
void printline(int matrix [MAX][MAX], int row, int column);


int main(){
    int matrix[MAX][MAX] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    printline(matrix, 0, 0);
    return 0;
}

void matrixdisplay(int matrix [MAX][MAX], int row, int column){
        if(column < MAX){
            printf("%d ", matrix[row][column]);
            matrixdisplay(matrix, row, ++column);
        } else {
            column = 0;
            row++;
            printline(matrix, row, column);
        }
    }

void printline(int matrix [MAX][MAX], int row, int column){
    printf("\n");
    if(row < MAX){  
        matrixdisplay(matrix, row, column);
    }
}