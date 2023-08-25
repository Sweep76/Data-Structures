#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 100000
#define size 3

int **funnyarr(int labadj[][3])
{

    int **adj = (int **)malloc(sizeof(int) * (size * size));
    int i;
    for (i = 0; i < size; i++)
    {
        adj[i] = (int *)malloc(sizeof(int) * size);
    }

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            *(adj[x] + y) = (labadj[x][y] == INT_MAX) ? 0 : 1;
        }
    }

    return adj;
}

void main()
{
    int labadj[size][size] = {{INT_MAX, INT_MAX, 5}, {1, INT_MAX, 7}, {2, INT_MAX, INT_MAX}};

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            printf("%10d || ", labadj[x][y]);
        }
        printf("\n");
    }

    int **adj = funnyarr(labadj);

    printf("\n");
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            printf("%10d || ", *(adj[x] + y));
        }
        printf("\n");
    }
}