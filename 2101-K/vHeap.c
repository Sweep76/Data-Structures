#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char data;
    int next;
} Node;

typedef struct {
    Node Nodes[MAX];
    int avail;
} Heap;

Heap initHeap()
{
    Heap newHeap;
    int i;
    for (i = 0; i < MAX; i++)
    {
        newHeap.Nodes[i].next = i - 1;
    }
    newHeap.avail = MAX - 1;
    return newHeap;
}

void drawHeap(Heap heap)
{
    int i;
    printf("avail: %02d\n", heap.avail);
    for (int i = 0; i < MAX; i++)
    {
        printf("%02d|'%c'|%02d|\n", i, heap.Nodes[i].data, heap.Nodes[i].next);
    }
}

int alloc(Heap *heap)
{
    // get prev avail
    int out = heap->avail;
    // change avail
    heap->avail = heap->Nodes[out].next;
    // return prev avai;
    return out;
}

// int initList(Heap *heap, data)e
// {
//     int out = heap->avail;
//     heap->avail = 
// }

int main()
{
    Heap myHeap = initHeap();
    drawHeap(myHeap);
    return 0;
}
