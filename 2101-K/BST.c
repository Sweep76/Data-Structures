#include <stdlib.h>
#include <stdio.h>

typedef struct cell
{
    int elem;
    struct cell *LC;
    struct cell *RC;
} ctype, *BST;

BST S;

typedef enum
{
    PREORDER,
    INORDER,
    POSTORDER,
} DisplayType;

// int isMember(BST tree, int elem)
// {
//     if (tree == NULL)
//         return 0;
//     else if (tree->elem == elem)
//         return 1;
//     else
//         return (tree->elem < elem) ? tree->LC : tree->RC;
// }

// delete leaf
// delete inode with a left child only
// delete inode with a right child only
// delete inode with two children

void init(BST *tree)
{
    (*tree) = NULL;
}

void insert(BST *tree, int elem)
{
    BST *cell = tree;
    while (*cell != NULL && (*cell)->elem != elem)
    {
        cell = ((*cell)->elem < elem) ? &(*cell)->LC : &(*cell)->RC;
    }
    if (*cell == NULL)
    {
        *cell = (BST)malloc(sizeof(ctype));
        (*cell)->elem = elem;
        (*cell)->LC = NULL;
        (*cell)->RC = NULL;
    }
}

void display(BST tree, DisplayType displayType)
{
    if (displayType == PREORDER)
        printf("%d ", tree->elem);
    if (tree->LC != NULL)
        display(tree->LC, displayType);
    if (displayType == INORDER)
        printf("%d ", tree->elem);
    if (tree->RC != NULL)
        display(tree->RC, displayType);
    if (displayType == POSTORDER)
        printf("%d ", tree->elem);
}

void freeBST(BST tree)
{
    if (tree->LC != NULL)
        freeBST(tree->LC);
    if (tree->RC != NULL)
        freeBST(tree->RC);
    free(tree);
}

int isMember(BST tree, int elem)
{
    BST cell = (BST)tree;
    while (cell != NULL && cell->elem != elem)
    {
        cell = (cell->elem < elem) ? cell->LC : cell->RC;
    }
    return (cell != NULL) ? 1 : 0;
}

void deleteElem(BST tree, int elem)
{
    BST *cell = tree;
    while (*cell != NULL && (*cell)->elem != elem)
    {
        cell = ((*cell)->elem < elem) ? &(*cell)->LC : &(*cell)->RC;
    }
    if (*cell != NULL)
    {
    }
}

int main()
{

    return 0;
}