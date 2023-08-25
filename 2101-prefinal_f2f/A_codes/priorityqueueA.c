#include <stdio.h>
#include <string.h>

#define MAX_HEAP 10
#define MAX_STRING 20

typedef struct{
    int ID;
    char Name[MAX_STRING];
    char Type; //s-1, 2-p, 3-r
}Record;

typedef struct{
    int custType; //1 - senior 2- pregnamt 3-regular
    Record data;
}NodeType;

typedef struct{
    NodeType Tree[MAX_HEAP];
    int last;
    int oldLast;
}Heap;


void main(){
    Heap POT;
    initialize(&POT);
    Record node1 = {1012, "Angelou", 'r'};
    insert(node1, &POT);

    node1.ID = 1234;
    strcpy(node1.Name, "David");
    node1.Type='s';
    insert(node1, &POT);

    node1.ID = 1124;
    strcpy(node1.Name, "Carla");
    node1.Type='p';
    insert(node1, &POT);

    node1.ID = 1111;
    strcpy(node1.Name, "Jonna");
    node1.Type='p';
    insert(node1, &POT);

    HeapSort(&POT);
    HeapSort(&POT);
    display(POT);
}

void initialize(Heap* T){
    T->last = -1;
    T->oldLast = -1;
}

void insert(Record node, Heap *T){
    int parentIDX, childIDX, tempCustType;
    Record temp;
    if(T->last < MAX_HEAP-1){ //if not full then proceed
        T->last = T->last+1;
        T->oldLast = T->last;
        switch(node.Type){
            case 's':
                T->Tree[T->last].custType = 1;
                break;
            case 'p':
                T->Tree[T->last].custType = 2;
                break;
            case 'r':
            default: 
                T->Tree[T->last].custType = 3;
                break;
        }

        T->Tree[T->last].data = node;
        childIDX = T->last;
        parentIDX = (childIDX-1)/2;
        while (T->Tree[childIDX].custType < T->Tree[parentIDX].custType){
            temp = T->Tree[childIDX].data;
            tempCustType = T->Tree[childIDX].custType;
            T->Tree[childIDX].data= T->Tree[parentIDX].data;
            T->Tree[childIDX].custType = T->Tree[parentIDX].custType;
            T->Tree[parentIDX].custType = tempCustType;
            T->Tree[parentIDX].data= temp;

            childIDX = parentIDX;
            parentIDX = (parentIDX-1)/2;
        }
    }
    // printf("Priority Number: %d \n", T->Tree[T->last].custType);
    // printf("CustID: %d Name: %s\n", T->Tree[T->last].data.ID, T->Tree[T->last].data.Name);
    // printf("LAST: %d\n", T->last);
    // printf("=========================\n\n");
    
}

void display(Heap T){
    int x;
    int MAX = T.last;
    for (x = 0; x <= MAX; x++){
        printf("Priority Number: %d ", T.Tree[x].custType);
        switch(T.Tree[x].custType){
            case 1:
                printf("[Senior Citizen]\n");
                break;
            case 2:
                printf("[Pregnant]\n");
                break;
            case 3:
            default:
                printf("[Regular]\n"); 
                break;
        }
        
        printf("CustID: %d Name: %s\n", T.Tree[x].data.ID, T.Tree[x].data.Name);
        printf("=========================\n\n");
    }
}

void HeapSort(Heap *T){
    int parentIDX, RCIDX, LCIDX, SCIDX, pot = 0, tempCustType;
    Record temp;
    parentIDX = 0;
    T->Tree[0].data = T->Tree[T->last].data;
    T->Tree[0].custType = T->Tree[T->last].custType;
    T->last = T->last-1;

    
    while (parentIDX != T->last && pot!= 1){
        LCIDX = (parentIDX*2)+1;
        RCIDX = LCIDX+1;
        if (RCIDX <= T->last){
            if (T->Tree[LCIDX].custType <= T->Tree[RCIDX].custType){
                SCIDX = LCIDX;
            }else{
                SCIDX = RCIDX;
            }
        }else if(LCIDX <= T->last){
            SCIDX = LCIDX;
        }else{
            pot=1;
        }
        if (pot!= 1){
        T->Tree[parentIDX].custType  = tempCustType;
        temp = T->Tree[parentIDX].data;
        T->Tree[parentIDX].data = T->Tree[SCIDX].data;
        T->Tree[parentIDX].custType = tempCustType;

        T->Tree[SCIDX].data = temp;
        T->Tree[SCIDX].custType = tempCustType;
        parentIDX = SCIDX;
        T->last = T->last-1;
        }
        
    }
}

