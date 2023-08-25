#include <stdio.h>
#include <stdlib.h>
#define SIZE 23
#define EMPTY 0
#define DELETED -1

typedef int Dictionary[SIZE];
typedef enum
{
    false,
    true
} bool;

Dictionary D;

int hashVal(int elem);
void initHashTable(Dictionary *hashT);
void displayHashTable(Dictionary hashT);

void insert(Dictionary *hashT, int elem)
{
    int hash = hashVal(elem);
    int idx = hash;
    while (1)
    {
        if ((*hashT)[idx] == elem)
            return;
        idx = (idx + 1) % SIZE;
        if (idx == hash)
            return;
    }
    for (idx = (hash + 1) % SIZE; idx != hash - 1 && (*hashT)[idx] != EMPTY && (*hashT)[idx] != DELETED && (*hashT)[idx] != elem; idx = (idx + 1) % SIZE) { }
    if ((*hashT)[idx] == EMPTY || (*hashT)[idx] == DELETED)
    {
        (*hashT)[idx] = elem;
    }
}

void delete(Dictionary *hashT, int elem)
{
    int hash = hashVal(elem);
    int idx = hash;
    if ((*hashT)[idx] != elem)
    {
        for (idx = (hash + 1) % SIZE; idx != hash && (*hashT)[idx] != EMPTY && (*hashT)[idx] != elem; idx = (idx + 1) % SIZE) { }
    }
    if ((*hashT)[idx] == elem)
    {
        (*hashT)[idx] = DELETED;
    }
    else
    {
        printf("The element with the value %d is not in the Dictionary\n", elem);
    }
}


int isMember(Dictionary hashT, int elem)
{
    int hash = hashVal(elem);
    int idx = hash;
    while (hashT[idx] != elem)
    {
        if (hashT[idx] == EMPTY)
            return 0;
        idx = (idx + 1) % SIZE;
        if (idx == hash)
            return 0;
    }
    return 1;
}


int main()
{
    initHashTable(&D);
    insert(&D, 4057);
    insert(&D, 3042);
    insert(&D, 3205);
    insert(&D, 848);
    insert(&D, 1864);
    insert(&D, 987);
    insert(&D, 3082);
    insert(&D, 414);
    insert(&D, 1728);
    insert(&D, 1400);
    insert(&D, 1223);
    insert(&D, 2710);
    insert(&D, 2486);
    insert(&D, 2885);
    insert(&D, 1192);
    insert(&D, 4057);

    delete(&D, 4057);
    delete(&D, 3205);
    delete(&D, 1728);
    delete(&D, 2486);
    delete(&D, 1192);
    delete(&D, 5595);

    insert(&D, 1400);
    insert(&D, 5595);
    insert(&D, 121);
    insert(&D, 139);
    insert(&D, 1532);
    insert(&D, 596);
    insert(&D, 2800);
    insert(&D, 1167);
    insert(&D, 213);
    displayHashTable(D);
}


int hashVal(int x)
{
    int hash = 0;
    int idx;
    for (; x > 0 && x % 10 == 0; x /= 10) { }
    for (idx = 0; idx < 4; hash += x % 10, x /= 10, idx++) { }
    return hash % SIZE;
}

void initHashTable(Dictionary *hashT)
{
    int idx;
    for (idx = 0; idx < SIZE; (*hashT)[idx] = EMPTY, idx++) { }
}

void displayHashTable(Dictionary hashT)
{
    int idx;
    printf("Index\tContent\t    Hash Value  Search Length\n");
    for (idx = 0; idx < SIZE; idx++)
    {
        printf("%5d\t", idx);
        if (hashT[idx] == EMPTY)
            printf("%7s\t    ", "EMPTY");
        else if (hashT[idx] == DELETED)
            printf("%7s\t    ", "DELETED");
        else
        {
            int hash = hashVal(hashT[idx]);
            printf("%7d\t    ", hashT[idx]);
            printf("%10d  ", hash);
            printf("%13d", (idx < hash ? idx + SIZE : idx) - hash + 1);
        }
        printf("\n");
    }
}
