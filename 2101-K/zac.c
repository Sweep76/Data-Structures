#include <stdio.h>
#include <ctype.h>
#define SIZE 10
typedef struct{
    char data;
    int link;
}Nodetype;

typedef struct{
    Nodetype Nodes[SIZE];
    int avail;
}VirtualHeap;

typedef int List;

void initializeVH(VirtualHeap *VH){
    int i = 0;
    VH->avail = i;
    for(; i < SIZE; i++){
        VH->Nodes[i].link = i + 1;
    }
    VH->Nodes[i - 1].link = -1;
}

int allocVH(VirtualHeap *VH){
    int node = -1;
    int link = VH->Nodes[VH->avail].link;
    
    if(link != -1){
        node = VH->avail;
        VH->avail = link;
    }
    
    return node;
}

void deallocVH(VirtualHeap *VH, int node){
    VH->Nodes[node].link = VH->avail;
    VH->avail = node;
}

void insert(VirtualHeap *VH, int *L, char elem){
    int alloc = allocVH(VH);
    int *trav;
    for (trav = L; *trav != -1; trav = &VH->Nodes[*trav].link) { }
    *trav = alloc;
    if(alloc != -1){
        VH->Nodes[alloc].data = elem;
        VH->Nodes[alloc].link = -1;
    }
}

void delete(VirtualHeap *VH, int *L, char elem){
    int *trav;
    for (trav = L; *trav != -1 && VH->Nodes[*trav].data != elem; trav = &VH->Nodes[*trav].link) { }
    if (*trav != -1)
    {
        int temp = VH->Nodes[*trav].link;
        deallocVH(VH, *trav);
        *trav = temp;
    }
}

void pdisplay(VirtualHeap VH, int point)
{
    int i;
    printf("___________\n");
    for (i = 0; i < SIZE; i++)
    {
        char ch = VH.Nodes[i].data;
        int isreadable = isalnum(ch) || ispunct(ch) || isspace(ch);
        printf("|%02d|", i, ch);
        if (isreadable)
            printf("'%c'|", ch);
        else
            printf(" ? |");
        printf("%02d|%c", VH.Nodes[i].link, (i == VH.avail) ? 'O' : ' ');
        if (point != -1 && i == point)
            printf("<--");
        printf("\n");
    }
    printf("___________\n");
}

void display(VirtualHeap VH)
{
    pdisplay(VH, -1);
}

int main()
{
    VirtualHeap VH;
    
    int L = 0;
    initializeVH(&VH);
    insert(&VH, &L, 'H');
    insert(&VH, &L, 'O');
    insert(&VH, &L, 'P');
    insert(&VH, &L, 'E');
    insert(&VH, &L, 'L');
    insert(&VH, &L, 'E');
    insert(&VH, &L, 'S');
    insert(&VH, &L, 'S');
    pdisplay(VH, L);
    
    delete(&VH, &L, 'P');
    pdisplay(VH, L);
}