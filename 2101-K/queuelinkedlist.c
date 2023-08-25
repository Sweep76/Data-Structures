#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *next;
} * LinkList;

typedef struct {
    LinkList front;
    LinkList rear;
} Queue;

void initQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue *queue, char elem)
{
    LinkList newElem = (LinkList) malloc(sizeof(struct node));
    newElem->elem = elem;
    newElem->next = NULL;
    if (queue->front == NULL)
        queue->front = newElem;
    if (queue->rear != NULL)
        queue->rear->next = newElem;
    queue->rear = newElem;
}

void dequeue(Queue *queue)
{
    LinkList *front = &queue->front;
    if (*front == NULL)
        return;
    LinkList oldElem = *front;
    *front = (*front)->next;
    if (*front == NULL)
        queue->rear = NULL;
    free(oldElem);
}

char front(Queue *queue)
{
    LinkList front = queue->front;
    return (front == NULL) ? NULL : front->elem;
}

int main()
{

    return 0;
}