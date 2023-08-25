#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node{
    int node;
    struct node *link;
}*LIST;

typedef struct {
    LIST Header[SIZE];
    int root;
}Tree;

int main(){
    LIST L;
    
}