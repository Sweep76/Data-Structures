/*
    Kyne Edric Sia
    Julian Ernest Camello
    Joel Jayme
*/
// #include "stackArray.h"
#include "stackLink.h"

void insertBottom(Stack *stack, char elem)
{
    Stack spare;
    initStack(&spare);
    while (!isEmpty(stack))
        push(&spare, pop(stack));
    push(stack, elem);
    while (!isEmpty(&spare))
        push(stack, pop(&spare));
}
