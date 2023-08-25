#include <stdio.h>
#include <stdlib.h>
#define VH_MAX 0XFF

typedef struct
{
    char FN[24], LN[16], MI;
} nametype;

typedef struct
{
    unsigned int ID;
    nametype name;
    char course[8];
    int yrLevel;
} studRec;

// Mdm's cursorlist fetish
typedef struct
{
    studRec stud;
    int prev;
    int next;
} CBnode;

typedef struct
{
    CBnode heap[VH_MAX];
    int avail;
} *Vheap;

typedef struct
{
    int elemPtr;
    Vheap VH;
} List;

typedef List BST;

/*
Function Bst2List() will remove all elements of the given BST from the biggest to the smallest and put them in a newly created list that is sorted in ascending order according to ID. The newly created list will be returned to the calling function. Note that the given BST is organized according to ID. Write the code of the function.
*/

// List *BST2List(BST *bst)
// {
//     int trav = bst->elemPtr;

//     trav =
// }

int main()
{
    return 0;
}