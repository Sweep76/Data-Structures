#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct
{
    int elem[SIZE];
    int lstNdx;
} Heap;

Heap *HeapInit()
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->lstNdx = -1;
    return heap;
}

void HeapInsert(int elem, Heap *heap)
{
    int lstNdx = ++heap->lstNdx;
    heap->elem[lstNdx] = elem;
    // traverse
    while (lstNdx > 0 && elem < heap->elem[(lstNdx - 1) / 2])
    {
        int parent = (lstNdx - 1) / 2;
        int spare = heap->elem[parent];
        heap->elem[lstNdx] = spare;
        heap->elem[parent] = elem;
        lstNdx = parent;
    }
}

void HeapSort(Heap *heap)
{
    int spare;
    while (heap->lstNdx > -1)
    {
        // swap last and first
        spare = heap->elem[0];
        heap->elem[0] = heap->elem[heap->lstNdx];
        heap->elem[heap->lstNdx] = spare;
        // sort thing stuff
        int idx = 0;
        int swapIdx;
        do
        {
            swapIdx = -1;
            int childIdx = idx * 2 + 1;
            if (heap->elem[childIdx] < heap->elem[childIdx + 1])
                childIdx++;

        } while (swapIdx != -1);
    }
}

int main()
{
    return 0;
}