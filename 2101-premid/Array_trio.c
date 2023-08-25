#include <stdio.h> 
#include <stdlib.h>
#ifndef STACK_H
#define STACK_H
#define MAX 10

typedef struct {
    int data[MAX];
    int next;
} Stack;

void INITIALIZE(Stack *S); //address
void PUSH(int elem, Stack *S); //address
void POP(Stack *S); //address
int TOP(Stack *S);
int isEmpty(Stack *S);
int isFull(Stack *S);
void displayStack(Stack S);

int main(){
    Stack S;
    INITIALIZE(&S);
    PUSH(1, &S);
    PUSH(2, &S);
    PUSH(3, &S);
    POP(&S);
    printf("%d",TOP(&S));
    displayStack(S);
}

void INITIALIZE(Stack *S) {
    S->next = MAX;
}

void PUSH(int elem, Stack *S) {
    S->next = (S->next) - 1;
    S->data[S->next] = elem;
}

void POP(Stack *S) {
    S->next = (S->next) + 1;
}

int TOP(Stack *S) {
    char new;
    new = S->data[S->next];
    return new;
}

int isEmpty(Stack *S) {
    return (S->next == MAX) ? 1:0;
}

int isFull(Stack *S) {
    return (S->next == 0) ? 1:0;
}

void displayStack(Stack S) {
    int ctr;
    for (ctr = MAX; ctr >= S.next; ctr++) {
        printf("%c", S.data[ctr]);
    }
}

#endif