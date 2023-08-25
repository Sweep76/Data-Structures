#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int elem;
    struct cell *LC;
    struct cell *RC;
} ctype, *BST;

BST BSTInit()
{
    return (BST)NULL;
}

void BSTInsert(BST *bst, int elem)
{
    BST *trav = bst;
    while (*trav != NULL)
    {
        trav = (elem < (*trav)->elem) ? &(*trav)->LC : &(*trav)->RC;
    }
    BST newCell = (BST)malloc(sizeof(ctype));
    newCell->elem = elem;
    newCell->LC = NULL;
    newCell->RC = NULL;
    *trav = newCell;
}

int BSTIsMember(BST bst, int elem)
{
    BST trav = bst;
    while (trav != NULL && trav->elem != elem)
    {
        trav = (elem < trav->elem) ? trav->LC : trav->RC;
    }
    return (trav == NULL) ? 0 : 1;
}

int BSTRecIsMember(BST bst, int elem)
{
    if (bst == NULL)
        return 0;
    else if (bst->elem == elem)
        return 1;
    else
        return BSTRecIsMember((elem < bst->elem) ? bst->LC : bst->RC, elem);
}

int main()
{
    BST bst = BSTInit();
    BSTInsert(&bst, 10);
    BSTInsert(&bst, 5);
    BSTInsert(&bst, 14);
    BSTInsert(&bst, 12);
    BSTInsert(&bst, 7);
    BSTInsert(&bst, 18);
    BSTInsert(&bst, 15);
    printf("%d", BSTRecIsMember(bst, 12));
    return 0;
}