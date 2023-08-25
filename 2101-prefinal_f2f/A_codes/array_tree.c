#include <stdio.h>

#define MAX 10

typedef int Node;
typedef struct {
    Node e[MAX];
    Node root;
}Tree;

void create(Tree *T, int arr[]);
void display(Tree T);
void initialize(Tree* T);

int main(){
    int arr[MAX] = {5,6,5,5,1,-1,5,1,2,-2};
    Tree T;
    initialize (&T);
    create(&T, arr);
    display(T);
    return 0;
}

void initialize(Tree* T){
    T->root = -1;
}

void create(Tree *T, int arr[]){
    int x;
    for (x = 0; x < MAX; x++){
        T->e[x] = arr[x];
        if (arr[x]== -1){
            T->root = x;
        }
    }
}

void display(Tree T){
    int x;
    for (x = 0; x < MAX; x++){
        printf("%d - %d\n", x, T.e[x]);
    }
    printf("Root: %d\n--------------------\n", T.root);
}

int leftmostSibling(Tree T, int n){
    int x;
    if (n < MAX){
        for (x = 0; x < MAX && T.e[x]!= n; x++){}
    }

    return (x != MAX)? x : -2;
}

int rightmostSibling(Tree T, int n){
    int x;
    if (n < MAX){
        for (x = MAX-1; x >= 0 && T.e[x]!= n; x--){}
    }

    return (x != -1)? x : -2;
}

int parent(int n, Tree T){
    return T.e[n];
}

int label(int n, Tree T){
    return n; // this looks dumb but yeah since we have no label to return HAHA 
}

int root(Tree T){
    return T.root;
}

int makenull(Tree T){
    int x;
    for (x = 0; x < MAX; x++){
        T.e[x] = -2;
    }
    T.root = -1;
}