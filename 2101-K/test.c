#include <stdlib.h>
#include <stdio.h>
#define MAX 8

typedef struct {
    char Elem[MAX];
    int top;
} Stack;

Stack *initialize()
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->top = -1;
    return newStack;
}

void push(Stack *stack, char elem)
{
    if (stack->top < MAX-1)
        stack->Elem[++stack->top] = elem;
}

char pop(Stack *stack)
{
    if (stack->top >= 0)
        return stack->Elem[stack->top--];
    return NULL;
}

char top(Stack *stack)
{
    if (stack->top >= 0)
        return stack->Elem[stack->top];
    return NULL;
}

int empty(Stack *stack)
{
    return stack->top == -1;
}

int full(Stack *stack)
{
    return stack->top == MAX - 1;
}

void display(Stack *stack)
{
    int i = 0;
    for (; i <= stack->top; i++)
    {
        printf("%c", stack->Elem[i]);
    }
    printf("\n");
}

int main()
{
    Stack *stack = initialize();
    printf("%d\n", empty(stack));
    push(stack, 'h');
    push(stack, 'e');
    push(stack, 'l');
    push(stack, 'l');
    push(stack, 'o');
    printf("%c\n", pop(stack));

    display(stack);
}