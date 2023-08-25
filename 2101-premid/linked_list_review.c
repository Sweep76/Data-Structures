#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}Node;

void addElement(Node **c, int element);
void display(Node *c);

int main(){
  Node *c = NULL;
  addElement(&c, 1);
  addElement(&c, 2);
  addElement(&c, 3);
  addElement(&c, 4);
  addElement(&c, 5);
  addElement(&c, 6);
  display(c);

//6->5->4->3->2->1

}

void addElement(Node **c, int element){
    Node *d = malloc(sizeof(Node));
    if(d != NULL){
        d->data = element;
        d->link = c;
        *c = d; 
    }
}

void display(Node *c){
    printf("{");
    while(c != NULL){
        printf("%d", c->data);
        if(c->link != NULL){
            printf(" -> ");
        }
        c = c->link;
    }
    printf("}\n");
}