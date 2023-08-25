#include <stdio.h>
#define SIZE 30

typedef struct {
    int data;
    int next;
}Data;

typedef struct{
    Data elem[SIZE];
    int available;
    int start;
}List;

void init(List *L);
void deleteAtIndex(List *L, int data);
int insert(List *L, int data);
int display(List L);


void main(){
    List L;
    init(&L);

    insert(&L,2);
    insert(&L,5);
    insert(&L,6);
    insert(&L,78);
    insert(&L,9);
    insert(&L,91);
    display(L);
    deleteAtIndex(&L,3);
    display(L);
    deleteAtIndex(&L,1);
    display(L);

}

void init(List *L){
    L->available = 0;
    L->start = -3;
    int x;
    for(x=0;x<SIZE;x++){
        L->elem[x].next = -1;
    }
}

int isEmpty(List L){
    if(L.start == -3){
        return 1;
    } else {
        return 0;
    }
}

int findPointer(List L, int find){
    int x;
    for(x=0;x<SIZE;x++){
        if(L.elem[x].next == find){
            return x;
        }
    }
    return -2;
}



int findAvail(List L){
    int x;
    for(x=0;x<SIZE;x++){
        if(L.elem[x].next == -1){
            return x;
        }
    }
}

int insert(List *L, int data){
    int var = findPointer(*L, L->available);
    int avail;
    if(L->start == -3){
        L->start = 0;
        L->elem[0].next = -2; // set next to last element
        avail = 1;
        L->available = avail;
        L->elem[0].data = data;
        
    } else {
        L->elem[findLast(*L)].next = L->available;
        L->elem[L->available].data = data;
        L->elem[L->available].next = -2;
        avail = findAvail(*L);
        L->available = avail;
        L->elem[var].next = L->available;
    }

}

int findLast(List L){
    int x;
    for(x=0;x<SIZE;x++){
        if(L.elem[x].next == -2){
            return x;
        }
    }
}

int display(List L){
    int trav;
    int x = 0;
    if(isEmpty(L) == 1){
        printf("Empty list!");
    }else{
        printf("\n");
        printf("\t---------------------\n");
        printf("\t%s\t%s\t%s\n", "INDEX","DATA","AVAIL");
        for(trav = L.start; trav != -2 && trav != -1; trav = L.elem[trav].next){
            printf("\t%d\t%d\t%d\n", x, L.elem[trav].data, L.elem[trav].next);
            x++;
        }
        printf("\n\tavailable:%d\n\tstart:%d\n", L.available, L.start);
    }
}

void deleteAtIndex(List *L, int data){
    int temp;
    if(data == L->start){
        L->elem[L->start].data = 0;
        temp = L->elem[L->start].next;
        L->elem[L->start].next = -1;
        if(temp > 0){
            L->start = temp;
        } else{
            L->start - 3;
        }
    } else{
        int point = findPointer(*L, data);
        L->elem[data].data = 0;
        L->elem[point].next = L->elem[data].next;
        L->elem[data].next = -1;
    }

    L->available = findAvail(*L);
}