#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *LChild;
    struct node *RChild;
} node, *BST;

void displayInc(BST tree)
{
    if (tree != NULL)
    {
        displayInc(tree->LChild);
        printf("%d ", tree->data);
        displayInc(tree->RChild);
    }
}

void displayDec(BST tree)
{
    if (tree != NULL)
    {
        displayDec(tree->RChild);
        printf("%d ", tree->data);
        displayDec(tree->LChild);
    }
}

int smallest(BST tree)
{
    if (tree == NULL)
        return -1;
    return smallest((tree->LChild != NULL) ? tree->LChild : tree->data);
}

int main()
{

    return 0;
}