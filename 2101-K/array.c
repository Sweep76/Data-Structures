#include <stdio.h>
#include <stdlib.h>
#define MAX 0xF

typedef struct node {
    char data[MAX];
    int ctr; // elements in array;
} * arrayList;

int changeLetter(arrayList list, char oldChar, char newChar);
arrayList initList();
int changeLetter(arrayList list, char oldChar, char newChar);
void insertSorted(arrayList list, char elem);
void deleteAll(arrayList list, char elem);

arrayList initList()
{
    arrayList newList = (arrayList)malloc(sizeof(struct node));
    newList->ctr = 0;
    return newList;
}

int changeLetter(arrayList list, char oldChar, char newChar)
{
    int i, changes;
    for (i = 0, changes = 0; i < list->ctr; i++)
    {
        if (list->data[i] == oldChar)
        {
            list->data[i] = newChar;
            changes++;
        }
    }
    return changes;
}

void insertSorted(arrayList list, char elem)
{
    // terminate if list reaches capacity
    if (list->ctr >= MAX)
        return;
    // empty list
    if (list->ctr <= 0)
    {
        list->data[0] = elem;
        list->ctr = 1;
        return;
    }
    // find idx to insert
    int back = 0, front = list->ctr;
    while (back < front)
    {
        int mid = (back+front)/2;
        if (list->data[mid] < elem)
            back = mid + 1;
        else
            front = mid;
    }
    // terminate if element exists in list
    if (list->data[back] == elem)
        return;
    // shift items from back idx to the right
    list->ctr++;
    int i;
    for (i = back + 1; i < list->ctr; i++)
        list->data[i] = list->data[i - 1];
    // assign element to back idx
    list->data[back] = elem;
}

void deleteAll(arrayList list, char elem)
{
    int i, scn;
    for (i = 0, scn = 0; scn < list->ctr; scn++)
    {
        if (list->data[scn] != elem)
            list->data[i++] = list->data[scn];
    }
    list->ctr = i;
}

int main()
{
    return 0;
}