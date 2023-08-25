#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
}*Node;

void addElement(Node *c, char element);
void deleteElem(Node *c, char element);
void display(Node c);

int main(){
  Node c = NULL;
  addElement(&c, 'A');
  addElement(&c, 'B');
  addElement(&c, 'C');
  addElement(&c, 'D');
  addElement(&c, 'E');
  addElement(&c, 'F');
  display(c);
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

void deleteElem(Node *c, char element){
    Node *trav, temp;
    int x=0;
    for(trav = c; *trav != NULL && (*trav)->data != element; trav = &(*trav)->link){
        printf("loop is %d time\n", ++x);
    }
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->link;
        printf("%c has been deleted\n", temp->data);
        free(temp);
    }
}   

void display(Node c){
    for(c; c != NULL; c = c->link){
        printf("%c->", c->data);
    }
    printf("NULL\n");
}
