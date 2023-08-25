#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
}*Node;

void addElement(Node *c, char element);
void deleteElem(Node *A, char elem);

int main(){
  Node c = NULL;
  addElement(&c, 'A');
  addElement(&c, 'B');
  addElement(&c, 'C');
  addElement(&c, 'D');
  addElement(&c, 'E');
  addElement(&c, 'F');
  deleteElem(&c, 'D');
  display(c);

//6->5->4->3->2->1

}

void addElement(Node *c, char element){
    Node d = (Node)malloc(sizeof(struct node));
    if(d != NULL){
        d->data = element;
        d->link = *c; //d link points to the node pointed by C, it's not pointing at c, but rather the node
        *c = d; // d holds the address of the node, not itself, so c inherits the address of the node
    }
}

void deleteElem(Node *A, char elem){
    Node *trav, temp;
    for(trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    if(*trav != NULL){
        temp = *trav; //points to the before deleted node
        *trav = temp -> link; //trav points to the next node
        free(temp); // frees memory of the chosen node to be deleted
    }
}

void display(Node c){
    printf("{");
    while(c != NULL){
        printf(" %c", c->data);
        if(c->link != NULL){
            printf(" -> ");
        }
        c = c->link;
    }
    printf("}\n");
}