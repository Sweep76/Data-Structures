#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node {
    int data;
    struct node *link;
} * List;

typedef struct {
    List items[SIZE];
} Set;