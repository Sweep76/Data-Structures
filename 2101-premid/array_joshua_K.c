#ifndef STACK_H
#define STACK_H
#define MAX 8
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[MAX];
    int TOP;
} Stack;

void PUSH(Stack *S, int data);
int POP(Stack *S);
int TOP(Stack S);
void initStack(Stack *S);
int isEmpty(Stack S);
int isFull(Stack S);
void displayStack(Stack S);

int main(){
    Stack S;
    initStack(&S);
    PUSH(&S,1);
    PUSH(&S,2);
    PUSH(&S,3);
    PUSH(&S,4);
    PUSH(&S,5);
    PUSH(&S,6);
    PUSH(&S,7);
    PUSH(&S,8);
    displayStack(S);
    POP(&S);
    printf("\nEmpty is: %d", isEmpty(S));
    printf("\nFull is: %d\n", isFull(S));
    printf("\nTOP is: %d\n", TOP(S));
    displayStack(S);
}

void PUSH(Stack *S, int data)
{
    if (!isFull(*S)) //to check if TOP is not full
        S->TOP += 1;
        S->data[S->TOP] = data;
}

int POP(Stack *S)
{
    if (isEmpty(*S)){ //If Array is not empty
    return NULL;
    } else{
        S->TOP -= 1;
        S->data[S->TOP];
    }
}

int TOP(Stack S)
{
    if(isEmpty(S)) {
        return NULL;
    } else {
        S.data[S.TOP];
    }
}

void initStack(Stack *S)
{
    S->TOP = -1;
}

int isEmpty(Stack S)
{
    return(S.TOP == -1) ? 1 : 0;
}

int isFull(Stack S)
{
    return(S.TOP == MAX - 1) ? 1 : 0;
}

void displayStack(Stack S)
{
    int i = 0;
    while (i <= S.TOP)
        printf("%d", S.data[i++]);
}

#endif