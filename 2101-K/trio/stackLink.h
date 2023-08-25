#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} * Node;

typedef struct {
    Node top;
} Stack;


void push(Stack *stack, char elem)
{
    Node node = (Node) malloc(sizeof(struct node));
    if (node != NULL)
    {
        node->data = elem;
        node->link = stack->top;
        stack->top = node;
    }
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    Node node = stack->top;
    char elem = node->data;
    stack->top = node->link;
    free(node);
    return elem;
}

char top(Stack *stack)
{
    return (isEmpty(stack)) ? 0 : stack->top->data;
}

void initStack(Stack *stack)
{
    stack->top = NULL;
}

int isFull(Stack *stack)
{
    return 1;
}

void displayStack(Stack *stack)
{
    Stack spare;
    initStack(&spare);
    while (!isEmpty(stack))
        push(&spare, pop(stack));
    while (!isEmpty(&spare))
    {
        char ch = pop(&spare);
        printf("%c", ch);
        push(stack, ch);
    }
}

#endif