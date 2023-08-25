/*MAX HEAPSORT*/
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
    int arr[] = {5,4,12,4,7,1,0};
    int size = sizeof(arr) / sizeof(int);
    initialize(&H);
    populate(&H, arr, size);
    HeapSort(&H);
    display(H);

}

//Display's the Heap Status
void display(Heap H){
    int x; 
    for (x = 0; x <= H.last; x++){
        printf("[%d] = %d\n", x, H.t[x]);
    }
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

//Initializes the Heap 
void initialize(Heap *H){
    H->last = -1;
}
/*Arranges the Heap to a POT using maxHeap, wherein elem[parent] > elem[children]. 
Then later on arranges the heap in acending order using delMax
*/
void HeapSort(Heap* H){
    int parent, idx, temp, oldLast = H->last, n, x, lc, rc, bc = 1;

    //insert in an initially empty POT
    H->last = -1;
    for (x = 0; x < oldLast; x++){
    if (H->last < MAX_HEAP-1){
        ++H->last;
        idx = H->last;
        parent = (idx-1)/2;
        n = H->t[x];
        while (idx!= 0 && H->t[parent]< n){
            H->t[idx] =  H->t[parent];

            idx = parent;
            parent = (idx-1)/2;
        }
        H->t[idx] = n;
    }
    }

    //MaxHeapsort using deleteMAX
    //Arranges the Heap in Ascending Order
    H->last = oldLast;
    while (H->last != -1){
        n = H->t[0];
        H->t[0] = H->t[H->last];
        H->t[H->last] = n;
        --H->last;
        parent = 0;
        lc = 1; 
        rc = 2;
        bc = -1;  //biggest child
        while (parent < H->last && lc <= H->last){
            if (rc <= H->last && H->t[rc] > H->t[parent] && H->t[rc] > H->t[lc]){
                bc = rc;
            } else if (H->t[lc] > H->t[parent]){
                bc = lc;
            } else{
                 parent = H->last;
            }

            if (bc != -1){
            temp = H->t[parent];
            H->t[parent] = H->t[bc];
            H->t[bc] = temp;

            parent = bc;
            lc = (parent*2)+1;
            rc = lc+1;
            }

        }

    }
    H->last = oldLast;
}