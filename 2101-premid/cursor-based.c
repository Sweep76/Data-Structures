#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct{
    char data[20];
    int group;
    int link;
}Nodetype;

typedef struct VHnode {
    Nodetype heap[SIZE];
    int avail;
}*VHeap;

typedef struct {
    int elemPtr;
    VHeap VH;
}cursorList;

void display(cursorList L){
    int trav;
    for(trav=L.elemPtr; trav!=-1; trav=L.VH->heap[trav].link){
        printf("\n%s",L.VH->heap[trav].data);
    }
}

void insertFirst(cursorList *L, char str[]){
    int temp;
    temp = L->VH->avail;
    L->VH->avail = L->VH->heap[temp].link;
    strcpy(L->VH->heap[temp].data, str);
    L->VH->heap[temp].link = L->elemPtr;
    L->elemPtr = temp;
}

void deleteFirst(cursorList *L, char str[]){
    int temp;
    temp = L->elemPtr;
    L->elemPtr = L->VH->heap[temp].link;
    L->VH->avail = L->VH->heap[temp].link;
    L->VH->heap[temp].link = L->VH->avail;
    L->VH->avail = temp;
}


int main(){
    cursorList L;
    insertFirst(&L, 'A');
    insertFirst(&L, 'B');
    insertFirst(&L, 'C');
    insertFirst(&L, 'D');
    display(L);

}