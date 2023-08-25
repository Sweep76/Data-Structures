#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 8

typedef struct {
    char elem[max];
    int top;
} Stack;

void INITIALIZE(Stack *stack)
{
    stack->top = -1;
}

void PUSH(char x, Stack *stack)
{
    stack->elem[++stack->top] = x;
}

char POP(Stack *stack)
{
    return (EMPTY(stack)) ? NULL : stack->elem[stack->top--];
}

char TOP(Stack *stack)
{
    return (EMPTY(stack)) ? NULL : stack->elem[stack->top];
}

int EMPTY(Stack *stack)
{
    return stack->top == -1;
}

int FULL(Stack *stack)
{
    return stack->top == max - 1;
}

void DISPLAY(Stack *stack)
{
    int i;
    printf("________\n");
    for (i = 0; i < max; i++)
    {
        char ch = stack->elem[i];
        int isreadable = isalnum(ch) || ispunct(ch) || isspace(ch);
        printf("|%02d|", i, ch);
        if (isreadable)
            printf("'%c'|", ch);
        else
            printf("???|");
        if (i == stack->top)
            printf("<--");
        printf("\n");
    }
    printf("________\n");
}

int main()
{
    Stack stack;
    INITIALIZE(&stack);
    PUSH('H', &stack);
    PUSH('O', &stack);
    PUSH('P', &stack);
    PUSH('E', &stack);
    printf("%c\n", TOP(&stack));
    DISPLAY(&stack);
    return 0;
}