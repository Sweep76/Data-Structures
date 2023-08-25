#include <stdio.h>

#define MAX_VH 20
#define MAX_HEAP 20

typedef struct {
    int data;
    int prev;
    int next;
}CBNode;

typedef struct {
    CBNode H[MAX_VH];
    int avail;
}VirtualHeap;

typedef int Node;

typedef struct {
    Node Tree[MAX_HEAP];
    int last;
}Heap;

void initializeVH(VirtualHeap* VH);


void main(){
    VirtualHeap VH;
    initializeVH(&VH);
    displayVH(VH);
    addNode(&VH);
    addNode(&VH);
    addNode(&VH);
    addNode(&VH);
    freeNode(&VH, 0);
    freeNode(&VH, 1);
    freeNode(&VH, 2);
    displayVH(VH);  
    
}

void initializeVH(VirtualHeap* VH){
    VH->avail = 0;
    int lim = MAX_VH - 1, x;
    for (x = 0; x < lim; x++){
        VH->H[x].data = 0;
        VH->H[x].prev = x-1;
        VH->H[x].next = x+1;
    }
    VH->H[x].next = -1;
    VH->H[x].prev = x-1;
}

void displayVH(VirtualHeap H){
    int x;
    printf("\nVIRTUAL HEAP:\n");
    for (x = 0; x < MAX_HEAP; x++){
        printf("[%d] - %d - %d - %d\n", x, H.H[x].data, H.H[x].prev, H.H[x].next);
    }
    printf("AVAIL: %d\n", H.avail);
}

int addNode(VirtualHeap *H){
    int retval = H->avail; //note of available node
    if (H->avail != -1){//check if VH is not full
        H->avail = H->H[H->avail].next; //update new avail
        H->H[retval].next = -1; //set pointer of availed node to null
        H->H[retval].prev = -1;
    }
    return retval;  //return available node to the calling func
}

void freeNode(VirtualHeap *VH, int n){
    VH->H[n].next = VH->avail;
    VH->H[n].prev = -1;
    VH->H[VH->avail].prev = n;
    VH->avail = n;
}