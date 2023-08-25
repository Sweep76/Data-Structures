#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

typedef int Node;
typedef Node *Tree[SIZE];

Node TreeParent(Tree tree, Node node)
{
    return (*tree)[node];
}

int main()
{

    return 0;
}