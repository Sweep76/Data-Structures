#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef int SET[MAX];

SET *Union(SET A, SET B)
{
    SET *C = (SET *) malloc(sizeof(SET));
    int x;
    for (x = 0; x < MAX; x++)
    {
        (*C)[x] = (A[x] == 1 || B[x] == 1) ? 1 : 0;
    }
    return C;
}

void Display(SET set)
{
    int i = 0;
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", set[i]);
    }
}

int main()
{
    SET A = {0, 1, 1, 0, 1, 0, 0, 1, 0, 1};
    SET B = {1, 0, 0, 1, 0, 1, 0, 0, 0, 0};
    SET *C = Union(A, B);
    Display(*C);
    return 0;
}