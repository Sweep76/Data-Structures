#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef int Node;

typedef struct node
{
    Node node;
    struct node link;
} * List;

typedef struct
{
    Node root;
    List header[SIZE];
} Tree;

Tree *initTree(Node root)
{
    Tree *tree = malloc(sizeof(Tree));
    tree->root = root;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        tree->header[i] = NULL;
    }
    return tree;
}

Node leftMostChild(Node node, Tree T)
{
    List childList = T.header[node];
    Node child = -1;
    if (childList != NULL)
        child = childList->node;
    return child;
}

Node parent(Node node, Tree T)
{
    Node parent = -1;
    int parentIdx;
    for (parentIdx = 0; parentIdx < SIZE && parent != -1; parentIdx++)
    {
        List childList = T.header[parentIdx];
        while (childList != NULL && childList->node != node)
            childList = childList->link;
        if (childList != NULL)
            parent = parentIdx;
    }
}

int main()
{

    return 0;
}