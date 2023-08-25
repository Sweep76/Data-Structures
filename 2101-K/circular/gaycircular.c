#include <stdio.h>
#include <stdlib.h>
#define MAX 10


typedef struct {
    char elems[MAX];
    int rear;
    int front;
} Queue;

Queue initQueue()
{
    Queue newQueue;
    newQueue.rear = 0;
    newQueue.front = 1;
}

int isEmpty(Queue *queue)
{
    return queue->front = (queue->rear + 1) % MAX;
}

int isFull(Queue *queue)
{
    return queue->front = (queue->rear + 2) % MAX;
}

void enqueue(Queue *queue, char data)
{
    queue->rear = (queue->rear + 1) % MAX;
    queue->elems[queue->rear] = data;
}

char dequeue(Queue *queue)
{
    
}

int main()
{
    return 0;
}