#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node{
    int data;
    struct node *link;
}*Node;

typedef struct {
    Node Tree[MAX];
    Node* root;
}Tree;

void main(){
    int arr[] = {7,6,2};
    Tree T;
    initialize(&T);
    create(5, &arr, &T);
    int arr1[]={1, 5};
    create(7, &arr1, &T);
    display(T);

    printf("Parent of 7 is %d\n", Parent(T, 2));
    printf("Parent of 1 is %d\n", Parent(T, 1));
    printf("LMC of 5 is %d\n", leftmostChild(T, 5));
    printf("LMC of 8 is %d\n", leftmostChild(T, 8));
    printf("RMC of 5 is %d\n", rightmostChild(T, 5));
     printf("RMC of 1 is %d\n", rightmostChild(T, 1));
    //replicate the matter is the right+
    //replicate for the leftmostchild
    printf("RMC of 5 is %d\n", rightmostChild(T, 1));

     makeNull(&T);
     display(T);
}

void initialize(Tree* T){
    T->root = NULL;
    int x;
    for (x =0; x < MAX; x++){
        T->Tree[x] = NULL;
    }
}

void create(int r, int arr[], Tree *T){
    int size = (sizeof(arr)/sizeof(int)), x;
    Node* trav;
    Node newnode;
    if (r < MAX){
        if (T->root == NULL){
            T->root = &(T->Tree[r]);
        }
        for (x = 0; x <= size; x++){
               for (trav = &(T->Tree[r]); *trav != NULL; trav = &(*trav)->link);
               newnode = malloc(sizeof(struct node));
               newnode->data = arr[x];
               newnode->link = NULL;

               *trav = newnode;
        }
    }
}


void display(Tree T){
    int x;
    Node trav;
    for (x = 0; x < MAX; x++){
        printf("[%d]=[%d] ", &(T.Tree[x]), x);
        for (trav = T.Tree[x]; trav!= NULL; trav = trav->link){
            printf("%d ", trav->data);
            if (trav->link!= NULL){
                printf("---> ");
            }
        }
        printf("\n");
    }
    printf("ROOT: %d\n\n", T.root);
}

int Parent(Tree T, int n){
    int x, retval = -2;
    Node trav;
    for (x = 0; x < MAX && retval == -2; x++){
        for (trav = T.Tree[x]; trav != NULL && trav->data != n; trav = trav->link){}
        if (trav != NULL){
            retval = x;
        }
    }
    return retval;
}

int leftmostChild(Tree T, int n){
    return (T.Tree[n]!= NULL)? T.Tree[n]->data : -2;
}

int rightmostChild(Tree T, int n){
    Node trav;
    if (T.Tree[n] != NULL){
        for (trav = T.Tree[n]->link; trav!= NULL && trav->link != NULL; trav = trav->link){}
        return (trav!= NULL)? trav->data: -2;
    }
}

Node root(Tree T, int n){
    return *T.root;
}

int makeNull(Tree* T){
    int x;
    Node* trav;
    Node temp;
        for (x = 0; x < MAX; x++){
               for (trav = &(T->Tree[x]); *trav != NULL; ){
                temp = (*trav);
                (*trav) = (*trav)->link;
                free(temp);
               }
        }
    T->root = NULL;
}



