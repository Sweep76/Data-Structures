#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int elem;
    struct cell *next;
}ctype, *SET;

SET UNION(SET A, SET B){
    SET C, *cptr, aptr, bptr;
    C = NULL;
    cptr = &C;
    aptr = A;
    bptr = B;
    while(aptr != NULL && bptr != NULL){
        *cptr = (SET)malloc(sizeof(ctype));
        if(aptr->elem < bptr->elem){
            (*cptr)->elem = aptr->elem;
            aptr = aptr->next;
        } else {
            if(aptr->elem == bptr->elem){
                aptr = aptr->next;
            }
        }
        (*cptr)->elem = bptr->elem;
        bptr = bptr->next;
    }
    cptr = &(*cptr)->next;
    if(bptr != NULL){
        aptr = bptr;
    }
    while(aptr != NULL){
        *cptr = (SET)malloc(sizeof(ctype));
        (*cptr)->elem = aptr->elem;
        aptr = aptr->next;
        cptr = &(*cptr)->next;
    }
    *cptr = NULL;
    return C;
}

  void PUSH(char elem, SET *S) { // Put in an element in the Stack
    SET temp = (SET)malloc(sizeof(ctype));
    if (S != NULL) {
      temp->elem = elem;
      temp->next = *S;
      *S = temp;
    }
  }

  void display(SET S) {
    printf("{");
    while (S != NULL) {
      printf(" %c", S->elem);
      if (S->next != NULL) {
        printf(" -> ");
      }
      S = S->next;
    }
    printf(" }\n");
  }

int main(){
    SET A = NULL, B = NULL, onion = NULL;
    PUSH('E', &A);
    PUSH('F', &A);
    PUSH('J', &A);
    PUSH('K', &A);
    PUSH('Q', &A);
    PUSH('F', &B);
    PUSH('G', &B);
    PUSH('I', &B);
    PUSH('K', &B);
    PUSH('M', &B);
    printf("SET A:");
    display(A);
    printf("SET B:");
    display(B);
    printf("SET UNION:");
    onion = UNION(A, B);
    display(onion);
}

