#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    char data;
    struct node *link;
}*List;

void insertnode(List *L, char data);
void display_element(List L);

int main() {
List L = NULL;
insertnode(&L, 'A');
insertnode(&L, 'B');
insertnode(&L, 'C');
insertnode(&L, 'D');
display_element(L);

}

void insertnode(List *L, char data){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->link = *L;
        *L = temp;
    }
}

void display_element(List L){
    while(L != NULL){
        printf(" %c", L->data);
        if(L->link != NULL){
            printf(",");
        }
        L = L->link;
    }
}

