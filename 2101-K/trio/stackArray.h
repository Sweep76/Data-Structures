#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#define max 8

typedef struct {
    char elem[max];
    int top;
} Stack;

void initStack(Stack *s){ //does not traverse but initializes the stack
	s->top = -1;
}

void push(Stack *s, char NewElem){ //inserts data traverse
	if(isFull(s)){
		printf("stack is full");
    }else{
		s->top++;
		s->elem[s->top] = NewElem;
	}
}

char pop(Stack *s){ //removes top element at the top
    char ch = s->elem[s->top];
    s->top--;
    return ch;
}

char top(Stack *s){ //gets the value of the element of the TOP but change it or deletes it. it is also known as peek();
	return s->elem[s->top];
}

int isEmpty(Stack *s){
	return (s->top > -1) ? 0:1;
}

int isFull(Stack *s){
    return (s->top == max-1) ? 1:0;
}

void displayStack(Stack *s)
{
    Stack temp;
    initStack(&temp);
    while (!isEmpty(s)){
        push(&temp, pop(s));
    }
    while (!isEmpty(&temp)){
        char ch = pop(&temp);
        printf("%c", ch);
        push(s, ch);
    }
}

#endif