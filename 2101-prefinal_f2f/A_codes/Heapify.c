/*Heapify MAX*/
#include <stdio.h>

#define MAX_HEAP 15

typedef int Node;
typedef struct {
    Node t[MAX_HEAP];
    int last;
}Heap;

void display(Heap H);
void populate(Heap *H, int arr[], int size);
void initialize(Heap *H);
void HeapSort(Heap *H);

void main(){
    Heap H;
    int arr[] = {6,1,9,5,10,7,8};
    int size = sizeof(arr) / sizeof(int);
    initialize(&H);
    populate(&H, arr, size);
    //Heapify(&H);
    printf("\nUNSORTED ARRAY:\n");
    display(H);

    printf("\n==========================\nMAX HEAPIFY:\n");
    MaxHeapify(&H);
    display(H);


    printf("\nMAX SORTED:\n");
    Heapify(&H);
    display(H);


    printf("\n===========================\nMIN HEAPIFY:\n");
    MinHeapify(&H);
    display(H);
    printf("\nMIN SORTED:\n");
    HeapifyMin(&H);
    display(H);

}

//Display's the Heap Status
void display(Heap H){
    int x; 
    for (x = 0; x <= H.last; x++){
        printf("[%d] = %d\n", x, H.t[x]);
    }
}

void initialize(Heap *H){
    H->last = -1;
}

//Populates the Heap (Unordered)
void populate(Heap* H, int arr[], int size){
    int x;
    for (x = 0; x < size; x++ ){
        if (H->last <= MAX_HEAP){
            ++H->last;
            H->t[H->last] = arr[H->last];
        }
    }
}

void maxSubHeapifyDEMO(Heap *H, int parent){
    int leftC, rightC, largeC, temp;
    leftC = (parent*2)+1;
    rightC = (parent*2)+2;
    largeC = (H->t[leftC] > H->t[rightC])? leftC: rightC;
        while (leftC <= H->last && H->t[parent] < H->t[largeC]){
            temp = H->t[parent];
            H->t[parent] = H->t[largeC];
            H->t[largeC] = temp;
            leftC = (largeC*2)+1;
            if (leftC <= H->last && rightC <= H->last){
                parent = largeC;
                largeC = (H->t[leftC] > H->t[leftC+1])? leftC : leftC+1;
            }
        }

}

void maxSubHeapify(Heap *H, int parent){
    int LC, RC, BC, temp;
    LC = parent * 2 + 1;
    RC = parent * 2 + 2;
        if (RC <= H->last){
            BC = (H->t[LC] > H->t[RC])? LC : RC;
        }else{
            BC = LC;
        }
    while (LC <= H->last && H->t[parent] < H->t[BC]){
        temp = H->t[parent];
        H->t[parent] = H->t[BC];
        H->t[BC] = temp;
        parent = BC;
        LC = parent * 2 + 1;
        RC = parent * 2 + 2;
            if (RC <= H->last){
                BC = (H->t[LC] > H->t[RC])? LC : RC;
            }else{
                BC = LC;
            }
    }
    
}

void MaxHeapify(Heap *H){
    int parent;
    for (parent = (H->last-1)/2; parent >= 0; parent--){
        maxSubHeapify(H, parent);
    }
}

void Heapify(Heap *H){
    int oldLast, LC, RC, temp;
    oldLast = H->last;
    while (H->last!= -1){
        temp = H->t[H->last];
        H->t[H->last] = H->t[0];
        H->t[0] = temp;
        --H->last;
        maxSubHeapify(H, 0);
    }
    H->last = oldLast;
}


/*Heapify in MIN*/
void minSubHeapify(Heap *H, int parent){
    int LC, RC, SC, temp;
    LC = parent * 2 + 1;
    RC = parent * 2 + 2;
    if (RC <= H->last && H->t[RC] <= H->t[LC]){
        SC = RC;
    }else{
        SC = LC;
    }
    while(LC <= H->last && H->t[SC] < H->t[parent]){
        temp = H->t[parent];
        H->t[parent] = H->t[SC];
        H->t[SC] = temp;
        parent = SC;
        LC = parent * 2 + 1;
        RC = parent * 2 + 2;
        if (RC <= H->last && H->t[RC] <= H->t[LC]){
            SC = RC;
        }else{
            SC = LC;
        }
    }
}

void MinHeapify(Heap *H){
    int parent;
    for (parent = (H->last-1)/2; parent >= 0; parent--){
        minSubHeapify(H, parent);
    }
}

void HeapifyMin(Heap *H){
    int LC, RC, SC, temp, oldLast = H->last;
    while (H->last!= -1){
        temp = H->t[0];
        H->t[0] = H->t[H->last];
        H->t[H->last] = temp;
        --H->last;
        minSubHeapify(H, 0);
    }
    H->last = oldLast;
}