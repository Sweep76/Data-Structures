#include <stdio.h>
#include <stdlib.h>
#ifndef  STACK_H
   #define STACK_H
      /* Stack definition */
      typedef struct node{
          int data;
          struct node*next;
      }*Stack;
      
//Functions

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
    POP(&S);
    printf("\nEmpty is: %d", isEmpty(S));
    printf("\nTOP is: %d\n", TOP(S));
    displayStack(S);
}

    
void INITALIZE(Stack *S){
    *S = NULL; //Make stack empty
}

int isEmpty(Stack S){
//Check if the Stack is empty
    int flag;
    if(S==NULL){
        flag = 0;
    }else{
        flag = 1;
    }
        
    return flag;
}

int TOP(Stack S){
//Returns the value of the element on top
//If list is empty, it returns -1
    int value;
    
    if(S != NULL){
        value =  S->data;
    }else{
        value = -1;
    }
    return value;
}

void PUSH(Stack *S, int elem){
//Put in an element in the Stack
    Stack temp = (Stack)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = *S;
    *S = temp;
 }
 
void POP(Stack*S){
//Take out an element from the Stack
    Stack temp = *S;
    *S = (*S)->next;
    free(temp);
 }
 
 void displayStack(Stack S){
//Prints the data in the Stack
//While emptying it
     printf("\n");
    while(isEmpty(S) != 0){
        printf("%d", TOP(S));
        POP(&S);
    }
 }
   #endif