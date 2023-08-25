#include <stdlib.h>
#include <stdio.h>

/*
1. insert
2. deletemin

initialize
makenull

1. Insert(x,A)
    - adds element x in set A, if the element x is not yet a member of the set
2. Deletemin(A)
    - removes and returns the smallest element in set A if the set is not empty; otherwise the operation fails

Implemenetations:
1. BitVector
2. Linked List
3. Array
4. Cursor Based
5. Partally Ordered Tree (P.O.T.)

P.O.T. Characteristics:
1. Binary Tree
    - A tree in which each node has either a left child, or a right child or both left and right children.
2. Balanced Tree
    - A tree in which the height is a minimum for the # of nodes.
3. At the lowest level, where the leaves may be missing, we require that all missing leaves are to the right of all the leaves present in the lowest level.
4. POT Property
    - The priority of the parent is less than or equal to the priority of the children

INSERT:
1. Place new element x at the lowest level to the right of the leaves present
or next level if current level is full
2. while (x is not root and POT property is not satisfied)
    SWAP(parent, x)

DELETEMIN:
1. min = root node
2. Replace root with the element x found at the lowest level far right
3. While ((x is not leaf) and NOT POT) {
    SChild = smaller child of parent x;
    SWAP(x, SChild);
}
4. return min;

Running Time for insert and deletmin is O(Log_2 N)
Maximum path of the tree is 1+Log_2 N

Implementation of POT
Heap
    - Array implementation of P.O.T.

heap:
lchild = parent * 2 + 1
parent = (child - 1) / 2

*/
#define SIZE 100

typedef struct
{
    int elem[SIZE];
    int lastNdx;
} HeapList;

void init(HeapList *heap)
{
    heap->lastNdx = -1;
}

void display(HeapList *heap)
{
    int i;
    for (i = 0; i <= heap->lastNdx; i++)
    {
        printf("%d ", heap->elem[i]);
    }
    printf("\n");
}

int parentIdx(int childIdx)
{
    return (childIdx - 1) / 2;
}

int childLIdx(int parentIdx)
{
    return parentIdx * 2 + 1;
}

void insert(HeapList *heap, int elem)
{
    int child = ++heap->lastNdx;
    int parent = parentIdx(child);
    heap->elem[child] = elem;
    while (child != 0 && heap->elem[parent] > heap->elem[child])
    {
        int spare = heap->elem[parent];
        heap->elem[parent] = heap->elem[child];
        heap->elem[child] = spare;
        child = parent;
        parent = parentIdx(child);
    }
}

int deleteMin(HeapList *heap)
{
    if (heap->lastNdx < 0)
        return -1;
    int min = heap->elem[0];
    heap->elem[0] = heap->elem[heap->lastNdx--];
    int idx = 0;
    int childL = childLIdx(idx);
    int isTrav = 1;
    while (childL <= heap->lastNdx && isTrav)
    {
        int small = heap->elem[childL];
        if (childL + 1 <= heap->lastNdx && small < heap->elem[childL + 1])
            small = heap->elem[childL + 1];
        isTrav = (heap->elem[idx] > small);
        if (isTrav)
        {
            idx = childL;
            childL = childLIdx(idx);
        }
    }
    return min;
}

int main()
{
    HeapList HL;
    init(&HL);
    insert(&HL, 6);
    insert(&HL, 3);
    insert(&HL, 9);
    insert(&HL, 8);
    insert(&HL, 2);
    insert(&HL, 5);
    insert(&HL, 1);
    insert(&HL, 4);
    insert(&HL, 7);
    insert(&HL, 10);
    display(&HL);
    return 0;
}
/*
0 1 3 7 15 31
                               0                               |31     1
               0                               0               |15 31  2
       0               0               0               0       |7  15  4
   0       0       0       0       0       0       0       0   |3  7   8
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 |1  3   16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0|0  1   32
*/