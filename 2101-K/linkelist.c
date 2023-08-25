#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char data;
    struct node *link;
} * linkList;

int findElem(linkList L, char elem)
{
    linkList trav = L;
    for (; trav != NULL; trav = trav->link)
    {
        if (trav->data == elem)
            return 1;
    }
    return 0;
}

void deleteElem(linkList *L, char elem)
{  
    linkList *trav = L;
    while (*trav != NULL && (*trav)->data != elem)
    {
        trav = &(*trav)->link;
    }
    if(*trav != NULL){
        linkList temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}


void deleteElems(linkList *L, char elem)
{
    linkList *trav = L;
    for (; *trav != NULL; trav = &(*trav)->link)
    {
        if ((*trav)->data == elem)
        {
            linkList temp = *trav;
            *trav = temp->link;
            free(temp);
        }
    }
}

void insertFirst(linkList *list, char elem)
{
    linkList newList = (linkList)malloc(sizeof(struct node));
    if (newList == NULL)
        return;
    newList->data = elem;
    newList->link = *list;
    *list = newList;
}

void changeLetter(linkList list, char old, char new)
{
    linkList trav = list;
    for (; trav != NULL; trav = trav->link)
    {
        if (trav->data == old)
            trav->data = new;
    }
}

void insertSorted(linkList *list, char elem)
{
    linkList *trav = list;
    while (*trav != NULL && elem >= (*trav)->data)
        trav = &(*trav)->link;
    linkList newList = (linkList)malloc(sizeof(struct node));
    newList->data = elem;
    newList->link = *trav;
    *trav = newList;
}

void insertEnd(linkList list, char elem)
{
    linkList trav = list;
    while (list->link != NULL)
        trav = trav->link;
    linkList newList = (linkList)malloc(sizeof(struct node));
    newList->data = elem;
    newList->link = NULL;
    trav->link = newList;
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
    linkList newList = initLinkList('b');
    insertSorted(&newList, 'd');
    insertSorted(&newList, 'f');
    insertSorted(&newList, 'a');
    insertSorted(&newList, 'c');
    insertSorted(&newList, 'e');
    insertSorted(&newList, 'g');
    printLinkList(newList);
    return 0;
}
