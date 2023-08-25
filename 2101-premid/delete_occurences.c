#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} * List;

void deleteOccurances(List *list, char delete)
{
    List *trav = list;
    while (*trav != NULL)
    {
        // check if delete char is detected
        if ((*trav)->data == delete)
        {
            // reference node to be deleted
            List toBeDeletedYes = *trav;
            // relink
            *trav = (*trav)->link;
            // free to be deleted node
            free(toBeDeletedYes);
        }
        else
            trav = &(*trav)->link;
    }  
}

void display(List list)
{
    List trav = list;
    while (trav != NULL)
    {
        printf("%c ", trav->data);
        trav = trav->link;
    }
    printf("\n");
}

void appendEnd(List *list, char data)
{
    // traverse to the end
    List *trav = list;
    while (*trav != NULL)
    {
        trav = &(*trav)->link;
    }
    // create new node
    List newNode = (List)malloc(sizeof(struct node));
    newNode->link = NULL;
    newNode->data = data;
    *trav = newNode;
}

int main()
{
    List myList = NULL;
    appendEnd(&myList, 'A');
    appendEnd(&myList, 'B');
    appendEnd(&myList, 'B');
    appendEnd(&myList, 'C');
    appendEnd(&myList, 'D');
    appendEnd(&myList, 'E');
    deleteOccurances(&myList, 'B');
    display(myList);
    return 0;
}