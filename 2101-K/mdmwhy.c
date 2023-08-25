#include <stdio.h> 
#include <stdlib.h>
#define DICK_LENGTH 10

typedef struct {
    char data;
    int link;
} Node;

typedef struct {
    Node Nodes[DICK_LENGTH];
    int avail;
} VirtualHeap;

typedef int List;

VirtualHeap initVH()
{
    VirtualHeap VH;
    int i;
    for (i = 0; i < DICK_LENGTH; i++)
    {
        VH.Nodes[i].data = '_';
        VH.Nodes[i].link = i - 1;
    }
    VH.avail = DICK_LENGTH - 1;
    return VH;
}

void insertFirst(List *L, char data, VirtualHeap *VH)
{
    if (*L > DICK_LENGTH - 1 || *L < -1)
        return;
    int tmpAvail = VH->avail;
    if (tmpAvail != -1)
    {
        VH->avail = VH->Nodes[tmpAvail].link;
        VH->Nodes[tmpAvail].link = *L;
        VH->Nodes[tmpAvail].data = data;
        *L = tmpAvail;
    }
}

void deleteFirst(List *L, VirtualHeap *VH)
{
    if (*L > DICK_LENGTH - 1 || *L < 0)
        return;
    List oldL = *L;
    *L = VH->Nodes[oldL].link;
    VH->Nodes[oldL].link = VH->avail;
    VH->avail = oldL;
}

void display(VirtualHeap VH)
{
    printf("avail: %d\n", VH.avail);
    printf("Nodes: \n");
    int i;
    for (i = 0; i < DICK_LENGTH; i++)
    {
        printf("%d | %c | %02d \n", i, VH.Nodes[i].data, VH.Nodes[i].link);
    }
}

int main()
{
    VirtualHeap VH = initVH();
    List L = -1;
    List M = -1;
    insertFirst(&L, 'A', &VH);
    insertFirst(&M, 'B', &VH);
    insertFirst(&M, 'C', &VH);
    insertFirst(&L, 'B', &VH);
    deleteFirst(&L, &VH);
    display(VH);
    return 0;
}
