#include <stdio.h>

#define MAX_HEAP 15

typedef int Node;
typedef struct {
    Node t[MAX_HEAP];
    int last;
}Heap;

void main(){
    Heap Vheap;
    initialize(&Vheap);
    insert(4,&Vheap);
    insert(7,&Vheap);
    insert(9,&Vheap);
    insert(1,&Vheap);

    //display(Vheap);
    //printf("Deleted %d\n", delete(&Vheap));
    //printf("Deleted %d\n", delete(&Vheap));
    //printf("Deleted %d\n", delete(&Vheap));
    //printf("Deleted %d\n", delete(&Vheap));

    
    HeapSort(&Vheap);
    display(Vheap);
}

void initialize(Heap *H){
    H->last = -1;
}


void display(Heap H){
    printf("=================\n");
    int x;
    for (x = 0; x <= H.last; x++){
        printf("%d ", H.t[x]);
    }
    if (H.last == -1){
        printf("[TREE EMPTY]");
    }
    printf("\nLast: %d", H.last);
}

void insert(int n, Heap *H){
    int p, sc, lc, rc, pot = 0, temp;
    if (H->last < MAX_HEAP-1){ //if list is not full
        H->last = H->last+1;
        H->t[H->last] = n;
        p = (H->last-1)/2;
        lc = (p*2)+1;
        rc = lc+1;
        while (pot!=1){
            if (rc <= H->last){
                if (H->t[lc] < H->t[rc]){
                    sc = lc;
                }else{
                    sc = rc;
                }
            }else if (lc <= H->last){
                sc = lc;
            }else{
                sc = p;
            }

            if (H->t[p] > H->t[sc]){
                temp = H->t[p];
                H->t[p] = H->t[sc];
                H->t[sc] = temp;
            }else{
                pot = 1;
            }
                p = (p-1)/2;
                lc = (p*2)+1;
                rc = lc+1;
        }

    }
}

int delete(Heap* H){
    int p=0, sc, lc=1, rc=2, pot = 0, temp;
    if (H->last!= -1){
        temp = H->t[0];
        H->t[0] = H->t[H->last];
        H->t[H->last] = temp;
        H->last = H->last-1;
        while (lc <= H->last && pot!= 1){
            if (rc <= H->last){
                if (H->t[lc] < H->t[rc]){
                    sc = lc;
                }else{
                    sc = rc;
                }
            }else{
                sc = lc;
            }

            if (H->t[p] > H->t[sc]){
                temp = H->t[p];
                H->t[p] = H->t[sc];
                H->t[sc] = temp;
            }else{
                pot = 1;
            }
                p = sc;
                lc = (p*2)+1;
                rc = lc+1;
        }
    }
}

void HeapSort(Heap* H){
    int oldLast = H->last;
    while (H->last != -1){
        delete(H);
    }
    H->last = oldLast;
}