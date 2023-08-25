#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;

}node;

typedef struct{
	node *head;
	node *tail;
}queue;


void disp(queue *q)
{
    node *trav = q->head;
    // do the rest
}

void enqueue(queue *q, int data){
	//create a NEWNODE;
	node * newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
    
    if (q->tail != NULL)
        q->tail->next = newnode;
    
    q->tail = newnode;

	if(q->head == NULL)
		q->head = newnode;
}

void dequeue(queue *q){
	
	//checker
	(q->head == NULL) ? puts("Queue is empty") : puts("DeQueue Proceeds");
    //saves the head of the queue
    node *temp = q->head;
    
    //save the result to be returned.
    int result = temp->data;
    
    q->head = q->head->next;
    
    if(q->head == NULL){
        q->head =NULL;
    }
	free(temp);
}
