#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char data;
    struct node *link;
} * linkList;


void insertSorted(linkList *list, char elem)
{
    linkList *trav = list;
    while (elem > (*trav)->data && (*trav)->link != NULL)
        trav = &(*trav)->link;
    if ((*trav)->data == elem)
        return;
    linkList newList = (linkList)malloc(sizeof(struct node));
    newList->data = elem;
    if (elem < (*trav)->data)
    {
        newList->link = *trav;
        *list = newList;
    }
    else
    {
        (*trav)->link = newList;
        newList->link = NULL;
    }
}

linkList initLinkList(char data)
{
    linkList list = (linkList)malloc(sizeof(struct node));
    list->data = data;
    list->link = NULL;
    return list;
}

void printLinkList(linkList list)
{
    while (list != NULL)
    {
        printf("%c", list->data);
        list = list->link;
    }
    printf("\n");
}

int main()
{
    linkList newList = initLinkList('f');
    insertSorted(&newList, 'g');
    insertSorted(&newList, 'e');
    insertSorted(&newList, 'd');
    insertSorted(&newList, 'c');
    printLinkList(newList);
    return 0;
}