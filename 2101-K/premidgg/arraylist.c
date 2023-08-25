#include <stdio.h>
#include <stdlib.h>
#define MAX 0xF

typedef struct {
    char elem[MAX];
    int size;
} L;

L initList()
{
    L newL;
    newL.size = 0;
    return newL;
}

void changeLetter(L *list, char A, char B)
{
    int i;
    for (i = 0; i < list->size; i++)
    {
        if (list->elem[i] == A)
            list->elem[i] = B;
    }
}

void insertSorted(L *list, char ch)
{
    if (list->size >= MAX)
        return;
    // find idx;
    int idx = 0;
    for (; idx < list->size && ch > list->elem[idx]; idx++) { }
    list->size += 1;
    // shift elements
    int shift;
    for (shift = list->size-1; shift > idx; shift--) 
    {
        list->elem[shift] = list->elem[shift - 1];
    }
    // set elem
    list->elem[idx] = ch;
}

void deleteAll(L *list, char ch)
{
    int newSize = list->size;
    int write = 0;
    int scan;
    for (scan = 0; scan < list->size; scan++)
    {
        if (list->elem[scan] == ch)
            newSize--;
        else
            list->elem[write++] = list->elem[scan];
    }
    list->size = newSize;
}

void disp(L *list)
{
    int i;
    for (i = 0; i < list->size; i++)
    {
        printf("%c", list->elem[i]);
    }
    printf("\n");
}

int main()
{
    L myList = initList();
    insertSorted(&myList, 'A');
    insertSorted(&myList, 'B');
    insertSorted(&myList, 'C');
    insertSorted(&myList, 'D');
    insertSorted(&myList, 'A');
    // deleteAll(&myList, 'A');
    disp(&myList);
    return 0;
}