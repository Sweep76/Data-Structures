#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} * SET;

SET Union(SET A, SET B)
{
    SET out = NULL;
    SET *trav = &out;
    SET end = NULL;
    // while both A and B aren't equal to NULL
    while (A != B || A != NULL)
    {
        SET *least;
        if (A == NULL || B == NULL)
            // find available if one of A and B is NULL
            least = (A != NULL) ? &A : &B;
        else
            // otherwise find the least of them
            least = (A->data < B->data) ? &A : &B;
        // check duplicate
        if (end == NULL || end->data != (*least)->data)
        {
            // construct new set
            SET newSet = (SET)malloc(sizeof(struct node));
            newSet->data = (*least)->data;
            newSet->link = NULL;
            // set the new ending of a set
            end = newSet;
            // update out set
            *trav = newSet;
            trav = &(newSet->link);
        }
        // traverse selected of either A and B
        *least = (*least)->link;
    }
    return out;
}

SET makeSet()
{
    return (SET)malloc(sizeof(struct node));
}

// void printLinkList(SET list)
// {
//     for (; list != NULL; list = list->link)
//         printf("%c", list->data);
//     printf("\n");
// }

// int main()
// {
//     SET A = makeSet();
//     A->data = 'A';
//     A->link = makeSet();
//     A->link->data = 'C';
//     A->link->link = makeSet();
//     A->link->link->data = 'G';
//     A->link->link->link = NULL;
//     SET B = makeSet();
//     B->data = 'D';
//     B->link = makeSet();
//     B->link->data = 'E';
//     B->link->link = makeSet();
//     B->link->link->data = 'H';
//     B->link->link->link = NULL;
//     SET C = Union(A, B);
//     // printLinkList(C);
//     return 0;
// }

int main()
{
    int a = 0, b = 0, c = 0;
    int *intAdder[] = {&a, &b, &c};

    printf("%d, %d, %d\n", a, b, c);

    int i;
    for (i = 0; i < 3; i++)
        *(intAdder[i]) = 10;
    
    printf("%d, %d, %d\n", a, b, c);
}