#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 100000
#define SIZE 5

int main()
{
    int AM[SIZE][SIZE] = {
        {0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}};

    int AML[SIZE][SIZE] = {
        {INT_MAX, 100, 30, INT_MAX, 10},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 60, INT_MAX, 20, INT_MAX},
        {20, 10, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 50, INT_MAX}};
    return 0;
}