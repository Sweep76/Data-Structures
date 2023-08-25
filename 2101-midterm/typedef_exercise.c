#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
   int data;
   struct node *link;
}*List;

typedef struct {
   List L[MAX];
}Set;

int main(){
    Set group;
}


