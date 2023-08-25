#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10

typedef struct{
    char elem[MAX];
    int front;
    int rear;
} Queue;

Queue initQueue()
{
    Queue newQueue;
    int i;
    for (i = 0; i < MAX; i++)
        newQueue.elem[i] = 0;
    newQueue.rear = 0;
    newQueue.front = 1;
    return newQueue;
}

int isEmpty(Queue *queue)
{
    return queue->front == (queue->rear + 1) % MAX;
}

int isFull(Queue *queue)
{
    return queue->front == (queue->rear + 2) % MAX;
}

void enqueue(Queue *queue, char elem)
{
    queue->rear = (queue->rear + 1) % MAX;
    queue->elem[queue->rear] = elem;
}

char dequeue(Queue *queue)
{
    char elem = queue->elem[queue->front];
    queue->front = (queue->front + 1) % MAX;
    return elem;
}

char front(Queue *queue)
{

}

Queue dispQueue(Queue queue)
{
    int i;
    printf("-------\n");
    printf("rear: %d\nfront: %d\n", queue.rear, queue.front);
    printf("-------\n");
    for (i = 0; i < MAX; i++)
    {
        char c = queue.elem[i];
        if (!(isalnum(c) || isspace(c) || ispunct(c)))
            c = '?';
        printf("%02d|'%c'|%c%c\n", i, c, queue.rear == i ? '<' : ' ', queue.front == i ? '>' : ' ');
    }
    printf("-------\n");
}

int main()
{
    Queue myQueue = initQueue();
    dispQueue(myQueue);
    int i;
    for (i = 0; i < MAX; i++)
    {
        enqueue(&myQueue, 'A'+i);
    }
    for (i = 0; i < MAX; i++)
    {
        dequeue(&myQueue);
        dispQueue(myQueue);
    }
    return 0;
}