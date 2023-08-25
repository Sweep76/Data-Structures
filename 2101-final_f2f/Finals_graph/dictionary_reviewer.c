#include <stdio.h>
#include <stdlib.h>
#define SIZE 0XD

typedef struct{
    char LN[16], FN[24], MI;
    /* Last Name, First name, and Mid initial */
}nametype;

typedef struct{
    unsigned long IDen;
    nametype name;
    char course[8];
    int year;
}studRec;

typedef struct node {
    studRec stud;
    struct node *next;
}*List;

typedef struct {
    List Head[SIZE];
    int count;
}Dictionary;

int openHash(unsigned long IDen);

void insertDic(Dictionary *D,studRec S) /* Blank_01 */
{
    int hash;
    List *ptr, temp; 
    hash = openHash(S.IDen); /* Blank_02 */
    
    /* Determines the position of the element to be inserted */
    for(ptr = &D->Head[hash]; *ptr != NULL && S.IDen>(*ptr)->stud.IDen; ptr = &(*ptr)->next){} /* Blank 3,4,5 */

    /* Conditions for a possible insertion */
    if(*ptr == NULL || (*ptr)->stud.IDen > S.IDen){ /* Blank 6 & Blank 7 */
        temp = (List)malloc(sizeof(struct node));
        if(temp != NULL){
            /* Statements to insert the element */
        }
    }

}