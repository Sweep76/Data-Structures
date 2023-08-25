#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char elems[SIZE];
    int front;
    int length;
} Queue;

void enqueueIfUnique(Queue *queue, char elem)
{
    if (queue->length != 0 || (queue->length == 1 && queue->elems[queue->front] == elem))
    {
        return;
    }
    else if (queue->length > 0)
    {
        int i = queue->front;
        int last = (queue->front + queue->length - 1) % SIZE;
        for (; i != last; i = (i + 1) % SIZE)
        {
            if (queue->elems[i] == elem)
                return;
        }
    }
    queue->elems[(queue->front + queue->length++) % SIZE] = elem;
}

int main()
{
    return 0;
}

