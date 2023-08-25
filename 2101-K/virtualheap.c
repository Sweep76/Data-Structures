#include <stdlib.h>
#include <stdio.h>
#define MAX 10


typedef struct {
    char data;
    int link;
} Nodetype;

typedef struct {
    Nodetype Nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

VirtualHeap initializeVH()
{
    VirtualHeap VH;
    int i;
    for (i = 0; i < MAX; i++)
    {
        VH.Nodes[i].link = i - 1;
    }
    VH.avail = MAX - 1;
    return VH;
}

int findElem(VirtualHeap VH, List L, char elem)
{
    List trav = L;
    for (; trav != -1; trav = VH.Nodes[trav].link)
    {
        if (VH.Nodes[trav].data == elem)
            return 1;
    }
    return 0;
}

void insertSorted(VirtualHeap *VH, List *L, char elem)
{
    List *trav = L;
    for (; *trav != -1 && elem > VH->Nodes[*trav].data; trav = &VH->Nodes[*trav].link) {}
    List newSpace = allocSpace(VH);
    if (newSpace != -1)
    {
        VH->Nodes[newSpace].data = elem;
        VH->Nodes[newSpace].link = VH->Nodes[*trav].link;
        *trav = newSpace;
    }
}

void displayList(VirtualHeap VH, List L)
{
    List trav = L;
    for (; trav != -1; trav = VH.Nodes[trav].link)
    {
        printf("%c", VH.Nodes[trav].data);
    }
}

int allocSpace(VirtualHeap *VH)
{
    int avail = VH->avail;
    int link = VH->Nodes[avail].link;
    if (link == -1)
    {
        return -1;
    }
    VH->avail = link;
    VH->Nodes[avail].link = -1;
    return avail;
}

void deallocSpace(VirtualHeap *VH, int node)
{
    VH->Nodes[node].link = VH->avail;
    VH->avail = node;
}

void deleteElem(List *L, char elem, VirtualHeap *VH)
{
    List *trav = L;
    for (; *trav != -1 && VH->Nodes[*trav].data != elem; trav = &(VH->Nodes[*trav].link)) {}
    if (*trav != -1)
    {
        List temp = *trav;
        *trav = VH->Nodes[temp].link;
        deallocSpace(VH, temp);
    }
}

// void deleteElem(linkList *L, char elem)
// {  
//     linkList *trav = L;
//     while (*trav != NULL && (*trav)->data != elem)
//     {
//         trav = &(*trav)->link;
//     }
//     if(*trav != NULL){
//         linkList temp = *trav;
//         *trav = temp->link;
//         free(temp);
//     }
// }

void insertFirst(List *L, char data, VirtualHeap *VH)
{
    List newElem = allocSpace(VH);
    if (newElem != -1)
    {
        VH->Nodes[newElem].data = data;
        VH->Nodes[newElem].link = *L;
        *L = newElem;
    }
}

List deleteFirst(List L, VirtualHeap *VH)
{

    deallocSpace(VH, (int)L);
}

void printVH(VirtualHeap VH)
{
    printf("avail = %d\n", VH.avail);
    int i = 0;
    for (i = 0; i < MAX; i++)
    {
        Nodetype node = VH.Nodes[i];
        printf("%02d|%02d|%02d\n", i, node.data, node.link);
    }
}

int main()
{
    VirtualHeap VH = initializeVH();
    printVH(VH);
    return 0;
}