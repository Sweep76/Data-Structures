#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node {
    int elem;
    struct node *link;
}List;

typedef List Dictionary[SIZE];

int main(){
    Dictionary L;
    List M;
    List *J;
}