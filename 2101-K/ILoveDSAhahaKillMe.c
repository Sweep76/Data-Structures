#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100
#define TABLE_SIZE 10

typedef struct
{
    int data;
    int next;
} NodeType;

typedef struct
{
    NodeType node[MAX_ELEMENTS];
    int avail; // holds index of next vacant field
} * VHeap;     // shared virtual heap.

typedef struct
{
    int head;
    VHeap vptr;
} List;

typedef struct
{
    int table[TABLE_SIZE]; // open hashing, pointer to the nodes
    VHeap vptr;
} HashTable;

// hash(x) = x % TABLE_SIZE

void VHeapAppend(VHeap heap, int head, int elem)
{
    int *idx = &head;
    for (; idx = &heap->node[*idx].next; *idx != -1) { }
    heap->node[*idx].data = elem;
    heap->avail = *idx;
    *idx = -1;
}

HashTable *listToHashTable(List *list)
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    int *idx = &list->head;
    while (*idx != -1)
    {
        NodeType node = list->vptr->node[*idx];
        int num = node.data;
        idx = &node.next;
    }
}