#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// DEFINITION

typedef struct List
{
    char elem[SIZE];
    int count;
} *List;

List ListInit();
void ListInsertFront(List list, char elem);
void ListInsertEnd(List list, char elem);
void ListInsertIdx(List list, int idx, char elem);
void ListInsertSorted(List list, char elem);
char ListPeek(List list, int idx);
void ListDeleteFront(List list);
void ListDeleteEnd(List list);
void ListDeleteIdx(List list, int idx);

// INIT

List ListInit()
{
    List list = (List)malloc(sizeof(struct List));
    list->count = 0;
    return list;
}

// CREATE

void ListInsertFront(List list, char elem)
{
    if (list->count < SIZE)
    {
        list->count++;
        int i;
        for (i = 1; i < list->count; i++)
        {
            list->elem[i] = list->elem[i - 1];
        }
        list->elem[0] = elem;
    }
}

void ListInsertEnd(List list, char elem)
{
    if (list->count < SIZE)
    {
        list->elem[list->count++] = elem;
    }
}

void ListInsertIdx(List list, int idx, char elem)
{
    if (list->count < SIZE && idx >= 0 && idx <= list->count)
    {
        list->count++;
        int i;
        for (i = list->count - 1; i > idx; i--)
        {
            list->elem[i] = list->elem[i - 1];
        }
        list->elem[idx] = elem;
    }
}

void ListInsertSorted(List list, char elem)
{
    if (list->count == 0)
    {
        list->elem[list->count++] = elem;
    }
    else if (list->count < SIZE)
    {
        int low = 0;
        int high = list->count - 1;
        int mid = (low + high) / 2;
        while (low <= high && list->elem[mid] != elem)
        {
            if (list->elem[mid] < elem)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }
        ListInsertIdx(list, (list->elem[mid] == elem) ? mid : low, elem);
    }
}

// READ

char ListPeek(List list, int idx)
{
    return (idx >= 0 && idx < list->count) ? list->elem[idx] : '\0';
}

void ListPrint(List list)
{
    printf("[");
    if (list->count > 0)
    {
        printf("%c", list->elem[0]);
        int i;
        for (i = 1; i < list->count; i++)
        {
            printf(", %c", list->elem[i]);
        }
    }
    printf("]\n");
}

// DELETE

void ListDeleteFront(List list)
{
    if (list->count > 0)
    {
        list->count--;
        int i;
        for (i = 0; i < list->count - 1; i++)
        {
            list->elem[i] = list->elem[i + 1];
        }
    }
}

void ListDeleteEnd(List list)
{
    if (list->count > 0)
    {
        list->count--;
    }
}

void ListDeleteIdx(List list, int idx)
{
    if (list->count > 0 && idx >= 0 && idx < list->count)
    {
        list->count--;
        int i;
        for (i = idx; i < list->count - 1; i++)
        {
            list->elem[i] = list->elem[i + 1];
        }
    }
}

int main()
{
    List list = ListInit();
    ListInsertSorted(list, 'b');
    ListInsertSorted(list, 'w');
    ListInsertSorted(list, 'a');
    ListInsertSorted(list, 'r');
    ListInsertSorted(list, 'h');
    ListInsertSorted(list, 'k');
    ListInsertSorted(list, 'e');
    ListInsertSorted(list, 'w');
    ListInsertSorted(list, 'u');
    ListInsertSorted(list, 'q');
    ListPrint(list);
    return 0;
}