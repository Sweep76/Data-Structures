#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
typedef struct
{
    char elem[SIZE];
    int front;
    int length;
} Queue;

void enqueueIfUniqueI(Queue *queue, char elem)
{
    // exit if queue exceeds SIZE or single-item queue contains elem
    if (queue->length >= SIZE || (queue->length == 1 && queue->elem[queue->front] == elem))
    {
        return;
    }
    // otherwise check if queue has items
    else if (queue->length > 0)
    {
        int i = queue->front;
        int last = (queue->front + queue->length - 1) % SIZE;
        for (; i != last; i = (i + 1) % SIZE)
        {
            // exit if element is found (not unique)
            if (queue->elem[i] == elem)
                return;
        }
    }
    // enqueue
    queue->elem[(queue->front + queue->length++) % SIZE] = elem;
}

void enqueueIfUniqueII(Queue *queue, char elem)
{
    // exit if queue exceeds SIZE or single-item queue contains elem
    if (queue->length >= SIZE)
    {
        return;
    }
    // otherwise check if queue has items
    else if (queue->length > 0)
    {
        int i = queue->front;
        int last = (queue->front + queue->length - 1) % SIZE;
        for (; i != last; i = (i + 1) % SIZE)
        {
            // exit if element is found (not unique)
            if (queue->elem[i] == elem)
                return;
        }
    }
    // enqueue
    queue->elem[(queue->front + queue->length++) % SIZE] = elem;
}

int main()
{
    Queue *q = malloc(sizeof(Queue));
    clock_t start_clk;
    long long int i;
    int b;
    double x = 0, y = 0;
    double t;
    for (b = 0; b < 10; b++)
    {
        t = 0;
        for (i = 0; i < 99999999; i++)
        {
            q->front = 0;
            q->length = 0;
            start_clk = clock();
            enqueueIfUniqueI(q, 'A');
            enqueueIfUniqueI(q, 'A');
            enqueueIfUniqueI(q, 'B');
            enqueueIfUniqueI(q, 'B');
            enqueueIfUniqueI(q, 'C');
            enqueueIfUniqueI(q, 'C');
            enqueueIfUniqueI(q, 'D');
            enqueueIfUniqueI(q, 'D');
            enqueueIfUniqueI(q, 'E');
            enqueueIfUniqueI(q, 'E');
            enqueueIfUniqueI(q, 'F');
            enqueueIfUniqueI(q, 'F');
            t += ((double)(clock() - start_clk)) / CLOCKS_PER_SEC;
        }
        printf("%f\n", t);
        x += t;
    }
    for (b = 0; b < 10; b++)
    {
        t = 0;
        for (i = 0; i < 99999999; i++)
        {
            q->front = 0;
            q->length = 0;
            start_clk = clock();
            enqueueIfUniqueII(q, 'A');
            enqueueIfUniqueII(q, 'A');
            enqueueIfUniqueII(q, 'B');
            enqueueIfUniqueII(q, 'B');
            enqueueIfUniqueII(q, 'C');
            enqueueIfUniqueII(q, 'C');
            enqueueIfUniqueII(q, 'D');
            enqueueIfUniqueII(q, 'D');
            enqueueIfUniqueII(q, 'E');
            enqueueIfUniqueII(q, 'E');
            enqueueIfUniqueII(q, 'F');
            enqueueIfUniqueII(q, 'F');
            t += ((double)(clock() - start_clk)) / CLOCKS_PER_SEC;
        }
        printf("%f\n", t);
        y += t;
    }
    x /= 10;
    y /= 10;
    printf("A: %f\nB: %f\n", x, y);
    return 0;
}