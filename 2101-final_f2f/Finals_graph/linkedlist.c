#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *link;
}*List;

void initialize(List *L){
    *L = NULL;
}   

void insertsortred(List *L, int data){
    List temp, *trav;
    for(trav = L; (*trav) != NULL && (*trav)->data < data; trav = &(*trav)->link);
    temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->link = *trav;
        *trav = temp;    
    } else {
        printf("Memory Not Allocated");
    }
}

void delete(List *L, int data){
    List *trav, temp;
    for(trav = L; (*trav) != NULL && (*trav)->data != data; trav = &(*trav)->link);
    temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp = *trav;
        *trav = temp->link;
        free(temp);
    } else {
        printf("Memory not allocated");
    }
}

void display(List L){
    List trav = L;
    
}

void display(List L){
    List trav = L;
    while(trav != NULL){
        printf("%d->", trav->data);
        trav = trav->link;
    }
    printf("NULL\n");
}

int main(){
    List L;
    initialize(&L);
    insertsortred(&L, 4);
    insertsortred(&L, 9);
    insertsortred(&L, 8);
    insertsortred(&L, 7);
    display(L);
    delete(&L, 4);
    display(L);
    delete(&L, 8);
    display(L);
    insertsortred(&L, 4);
    insertsortred(&L, 8);
    display(L);
    
}