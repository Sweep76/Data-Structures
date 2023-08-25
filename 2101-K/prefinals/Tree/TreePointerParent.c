#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef int node;
typedef node Tree[SIZE];

node PARENT(node n, Tree T)
{
    if (n < 0 || n >= SIZE)
        return -2;
    return T[n];
}

node RIGHT_SIBLING(node n, Tree T)
{
    if (n < 0 || n >= SIZE)
        return -2;
    node parent = T[n];
    node i;
    for (i = 0; i < SIZE && (T[i] != parent || i == n); i++)
    {
    }
}

int main()
{
    Tree T = {5, 6, 5, 6, 1, -1, 5, 1, 2, -2};
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", T[i]);
    }
    printf("\n");
    printf("%d\n", PARENT(6, T));
    printf("%d\n", RIGHT_SIBLING(0, T));
    return 0;
}