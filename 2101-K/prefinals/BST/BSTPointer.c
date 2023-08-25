#include <stdlib.h>
#include <stdio.h>

typedef struct cell
{
    int elem;
    struct cell *LC;
    struct cell *RC;
} ctype, *BST;

BST BSTInit(int elem)
{
    BST bst = (BST)malloc(sizeof(ctype));
    bst->elem = elem;
    bst->LC = NULL;
    bst->RC = NULL;
    return bst;
}

void BSTInsert(int elem, BST *bst)
{
    BST *trav = bst;
    while (*trav != NULL && (*trav)->elem != elem)
        trav = (elem < (*trav)->elem) ? &(*trav)->LC : &(*trav)->RC;
    if (*trav == NULL)
        *trav = BSTInit(elem);
}

void BSTInsertRec(int elem, BST *bst)
{
    if (*bst == NULL)
        *bst = BSTInit(elem);
    else if ((*bst)->elem != elem)
        BSTInsertRec(elem, (elem < (*bst)->elem) ? &(*bst)->LC : &(*bst)->RC);
}

int BSTMember(int elem, BST bst)
{
    while (bst != NULL && bst->elem != elem)
    {
        bst = (elem < bst->elem) ? bst->LC : bst->RC;
    }
    return (bst == NULL) ? 0 : 1;
}

int BSTMemberRec(int elem, BST bst)
{
    if (bst == NULL)
        return 0;
    else if (bst->elem == elem)
        return 1;
    return BSTMemberRec(elem, (elem < bst->elem) ? bst->LC : bst->RC);
}

void BSTDeleteLeaf(int elem, BST *bst)
{
    BST *trav = bst;
    while (*trav != NULL && (*trav)->elem != elem)
        trav = (elem < (*trav)->elem) ? &(*trav)->LC : &(*trav)->RC;
    if ((*trav)->elem == elem && (*trav)->LC == NULL && (*trav)->RC == NULL)
    {
        free(*trav);
        *trav = NULL;
    }
}

// idk
void BSTDeleteINodeL(int elem, BST *bst)
{
    BST *trav = bst;
    while (*trav != NULL)
    {
        if ((*trav)->LC != NULL && (*trav)->LC->elem != elem)
        {
        }
        else
        {
            trav = (elem < (*trav)->elem) ? &(*trav)->LC : &(*trav)->RC;
        }
    }
    if (*trav != NULL && (*trav)->LC != NULL && (*trav)->LC->elem == elem)
    {
        free(*trav);
        *trav = NULL;
    }
}

void BSTDeleteMin(BST *bst)
{
    BST *trav = bst;
    while (*trav != NULL)
    {
        trav = &(*trav)->LC;
    }
    BST temp = *trav;
    int min = temp->elem;
    *trav = NULL;
    free(temp);
    return min;
}

int main()
{
    BST S;

    return 0;
}