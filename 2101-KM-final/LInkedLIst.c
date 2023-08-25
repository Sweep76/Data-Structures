#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct node{
    char data[MAX];
    struct node *link;
}*List, nodetype;

void init(List *L);
void display(List L);
void delete(List *L, char *str);
void update(List *L, char *oldstr, char *newstr);
void insertSorted(List *L, char *str);

int main(){
    List L;
    initialize(&L);
    insertSorted(&L, "aaron");
    insertSorted(&L, "zoey");
    insertSorted(&L, "gepard");
    insertSorted(&L, "char");
    display(L);
}

void initialize(List *L){
    *L = NULL;
}

void insertSorted(List *L, char *str){
    List *trav, temp;
    for(trav = L; (*trav) != NULL && (strcmp((*trav)->data, str) < 0); trav = &(*trav)->link);
    temp = malloc(sizeof(nodetype));
    if(temp != NULL){
        strcpy(temp->data, str);
        temp->link = *trav;
        *trav = temp;
    } else {
        printf("MEMORY NOT ALLOCATED");
    }
}

void display(List L){
    List trav;
    printf("\nLinked List Display\n");
    for(trav = L; trav != NULL; trav = trav->link){
        printf("%s ->", trav->data);
    }
    printf("NULL");
}

